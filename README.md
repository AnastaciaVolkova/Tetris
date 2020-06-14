# Tetris
Capstone project for Udacity Nanodegree program [CppND](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).Project implements the game [Tetris](https://en.wikipedia.org/wiki/Tetris).
![Game field gif](https://github.com/AnastaciaVolkova/Tetris/blob/master/doc/out.gif)
## Gameplay
Player should place the falling figures in a way that the pile on the bottom has as less as possible empty cells. When line in the pile has no empty cells, it is deleted. Player can rotate figures, accelerate their fall. Player fails, when at least one figure exaggerates the game field on the top. For one deleted line player receives 10 scores, for two deleted at once lines - 40, three - 80,  four - 160.
- left arrow - move figure left
- right arrow - move figure right
- up arrow - rotate counter clock wise
- up down - rotate clock wise
- space - accelerate falling of figure
- q or esc - leave game

![Game field](https://github.com/AnastaciaVolkova/Tetris/blob/master/doc/Game.png)

# Dependencies for Running Locally
- cmake >= 3.16.7
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- SDL >= 2.0
  - All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  - Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
- gcc/g++ >= 7.5.0
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

# Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./tetris`.

## Notes
- framework is inspired from [Udacity Snake](https://github.com/udacity/CppND_Capstone_Snake_Game)

# Project description
Program is logically divided into three parts Model - View - Controller. Model stands for Gameplay. View represents graphically game. View knows quite nothing about game and receives commands from Controller. Controller implements interface between model (game) and view (SDL). In case view sdl is changed with another graphical library (QT eg) only few changes should be done in Controller.
<br>
*Files and classes of Model:*
- model.cpp model.hpp (class Model) - main gameplay is done here. Creates and uses figures, creates and uses class Pile, provides points to draw to Controller. Knows nothing about graphic libraries.
- figure.cpp figure.hpp (Abstract class Figure)  - declare abstract class, which represents figure. Figure has  forms. Form is the set of points with definite color. Figure has several forms, as it is rotated.
- figure1.cpp, figure1.hpp - class Figure1 inherits abstract class Figure. Figure1 is a figure which is central-symmetrical and that’s why has only one form.
- figure2.cpp, figure2.hpp - class Figure2 inherits abstract class Figure. Figure2 is a figure which is horizontally symmetric and has two forms.
- figure4.cpp, figure4.hpp - class Figure4 inherits abstract class Figure. Figure4 is figure which has four different rotational forms.
- pile.cpp, pile.hpp - class Pile implements Pile of figure on the bottom. Main functionality is to accept new figures and check if there are lines to be deleted.</br>
*Files and class of Controller*:
- point.cpp point.hpp (class Point) - class Point implements 2D point with colors. Is used actively by Figure and Pile.
- controller.hpp, controller.cpp (class Point) - class Controller uses methods of View and Model classes. It organizes Input-Update-Render loop, create object of classes View and Model. Class Controller processes commands from player.</br>
*Files and class of View*:
- view.hpp, view.cpp - class View is graphical representation of the game. It create main game window, draw objects, which are provided by controller, process keyboard commands.


# The following rubric points are addressed
1. Class constructors utilize member initialization lists (All class members that are set to argument values are initialized through member initialization lists) -  ./src/pile.cpp:8
2. Derived class functions override virtual base class functions (One member function in an inherited class overrides a virtual base class member function) - src/Figure2.hpp:24, src/Figure2.cpp:10
3. Classes use appropriate access specifiers for class members (All class data members are explicitly specified as public, protected, or private.) - src/Figure.hpp:11 and src/Figure1.hpp:10
4. Classes encapsulate behavior (Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions) - ./src/Model.hpp
5. The project makes use of references in function declarations (At least two variables are defined as references, or two functions use pass-by-reference in the project code) ./src/model.hpp:26, ./src/figure.hpp:23

# Class Description
## Commands
<pre> Class contains user commands.</pre>
## Controller
<pre> Class takes over interacting between game and its graphical representation.</pre>
###  Controller::Controller(size_t target_frame_duration, size_t screen_height)
<pre> Constructor</pre>
_[in] target_frame_duration duration of game loop_
_[in] screen_height height of the window_
###  Controller::Run()
<pre> Game loop</pre>
###  Controller::Input()
<pre> Get user command from keyboard.</pre>
<pre> Key code</pre>
###  Controller::Update(Commands command)
<pre> Update game state</pre>
_[in] command command from user_
###  Controller::Render()
<pre> Draw the figure</pre>
_[in] space point to draw_

## Model
<pre> Class implements game model</pre>
###  Model::Model()
<pre> Constructor</pre>
###  Model::GetOccupiedSpace()
<pre> Receive points, which represent occupied by figure space</pre>
<pre> returns points of occupied space</pre>
###  Model::UpdatePosition(Point &&point)
<pre> Update position of figure</pre>
_[in] point difference between new position and previous one_
###  Model::GetTimeFall()
<pre> Get fall time (s)</pre>
###  Model::RotateCounter()
<pre> Rotate counter clock-wise figure</pre>
###  Model::Rotate()
<pre> Rotate clock-wise figure</pre>
###  Model::Accelerate()
<pre> Accelerate falling figure</pre>
###  Model::GetScore()
<pre> Get player score</pre>
<pre> returns player score</pre>
###  Model::IsGameOver()
<pre> Check if game over</pre>
<pre> returns true if game over has happened, otherwise returns false</pre>
###  Model::GetGameFieldWidth()
<pre> Get game field width</pre>
<pre> returns game field width</pre>
###  Model::GetGameFieldHeight()
<pre> Get game field height</pre>
<pre> returns game field height</pre>
###  Model::CheckBoundaries()
<pre> Check if figure is in boundaries of game field</pre>
###  Model::UpdateFallingFigureSpace()
<pre></pre>
###  Model::FigureGenerator()
<pre> Get new figure</pre>
###  Model::ComputeScore(unsigned num_del_lines)
<pre> Compute score</pre>
_[in] num_del_lines number of deleted lines_
## Pile
<pre> Class implements bottom of the game field</pre>
###  Pile::Pile(int width, int height)
<pre> Default constructor</pre>
_[in] width width of game field_
_[in] height height of game field_
###  Pile::IsTouched(const Figure *figure)
<pre> Checks if figure touches bottom</pre>
_[in] figure figure to check if touches pile_
<pre> returns true if figure touches bottom</pre>
###  Pile::AddFigure(const Figure *figure)
<pre> Add figure to pile</pre>
_[in] space points of figure_
<pre> returns number of deleted lines</pre>
###  Pile::GetPile()
<pre> Get points of pile</pre>
<pre> returns points of pile</pre>
###  Pile::IsOverloaded()
<pre> Get information on pipe overload</pre>
<pre> returns true if pipe is overloaded, otherwise returns false</pre>
###  Pile::ClearLine()
<pre> Search for line to clear and clear it</pre>
<pre> returns number of deleted lines</pre>
###  Pile::ComputePilePointsSpace()
<pre> Compute points of pile</pre>
## Figure1
<pre> Class Figure1 represents the game figure with rotation 1 state</pre>
###  Figure1::Figure1(Point &&p, Color c)
<pre> Constructor</pre>
_[in] p point initial position of the figure_
_[in] c color of the figure_
###  Figure1::RotateCounter()
<pre> Rotate counter clock-wise</pre>
###  Figure1::Rotate()
<pre> Rotate clock-wise</pre>
###  Figure1::make_square(Point &&p)
<pre> Makes left-s figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure1 object, which is initialized as square</pre>
## Figure2
<pre> Class Figure2 represents the game figure with rotation 2 states</pre>
###  Figure2::Figure2(Point &&p, Color c)
<pre> Constructor</pre>
_[in] p point initial position of the figure_
_[in] c color of the figure_
###  Figure2::RotateCounter()
<pre> Rotate counter clock-wise</pre>
###  Figure2::Rotate()
<pre> Rotate clock-wise</pre>
###  Figure2::make_ls(Point &&p)
<pre> Makes left-s figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure2 object, which is initialized as left-s figure</pre>
###  Figure2::make_rs(Point &&p)
<pre> Make right-s figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure2 object, which is initialized as right-s figure</pre>
###  Figure2::make_stick(Point &&p)
<pre> Make stick figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure2 object, which is initialized as stick figure</pre>
## Figure4
<pre> Class Figure4 represents the game figure with rotation 4 states</pre>
###  Figure4::Figure4(Point &&p, Color c)
<pre> Constructor</pre>
_[in] p point initial position of the figure_
_[in] c color of the figure_
###  Figure4::RotateCounter()
<pre> Rotate counter clock-wise</pre>
###  Figure4::Rotate()
<pre> Rotate clock-wise</pre>
###  Figure4::make_lhook(Point &&p)
<pre> Makes left hook figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure4 object, which is initialized as left-hook figure</pre>
###  Figure4::make_rhook(Point &&p)
<pre> Make right hook figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure4 object, which is initialized as right-hook figure</pre>
###  Figure4::make_t(Point &&p)
<pre> Make T figure</pre>
_[in] p point initial position of figure_
<pre> returns Figure4 object, which is initialized as T figure</pre>
## View
<pre> Provides graphical part of the game.</pre>
## Color
<pre> Contains figure color</pre>
###  Color::Point()
<pre> Struct Point implements operations with points</pre>
###  Color::Point(int xx, int yy, Color color = Color::kBlack)
<pre> Constructor</pre>
_[in] xx x-coordinate_
_[in] yy y-coordinate_
_[in] cc Color_
###  Color::GetRgba()
<pre> Get tuple of rgba</pre>
###  View::View()
<pre> Constructor</pre>
_[in] screen_width width of the screen_
_[in] screen_height height of the screen_
_[in] cell_size size of quadratic cell_
###  View::Render(const std::vector<Point> &x, const std::string &title)
<pre> Draw the points</pre>
_[in] x points to draw_
_[in] title window title_
###  View::GetHeight()
<pre> Getter for height of the game field</pre>
<pre> returns height of the game field</pre>