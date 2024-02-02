#include "mysmart_ptr.h"

int main() {
  
    mysmart_ptr<double> smart_ptr1(new double(2.5));
  
    std::cout << "Smart ptr1 ptr value: " << *(smart_ptr1.getPtr()) << std::endl;
    std::cout << "Smart ptr1 count value: " << *(smart_ptr1.getCount()) << std::endl << std::endl;

    mysmart_ptr<double> smart_ptr2(smart_ptr1);
    mysmart_ptr<double> smart_ptr3;

    std::cout << "Smart ptr2 ptr value: " << *(smart_ptr2.getPtr()) << std::endl;
    std::cout << "Smart ptr2 count value: " << *(smart_ptr2.getCount()) << std::endl << std::endl;

    smart_ptr3 = smart_ptr1;
    
    std::cout << "Smart ptr3 ptr value: " << *(smart_ptr3.getPtr()) << std::endl;
    std::cout << "Smart ptr3 count value: " << *(smart_ptr3.getCount()) << std::endl << std::endl;

    if (true) {
        mysmart_ptr<double> smart_ptr4;
        smart_ptr4 = smart_ptr1;

        std::cout << "Smart ptr4 ptr value: " << *(smart_ptr4.getPtr()) << std::endl;
        std::cout << "Smart ptr4 count value: " << *(smart_ptr4.getCount()) << std::endl << std::endl;
    }
    
    std::cout << "Smart ptr3 ptr value: " << *(smart_ptr3.getPtr()) << std::endl;
    std::cout << "Smart ptr3 count value: " << *(smart_ptr3.getCount()) << std::endl << std::endl;

}