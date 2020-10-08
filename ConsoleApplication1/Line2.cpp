#include "Line2.h"
#include <math.h>
Line2::Line2(Point a, Point b, Scalar color) {
    this->a = a;
    this->b = b;
    this->color = color;
    this->direction = Vector2f(b.x - a.x, b.y - a.y);
    this->length = direction.norm();
    this->direction /= length;
    float ax = a.x, ay = a.y, bx = b.x, by = b.y;
    float denominator = ax - ay - bx + by + ay * bx - ax * by;
    A = -(ay - by) / denominator;
    B = (ax - bx) / denominator;
    C = (ay * bx - ax * by) / denominator;
    visible = true;
}
Line2::Line2() {
    a = Point(0, 0);
    b = Point(0, 0);
    visible = false;
}
float Line2::getPointDistance(Point p) {
    Vector2f pointVec(p.x, p.y);
    Vector2f perpendicular = getPerpendicular();
    Vector2f aVec(a.x, a.y);
    Vector2f bVec(b.x, b.y);
    float distance = abs((perpendicular.transpose() * pointVec)[0] - (perpendicular.transpose() * aVec)[0]);
    distance = min(min(distance, (pointVec - aVec).norm()), (pointVec - bVec).norm());
    return distance;
}
void Line2::draw(Mat img) {
    if (a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0) return;
    Point center(img.cols / 2, img.rows / 2);
    line(img, a + center, b + center, color, 10);
}
float Line2::matchTo(Line2 line, int imSize) {
    if (color != line.color) {
        return 999999;
    }
    float angleDifference = 1 - (direction.transpose() * line.direction)[0];
    float distance1 = line.getPointDistance(a);
    float distance2 = line.getPointDistance(b);
    float distanceError = distance1 / imSize + distance2 / imSize;
    return angleDifference + distanceError;
}
bool Line2::contains(Point p) {
    float threshold = 1;
    if (abs(A * p.x + B * p.y + C) > threshold) return false;
    float diff_xa = a.x - p.x;
    float diff_ya = a.y - p.y;
    float diff_xb = b.x - p.x;
    float diff_yb = b.y - p.y;
    if (diff_xa * diff_xa + diff_ya * diff_ya > length * length) return false;
    if (diff_xb * diff_xb + diff_yb * diff_yb > length * length) return false;
    return true;
}
bool Line2::intersection(Line2 line, Point* intersection) {
    float denominator = ((a.x - b.x) * (line.a.y - line.b.y) - (a.y - b.y) * (line.a.x - line.b.x));
    float threshold = 0.0000001;
    if (abs(denominator) < threshold) {
        return false;
    }
    float t = ((a.x - line.a.x) * (line.a.y - line.b.y) - (a.y - line.a.y) * (line.a.x - line.b.x)) / denominator;
    if (t < 0 || t>1) {
        //return false;
    }
    intersection->x = a.x + t * (b.x - a.x);
    intersection->y = a.y + t * (b.y - a.y);
    float diff_x = intersection->x - line.a.x;
    float diff_y = intersection->y - line.a.y;
    float distance_a = sqrt(diff_x * diff_x + diff_y * diff_y);
    diff_x = intersection->x - line.b.x;
    diff_y = intersection->y - line.b.y;
    float distance_b = sqrt(diff_x * diff_x + diff_y * diff_y);
    if (distance_a > line.length || distance_b > line.length) {
        return false;
    }
    return true;
}
bool Line2::intersection2(Line2 line, Point* intersection) {
    if (abs(A * line.B - line.A * B) < 0.00000001) {
        return false;
    }
    float x = (B * line.C - line.B * C) / (A * line.B - line.A * B);
    float y = (line.A * C - A * line.C) / (A * line.B - line.A * B);
    intersection->x = x;
    intersection->y = y;
    if (line.contains(*intersection) && contains(*intersection)) return true;
    return false;
}