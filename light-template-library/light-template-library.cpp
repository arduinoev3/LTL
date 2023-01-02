#include <iostream>
#include "ltl/iostream.h"


using namespace ltd;

int main()
{
    vector <int> v;
    cout << v;
    v.pb(1);
    cout << v << '\n';
    v.pb(2);
    cout << v << '\n';
    v.pb(3);
    cout << v << '\n';
    v.erase(v.begin());
    cout << v << '\n';
    v.erase(v.begin() + 1);
    cout << v << '\n';
}