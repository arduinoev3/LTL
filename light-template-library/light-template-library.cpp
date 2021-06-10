#include <iostream>
void write_one(char c) {
    std::cout << c;
}
#include "ltl/iostream.h"
#include "ltl/vector.h"
#include "ltl/string.h"
#include "ltl/deque.h"

using namespace ltd;

int main()
{
    try {
        vector <int> v(5, 7), f(3, 6);
        v = 5 + v;
        out << v + f + 8;
    }
    catch (exception& exc) {
        out << exc.what();
    }
}