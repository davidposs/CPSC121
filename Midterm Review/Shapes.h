#pragma once
#include <iostream>

/* I defined all the member functions within the classes themselves just 
   because they're all one or two lines, and didn't want anyone to waste
   time flipping back and forth for just a line or to. But remember its
   bad practice! The int_stack class for question 8 is properly formatted */

class Point {
public:
	Point() : x_(0), y_(0) {}
	Point(float x, float y) : x_(x), y_(y) {}

	// Getters
	float x() { return x_; }
	float y() { return y_; }

	// Setters
	void setX(float x) { x_ = x; }
	void setY(float y) { y_ = y; }

	friend std::ostream& operator<<(std::ostream& os, Point p) {
		os << "Point: (" << p.x() << ", " << p.y() << ")";
		return os;
	}

private:
	float x_, y_;
};


class Shape {
public:
	// Initialize center_ with default Point constructor
	Shape() : center_(Point()), length_(0), width_(0) {}
	// Initialize center_ with Point passed to constructor
	Shape(Point p, float l, float w) : center_(p), length_(l), width_(w) {}

	// Declare some pure virtual functions. Makes shape an abstract class.
	// Note we don't define them, that must be done by child classes of Shape.
	virtual float area() = 0;
	virtual float perimeter() = 0;

	// Getters
	float length() { return length_; }
	float width() { return width_; }

	// Setters
	void setLength(float newLength) { length_ = newLength; }
	void setWidth(float newWidth) { width_ = newWidth; }

private:
	Point center_;
	float length_, width_;
};


class Rectangle : public Shape {
public:
	Rectangle() {}
	Rectangle(float l, float w, Point p) : Shape(p, l, w) {}


	// THIS is where we have to define those functions with =0 at the end 
	float area() { return length() * width(); }
	float perimeter() { return 2 * (length() + width()); }

	friend std::ostream& operator<<(std::ostream& os, Rectangle r) {
		os << "Rectangle:\n\tWidth: " << r.width() << "\n\tLength: "
			<< r.length() << "\n\tArea: " << r.area() << "\n\tPerimeter: "
			<< r.perimeter();
		return os;
	}
private:
	// Don't really need anything here
};