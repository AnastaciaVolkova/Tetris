import sys
import re
import os
import time
from subprocess import Popen, PIPE
from spellchecker import SpellChecker


class Params:
    def __init__(self, n, in_out, d):
        self.name = n
        self.in_out = in_out
        self.description = d


class Ret:
    def __init__(self, ret):
        self.description = ret


class Method:
    def __init__(self, n, d):
        self.params = list()
        self.name = n
        self.description = d
        self.ret = ""


class Class:
    def  __init__(self, n, d):
        self.description = d
        self.methods = list()
        self.name = n


def GetTypos(line):
    typos = ""
    if line != "":
        spell = SpellChecker()
        word_pat = re.compile("(\w+)")
        to_check = word_pat.findall(line)
        to_check = [str(s) for s in to_check]
        typos = spell.unknown(to_check)
    return typos


def main():
    pat = re.compile("(?<=//\!).+");
    pat_be = "/*!";
    pat_en = "*/"
    pat_cl = re.compile("(?<=class) +\w+")
    pat_me = re.compile("\w+\(.*?\)")
    pat_pa = re.compile("(?<=\\\\param) +(\[.+\]) +(\w+) +(.+)")
    pat_re = re.compile("(?<=\\\\return).+")

    with open(sys.argv[1]) as fid:
        lines = fid.read().splitlines();
    
    desc = ""
    methods = list()
    classes = list()
    params = list()
    braces_count = 0
    for i in range(len(lines)):
        if lines[i].startswith("#") or len(lines[i].strip()) == 0:
            i += 1
            continue
        m = pat.findall(lines[i])
        m_cl = pat_cl.findall(lines[i])
        m_me = pat_me.findall(lines[i])
        if len(m) != 0:
            desc = m[0]
        elif len(m_me) != 0:
            methods.append(Method(m_me[0], desc))
            for p in params:
                methods[-1].params.append(p)
            desc = ""
            params = list()
        elif pat_be in lines[i]:
            i += 1
            while pat_en not in lines[i]:
                m_pa = pat_pa.findall(lines[i])
                m_re = pat_re.findall(lines[i])
                if len(m_pa) != 0:
                    params.append(Params(m_pa[0][0], m_pa[0][1], m_pa[0][2]))
                elif len(m_re) != 0:
                    params.append(Ret(m_re[0]))
                else:
                    desc += lines[i] + "\n"
                i += 1
        else:
            if len(m_cl) != 0:
                braces_count = 0
                classes.append(Class(m_cl[0], desc))
                desc = ""

            braces_count += lines[i].count("{") - lines[i].count("}")
            if braces_count == 0:
                if len(methods) != 0:
                    classes[-1].methods = methods
                    methods = list()
            i += 1

    with open("results.txt", "w") as fid:
        fid.write(os.path.basename(sys.argv[1] + "\n"))
        for cls in classes:
            fid.write(cls.name + "\n")
            fid.write(cls.description + "\n")
            typos = GetTypos(cls.description)
            if len(typos):
                print(typos)
            for m in cls.methods:
                fid.write("{0}::{1}\n".format(cls.name, m.name))
                fid.write(m.description + "\n")
                typos = GetTypos(m.description)
                if len(typos):
                    print(typos)
                for p in m.params:
                    if type(p).__name__ == "Params":
                        fid.write("{0} {1} {2}\n".format(p.name, p.in_out, p.description))
                    else:
                        fid.write(p.description + "\n")
                    typos = GetTypos(p.description)
                    if len(typos):
                        print(typos)

    '''
    proc = Popen("aspell -c dest.txt".split(), stdout=PIPE, stderr=PIPE)
    out, err = proc.communicate()
    out = out.decode()
    err = err.decode()
    '''
    pass


if __name__ == "__main__":
    main()

