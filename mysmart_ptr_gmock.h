#ifndef MYSMART_PTR_GMOCK_H_
#define MYSMART_PTR_GMOCK_H_

#include <iostream>
#include <gmock/gmock.h>

template <class T>
class Mock_mysmart_ptr : public mysmart_ptr {

    public:
        MOCK_METHOD(T*, getPtr, (), (override));

        MOCK_METHOD(void, setPtr, (T* ptr), (override));

        MOCK_METHOD(int*, getCount, (), (override));

        MOCK_METHOD(void, setCount, (int* count), (override));

        MOCK_METHOD(void, useCount, (), (override));
};


#endif