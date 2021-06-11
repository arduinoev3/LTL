#pragma once

#ifndef STRING_LTD
#define STRING_LTD

#include "exception.h"
#include "vector.h"

namespace ltd {
    class string {
        vector<char> data;
    public:
        string();
        string(int);
        string(int, char);
        string(char*);
        string(const char*);

        void pb(char);
        void push_back(char);
        void pop_back();
        int size() const;
        bool empty();
        void clear();
        char& operator[](const int);
        const char& operator[](const int) const;
        void operator=(const string&);
        void operator=(char*&);
        void operator=(const char*&);

        operator int();
        operator bool();
        char* begin();
        char* end();
        void erase(char*);
    };

#ifdef _IOSTREAM_
    std::ostream& operator<< (std::ostream& out, const string& s) {
        for (int i = 0; i < s.size(); ++i)
            out << s[i];
        return out;
    }
#endif

#ifdef IOSTREAM_LTD
    ostream& operator<< (ostream& out, const string& s) {
        for (int i = 0; i < s.size(); ++i)
            out << s[i];
        return out;
    }
#endif

    string::string() : data() {
        data.pb('\0');
    }

    string::string(int need) : data(need) {
        data.pb('\0');
    }

    string::string(int need, char write) : data(need, write) {
        data.pb('\0');
    }

    string::string(char* chr) : data() {
        int i = 0;
        while (chr[i] != '\o') {
            push_back(chr[i]);
            ++i;
        }
    }

    string::string(const char* chr) : data() {
        int i = 0;
        while (chr[i] != '\o') {
            push_back(chr[i]);
            ++i;
        }
    }

    int string::size() const {
        return data.size() - 1;
    }

    void string::pb(char elem) {
        data[data.size() - 1] = elem;
        data.pb('\0');
    }

    void string::push_back(char elem) {
        data[data.size() - 1] = elem;
        data.pb('\0');
    }

    void string::pop_back() {
        data[data.size() - 1] = '\0';
        data.pop_back();
    }

    bool string::empty() {
        return data.empty();
    }

    void string::clear() {
        data.clear();
    }

    char& string::operator[](const int ind) {
        if (ind < 0 || data.size() <= ind)
            throw out_of_range("string range");
        return data[ind];
    }

    const char& string::operator[](const int ind) const {
        if (ind < 0 || data.size() <= ind)
            throw out_of_range("string range");
        return data[ind];
    }

    void string::operator=(const string& copy) {
        data = copy.data;
    }

    void string::operator=(char*& chr) {
        *this = string(chr);
    }

    void string::operator=(const char*& chr) {
        *this = string(chr);
    }

    string::operator int() {
        return size();
    }

    string::operator bool() {
        return !empty();
    }

    char* string::begin() {
        return data.begin();
    }

    char* string::end() {
        return data.end() - 1;
    }

    void string::erase(char* item) {
        data.erase(item);
    }

    string operator+(string a, string b) {
        string ans;
        a.pop_back();
        return a + b;
    }

    string operator+(string a, char b) {
        string ans = a;
        ans.pb(b);
        return ans;
    }

    string operator+(char a, string b) {
        string ans;
        ans.pb(a);
        for (char i : b)
            ans.pb(i);
        return ans;
    }

    string operator+(string a, char* b) {
        return a + string(b);
    }

    string operator+(char* a, string b) {
        return string(a) + b;
    }

    string operator+(string a, const char* b) {
        return a + string(b);
    }

    string operator+(const char* a, string b) {
        return string(a) + b;
    }

    string& operator+=(string& a, string b) {
        a = a + b;
        return a;
    }

    string& operator+=(string& a, char b) {
        a = a + b;
        return a;
    }

    string& operator+=(string& a, char* b) {
        a = a + b;
        return a;
    }

    string& operator+=(string& a, const char* b) {
        a = a + b;
        return a;
    }

    string operator*(string& a, int b) {
        string ans;
        for (int i = 0; i < b; ++i)
            for (char j : a)
                ans += j;
        return ans;
    }

    string operator*=(string& a, int b) {
        a = a * b;
        return a;
    }
}

    string to_string(const char* conv) {
        return string(conv);
    }
    string to_string(char* conv) {
        return string(conv);
    }
    string to_string(string conv) {
        return conv;
    }
    string to_string(char conv) {
        string ans = "";
        ans += conv;
        return ans;
    }
    string to_string(int conv) {
        string ans = "";
        if (conv == 0)
            ans = "0";
        else {
            if (conv < 0) {
                ans += '-';
                conv = -conv;
            }
            while (conv) {
                char toInsert = (conv % 10) + '0';
                ans.insert(0, 1, toInsert);
                conv /= 10;
            }
        }
        return ans;
    }
}

#endif