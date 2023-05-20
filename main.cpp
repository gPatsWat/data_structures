#include <iostream>
#include <memory>
#include "Bar.h"
// #include "Foo.h"

using namespace std;

int main() {
     unique_ptr<int> np {new int{5}};
     unique_ptr<Bar> nb (new Bar);
}