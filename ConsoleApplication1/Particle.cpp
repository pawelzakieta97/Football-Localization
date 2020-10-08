#include "Particle.h"
float Particle::getProbability(Shape2 observaiton) {
    view = camera.render(enviornment);
    return observaiton.matchTo(view);
}