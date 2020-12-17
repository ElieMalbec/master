
#ifndef POINT_HPP
#define POINT_HPP
class Point {
    private :
    int x;
    int y;

    public:
    Point (int x, int y);

    int getX();
    int getY();

    int setX(int value);
    int setY(int value);

    void print();
};
double distance( Point &a,  Point &b);
#endif