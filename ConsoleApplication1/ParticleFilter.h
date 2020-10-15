#pragma once
//#include <Eigen/Dense>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

// PARTICLE FILTER PARAMETERS
#define PARTICLE_COUNT 1000
#define STEP_LEN 5
#define ROTATION M_PI * 15/180
#define STEP_SIGMA 0.5
#define ROTATION_SIGMA M_PI * 1.5/180

class Observation {};
class UpdateAction {};

class Particle abstract{

	float probability;
public:
	virtual Particle* copy() = 0;
    virtual void update(UpdateAction* action)=0;
	virtual void updateProbability(Observation* observation)=0;
    float getProbability();
};

class ParticleFilter
{
	std::vector<Particle*> particles;
public:
	ParticleFilter(Particle* p);
	void update(UpdateAction* action, Observation* observation);
	Particle* getPose();
};

