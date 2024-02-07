#include "myshared_ptr.h"
#include "myshared_ptr_gmock.h"


using ::testing::AtLeast;

TEST(MySharedPtrTest, CanGetPtr) {
    Mock_myshared_ptr<int> shared_ptr1;
    Mock_myshared_ptr<int> shared_ptr2;
    // shared_ptr2 = shared_ptr1;

    EXPECT_CALL(shared_ptr1, getPtr()).Times(AtLeast(1));

}

int main(int argc, char** argv) {

    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
  
    // myshared_ptr<double> shared_ptr1(new double(2.5));
  
    // std::cout << "Smart ptr1 ptr value: " << *(shared_ptr1.getPtr()) << std::endl;
    // std::cout << "Smart ptr1 count value: " << *(shared_ptr1.getCount()) << std::endl << std::endl;

    // myshared_ptr<double> shared_ptr2(shared_ptr1);
    // myshared_ptr<double> shared_ptr3;

    // std::cout << "Smart ptr2 ptr value: " << *(shared_ptr2.getPtr()) << std::endl;
    // std::cout << "Smart ptr2 count value: " << *(shared_ptr2.getCount()) << std::endl << std::endl;

    // shared_ptr3 = shared_ptr1;
    
    // std::cout << "Smart ptr3 ptr value: " << *(shared_ptr3.getPtr()) << std::endl;
    // std::cout << "Smart ptr3 count value: " << *(shared_ptr3.getCount()) << std::endl << std::endl;

    // if (true) {
    //     myshared_ptr<double> shared_ptr4;
    //     shared_ptr4 = shared_ptr1;

    //     std::cout << "Smart ptr4 ptr value: " << *(shared_ptr4.getPtr()) << std::endl;
    //     std::cout << "Smart ptr4 count value: " << *(shared_ptr4.getCount()) << std::endl << std::endl;
    // }
    
    // std::cout << "Smart ptr3 ptr value: " << *(shared_ptr3.getPtr()) << std::endl;
    // std::cout << "Smart ptr3 count value: " << *(shared_ptr3.getCount()) << std::endl << std::endl;

}