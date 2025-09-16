#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    x = X;
    y = Y;
    nearestPoint = closestPoint;
}
//Destructor
points::Point::~Point()
{

}

//Getters
int points::Point::getX()
{
    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    if(arrSize == 0){
        return nullptr;
    }

    Point* closest = nullptr;
    double minDist = INFINITY;

    for(unsigned long i = 0; i < arrAize; i++){
        Point* candidate = pointList[i];
        if(candidate == this){
            continue;
        }

        double dist = distPoints(*candidate);
        if(dist < minDist){
            minDist = dist;
            closest = candidate;
        }
    }

    setNearestPoint(closest);
    return closest;
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    return sqrt(pow(x - point.getX(), 2) + pow(y - point.getY(), 2));
}
