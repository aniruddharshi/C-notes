
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
  private:
    vector<T> container;

  public:
    Stack() {}
    
    ~Stack() {}
    
    void Push(const T val) {
        container.push_back(val);
    }
    
    void Pop() {
        if(Empty()) {
            throw std::out_of_range("Peek on empty stack.");
        }
        container.pop_back();
    }
    
    bool Empty() const {
        return container.empty();
    }
    
    T& Peek() const {
        if(Empty()) {
            throw std::out_of_range("Peek on empty stack.");
        }
        return container.back();
    }
};
