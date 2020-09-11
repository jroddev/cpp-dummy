#ifndef CPP_DUMMY_DUMMY_H
#define CPP_DUMMY_DUMMY_H

template<typename T>
T dummy();

template<typename T, typename ARG>
T dummy(ARG);

template<typename T, typename ARG>
T dummy(ARG, ARG);


#endif //CPP_DUMMY_DUMMY_H
