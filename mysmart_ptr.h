#ifndef MYSMART_PTR_H_
#define MYSMART_PTR_H_

#include <iostream>

template <class T>
class mysmart_ptr {

    public:
        mysmart_ptr(T *ptr);

        mysmart_ptr(mysmart_ptr<T>& smart_ptr);
    
        mysmart_ptr();

        ~mysmart_ptr();

        void operator=(mysmart_ptr<T>& their_smart_ptr);

        T* getPtr();

        void setPtr(T* ptr);

        int* getCount();

        void setCount(int* count);

        void useCount();

    private:
        //Pointer to the underlying object that is being shared
        T* ptr_;
        //Count of how many references are currently being made to the underlying object
        int* count_;

};


#endif