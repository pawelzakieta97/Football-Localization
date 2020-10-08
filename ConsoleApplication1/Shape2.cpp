#include "Shape2.h"
Shape2::Shape2() {
    pose = Matrix3f::Zero();
}
void Shape2::addline(Line2 line) {
    lines.push_back(line);
}
void Shape2::draw(Mat img) {
    for (auto line : lines) {
        line.draw(img);
    }
}
float Shape2::matchTo(Shape2 shape, bool matchColor) {
    float totalDifference = 0;
    for (Line2 lineObserved : lines) {
        float minDiff = 9999999;
        Line2* closest = &shape.lines[0];
        for (Line2 lineMatchTo : shape.lines) {
            float difference = lineObserved.matchTo(lineMatchTo);
            if (difference < minDiff) {
                minDiff = difference;
                closest = &lineMatchTo;
            }
        }
        totalDifference += minDiff;
        if (matchColor) {
            closest->color = lineObserved.color;
        }
    }
    return totalDifference;
}
void Shape2::clip(int width, int heigth) {
    // CLips all the lines so that they fit in the frame
    Line2 borders[4];
    borders[0] = Line2(Point(-width / 2, -heigth / 2), Point(-width / 2, heigth / 2));
    borders[1] = Line2(Point(-width / 2, heigth / 2), Point(width / 2, heigth / 2));
    borders[2] = Line2(Point(width / 2, heigth / 2), Point(width / 2, -heigth / 2));
    borders[3] = Line2(Point(width / 2, -heigth / 2), Point(-width / 2, -heigth / 2));
    auto it = lines.begin();
    while (it != lines.end()) {// (auto &line : lines) {
        Point intersections[4];
        int ints = 0;
        auto& line = *it;
        for (Line2 border : borders) {
            if (line.intersection2(border, intersections + ints)) {
                ints++;
            }
        }
        if (ints == 2) {
            line.a.x = intersections[0].x;
            line.a.y = intersections[0].y;
            line.b.x = intersections[1].x;
            line.b.y = intersections[1].y;
        }
        if (ints == 1) {
            if (line.b.x > -width / 2 && line.b.x < width / 2 && line.b.y > -heigth / 2 && line.b.y < heigth / 2) {
                line.a.x = intersections[0].x;
                line.a.y = intersections[0].y;
            }
            else {
                line.b.x = intersections[0].x;
                line.b.y = intersections[0].y;
            }
        }

        if ((ints == 0)
            && (!(line.b.x > -width / 2 && line.b.x < width / 2 && line.b.y > -heigth / 2 && line.b.y < heigth / 2))) {
            it = lines.erase(it);
            //line.color = Scalar(50, 50, 50);
        }
        else it++;
    }
}