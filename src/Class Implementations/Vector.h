
#include <iostream>
using namespace std;

template <typename T>
class Vector {
 
private: 
    T* container;
    int size;
    int capacity;
    
public:
    // default constructor
    Vector<T>() {
        size = 0;
        capacity = 1;
        container = new T[capacity];
    }
    
    ~Vector<T>() {
        if(container) {
            delete[] container;
            container = nullptr;
            size = 0;
            capacity = 0;
        }
    }
    
    // copy constructor
    Vector<T>(const Vector<T>& obj) : size(obj.size), capacity(obj.capacity), container(new T[capacity]) {
        
        for(int i = 0; i < size; i++) {
            container[i] = obj.container[i];
        }
    }
    
    // vector with number of elements and value
    Vector<T>(const int elements, const int value) {
        size = elements;
        capacity = elements;
        container = new T[capacity];
        for(int i = 0; i < size; i++) {
            container[i] = value;
        }
    }
    
    // Initialiser std::list ;
    Vector<T>(std::initializer_list<T>& list) : size(list.size()), capacity(2 * list.size()), container(new T[capacity])) {
        for(auto i : list) {
            Pushback(i);
        }
    }
    
    // Copy assignment
    Vector<T> operator=(const Vector<T>& obj) {
        
        if(container && obj.size > capacity) {
            delete[] container;
            container = nullptr;
        }
        
        size = obj.size;
        capacity = obj.capacity;
        container = obj.container;
        
        return *this;
    }
    
    // Pushback
    void Pushback(T val) {
        
        if(size >= capacity) {
            Reserve(2 * size);
        }
        
        container[size++] = val;
    }
    
    // Popback 
    void Popback() {
        if(size == 0) {
            throw std::exception("Popback on empty vector.");
        }
        size--;
    }
    
    // Reserve
    void  Reserve(int newcap) {
        T* tarr = new T[newcap]; 
        for(int i = 0; i < size; i++) {
            tarr[i] = container[i];
        }
        
        delete[] container;
        container = nullptr;
        
        container = tarr;
        capacity = newcap;
    }
    
    
    // Empty
    bool Empty() const {
        return size == 0;
    }
    
    // size
    int Size() const {
        return size;
    }
    
    // capacity
    int Capacity() const {
        return capacity;
    }
    
    // Equality
    bool operator==(const Vector& obj) {
        if(Size() != obj.Size()) {
            return false;
        }
        
        for(int i = 0; i < Size(); i++) {
            if(container[i] != obj.container[i]) {
                return false;
            }
        }
        return true;
    }
    
    // [] operator
    T& operator[](const int idx) {
        return container[idx];
    }
    
    // Retrieve at
    T& At(const int idx) {
        if(idx < 0 || idx >= size) {
            throw std::out_of_range("Index out of range.");
        }
        return container[idx];
    }
    
    // Front 
    T& Front() {
        return container[0];
    }
    
    // Back
    T& Back() {
        if(size == 0) {
            throw exception("Accessing an empty array.");
        }
        return container[size - 1];
    }
    
    // Insert at :
    void InsertAt(const T& val, int idx) {
        if(idx < 0 || idx > size) {
            throw std::out_of_range("Index out of range.");
        }
        
        if(size >= capacity) {
            Reserve(2 * size);
        }
        
        for(int i = size - 1; i >= idx; i--) {
            container[i + 1] = container[i];
        }
        
        container[idx] = val;
        size++;
    }
    
    // Erase 
    void Erase(const idx) {
        if(idx < 0 || idx >= size) {
            throw std::out_of_range("Index out of range.");
        }
        
        for(int i = idx; i < size - 1; i++) {
            container[i] = container[i + 1];
        }
        size--;
    }
    
    // Clear
    void Clear() {
        size = 0;
    }
    
    // Friend functions
    friend ostream& operator<<(ostream& out, const Vector<T>& obj);
};

template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& obj) {
    for(int i = 0; i < obj.size; i++) {
        out << obj.container[i] << " ";
    }
    return out;
}
