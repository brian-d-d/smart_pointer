#ifndef MYSMART_PTR_H_
#define MYSMART_PTR_H_

#include <iostream>

template <class T>
class mysmart_ptr {

    public:
        //Passing something like new int() as the argument
        mysmart_ptr(T *ptr);

        //Passing an existing smart pointer
        mysmart_ptr(mysmart_ptr<T>& smart_ptr);

        //Creates a new smart pointer with memory allocated
        mysmart_ptr();

        virtual ~mysmart_ptr();

        virtual void operator=(mysmart_ptr<T>& their_smart_ptr);

        virtual T* getPtr();

        virtual void setPtr(T* ptr);

        virtual int* getCount();

        virtual void setCount(int* count);

        virtual void useCount();

    private:
        //Pointer which is shared between the shared pointers
        T* ptr_;
        
        //Count of how many references are currently in scope and being made to the underlying pointer
        int* count_;

};


#endif