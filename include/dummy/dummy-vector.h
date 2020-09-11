#include <vector>

template<typename T>
std::vector<T> dummyVector(int length, std::function<T()> generator) {
    auto result = std::vector<T>{};
    result.resize(length);
    std::generate_n(begin(result), length, generator);
    return result;
}