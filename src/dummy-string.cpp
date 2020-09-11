#include "dummy/dummy.h"

#include <cstring>
#include <string>
#include <algorithm>

template<>
std::string dummy(int length) {
    static constexpr auto validCharacters =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    static const auto validCharacterCount = std::strlen(validCharacters);
    auto result = std::string(length, '\0');
    std::generate_n(begin(result), length, [&]() {
        return validCharacters[rand() % validCharacterCount];
    });
    return result;
}