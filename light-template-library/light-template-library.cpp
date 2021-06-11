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
        vector <int> v(5, 7);
        v *= 2;
        out << v;
    }
    catch (exception& exc) {
        out << exc.what();
    }
}