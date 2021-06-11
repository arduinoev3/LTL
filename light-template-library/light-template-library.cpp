#include <iostream>
#include "ltl/iostream.h"
#include "ltl/deque.h"

using namespace ltd;

int main()
{
    deque<int> d;
    cout << d;
    d.push_back(1);
    cout << d;
    d.push_front(0);
    d.push_front(0);
    d.push_front(0);
    d.push_front(0);
    d.push_front(0);
    cout << d;
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_front();
    cout << d;
}