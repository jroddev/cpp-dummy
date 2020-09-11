#include "dummy/dummy.h"

#include <algorithm>
// Can replace these with concepts once supported
// concept floating_point = std::is_floating_point_v<T>;

template<>
float dummy() {
    return ((float) rand()) / (float) RAND_MAX;
}

template<>
float dummy(float minValue, float maxValue) {
    float range = maxValue - minValue;
    return (dummy<float>() * range) + minValue;
}

template<>
double dummy() {
    return ((double) rand()) / (double) RAND_MAX;
}

template<>
double dummy(double minValue, double maxValue) {
    double range = maxValue - minValue;
    return (dummy<double>() * range) + minValue;
}
