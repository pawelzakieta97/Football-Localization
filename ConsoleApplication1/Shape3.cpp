#include "Shape3.h"
Shape3::Shape3() {
    pose = Matrix4f::Zero();
}
void Shape3::addline(Line3 line) {
    lines.push_back(line);
}