#pragma once

#ifndef DEQUE_LTD
#define DEQUE_LTD

#include "exception.h"
#include "vector.h"

namespace ltd {
    template <class T>
    class deque {
        vector<T> data;
        int first;
        int last;
    public:

        deque();
        deque(int);

        T& front();
        T& back();

        void push_front(T);
        void push_back(T);

        T pop_front();
        T pop_back();

        int size() const;
        
        bool empty();

        void clear();

        T& operator[](int);
        
        auto begin();
        auto end();

        operator int();
        operator bool();
    };

#ifdef _IOSTREAM_
    template <class T>
    std::ostream& operator<< (std::ostream& out, const deque<T>& dec) {
        out << '[';
        for (int i = 0; i < dec.size() - 1; ++i)
            out << dec[i] << ", ";
        out << dec[vec.size() - 1] << ']';
        return out;
    }
#endif



    template <class T>
    deque<T>::deque() : data(1), first(0), last(0) {}

    template <class T>
    deque<T>::deque(int start_len) : data(start_len), first(0), last(0) {}

    template <class T>
    int deque<T>::size() const {
        if (first - last > 0)
            return first - last;
        else
            return last - first;
    }
    
    template <class T>
    T& deque<T>::front() {
        if (first == last)
            throw out_of_range("deque front");
        return data[first];
    }
    
    template <class T>
    T& deque<T>::back() {
        if (first == last)
            throw out_of_range("deque front");
        return data[last];
    }

    template <class T>
    void deque<T>::push_front(T elem) {
        if (last == (first - 1) % data.size()) {
            vector<T> vec(data.capacity * 2);
            vec.pb(elem);
            for (int i = 0; i < size(); ++i:)
                vec.pb(this->[i]);
            data = vec;
            first = 0;
            last = vec.size();
        }
        else {
            first = (first - 1) % data.size();
            data[first] = newElem;
        }
    }

    template <class T>
    void deque<T>::push_back(T newElem) {
        if (first == (last +  1) % data.size()) {
            vector<T> vec(data.capacity * 2);
            for (int i = 0; i < size(); ++i:)
                vec.pb(this->[i]);
            vec.pb(elem);
            data = vec;
            first = 0;
            last = vec.size();
        }
        else {
            data[last] = newElem;
            last = (last + 1) % data.size();
        }
    }

    template <class T>
    T deque<T>::pop_front() {
        int now = first;
        first = (first + 1) % data.size();
        return data[now];
    }
    
    template <class T>
    T deque<T>::pop_back() {
        last = (last - 1) % data.size();
        return data[last];
    }

    template <class T>
    bool deque<T>::empty() {
        return first == last;
    }

    template <class T>
    void deque<T>::clear() {
        data = vector<T>(1);
        first = last = 0;
    }

    template <class T>
    T& deque<T>::operator[](int ind) {
        if (ind < 0 || ind >= size())
            out_of_range("deque index");
        return data[(first + ind) % data.size()];
    }

    template <class T>
    deque<T>::operator int() {
        return size();
    }
    
    template <class T>
    deque<T>::operator bool() {
        return !empty();
    }
}

#endif