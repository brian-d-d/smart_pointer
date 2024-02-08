#ifndef MYshared_ptr_H_
#define MYshared_ptr_H_

#include <iostream>

template <class T>
class myshared_ptr {

    public:
        //Passing something like new int() as the argument
        myshared_ptr(T *ptr);

        //Passing an existing smart pointer
        myshared_ptr(myshared_ptr<T>& shared_ptr);

        //Creates a new smart pointer with memory allocated
        myshared_ptr();

        virtual ~myshared_ptr();

        virtual void operator=(myshared_ptr<T>& their_shared_ptr);

        virtual T* getPtr();

        virtual void setPtr(T* ptr);

        virtual int* getCount();

        virtual void setCount(int* count);

        virtual int useCount();

    private:
        //Pointer which is shared between the shared pointers
        T* ptr_;
        
        //Count of how many references are currently in scope and being made to the underlying pointer
        int* count_;

};


#endif