#include "Line3.h"
Line3::Line3() {
    a = Vector4f::Zero();
    b = Vector4f::Zero();
    color = Scalar(255, 255, 255);
}
Line3::Line3(Vector4f a, Vector4f b, Scalar color) {
    this->a = a;
    this->b = b;
    this->color = color;
}