
#ifndef CSE241_HW6_GTUITERATORCONST_H
#define CSE241_HW6_GTUITERATORCONST_H
namespace burak {
    using namespace std;

#include <iostream>

    template<typename T>
    class GTUIteratorConst {
    private:
        const T *my_ptr;
    public:
        explicit GTUIteratorConst(shared_ptr<T> myPtr);

        GTUIteratorConst(T *element);

        GTUIteratorConst();

        const T &operator*() const;

        T &operator->();

        GTUIteratorConst<T> &operator++();

        GTUIteratorConst<T> &operator--();

        bool operator==(const GTUIteratorConst<T> &rhs) const;

        bool operator!=(const GTUIteratorConst<T> &rhs) const;

        GTUIteratorConst &operator=(const GTUIteratorConst<T> &rhs);

        T *getMyPtr() const;

        void setMyPtr(T *myPtr);
    };

    template<typename T>
    const T &GTUIteratorConst<T>::operator*() const {
        return *my_ptr;
    }

    template<typename T>
    T &GTUIteratorConst<T>::operator->() {
        return my_ptr;
    }

    template<typename T>
    GTUIteratorConst<T> &GTUIteratorConst<T>::operator++() {
        my_ptr = my_ptr + 1;
        return *this;
    }

    template<typename T>
    GTUIteratorConst<T> &GTUIteratorConst<T>::operator--() {
        my_ptr = my_ptr - 1;
        return *this;
    }

    template<typename T>
    GTUIteratorConst<T> &GTUIteratorConst<T>::operator=(const GTUIteratorConst<T> &rhs) {
        this->my_ptr = rhs.my_ptr;
        return *this;
    }

    template<typename T>
    bool GTUIteratorConst<T>::operator==(const GTUIteratorConst<T> &rhs) const {
        return (my_ptr == rhs.my_ptr);
    }

    template<typename T>
    bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst<T> &rhs) const {
        return (my_ptr != rhs.my_ptr);
    }

    template<typename T>
    GTUIteratorConst<T>::GTUIteratorConst(shared_ptr<T> myPtr) {
        my_ptr = myPtr;
    }

    template<typename T>
    GTUIteratorConst<T>::GTUIteratorConst() {
        my_ptr = nullptr;
    }

    template<typename T>
    void GTUIteratorConst<T>::setMyPtr(T *myPtr) {
        my_ptr = myPtr;
    }

    template<typename T>
    T *GTUIteratorConst<T>::getMyPtr() const {
        return my_ptr;
    }

    template<typename T>
    GTUIteratorConst<T>::GTUIteratorConst(T *element) {
        my_ptr = element;
    }
}
#endif //CSE241_HW6_GTUITERATORCONST_H
