#pragma once

#ifndef VECTOR_LTD
#define VECTOR_LTD

#include "ltl/Exception.h"

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
        vector(const vector& copy);
        ~vector();

        void pb(T);
        void push_back(T);
        void pop_back();
        int size() const;
        bool empty();
        void clear();
        T& operator[](const int);
        const T& operator[](const int) const;
        void operator=(const vector&); // полное поэлементное копирование

        operator int();
        operator bool();
        T* begin();
        T* end();
        void erase(T*);
    };


#ifdef _IOSTREAM_
    template <class T>
    std::ostream& operator<< (std::ostream& out, const vector<T>& vec) {
        out << '[';
        for (int i = 0; i < vec.size() - 1; ++i)
            out << vec[i] << ", ";
        out << vec[vec.size() - 1] << ']';
        return out;
    }
#endif

#ifdef IOSTREAM_LTD
    template <class T>
    ostream& operator<< (ostream& out, const vector<T>& vec) {
        out << '[';
        for (int i = 0; i < vec.size() - 1; ++i)
            out << vec[i] << ", ";
        out << vec[vec.size() - 1] << ']';
        return out;
    }
#endif

    

    template <class T>
    vector<T>::vector() : ptr(NULL), now(0), capacity(0) {};

    template <class T>
    vector<T>::vector(int need) : ptr(new T[need]), now(need), capacity(need) {}

    template <class T>
    vector<T>::vector(int need, T write) : ptr(new T[need]), now(need), capacity(need) {
        for (int i = 0; i < now; ++i)
            ptr[i] = write;
    }

    template <class T>
    vector<T>::vector(const vector& copy) : ptr(new T[copy.now]), now(copy.now), capacity(copy.now) {
        for (int i = 0; i < now; ++i)
            ptr[i] = copy[i];
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
    void vector<T>::pb(T elem) {
        if (now >= capacity) {
            if (capacity == 0)
                capacity = 1;
            capacity = capacity * 2;
            T* new_ptr = new T[capacity];
            for (int i = 0; i < now; ++i)
                new_ptr[i] = ptr[i];
            delete[] ptr;
            ptr = new_ptr;
        }
        ptr[now] = elem;
        now++;
    }

    template <class T>
    void vector<T>::push_back(T elem) {
        (*this).pb(elem);
    }

    template <class T>
    void vector<T>::pop_back() {
        --size;
    }

    template <class T>
    bool vector<T>::empty() {
        return now == 0;
    }

    template <class T>
    void vector<T>::clear() {
        delete[] ptr;
        ptr = NULL;
        now = 0;
        capacity = 0;
    }

    template <class T>
    T& vector<T>::operator[](const int ind) {
        if (ind < 0 || now <= ind)
            throw out_of_range("vector range");
        return ptr[ind];
    }

    template <class T>
    const T& vector<T>::operator[](const int ind) const {
        if (ind < 0 || now <= ind)
            throw out_of_range("vector range");
        return ptr[ind];
    }

    template <class T>
    void vector<T>::operator=(const vector& copy) {
        delete[] ptr;
        ptr = new T[copy.now];
        now = copy.now;
        capacity = copy.now;
        for (int i = 0; i < now; ++i)
            ptr[i] = copy[i];
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
    T* vector<T>::begin() {
        return ptr;
    }

    template <class T>
    T* vector<T>::end() {
        return ptr + now;
    }

    template <class T>
    void vector<T>::erase(T* item) {
        if (item == end())
            return;
        item++;
        while (item != end()) {
            *(item - 1) = *item;
            item++;
        }
        now--;
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
}

#endif