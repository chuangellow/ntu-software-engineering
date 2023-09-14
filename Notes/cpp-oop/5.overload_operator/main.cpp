#include <iostream>

class Point {
		int *x, *y;
	public:
		Point ();
		Point (int, int);
		Point operator+(Point);
		Point operator-(Point);
		Point& operator++(void);
		Point operator++(int);
		int distance_to_origin(void);
		int get_x(void) {return *x;}
		int get_y(void) {return *y;}
};

Point::Point () {
	x = new int;
	y = new int;
	*x = 1;
	*y = 2;
}

Point::Point(int a, int b) {
	x = new int;
	y = new int;
	*x = a;
	*y = b;
}

Point& Point::operator++(void) {
	*x = *x + 1;
	*y = *y + 1;
	return *this;
}

Point Point::operator++(int) {
	Point temp = *this;
	++*this;
	return temp;
}


Point Point::operator+(Point p) {
	Point new_point;
	*new_point.x = *x + *p.x;
	*new_point.y = *y + *p.y;
	return new_point;
}

Point Point::operator-(Point p) {
	Point new_point;
	*new_point.x = *x - *p.x;
	*new_point.y = *y - *p.y;
	return new_point;
}

int Point::distance_to_origin(void) {
	return (*x)*(*x) + (*y)*(*y);
}

int main(void) {
	Point p;
	Point new_point (7, 8);
	std::cout << p.get_x() << " " << p.get_y() << std::endl;
	std::cout << new_point.distance_to_origin() << std::endl;
	Point sum = p + new_point;
	std::cout << sum.get_x() << " " << sum.get_y() << std::endl;
	Point diff = p - new_point;
	std::cout << diff.get_x() << " " << diff.get_y() << std::endl;

	p++;
	std::cout << p.get_x() << " " << p.get_y() << std::endl;
	return 0;
}
