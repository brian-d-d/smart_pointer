#include "myshared_ptr.h"
#include "myshared_ptr_gmock.h"
#include "unique_ptr_gtest.h"
#include <gtest/gtest.h>

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

TEST_F(unique_ptr_gtest<int>, ptr_value) {
    EXPECT_EQ(*(unique_ptr1.get()), 1);
}




int main(int argc, char** argv) {
    // ::testing::InitGoogleMock(&argc, argv);
    // return RUN_ALL_TESTS();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}