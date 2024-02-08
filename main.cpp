#include "myshared_ptr.h"
#include "myshared_ptr_gmock.h"
#include "unique_ptr_gtest.h"
#include <gtest/gtest.h>
#include <iostream>

using ::testing::AtLeast;
using ::testing::Return;

// TEST(MySharedPtrTest, CanGetCount) {
//     Mock_myshared_ptr<int> shared_ptr1(new int(3));
//     myshared_ptr<int> shared_ptr3(new int(3));

//     // EXPECT_CALL(shared_ptr1, getPtr()).Times(1);
//     // EXPECT_CALL(shared_ptr1, getCount()).Times(1);

//     // shared_ptr1.setPtr(new int(3));

//     std::cout << shared_ptr1.getPtr() << std::endl;
//     std::cout << shared_ptr3.getPtr() << std::endl;

// }

// TEST(UniquePtrTest, Test1) {
//     Mock_unique_ptr<int> unique_ptr1(new int(1));
//     std::unique_ptr<int> unique_ptr2(new int(1));

//     int* num = unique_ptr2.get();
//     std::cout << *num << std::endl;

// }

TEST_F(unique_ptr_gtest, ptr_value) {
    EXPECT_EQ(*(unique_ptr1.get()), 1);
    EXPECT_EQ(*(unique_ptr2.get()), 2);
    EXPECT_EQ(*(unique_ptr3.get()), 3);
}

//Checks if the unique pointer releases the ownership of the pointer
TEST_F(unique_ptr_gtest, release) {
    unique_ptr1.release();
    EXPECT_EQ(unique_ptr1.get(), nullptr);
}

//Checks if ownership of the pointer is transferred between unique pointers
TEST(unique_ptr_gtest_no_class, ownership1) {
    std::unique_ptr<int> unique_ptr1(new int (1));
    std::unique_ptr<int> unique_ptr2(std::move(unique_ptr1));

    EXPECT_EQ(unique_ptr1.get(), nullptr);
    EXPECT_EQ(*(unique_ptr2.get()), 1);
}

//Checks that the ownership of the num pointer is transferred to unique_ptr1 even after num goes out of scope
TEST(unique_ptr_gtest_no_class, ownership2) {
    std::unique_ptr<int> unique_ptr1;
    if (true) {
        int *num = new int(5);
        unique_ptr1 = std::unique_ptr<int>(std::move(num));
    }

    EXPECT_EQ(*(unique_ptr1.get()), 5);
}

//Checks that the weak pointer does not stop num from being deleted after shared_ptr1 goes out of scope
TEST(weak_ptr_gtest_no_class, ownership1) {
    std::weak_ptr<int> weak_ptr1;
    if (true) {
        int *num = new int(5);
        std::shared_ptr<int> shared_ptr1(std::move(num));
        weak_ptr1 = shared_ptr1;

        EXPECT_EQ(*((weak_ptr1.lock()).get()), 5);
    }

    EXPECT_EQ(weak_ptr1.expired(), true);
}








int main(int argc, char** argv) {
    // ::testing::InitGoogleMock(&argc, argv);
    // return RUN_ALL_TESTS();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}