#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <time.h>

static inline void InitRandomSeed(void) { srand(time(NULL)); } // No need for inline. just for the sake of simplicity 
static inline float RandomFloat(float min, float max) { return (max - min) * ((float)rand() / RAND_MAX) + min; }

#endif