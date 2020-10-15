#include "MelsonParticle.h"

MelsonParticle* MelsonParticle::copy()
{
    MelsonParticle* copy = new MelsonParticle;
    copy->camera = Camera(camera);
}
