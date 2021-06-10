#pragma once

#ifndef DEQUE_LTD
#define DEQUE_LTD

#include "ltl/Exception.h"
#include "Vector.h"

namespace ltd {
    template <class T>
    class deque {
        T* startPtr;    // указывает на начало выделенной памяти
        T* frontPtr;    // указывает на первый элемент в деке
        T* backPtr;     // указывает на последний элемет в деке
        int maxSize;    // максимальный размер, указанный при создании дека

    public:
        void setStartPtr(T*);   // сеттер
        void setFrontPtr(T*);   // сеттер
        void setBackPtr(T*);    // сеттер
        void setMaxSize(T*);    // сеттер

        T* getStartPtr() const; // геттер
        T* getFrontPtr() const; // геттер
        T* getBackPtr() const;  // геттер
        T* getMaxSize() const;  // геттер

        deque(int);                    // простой конструктор с указанием наксимального кол-ва элементов, которые будут добавлены в дек
        deque(const deque&);           // конструктор копирования с полным поэлементым копированием
        ~deque();                      // дестркутор с простой очиткой памяти

        T& front();             // возврашает элемент в начале дека
        T& back();              // возвращает элемент в конце дека

        void push_front(T);     // добавление элемента в начало дека
        void push_back(T);      // добавление элемента в конец дека

        T& pop_front();         // удаление элемента из начала дека
        T& pop_back();          // удаление элемента из конца дека

        int size();             // вернет текущий размер дека
        int max_size() const;   // вернет максимальный размер дека в одну сторону (относительно начального указателя)

        bool empty();           // вернет True, если дек пуст, и False, если дек не пуст

        void clear();           // очищает дек, не удаляя элементы, а просто сдвигая указатели

        T& operator[](int);     // обращаестя к нужному элементу дека по очереди считая от начала (асимптотика O(1))
        T& at(int);             // аналогичен operator[]

        auto begin();           // итератор на начало дека
        auto end();             // итератор на следующую ячейку за концом дека

        void operator=(deque&); // полное поэлементное копирование

        operator int();         // вернет размер
        operator bool();        // вернет True, если дек не пуст, и False, если дек пуст
    };

    // сеттеры
    template <class T>
    void deque<T>::setStartPtr(T* newStartPtr) { startPtr = newStartPtr; };
    template <class T>
    void deque<T>::setFrontPtr(T* newFrontPtr) { frontPtr = newFrontPtr; };
    template <class T>
    void deque<T>::setBackPtr(T* newBackPtr) { backPtr = newBackPtr; };
    template <class T>
    void deque<T>::setMaxSize(T* newMaxSize) { maxSize = newMaxSize; };

    // геттеры
    template <class T>
    T* deque<T>::getStartPtr() const { return startPtr; };
    template <class T>
    T* deque<T>::getFrontPtr() const { return frontPtr; };
    template <class T>
    T* deque<T>::getBackPtr() const { return backPtr; };
    template <class T>
    T* deque<T>::getMaxSize() const { return maxSize; };

    template <class T>  // простой конструктор с указанием наксимального кол-ва элементов, которые будут добавлены в дек
    deque<T>::deque(int maxLen) : startPtr(new T[maxLen * 2 - 1]),
        frontPtr(startPtr + maxLen - 1),
        backPtr(startPtr + maxLen - 2),
        maxSize(maxLen) {};

    template <class T>  // конструктор копирования с полным поэлементым копированием
    deque<T>::deque(const deque& copy) : startPtr(new T[copy.max_size() * 2 - 1]),
        frontPtr(startPtr + (copy.getFrontPtr() - copy.getStartPtr())),
        backPtr(startPtr + (copy.getBackPtr() - copy.getStartPtr())),
        maxSize(copy.max_size()) {
        for (int i = copy.getFrontPtr() - copy.getStartPtr(); i <= copy.getBackPtr() - copy.getStartPtr(); ++i)
            startPtr[i] = copy.getStartPtr()[i];
    };

    template <class T>  // дестркутор с простой очиткой памяти
    deque<T>::~deque() { delete[] startPtr; };

    template <class T>  // вернет текущий размер дека
    int deque<T>::size() { return backPtr - frontPtr + 1; }
    template <class T>  // вернет максимальный размер дека в одну сторону (относительно начального указателя)
    int deque<T>::max_size() const { return maxSize; }

    template <class T>  // возврашает элемент в начале дека
    T& deque<T>::front() { return *frontPtr; };
    template <class T>  // возвращает элемент в конце дека
    T& deque<T>::back() { return *backPtr; }

    template <class T>  // добавление элемента в начало дека
    void deque<T>::push_front(T newElem) { *(--frontPtr) = newElem; };
    template <class T>  // добавление элемента в конец дека
    void deque<T>::push_back(T newElem) { *(++backPtr) = newElem; };

    template <class T>  // удаление элемента из начала дека
    T& deque<T>::pop_front() { return *(frontPtr++); };
    template <class T>  // удаление элемента из конца дека
    T& deque<T>::pop_back() { return *(backPtr--); };

    template <class T>  // вернет True, если дек пуст, и False, если дек не пуст
    bool deque<T>::empty() { return backPtr < frontPtr; }

    template <class T>  // очищает дек, не удаляя элементы, просто сдвигая указатели
    void deque<T>::clear() {
        frontPtr = startPtr + maxSize - 1;
        backPtr = startPtr + maxSize - 2;
    }

    template <class T>  // обращаестя к нужному элементу дека по очереди считая от начала (асимптотика O(1))
    T& deque<T>::operator[](int index) { return frontPtr[index]; }
    template <class T>  // аналогичен operator[]
    T& deque<T>::at(int index) { return frontPtr[index]; }

    template <class T>  // полное поэлементное копирование
    void deque<T>::operator=(deque& copy) {
        startPtr = new T[copy.max_size() * 2 - 1];
        frontPtr = startPtr + (copy.getFrontPtr() - copy.getStartPtr());
        backPtr = startPtr + (copy.getBackPtr() - copy.getStartPtr());
        maxSize = copy.max_size();
        for (int i = copy.getFrontPtr() - copy.getStartPtr(); i <= copy.getBackPtr() - copy.getStartPtr(); ++i)
            startPtr[i] = copy.getStartPtr()[i];
    };

    template <class T>  // итератор на начало дека
    auto deque<T>::begin() { return frontPtr; }
    template <class T>  // итератор на следующую ячейку за концом дека
    auto deque<T>::end() { return backPtr + 1; }

    template <class T>  // вернет размер
    deque<T>::operator int() { return size(); }
    template <class T>  // вернет True, если дек не пуст, и False, если дек пуст
    deque<T>::operator bool() { return backPtr >= frontPtr; }
}

#endif