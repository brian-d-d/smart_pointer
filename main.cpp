#include "myshared_ptr.h"

int main() {
  
    myshared_ptr<double> shared_ptr1(new double(2.5));
  
    std::cout << "Smart ptr1 ptr value: " << *(shared_ptr1.getPtr()) << std::endl;
    std::cout << "Smart ptr1 count value: " << *(shared_ptr1.getCount()) << std::endl << std::endl;

    myshared_ptr<double> shared_ptr2(shared_ptr1);
    myshared_ptr<double> shared_ptr3;

    std::cout << "Smart ptr2 ptr value: " << *(shared_ptr2.getPtr()) << std::endl;
    std::cout << "Smart ptr2 count value: " << *(shared_ptr2.getCount()) << std::endl << std::endl;

    shared_ptr3 = shared_ptr1;
    
    std::cout << "Smart ptr3 ptr value: " << *(shared_ptr3.getPtr()) << std::endl;
    std::cout << "Smart ptr3 count value: " << *(shared_ptr3.getCount()) << std::endl << std::endl;

    if (true) {
        myshared_ptr<double> shared_ptr4;
        shared_ptr4 = shared_ptr1;

        std::cout << "Smart ptr4 ptr value: " << *(shared_ptr4.getPtr()) << std::endl;
        std::cout << "Smart ptr4 count value: " << *(shared_ptr4.getCount()) << std::endl << std::endl;
    }
    
    std::cout << "Smart ptr3 ptr value: " << *(shared_ptr3.getPtr()) << std::endl;
    std::cout << "Smart ptr3 count value: " << *(shared_ptr3.getCount()) << std::endl << std::endl;

}