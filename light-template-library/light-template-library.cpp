#include <iostream>
void write_one(char c) {
    std::cout << c;
}
#include "ltl/iostream.h"
#include "ltl/vector.h"

using namespace ltd;

int main()
{
    ostream mout(write_one);
    try {
        vector <int> v(5, 7);
        v *= 2;
        mout << v;
    }
    catch (exception& exc) {
        mout << exc.what();
    }
}