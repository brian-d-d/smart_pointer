#include "myshared_ptr.h"

template <typename T>
myshared_ptr<T>::myshared_ptr(T* ptr) : ptr_(), count_(new int(1)) {
    ptr_ = ptr;
}

template <typename T>
myshared_ptr<T>::myshared_ptr(myshared_ptr<T>& shared_ptr) {
    ptr_ = shared_ptr.getPtr();
    count_ = shared_ptr.getCount();
    (*count_)++;
}

template <typename T>
myshared_ptr<T>::myshared_ptr() : ptr_(new T()), count_(new int(1)) {

}

template <typename T>
myshared_ptr<T>::~myshared_ptr() {
    std::cout << "Got destructor with count: " << (*count_) << std::endl;
    (*count_)--;
    if ((*count_) == 0) {
        std::cout << "Deleted" << std::endl;
        delete ptr_;
        delete count_;
    }
}

template <typename T>
T* myshared_ptr<T>::getPtr() {
    return ptr_;
}

template <typename T>
void myshared_ptr<T>::setPtr(T* ptr) {
    ptr_ = ptr;
}

template <typename T>
int* myshared_ptr<T>::getCount() {
    return count_;
}

template <typename T>
void myshared_ptr<T>::setCount(int* count) {
    count_ = count;
}

template <typename T>
void myshared_ptr<T>::useCount() {
    std::cout << *count_ << std::endl;
}

template <typename T>
void myshared_ptr<T>::operator=(myshared_ptr<T>& rhs) {
    ptr_ = rhs.getPtr();
    count_ = rhs.getCount();
    (*count_)++;
}

template class myshared_ptr<double>;
template class myshared_ptr<char>;
template class myshared_ptr<int>;