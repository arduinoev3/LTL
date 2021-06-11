#pragma once

#ifndef IOSTREAM_LTD
#define IOSTREAM_LTD

#include "string.h"

namespace ltd {
    class ostream {
        void (*def)(char);
    public:
        ostream(void (*_def)(char)) {
            def = _def;
        }

        template<class T>
        ostream& operator<<(T x) {
            string s = to_string(x);
            for (int i = 0; i < (int)s.size(); ++i)
                def(s[i]);
            return *this;
        }
    };
    ostream mout;
}
#endif