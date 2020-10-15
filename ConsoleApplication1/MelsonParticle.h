#pragma once
#include "ParticleFilter.h"
#include "Shape2.h"
#include "Shape3.h"
#include "Camera.h"
class MelsonParticle :
    public Particle
{
    static Shape3 enviornment;
    Camera camera;
public:
    MelsonParticle* copy();
    void update(UpdateAction* action);
    void updateProbability(Observation* observation);
};

