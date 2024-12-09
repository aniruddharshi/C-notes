
#include <iostream>
using namespace std;

template <typename T>
class uniqueptr {
  private:
    T* res;
    
  public:
    // default and parameterised constructor
    uniqueptr(const T* arg = nullptr) : res(arg) { }
    
    // destructor
    ~uniqueptr() {
        if(res) {
            delete res;
            res = nullptr;
        }
    }
    
    // copy constructor
    uniqueptr(const uniqueptr& arg) = delete;
    
    // copy assignment operator
    uniqueptr& operator=(const uniqueptr& arg) = delete;
    
    // move constructor
    uniqueptr(uniqueptr&& arg) {
        res = arg.res;
        arg.res = nullptr;
    }
    
    // move assignment 
    uniqueptr& operator=(uniqueptr&& arg) {
        if(this != &arg) {
            res = arg.res;
            arg.res = nullptr;
        }
        return *this;
    }
    
    //operator->
    const T* operator->() const {
        return res;
    }
    
    // operator*
    const T& operator*() const {
        return (*res);
    }
    
    // reset 
    void Reset(const T* arg = nullptr) {
        delete res;
        res = arg;
    }
};
