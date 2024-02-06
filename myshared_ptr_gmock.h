#ifndef MYshared_ptr_GMOCK_H_
#define MYshared_ptr_GMOCK_H_

#include <iostream>
#include <gmock/gmock.h>

template <class T>
class Mock_myshared_ptr : public myshared_ptr {

    public:
        MOCK_METHOD(T*, getPtr, (), (override));

        MOCK_METHOD(void, setPtr, (T* ptr), (override));

        MOCK_METHOD(int*, getCount, (), (override));

        MOCK_METHOD(void, setCount, (int* count), (override));

        MOCK_METHOD(void, useCount, (), (override));
};


#endif