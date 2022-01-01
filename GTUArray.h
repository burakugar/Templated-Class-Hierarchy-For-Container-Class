
#ifndef CSE241_HW6_GTUARRAY_H
#define CSE241_HW6_GTUARRAY_H
namespace burak {

#include "Iterable.h"
#include "GTUIterator.h"
#include <memory>
#include <iterator>
#include <array>

    using namespace std;

    template<typename T, int SIZE>

    class GTUArray : public burak::Iterable<T> {
    public:
        GTUArray() : capacity(0) { // default constructor
            shared_ptr<T> str(new T[SIZE], array_deleter<T>());
            ptr = str;
        };

        GTUArray(shared_ptr<T> str1, int capacity) : capacity(capacity) { // pointer constructor
            ptr = str1;
        };

        GTUArray(GTUArray &&that) noexcept {
            ptr.move(that);
            that.setPtr(NULL);
        };

        bool empty() const override { // checks for the set is empty or not
            if (SIZE == capacity) {
                return false;
            } else return true;
        };

        int size() const override { // returns the size
            return SIZE;
        };

        T *getElement(int id) { // returns the given element with index
            return &ptr.get()[id];
        }

        void clear() override {  //Clear all content
            shared_ptr<T> str(new T[SIZE], array_deleter<T>());
            ptr = str;
            capacity = 0; // number of elements in the set is now 0 because we cleared it
        };

        const shared_ptr<T> &getPtr() const {
            return ptr;
        }

        GTUArray &operator=(GTUArray &&other) noexcept { // assingment operator for array class with move semantics
            if (this != &other) {
                if (ptr) {
                    delete ptr;
                }
                ptr = other.ptr;
                other.buffer = nullptr;
            }
        }

        void setPtr(const shared_ptr<T> &ptr1) {
            ptr = ptr1;
        }

        int getSize() const {
            return SIZE;
        }

        int getCapacity() const { // returns the capacity
            return capacity;
        };

        void setCapacity(int capacity1) {
            capacity = capacity1;
        }

        GTUIterator<T> begin() override { // Return iterator to beginning
            GTUIterator<T> iter(ptr.get());
            return iter;
        }

        GTUIterator<T> end() override { // Return iterator to end
            GTUIterator<T> iter(&ptr.get()[capacity]);
            return iter;
        }

        void erase(GTUIterator<T> iter) override { // Erase element pointed by the given iterator
            T tempElement = *iter;
            for (int i = 0; i < capacity; i++) {
                if (tempElement == ptr.get()[i]) {
                    for (int j = i + 1; j < capacity; j++) {
                        ptr.get()[j - 1] = ptr.get()[j];
                    }
                    break;
                }
            }
            setCapacity(capacity - 1);
        }

        virtual ~GTUArray() = default;

        const GTUIterator<T> cbegin() const override { // Return a constant iterator to beginning
            const GTUIterator<T> iter(ptr.get());
            return iter;
        }

        const GTUIterator<T> cend() const override { // Return a constant iterator to end
            const GTUIterator<T> iter(&ptr.get()[capacity]);
            return iter;
        }

        void add(T element) { // if the capacity is not full adds the element to the array
            if (SIZE == capacity) {
                cout << "Capacity is full";
                return;
            }
            ptr.get()[capacity] = element;
            capacity = capacity + 1;
        }

        T &operator[](int i) { // [] operator for the array
            if (i > SIZE) {
                cout << "Index out of bounds" << endl;
                // return first element.
                return ptr.get()[0];
            }

            return ptr.get()[i];
        }

        T *create_array(T *array) {
            for (int i = 0; i < capacity; i++) {
                array[i] = ptr.get()[i];
            }
        }

    private:
        shared_ptr<T> ptr;
        int capacity;
    };
}

#endif //CSE241_HW6_GTUARRAY_H
