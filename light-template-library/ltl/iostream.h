#pragma once

#ifndef IOSTREAM_LTD
#define IOSTREAM_LTD

#include "ltl/String.h"

namespace ltd {
    class ostream {
    public:
        template<class T>
        ostream& operator<<(T x) {
            string s = to_string(x);
            for (int i = 0; i < (int)s.size(); ++i)
                write_one(s[i]);
            return *this;
        }
    };
    ostream out;
}

#endif