#include <iostream>

using namespace std;

class Point {
	int x, y;
	public:
		static int count;
		Point() {
			x = 0;
			y = 0;
			count++;
		}
		~Point() {
			count--;
		}
		Point(int x, int y) {
			this->x = x;
			this->y = y;
			count++;
		}
		void print() {
			cout << "(" << x << ", " << y << ")" << endl;
		}
};

int Point::count = 0;

int main(void) {
	Point p1 = Point(1, 2);
	Point p2 = Point(3, 4);
	p1.print();
	p2.print();
	cout << "Number of points: " << Point::count << endl;
	return 0;
}
