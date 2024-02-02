#include "mysmart_ptr.h"

template <typename T>
mysmart_ptr<T>::mysmart_ptr(T* ptr) : ptr_(ptr), count_(nullptr) {
    count_ = (int*) malloc(sizeof(int));
    *count_ = 1;
}

template <typename T>
mysmart_ptr<T>::mysmart_ptr(T* ptr, int* count) : ptr_(ptr), count_(count) {

}

template <typename T>
mysmart_ptr<T>::mysmart_ptr() : ptr_(nullptr), count_(nullptr) {
    ptr_ = (T*) malloc(sizeof(T));
    count_ = (int*) malloc(sizeof(int));
    *count_ = 1;
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

template class mysmart_ptr<int>;

