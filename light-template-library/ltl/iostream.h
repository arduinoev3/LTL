#pragma once

#ifndef IOSTREAM_LTD
#define IOSTREAM_LTD

#include "ltl/string.h"

namespace ltd {
    class ostream {
        void (*def)(char);
    public:
        ostream(void (*_def)(char)) {
            def = _def;
        }

        ostream& operator<<(const char* x) {
            string s = to_string(x);
            for (int i = 0; i < s.size(); ++i) {
                def(s[i]);
            }
            return *this;
        }

        ostream& operator<<(char* x) {
            string s = to_string(x);
            for (int i = 0; i < s.size(); ++i) {
                def(s[i]);
            }
            return *this;
        }

        ostream& operator<<(string x) {
            string s = to_string(x);
            for (int i = 0; i < s.size(); ++i) {
                def(s[i]);
            }
            return *this;
        }

        ostream& operator<<(char x) {
            string s = to_string(x);
            for (int i = 0; i < s.size(); ++i) {
                def(s[i]);
            }
            return *this;
        }

        ostream& operator<<(int x) {
            string s = to_string(x);
            for (int i = 0; i < s.size(); ++i) {
                def(s[i]);
            }
            return *this;
        }

        ostream& operator<<(bool x) {
            string s = to_string(x);
            for (int i = 0; i < s.size(); ++i) {
                def(s[i]);
            }
            return *this;
        }
    };

    ostream& operator<< (ostream& out, string& s) {
        for (int i = 0; i < s.size(); ++i)
            out << s[i];
        return out;
    }

    template <class T>
    ostream& operator<<(ostream& out, vector<T> vec) {
        out << '[';
        for (int i = 0; i < vec.size() - 1; ++i)
            out << vec[i] << ", ";
        if (vec.size() > 0)
            out << vec[vec.size() - 1];
        out << ']';
        return out;
    }

    template <class F, class S>
    struct pair {
        F first;
        S second;

        pair() {}

        pair(const F& _first, const S& _second) {
            first = _first;
            second = _second;
        }

        pair(const pair<F, S>& copy) {
            first = copy.first;
            second = copy.second;
        }

        void operator=(const pair<F, S> copy) {
            first = copy.first;
            second = copy.second;
        }
    };

    template <class F, class S>
    bool operator==(const pair<F, S> a, const pair<F, S> b) {
        return a.first == b.first && a.second == b.second;
    }

    template <class F, class S>
    bool operator!=(const pair<F, S> a, const pair<F, S> b) {
        return a.first != b.first || a.second != b.second;
    }

    template <class F, class S>
    pair<F, S> make_pair(const F& _first, const S& _second) {
        return pair<F, S>(_first, _second);
    }


#ifdef _IOSTREAM_
    void write_one(char c) {
        std::cout << c;
    }
    ostream cout(write_one);
#endif // _IOSTREAM_
}
#endif