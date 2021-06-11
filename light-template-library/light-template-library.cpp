#include <iostream>
#include "ltl/iostream.h"
#include "ltl/deque.h"
#include "ltl/vector.h"
#include "ltl/string.h"


using namespace ltd;

/*class ede {
public:
    ede() {}
};
ostream& operator<<(ostream& out, ede& ed) {
    out << "rus good";
    return out;
}*/

int main()
{
    deque<int> d;
    cout << d;
    d.push_back(1);
    d.push_back(2);
    d.pop_back();
    d.push_back(3);
    cout << d;
}