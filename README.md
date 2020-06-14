# Tetris
Capstone project for Udacity Nanodegree program [CppND](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).Project implements the game [Tetris](https://en.wikipedia.org/wiki/Tetris).
## Gameplay
Player should place the falling figures in a way that the pile on the bottom has as less as possible empty cells. When line in the pile has no empty cells, it is deleted. Player can rotate figures, accelerate their fall. Player fails, when at least one figure exaggerates the game field on the top. For one deleted line player receives 10 scores, for two deleted at once lines - 40, three - 80,  four - 160.
- left arrow - move figure left
- right arrow - move figure right
- up arrow - rotate counter clock wise
- up down - rotate clock wise
- space - accelerate falling of figure
- q, esc - leave game
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

# Classes descriptions
## Commands
<pre>Class contains user commands.</pre>
## Controller
<pre>Class takes over interacting between game and its graphical representation.</pre>
### Controller::Controller(Model &model, View &view)
<pre>Constructor</pre>
- [in,out] model reference to model of game
- [in,out] view reference to graphical representation of view
### Controller::Run(size_t target_frame_duration)
<pre>Game loop</pre>
- [in] target_frame_duration duration of game loop (game frame)
### Controller::Input(size_t target_frame_duration)
<pre>Get user command from keyboard.</pre>
-[in] target_frame_duration duration of game loop (game frame)
returns Key code
### Controller::Render(std::vector<Point> space)
<pre>Draw the figure</pre>
-[in] space point to draw

## Point
Struct Point implements operations with points

## Figure
<pre>Class Figure represents the game figure</pre>
### Figure::Figure()
<pre>Default constructor</pre>
### Figure::Figure(Point &&p)
<pre>Constructor</pre>
- [in] p point initial position of figure
### Figure::GetForm()
<pre>Get form of the figure</pre>
returns vector with point of figure form
### Figure::GetPosition()
<pre>Get current position of figure</pre>
### Figure::SetPosition(Point p)
<pre>Set current position of figure</pre>
- [in] p position of figure

## View
<pre>Provides graphical part of the game.</pre>
### View::View()
<pre>Constructor</pre>
- [in] screen_width width of screen
- [in] screen_height height of screen
- [in] grid_width width of element to draw
- [in] grid_height height of element to draw
### View::SetController(Controller *controller)
<pre>Provide the controller for interaction with it</pre>
- [in,out] controller controller for interaction
### View::Render(std::vector<Point> x)
<pre>Draw the points</pre>
- [in] x points to draw

## Model
<pre>Class implements game model</pre>
### Model::Model()
<pre>Constructor</pre>
### Model::SetController(Controller *controller)
<pre>Setter for controller field</pre>
- [in,out] controller pointer for manipulation
### Model::GetOccupiedSpace()
<pre>Receive points, which represent occupied by figure space</pre>
- returns points of occupied space
### Model::UpdatePosition(Point &point)
<pre>Update position of figure</pre>
- [in] point new position
### Model::GetTimeFall()
<pre>Get fall time (s)</pre>

controller.hpp
figure.hpp
view.hpp
model.hpp