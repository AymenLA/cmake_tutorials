#include <iostream>
#include "Sum.hpp"
#include "Component.hpp"
#include "dconfiguration.h"

using namespace std;
int32_t main(int32_t argc, char* argv[]) {
    cout << "hello cmake tutorial" << endl;
#if (DEBUG == 1)
    cout << "tutorial name : " << PRODUCT_NAME << endl;
    cout << "tutorial version : " << VERSION_MAJOR << "." << VERSION_MINOR << endl;
    cout << "tutorial production date : " << PRODUCTION_YEAR << "-" << PRODUCTION_WEEK << endl;
    cout << "tutorial added definition through cmake = " << ADEF << endl;
#endif
    Sum(5,8);
    SomeComponentInit();
    return 0;
}