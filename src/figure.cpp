#include "figure.hpp"

using std::vector;

Figure::Figure(Point &&p, Color color) : position_(p), color_(color){};

const vector<Point> &Figure::GetForm() const { return forms_.at(state_); };

const Point &Figure::GetPosition() const { return position_; };

void Figure::SetPosition(Point &&p) { position_ = p; };
