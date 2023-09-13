#include <iostream>

class Point {
		int *x, *y;
	public:
		Point ();
		Point (int, int);
		~Point ();
		int distance_to_origin(void);
		int get_x(void) {return *x;}
		int get_y(void) {return *y;}
};

Point::Point () {
	x = new int;
	y = new int;
	*x = 0;
	*y = 0;
}

Point::Point(int a, int b) {
	x = new int;
	y = new int;
	*x = a;
	*y = b;
}

Point::~Point() {
	delete x;
	delete y;
}

int Point::distance_to_origin(void) {
	return (*x)*(*x) + (*y)*(*y);
}

int main(void) {
	Point *p = new Point(3, 4);
	std::cout << p->get_x() << std::endl;
	std::cout << p->get_y() << std::endl;
	return 0;
}
