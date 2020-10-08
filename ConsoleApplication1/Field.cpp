#include "Field.h"
Field::Field(float length, float width, float goalWidth, float goalHeight, Scalar lineColor, Scalar goalColor) {
    this->length = length;
    this->widht = width;
    this->goalHeight = goalHeight;
    this->goalWidth = goalWidth;
    this->lineColor = lineColor;
    this->goalColor = goalColor;
    lMid = Vector4f(-width / 2, 0, 0, 1);
    rMid = Vector4f(width / 2, 0, 0, 1);
    lTop = Vector4f(-width / 2, length / 2, 0, 1);
    rTop = Vector4f(width / 2, length / 2, 0, 1);
    lBottom = Vector4f(-width / 2, -length / 2, 0, 1);
    rBottom = Vector4f(width / 2, -length / 2, 0, 1);
    lGoalTopLow = Vector4f(-goalWidth / 2, length / 2, 0, 1);
    rGoalTopLow = Vector4f(goalWidth / 2, length / 2, 0, 1);
    lGoalBottomLow = Vector4f(-goalWidth / 2, -length / 2, 0, 1);
    rGoalBottomLow = Vector4f(goalWidth / 2, -length / 2, 0, 1);
    lGoalTopHi = Vector4f(-goalWidth / 2, length / 2, goalHeight, 1);
    rGoalTopHi = Vector4f(goalWidth / 2, length / 2, goalHeight, 1);
    lGoalBottomHi = Vector4f(-goalWidth / 2, -length / 2, goalHeight, 1);
    rGoalBottomHi = Vector4f(goalWidth / 2, -length / 2, goalHeight, 1);

    addline(Line3(lMid, rMid, lineColor));
    addline(Line3(lBottom, lTop, lineColor));
    addline(Line3(rBottom, rTop, lineColor));
    addline(Line3(lTop, rTop, lineColor));
    addline(Line3(lBottom, rBottom, lineColor));

    addline(Line3(lGoalTopLow, lGoalTopHi, goalColor));
    addline(Line3(lGoalTopHi, rGoalTopHi, goalColor));
    addline(Line3(rGoalTopHi, rGoalTopLow, goalColor));

    addline(Line3(lGoalBottomLow, lGoalBottomHi, goalColor));
    addline(Line3(lGoalBottomHi, rGoalBottomHi, goalColor));
    addline(Line3(rGoalBottomHi, rGoalBottomLow, goalColor));
}