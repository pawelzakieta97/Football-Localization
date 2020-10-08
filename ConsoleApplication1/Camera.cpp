#include "Camera.h"
Camera::Camera() {
    pose = Matrix4f::Identity();
}
void Camera::translate(Vector3f translate) {
    pose.block<3, 1>(0, 3) += translate;
}
Line2 Camera::render(Vector4f a, Vector4f b) {

    Vector4f relativeA = pose.inverse() * a;
    Vector4f relativeB = pose.inverse() * b;
    if (relativeA[2] <= 0 && relativeB[2] <= 0) {
        return Line2();
    }
    if (relativeB[2] <= 0) {
        relativeB = relativeB + (relativeA - relativeB) * (-relativeB[2] / (relativeA[2] - relativeB[2]));
        relativeB += Vector4f(0, 0, 0.01, 0);
    }
    if (relativeA[2] <= 0) {
        relativeA = relativeA + (relativeB - relativeA) * (-relativeA[2] / (relativeB[2] - relativeA[2]));
        relativeA += Vector4f(0, 0, 0.01, 0);
    }
    if (relativeA[2] <= 0 || relativeB[2] <= 0) {
        cout << relativeA << endl << relativeB << endl;
    }
    Point lineA = Point(f * relativeA[0] / relativeA[2], f * relativeA[1] / relativeA[2]);
    Point lineB = Point(f * relativeB[0] / relativeB[2], f * relativeB[1] / relativeB[2]);
    return Line2(lineA, lineB);
}
Line2 Camera::render(Line3 line) {
    auto line2 = render(line.a, line.b);
    line2.color = line.color;
    return line2;
}
Shape2 Camera::render(Shape3 shape) {
    Shape2 shape2;
    for (Line3 line : shape.lines) {
        Line2 line2d = render(line);
        if (line2d.visible) shape2.addline(line2d);
    }
    return shape2;
}