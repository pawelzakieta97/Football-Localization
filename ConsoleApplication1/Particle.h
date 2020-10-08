#pragma once
#include "Camera.h"
#include "Shape2.h"
#include "Shape3.h"

class Particle {
    Camera camera;
    Shape2 view;
    Shape3 enviornment;
    float getProbability(Shape2 observaiton);
};

