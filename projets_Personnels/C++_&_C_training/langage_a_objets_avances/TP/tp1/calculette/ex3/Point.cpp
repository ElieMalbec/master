#include <iostream>
#include <cmath>
#include "Point.hpp"

/* class Point {
    private :
    int x;
    int y;

    public:
    Point (int x, int y){
        this->x = x;
        this->y = y;
    }

    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }

    int setX(int value){
        return this->x = value;
    }
    int setY(int value){
        return this->y = value;
    }

    void print(){
        std::cout << "x: " << this->x << " y: " << this->y << "\n";
    }
}; */

Point::Point (int x, int y){
        this->x = x;
        this->y = y;
}
int Point::getX(){
        return this->x;
}

int Point::getY(){
        return this->y;
}

int Point::setX(int value){
        return this->x = value;
}

int Point::setY(int value){
        return this->y = value;
}

void Point::print(){
        std::cout << "x: " << this->x << " y: " << this->y << "\n";
}

double distance( Point &a,  Point &b){
    return (sqrt(pow(b.getX() - a.getX(),2) + pow(b.getY() - a.getY(),2) ));
}