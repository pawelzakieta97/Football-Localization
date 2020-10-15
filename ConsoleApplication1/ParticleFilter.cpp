#include "ParticleFilter.h"

ParticleFilter::ParticleFilter(Particle* p)
{
	for (int i = 0; i < PARTICLE_COUNT; i++) {
		particles[i] = p->copy();
	}
}

Particle* ParticleFilter::getPose()
{
	float max_probability = 0;
	Particle* best = particles[0];
	for (Particle* p : particles) {
		if (p->getProbability() > max_probability) {
			best = p;
			max_probability = p->getProbability();
		}
	}
	return best;
}

void ParticleFilter::update(UpdateAction action, Observation observation)
{
	for (Particle* p : particles) {
		p->update(action);
		p->updateProbability(observation);
	}
}

float Particle::getProbability()
{
	return probability;
}
