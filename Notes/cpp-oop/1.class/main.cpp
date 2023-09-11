#include <iostream>

class Point {
		int x, y;
	public:
		void set_values(int, int);
		int distance_to_origin(void);
		int get_x(void) {return x;}
		int get_y(void) {return y;}
} point;

void Point::set_values(int a, int b) {
	x = a;
	y = b;
}

int Point::distance_to_origin(void) {
	return x*x + y*y;
}

int main(void) {
	Point new_point;
	new_point.set_values(3, 4);
	std::cout << "x: " << new_point.get_x() << " " << "y: " << new_point.get_y() << std::endl;
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
