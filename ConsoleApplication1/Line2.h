#pragma once
#include <Eigen/Dense>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace Eigen;
using namespace cv;
class Line2 {
public:
    Point a, b;
    Vector2f direction;
    float A, B, C;
    Scalar color;
    float length;
    bool visible;
    Vector2f getPerpendicular() {
        return Vector2f(-direction[1], direction[0]);
    }
    Line2(Point a, Point b, Scalar color = Scalar(255, 255, 255));
    Line2();
    float getPointDistance(Point p);
    void draw(Mat img);
    float matchTo(Line2 line, int imSize = 1500);
    /*bool intersects(Line2 line, Point &point) {
        if ((direction - line.direction).norm() < 0.001) return false;
    }*/
    bool contains(Point p);
    bool intersection(Line2 line, Point* intersection);
    bool intersection2(Line2 line, Point* intersection);
};

