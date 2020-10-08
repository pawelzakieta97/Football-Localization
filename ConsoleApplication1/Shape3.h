#pragma once
#include <Eigen/Dense>
#include "Line3.h"
using namespace std;
using namespace Eigen;
class Shape3 {
public:
    std::vector<Line3> lines;
    Matrix4f pose;
    Shape3();
    void addline(Line3 line);
};

