
#include <iostream>
#include <cstring>

using namespace std;

class String {

private:
    char *str;
    unsigned int len;

public:
    // default constructor
    String() : str(nullptr), len(0) {}
    
    // destructor 
    ~String() {
        if(str) {
            delete[] str;
            str = nullptr;
            len = 0;
        }
    }
    // parameterised constructor
    String(const char* arg) {
        len = strlen(arg);
        str = new char[len + 1];
        strcpy(str, arg);
    }
    
    // Copy constructor
    String(const String& arg) {
        len = arg.len;
        str = new char[len + 1];
        strcpy(str, arg.str);
    }
    
    // Move copy constructor
    String(String&& arg) {
        len = arg.len;
        str = arg.str;
        arg = nullptr;
        arg.len = 0;
    }
    
    // Copy assignment operator
    String& operator=(const String& arg) {
        if(this != &arg) {
            if(str) {
                delete str;
                str = nullptr;
            }
            len = arg.len;
            str = new char[len + 1];
            strcpy(str, arg.str);
        }
        return *this;
    }
    
    // move assignment operator
    String& operator=(String&& arg) {
        if(this != &arg) {
            if(str) {
                delete str;
            }
            len = arg.len;
            str = arg.str;
            arg = nullptr;
            arg.len = 0;
        }
        return *this;
    }
    
    unsigned int length() const {
        return len;
    }
    
    const char* getcstr() {
        return str ? str : "";
    }
    
    friend ostream& operator<<(ostream& out, const String& arg);
    friend istream& operator>>(istream& in, String& arg);

};

ostream& operator<<(ostream& out, const String& arg) {
    out << arg.str << endl;
    return out;
}

istream& operator>>(istream& in, String& arg) {
    delete[] arg.str;
    char buffer[256];
    in >> buffer;
    
    arg.len = strlen(buffer);
    arg.str = new char[arg.len + 1];
    strcpy(arg.str, buffer);
    return in;
}

