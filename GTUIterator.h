
#ifndef CSE241_HW6_GTUITERATOR_H
#define CSE241_HW6_GTUITERATOR_H

#include <iostream>


using namespace std;

template <typename T>

class GTUIterator {
private:
    T* my_ptr;
public:
    explicit GTUIterator(shared_ptr<T> myPtr);
    GTUIterator(T* element);
    GTUIterator();
    T& operator*();
    T& operator->();
    GTUIterator<T>& operator++();
    GTUIterator<T>& operator--();
    bool operator ==(const GTUIterator<T> &rhs) const;
    bool operator !=(const GTUIterator<T> &rhs) const;
    GTUIterator& operator =(const GTUIterator<T> &rhs);
    T *getMyPtr() const;
    void setMyPtr(T *myPtr);
};

template<typename T>
T &GTUIterator<T>::operator*() {
    return *my_ptr;
}

template<typename T>
T &GTUIterator<T>::operator->() {
    return my_ptr;
}

template<typename T>
GTUIterator<T> &GTUIterator<T>::operator++(){
    my_ptr= my_ptr+1;
    return *this;
}
template<typename T>
GTUIterator<T> &GTUIterator<T>::operator--() {
    my_ptr=my_ptr-1;
    return *this;
}

template<typename T>
GTUIterator<T> &GTUIterator<T>::operator=(const GTUIterator<T> &rhs) {
    this->my_ptr=rhs.my_ptr;
    return *this;
}

template<typename T>
bool GTUIterator<T>::operator==(const GTUIterator<T> &rhs) const{
    return (my_ptr==rhs.my_ptr);
}

template<typename T>
bool GTUIterator<T>::operator !=(const GTUIterator<T> &rhs) const{
    return (my_ptr!=rhs.my_ptr);
}

template<typename T>
GTUIterator<T>::GTUIterator(shared_ptr<T> myPtr) {
    my_ptr=myPtr;
}

template<typename T>
GTUIterator<T>::GTUIterator() {
    my_ptr= nullptr;
}

template<typename T>
void GTUIterator<T>::setMyPtr(T *myPtr) {
    my_ptr = myPtr;
}

template<typename T>
T *GTUIterator<T>::getMyPtr() const {
    return my_ptr;
}

template<typename T>
GTUIterator<T>::GTUIterator(T* element){
    my_ptr= element;
}

#endif //CSE241_HW6_GTUITERATOR_H
