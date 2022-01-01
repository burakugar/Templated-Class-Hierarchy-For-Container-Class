
#ifndef CSE241_HW6_GTUVECTOR_H
#define CSE241_HW6_GTUVECTOR_H
#include "Iterable.h"
#include "GTUIterator.h"
#include <memory>
#include <iterator>
#include <array>
using namespace std;
template< typename T >
struct array_deleter
{
    void operator ()( T const * p)
    {
        delete[] p;
    }
};
template<typename T>

class GTUVector:public burak::Iterable<T> {
public:
    GTUVector():Size(1),capacity(0){
       shared_ptr<T> str (new T[Size],array_deleter<T>());
       ptr=str;
    };

    GTUVector(shared_ptr<T> str1, int size, int capacity): Size(size), capacity(capacity) {
        ptr=str1;
    };

    GTUVector(GTUVector && that) noexcept {
        ptr.move(that);
        that.setPtr(NULL);
    };

    bool empty() const override { // Test whether container is empty
        if(Size == capacity){
            return false;
        }
        else return true;
    } ;

    int size() const override {
        return Size;
    };

    T* getElement(int&& id){
        return &ptr.get()[id];
    }
    void clear() override{ // Clear all content in the vector
        shared_ptr<T> str (new T[Size],array_deleter<T>());
        ptr=str;
        capacity=0; // number of elements in the set is now 0 because we cleared it
    };

    const shared_ptr<T> &getPtr() const{
        return ptr;
    }

    void setPtr(const shared_ptr<T> &ptr1){
        ptr=move(ptr1);

    }

    int getSize() const{
        return Size;
    }

    void setSize(int&& size){
        Size = size;
    }

    int getCapacity() const{
        return capacity;
    };

    void setCapacity(int&& capacity1){
        capacity = capacity1;
    }

   GTUIterator<T> begin() override{ // Return iterator to beginning
        GTUIterator<T> iter(ptr.get());
        return iter;
    }

    GTUIterator<T> end() override{ // Return iterator to end
        GTUIterator<T> iter(&ptr.get()[capacity]);
        return iter;
    }

    void erase(GTUIterator<T> iter) override{ //Erase element pointed by the given iterator
        T tempElement=*iter;
       for(int i=0;i<capacity;i++){
           if(tempElement==ptr.get()[i]){
               for(int j=i+1;j<capacity;j++){
                   ptr.get()[j-1]=ptr.get()[j];
               }
               break;
           }
       }
        setCapacity(capacity-1);
    }

    virtual ~GTUVector()= default;

    const GTUIterator<T> cbegin() const override{ // Return a constant iterator to beginning
        const GTUIterator<T> iter(ptr.get());
        return iter;
    }

    const GTUIterator<T> cend() const override{ //Return a constant iterator to end
        const GTUIterator<T> iter(&ptr.get()[capacity]);
        return iter;
    }
    void add(T element) { // adds an element with type T to the vector
        if(Size == capacity){
            Size=Size+1;
        }
        ptr.get()[capacity]=element;
        capacity=capacity+1;
    }

    T &operator[](int&& i) { // [] operator for vector class
        if( i > Size ) {
            cout << "Index out of bounds" <<endl;
            // return first element.
            return ptr.get()[0];
        }

        return ptr.get()[i];
    }
    T* create_array(T* array){ // creates a new array
        for(int i=0;i<capacity;i++){
            array[i]= ptr.get()[i];
        }
    }

private:
    shared_ptr<T> ptr;
    int Size;
    int capacity;
};



#endif //CSE241_HW6_GTUVECTOR_H
