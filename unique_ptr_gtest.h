#ifndef UNIQUE_PTR_GTEST_H_
#define UNIQUE_PTR_GTEST_H_

#include <memory>
#include <gtest/gtest.h>

template <class T>
class unique_ptr_gtest : public testing::Test {
    protected:
        void SetUp() override {
            unique_ptr1 = std::unique_ptr<T>(new T(1));
            unique_ptr2 = std::unique_ptr<T>(new T(2));
            unique_ptr3 = std::unique_ptr<T>(new T(3));
        }

        std::unique_ptr<T> unique_ptr1;
        std::unique_ptr<T> unique_ptr2;
        std::unique_ptr<T> unique_ptr3;
};

#endif

