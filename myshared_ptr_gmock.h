#ifndef MYSHARED_PTR_GMOCK_H_
#define MYSHARED_PTR_GMOCK_H_

#include <iostream>
#include <gmock/gmock.h>
#include "myshared_ptr.h"

template <class T>
class Mock_myshared_ptr : public myshared_ptr<T> {
    public:
        Mock_myshared_ptr(T* ptr) : myshared_ptr<T>(ptr) {}

        MOCK_METHOD(T*, getPtr, (), (override));

        MOCK_METHOD(void, setPtr, (T* ptr), (override));

        MOCK_METHOD(int*, getCount, (), (override));

        MOCK_METHOD(void, setCount, (int* count), (override));

        MOCK_METHOD(int, useCount, (), (override));
};

#endif