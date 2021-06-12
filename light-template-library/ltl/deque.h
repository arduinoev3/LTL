#pragma once

#ifndef DEQUE_LTD
#define DEQUE_LTD

#include "ltl/exception.h"

namespace ltd {
    template <class T>
    class deque {
        T* ptr;
        int first;
        int last;
        int capacity;
    public:

        deque();
        deque(int);
        deque(const deque& copy);
        ~deque();

        T& front();
        T& back();

        void push_front(const T&);
        void push_back(const T&);

        T& pop_front();
        T& pop_back();

        int size() const;
        
        bool empty();

        void clear();

        T& operator[](int);
        const T& operator[](int) const;
        void operator=(const deque&);

        operator int();
        operator bool();
    };

    template <class T>
    deque<T>::deque() {
        ptr = new T[2];
        capacity = 2;
        first = last = 0;
    }

    template <class T>
    deque<T>::deque(int need) {
        if (need < 2)
            throw invalid_argument("deque init need > 1");
        ptr = new T[need];
        capacity = need;
        first = last = 0;
    }

    template <class T>
    deque<T>::deque(const deque& copy) {
        delete[] ptr;
        ptr = new T[copy.capacity];
        capacity = copy.capacity;
        int i = 0;
        while (i < copy.size()) {
            ptr[i] = copy[i];
            ++i;
        }
        first = 0;
        last = i;
    }

    template <class T>
    deque<T>::~deque() {
        delete[] ptr;
    }

    template <class T>
    T& deque<T>::front() {
        if (first == last)
            throw out_of_range("deque front");
        return ptr[first];
    }
    
    template <class T>
    T& deque<T>::back() {
        if (first == last)
            throw out_of_range("deque last");
        return ptr[(last - 1) % capacity];
    }

    template <class T>
    void deque<T>::push_front(const T& elem) {
        if ((capacity + first - 1) % capacity == last) {
            T* newPtr = new T[capacity * 2];
            newPtr[0] = elem;
            int i = 0;
            while (i < size()) {
                newPtr[i + 1] = (*this)[i];
                ++i;
            }
            delete[] ptr;
            ptr = newPtr;
            capacity *= 2;
            first = 0;
            last = i + 1;
        }
        else {
            first = (capacity + first - 1) % capacity;
            ptr[first] = elem;
        }
    }

    template <class T>
    inline void deque<T>::push_back(const T& elem) {
        ptr[last] = elem;
        if (++last == capacity)
            last = 0;
        if (last == first) {
            T* newPtr = new T[capacity * 2];
            int i = 0;
            while (i < size()) {
                newPtr[i] = (*this)[i];
                ++i;
            }
            newPtr[i] = elem;
            ++i;
            delete[] ptr;
            ptr = newPtr;
            capacity *= 2;
            first = 0;
            last = i;
        }
    }

    template <class T>
    inline T& deque<T>::pop_front() {
        if (first == last)
            throw out_of_range("deque pop front");
        int now = first;
        if (++first == capacity)
            first = 0;
        return ptr[now];
    }
    
    template <class T>
    T& deque<T>::pop_back() {
        if (first == last)
            throw out_of_range("deque pop back");
        last = (last - 1) % capacity;
        return ptr[last];
    }

    template <class T>
    int deque<T>::size() const {
        if (last >= first)
            return last - first;
        else
            return capacity - first + last;
    }

    template <class T>
    bool deque<T>::empty() {
        return first == last;
    }

    template <class T>
    void deque<T>::clear() {
        first = last = 0;
    }

    template <class T>
    T& deque<T>::operator[](int ind) {
        if (ind < 0 || ind >= size())
            out_of_range("deque index");
        return ptr[(first + ind) % capacity];
    }

    template <class T>
    const T& deque<T>::operator[](int ind) const {
        if (ind < 0 || ind >= size())
            out_of_range("deque index");
        return ptr[(first + ind) % capacity];
    }

    template <class T>
    void deque<T>::operator=(const deque& copy) {
        delete[] ptr;
        ptr = new T[copy.capacity];
        int i = 0;
        while (i < copy.size()) {
            ptr[i] = copy[i];
            ++i;
        }
        first = 0;
        last = i;
    }

    template <class T>
    deque<T>::operator int() {
        return size();
    }
    
    template <class T>
    deque<T>::operator bool() {
        return !empty();
    }

#ifdef _IOSTREAM_
    template <class T>
    std::ostream& operator<< (std::ostream& out, const deque<T>& dec) {
        out << '[';
        for (int i = 0; i < dec.size() - 1; ++i)
            out << dec[i] << ", ";
        if (dec.size() > 0)
            out << dec[dec.size() - 1] << ']';
        return out;
    }
#endif // _IOSTREAM_

#ifdef IOSTREAM_LTD
    template <class T>
    ostream& operator<< (ostream& out, deque<T>& dec) {
        out << '[';
        for (int i = 0; i < dec.size() - 1; ++i)
            out << dec[i] << ", ";
        if (dec.size() > 0)
            out << dec[dec.size() - 1];
        out << ']';
        return out;
    }
#endif // IOSTREAM_LTD
    
}

#endif