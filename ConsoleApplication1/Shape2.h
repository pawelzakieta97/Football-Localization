#pragma once
#include<opencv2/opencv.hpp>
#include <Eigen/Dense>
#include "Line2.h"
#include "ParticleFilter.h"
using namespace Eigen;
using namespace std;
using namespace cv;
class Shape2: public Observation{
public:
    std::vector<Line2> lines;
    Matrix3f pose;
    Shape2();
    void addline(Line2 line);
    void draw(Mat img);
    float matchTo(Shape2 shape, bool matchColor = false);
    void clip(int width = 1500, int heigth = 1500);

};

