#include <iostream>
#include "Sum.hpp"

using namespace std;

int32_t Sum(int32_t x, int32_t y) {
    cout << "Sum of " << x << " + " << y << " = " << (x+y) << endl;    
    return (x+y);
}