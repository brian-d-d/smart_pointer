#include "mysmart_ptr.h"

template <typename T>
mysmart_ptr<T>::mysmart_ptr(T* ptr) : ptr_(), count_(new int(1)) {
    ptr_ = ptr;
}

template <typename T>
mysmart_ptr<T>::mysmart_ptr(mysmart_ptr<T>& smart_ptr) {
    ptr_ = smart_ptr.getPtr();
    count_ = smart_ptr.getCount();
    (*count_)++;
}

template <typename T>
mysmart_ptr<T>::mysmart_ptr() : ptr_(new T()), count_(new int(1)) {

}

template <typename T>
mysmart_ptr<T>::~mysmart_ptr() {
    std::cout << "Got destructor with count: " << (*count_) << std::endl;
    (*count_)--;
    if ((*count_) == 0) {
        std::cout << "Deleted" << std::endl;
        delete ptr_;
        delete count_;
    }
}

template <typename T>
T* mysmart_ptr<T>::getPtr() {
    return ptr_;
}

template <typename T>
void mysmart_ptr<T>::setPtr(T* ptr) {
    ptr_ = ptr;
}

template <typename T>
int* mysmart_ptr<T>::getCount() {
    return count_;
}

template <typename T>
void mysmart_ptr<T>::setCount(int* count) {
    count_ = count;
}

template <typename T>
void mysmart_ptr<T>::useCount() {
    std::cout << *count_ << std::endl;
}

template <typename T>
void mysmart_ptr<T>::operator=(mysmart_ptr<T>& rhs) {
    ptr_ = rhs.getPtr();
    count_ = rhs.getCount();
    (*count_)++;
}

template class mysmart_ptr<double>;
template class mysmart_ptr<char>;
template class mysmart_ptr<int>;