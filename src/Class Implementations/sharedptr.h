
#include <iostream>

using namespace std;

template <typename T>
class sharedptr {
  private:
    T* res;
    int* counter;
    
    void increamentCounter() {
       if(counter) {
           (*counter)++;
       } 
    }
    
    void decreamentCounter() {
        if(counter) {
            (*counter)--;
            if((*counter) == 0) {
                if(res) {
                    delete res;
                    res = nullptr;
                    delete counter;
                    counter = nullptr;
                }
            }
        }
    }
    
  public:
    // default and parameterised constructor
    sharedptr(const T* ptr = nullptr) : res(arg), counter(new int(1)) {    }
    
    // destructor
    ~sharedptr() {
        decreamentCounter();
    }
    
    // copy constructor
    sharedptr(const sharedptr& ptr) {
        res = ptr.res;
        counter = ptr.counter;
        increamentCounter();
    }
    
    // move constructor
    sharedptr(sharedptr&& ptr) {
        res = ptr.res;
        counter = ptr.counter;
        
        ptr.res = nullptr;
        ptr.counter = nullptr;
    }
    
    // copy assignment 
    sharedptr& operator=(const sharedptr& ptr) {
        if(this != &res) {
            decreamentCounter();
            res = ptr.res;
            counter = ptr.counter;
            increamentCounter();
        }
        return *this;
    }
    
    // move assignment
    sharedptr& operator=(sharedptr&& ptr) {
        if(this != &ptr) {
            decreamentCounter();
            res = ptr.res;
            counter = ptr.counter;
            
            ptr.res = nullptr;
            ptr.counter = nullptr;
        }
        return *this;
    }
    
    // operator -> 
    T* operator->() const {
        return res;
    }
    
    // operator * 
    T& operator*() const {
        return (*res);
    }
    
    // get_count
    int get_count() const {
        if(!counter) {
            throw std::runtime_error("get count on null pointer.");
        }
        return (*counter);
    }
    
    // reset
    void reset (const T* ptr = nullptr) {
        decreamentCounter();
        res = ptr;
        counter = ptr ? new int(1) : nullptr;
    }
    
};
