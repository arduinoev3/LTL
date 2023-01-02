#pragma once

#ifndef VECTOR_LTD
#define VECTOR_LTD

#include "ltl/exception.h"


namespace ltd {
    template <class T>
    class vector {
        T* ptr;
        int now;
        int capacity;
    public:

        vector();
        vector(int);
        vector(int, T);
        vector(const vector&);
        ~vector();

        void pb(const T&);
        void push_back(const T&);
        void pop_back();

        int size() const;
        int max_size();
        bool empty();
        void clear();

        T& operator[](int);
        const T& operator[](int) const;
        vector<T>& operator=(const vector&);

        operator int();
        operator bool();

        T* begin();
        T* end();

        void erase(T*);

        friend class string;
    };

    template <class T>
    vector<T>::vector() : ptr(new T[1]), now(0), capacity(1) {}

    template <class T>
    vector<T>::vector(int need) {
        if (need < 1)
            throw invalid_argument("vector init size");
        ptr = new T[need];
        now = need;
        capacity = need;
    }

    template <class T>
    vector<T>::vector(int need, T write) {
        if (need < 1)
            throw invalid_argument("vector init size");
        ptr = new T[need];
        now = need;
        capacity = need;
        register T* _ptr = ptr;
        T* end = ptr + now;
        for (register T* _ptr = ptr; _ptr != end; ++_ptr)
            *_ptr = write;
    }

    template <class T>
    vector<T>::vector(const vector& copy) {
        now = copy.now;
        ptr = new T[now];
        capacity = now;

        register T* to_ptr = ptr;
        register T* from_ptr = copy.ptr;
        T* end = from_ptr + now;

        while (from_ptr != end) {
            *to_ptr = *from_ptr;
            ++to_ptr;
            ++from_ptr;
        }
    }

    template <class T>
    vector<T>::~vector() {
        delete[] ptr;
    }

    template <class T>
    int vector<T>::size() const {
        return now;
    }

    template <class T>
    int vector<T>::max_size() {
        return capacity;
    }

    template <class T>
    void vector<T>::pb(const T& elem) {
        if (now == capacity) {
            capacity *= 2;

            T* new_ptr = new T[capacity];

            register T* _new_ptr = new_ptr;
            register T* c_ptr = ptr;
            T* end = ptr + now;
            while (c_ptr != end) {
                *_new_ptr = *c_ptr;
                ++c_ptr;
                ++_new_ptr;
            }

            delete[] ptr;
            ptr = new_ptr;
        }
        ptr[now++] = elem;
    }

    template <class T>
    inline void vector<T>::push_back(const T& elem) {
        (*this).pb(elem);
    }

    template <class T>
    void vector<T>::pop_back() {
        --now;
    }

    template <class T>
    bool vector<T>::empty() {
        return now == 0;
    }

    template <class T>
    void vector<T>::clear() {
        now = 0;
    }

    template <class T>
    T& vector<T>::operator[](int ind) {
        if (ind < 0 || ind >= now)
            throw out_of_range("vector range");
        return ptr[ind];
    }

    template <class T>
    const T& vector<T>::operator[](int ind) const {
        if (ind < 0 || now <= ind)
            throw out_of_range("vector range");
        return ptr[ind];
    }

    template <class T>
    vector<T>& vector<T>::operator=(const vector& copy) {
        now = copy.now;
        if (capacity < copy.now) {
            delete[] ptr;
            ptr = new T[copy.now];
            capacity = copy.now;
        }

        register T* to_ptr = ptr;
        register T* from_ptr = copy.ptr;
        T* end = from_ptr + copy.size();

        while (from_ptr != end) {
            *to_ptr = *from_ptr;
            ++to_ptr;
            ++from_ptr;
        }

        return *this;
    }

    template <class T>
    vector<T>::operator int() {
        return size();
    }

    template <class T>
    vector<T>::operator bool() {
        return !empty();
    }

    template <class T>
    inline T* vector<T>::begin() {
        return ptr;
    }

    template <class T>
    inline T* vector<T>::end() {
        return ptr + now;
    }

    template <class T>
    void vector<T>::erase(register T* item) {
        if (item < end()) {
            if (item < ptr)
                throw invalid_argument("vector erase");

            T* ending = end() - 1;
            while (item != ending) {
                *item = *(item + 1);
                ++item;
            }
            --now;
        }
    }

    template<class T>
    vector<T> operator+(vector<T> a, vector<T> b) {
        vector<T> ans;
        for (T i : a)
            ans.pb(i);
        for (T i : b)
            ans.pb(i);
        return ans;
    }

    template<class T>
    vector<T> operator+(vector<T> a, T b) {
        vector<T> ans = a;
        ans.pb(b);
        return ans;
    }

    template<class T>
    vector<T> operator+(T a, vector<T> b) {
        vector<T> ans;
        ans.pb(a);
        for (T i : b)
            ans.pb(i);
        return ans;
    }

    template<class T>
    vector<T>& operator+=(vector<T>& a, vector<T> b) {
        a = a + b;
        return a;
    }

    template<class T>
    vector<T>& operator+=(vector<T>& a, T b) {
        a = a + b;
        return a;
    }

    template<class T>
    vector<T> operator*(vector<T>& a, int b) {
        vector <T> ans;
        for (int i = 0; i < b; ++i)
            for (T j : a)
                ans += j;
        return ans;
    }

    template<class T>
    vector<T> operator*=(vector<T>& a, int b) {
        a = a * b;
        return a;
    }

#ifdef _IOSTREAM_
    template <class T>
    std::ostream& operator<< (std::ostream& out, const vector<T>& vec) {
        out << '[';
        for (int i = 0; i < vec.size() - 1; ++i)
            out << vec[i] << ", ";
        if (vec.size() > 0)
            out << vec[vec.size() - 1];
        out << ']';
        return out;
    }
#endif // _IOSTREAM_
}


#endif