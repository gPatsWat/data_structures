#include <algorithm>
#include <variant>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {
   vector<int> v1 = {1,25,2 ,235};
   vector<int> v2 = {1,25,2241, 522 ,235};
   vector<int> v;
   set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));
   for(auto i : v) {
      cout << i << endl;
   }
}