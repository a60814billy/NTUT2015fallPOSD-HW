#include <sstream>
#include "circle.h"
#include "boundingbox.h"

Circle::Circle(int cx, int cy, int radius)
	:Shape("circle"), _cx(cx), _cy(cy), _radius(radius) {}

string Circle::print() {
	std::ostringstream oss;
	oss << name() << "(" << _cx << "," << _cy << "," << _radius << ")";
	return oss.str();
}

BoundingBox Circle::getBoundingBox() const {
	BoundingBox box(_cx - _radius, _cy - _radius, _radius * 2, _radius * 2);
	return box;
}

int Circle::area() const {
	return 3 * _radius*_radius;
}