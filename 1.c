#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

void printPoint(Point p){
    printf("(%lf, %lf)\n", p.x, p.y);
}

Point createPoint(double x, double y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b){
    double distance;
    distance = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
    return distance;
}

int main() {
//    Point p1;
//    Point p2;

//    p1.x = 2.0;
//    p1.y = 3.0;
//    p2.x = 4.0;
//    p2.y = 5.0;
//    p1 = createPoint(2.0, 3.0);
//    printPoint(p1);
//    p2 = createPoint(4.0, 5.0);
//    printPoint(p2);

    double distance = getDistance(createPoint(2.0, 3.0), createPoint(4.0, 5.0));
    printf("%lf", distance);
    return 0;
}
