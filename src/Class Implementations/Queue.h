
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Queue {
  private:
    vector<T> container;
    
  public:
    Queue() {}
    ~Queue() {}
    
    void Push(const T val) {
        container.push_back(val);
    }
    
    void Pop() {
        if(Empty()) {
            throw std::out_of_range("Pop on empty queue.");
        }
        container.erase(container.begin());
    }
    
    bool Empty() const {
        return container.empty();
    }
    
    T& Front() const {
        if(Empty()) {
            throw std::out_of_range("Pop on empty queue.");
        }
        return container.front();
    }
    
    T& Back() const {
        if(Empty()) {
            throw std::out_of_range("Pop on empty queue.");
        }
        return container.back();
    }
};
