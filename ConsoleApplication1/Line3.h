#pragma once
#include <Eigen/Dense>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace Eigen;
class Line3 {
public:
    Vector4f a, b;
    Scalar color;
    Line3();
    Line3(Vector4f a, Vector4f b, Scalar color = Scalar(255, 255, 255));
};

