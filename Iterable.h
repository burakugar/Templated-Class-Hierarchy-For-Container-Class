
#ifndef CSE241_HW6_ITERABLE_H
#define CSE241_HW6_ITERABLE_H

#include <iostream>
#include "GTUIterator.h"
using namespace std;
namespace burak {
    template<typename T>
    class Iterable {
    protected:
        virtual bool empty() const = 0;

        virtual int size() const = 0;

        virtual void erase(GTUIterator<T> iter) = 0;

        virtual void clear() = 0;

        virtual GTUIterator<T> begin() = 0;

        virtual GTUIterator<T> end() = 0;

        virtual const GTUIterator<T> cbegin() const = 0;

        virtual const GTUIterator<T> cend() const = 0;

        virtual ~Iterable() = default;

    };
}

#endif //CSE241_HW6_ITERABLE_H
