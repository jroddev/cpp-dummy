#include "dummy/dummy.h"
#include "dummy-user-defined.h"

template<>
MyType dummy(){
    return {
            .name = dummy<std::string>(8),
            .age = dummy<int>(0, 100)
    };
}