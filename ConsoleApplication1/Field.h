#pragma once
#include<opencv2/opencv.hpp>
#include <Eigen/Dense>
#include "Shape3.h"
#include "Line3.h"
using namespace Eigen;
using namespace std;
using namespace cv;
class Field :public Shape3 {
public:
    float length;
    float widht;
    float goalWidth;
    float goalHeight;
    Vector4f lMid;
    Vector4f rMid;
    Vector4f lTop;
    Vector4f rTop;
    Vector4f lBottom;
    Vector4f rBottom;
    Vector4f lGoalTopLow;
    Vector4f rGoalTopLow;
    Vector4f lGoalBottomLow;
    Vector4f rGoalBottomLow;
    Vector4f lGoalTopHi;
    Vector4f rGoalTopHi;
    Vector4f lGoalBottomHi;
    Vector4f rGoalBottomHi;
    Scalar goalColor, lineColor;
    Field(float length, float width = 60, float goalWidth = 20, float goalHeight = 10, Scalar lineColor = Scalar(255, 255, 255), Scalar goalColor = Scalar(0, 255, 255));
};
