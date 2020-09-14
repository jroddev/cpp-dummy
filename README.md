## Dummy Library C++

This is a small library to generate random instances for use in unit tests.
Extra types can be added by specialising `T dummy()` template (see user defined types).

#### Basic Types
```c++
auto randomInt = dummy<int>();
auto randomFloat = dummy<float>();
// random string with length of 10
auto randomString = dummy<std::string>(10);
```

#### User Defined Types
```c++
struct MyType {
    std::string name;
    int age;
};

template<>
MyType dummy(){
    return {
            .name = dummy<std::string>(8),
            .age = dummy<int>(0, 100)
    };
}

auto randomMyType = dummy<MyType>();
```

### Vector of
```c++
// vector of 10 random ints
dummyVector<int>(10, dummy<int>);

// lambda passed in to generate the ints
dummyVector<int>(10, [](){
    return dummy<int>(50, 200);
});

// vector of user defined types
dummyVector<MyType>(15, dummy<MyType>);
```