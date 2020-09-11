#include "dummy/dummy.h"

#include <algorithm>
// Can replace these with concepts once supported
// concept integral = std::is_integral_v<T>;

template<>
int dummy() {
    return rand();
}

template<>
int dummy(int minValue, int maxValue) {
    return minValue + (dummy<int>() % (maxValue-minValue));
}

template<>
long dummy() {
    return rand();
}

template<>
long dummy(long minValue, long maxValue) {
    return minValue + (dummy<long>() % (maxValue-minValue));
}