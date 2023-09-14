#include <iostream>

class Point {
        int x, y;
    public:
        Point (int, int);
        int distance_to_origin(void);
        int get_x(void) {return x;}
        int get_y(void) {return y;}
};

Point::Point(int a, int b) {
    x = a;
    y = b;
}

int Point::distance_to_origin(void) {
    return x*x + y*y;
}

int main(void) {
    Point new_point (3, 4);
    std::cout << new_point.distance_to_origin() << std::endl;
    return 0;
}
