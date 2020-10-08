#pragma once
#include <Eigen/Dense>
#include "Line2.h"
#include "Line3.h"
#include "Shape2.h"
#include "Shape3.h"
#include<opencv2/opencv.hpp>
using namespace Eigen;
class Camera {
public:
    Matrix4f pose;
    float f = 500;

    Camera();
    void translate(Vector3f translate);

    Line2 render(Vector4f a, Vector4f b);
    Line2 render(Line3 line);
    Shape2 render(Shape3 shape);
};

