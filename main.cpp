#include "mysmart_ptr.h"

int main() {

    int num = 5;
    int* number = &num;

    std::cout << "Initial Number value: " << *number << std::endl;

    mysmart_ptr<int> smart_ptr1(number);
    mysmart_ptr<int> smart_ptr2;
    mysmart_ptr<int> smart_ptr3;

    smart_ptr2 = smart_ptr1;
    smart_ptr3 = smart_ptr1;
    
    std::cout << "Smart ptr1 ptr value: " << *(smart_ptr1.getPtr()) << std::endl;
    std::cout << "Smart ptr1 count value: " << *(smart_ptr1.getCount()) << std::endl;

    std::cout << "Smart ptr2 ptr value: " << *(smart_ptr2.getPtr()) << std::endl;
    std::cout << "Smart ptr2 count value: " << *(smart_ptr2.getCount()) << std::endl;

    std::cout << "Smart ptr3 ptr value: " << *(smart_ptr3.getPtr()) << std::endl;
    std::cout << "Smart ptr3 count value: " << *(smart_ptr3.getCount()) << std::endl;

}