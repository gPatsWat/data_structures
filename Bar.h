#ifndef foo
#define foo

#include <iostream>

using namespace std;

// #include "Foo.h"
class Foo;

class Bar {
    public:
    Bar() {}
    ~Bar() {
        cout << "bar destructor" << endl;
    }
};

#endif