

#ifndef CSE241_HW6_GTUSET_H
#define CSE241_HW6_GTUSET_H
namespace burak {

#include "Iterable.h"
#include "GTUIterator.h"
#include <memory>
#include <iterator>
#include <array>
#include <algorithm>

    template<typename T>
    class GTUSet : public burak::Iterable<T> {
    public:
        GTUSet() : Size(1), capacity(0) { // default constructor
            shared_ptr<T> str(new T[Size], array_deleter<T>());
            ptr = str;
        };

        GTUSet(shared_ptr<T> str1, int size, int capacity) : Size(size), capacity(capacity) { // pointer constructor
            ptr = str1;
        };


        bool empty() const override { // checks for the set is empty or not
            if (Size == capacity) {
                return false;
            } else
                return true;
        };

        int size() const override { // returns the size
            return Size;
        };

        T *getElement(int &&id) {  // returns the given element with index
            return &ptr.get()[id];
        }

        void clear() override { //Clear all content
            shared_ptr<T> str(new T[Size], array_deleter<T>());
            ptr = str;
            capacity = 0; // number of elements in the set is now 0 because we cleared it
        };

        const shared_ptr<T> &getPtr() const {
            return ptr;
        }

        void setPtr(const shared_ptr<T> &ptr1) {
            ptr = move(ptr1);

        }

        int getSize() const {
            return Size;
        }

        void setSize(int &&size) {
            Size = size;
        }

        int getCapacity() const {
            return capacity;
        };

        void setCapacity(int &&capacity1) {
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

        virtual ~GTUSet() = default; // destructor

        const GTUIterator<T> cbegin() const override { // Return a constant iterator to beginning
            const GTUIterator<T> iter(ptr.get());
            return iter;
        }

        const GTUIterator<T> cend() const override { // Return a constant iterator to end
            const GTUIterator<T> iter(&ptr.get()[capacity]);
            return iter;
        }

        void add(T element) { // if the capacity is not full adds the element to the set
            for (int i = 0; i < capacity; i++) {
                if (element == ptr.get()[i]) {
                    cout << "Element is already in the set !" << endl;
                    return;
                }
            }
            if (Size == capacity) {
                Size = Size + 1;
            }
            ptr.get()[capacity] = element;
            capacity = capacity + 1;
        }

        void delete_element(T element) {
            int index;
            if (capacity == 0) {
                cout << "Set is empty!" << endl;
                return;
            }
            int flag = 0;
            for (int i = 0; i < capacity; i++) {
                if (element == ptr.get()[i]) {
                    index = i;
                    flag = 1;
                }
            }
            if (flag == 0) {
                cout << "Element is not found in the set!" << endl;
                return;
            }
            for (int i = index; i < capacity-1; i++) {
                ptr.get()[i] = ptr.get()[i + 1];
            }
            if (capacity > 1) {
                capacity = capacity - 1;
            }
        }

        T &operator[](int &&i) {
            if (i > Size) {
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

        void search(T element) {
            for (int i = 0; i < capacity; i++) {
                if (element == ptr.get()[i]) {
                    cout << "Element is found in the set at index " << i << endl;
                    return;
                }
            }
            cout << "Element is not found in the set!" << endl;
        }

        void union_set(GTUSet<T> added) {
            T array[capacity];
            T array1[added.getCapacity()];
            int union_number;
            int loop_number;
            create_array(array);
            create_array(array1);
            sort(array, array + capacity);
            sort(array1, array1 + added.getCapacity());

            if (capacity > added.getCapacity()) {
                loop_number = capacity;
            } else {
                loop_number = added.getCapacity();
            }
            T temp_array[loop_number];
            int k = 0;
            int j;
            T union_array[union_number];
            for (int i = 0; i < capacity; i++) {
                // repeted element is not allowed so we check is any value repeated
                for (j = 0; j < k; j++) {
                    if (temp_array[j] == array[i])
                        break;
                }
                if (j == k) //if not repeated then store value in set c
                {
                    temp_array[k] = array[i];
                    k++;
                }
            }
            // copy element of set B in set C
            for (int i = 0; i < added.getCapacity(); i++) {
                // check for repeated element
                for (j = 0; j < k; j++) {
                    if (temp_array[j] == array1[i])
                        break;
                }
                if (j == k) // if element is not repeated then store in set C
                {
                    temp_array[k] = array1[i];
                    k++;
                }
            }
            cout << "Union array is : " << endl;
            for (int i = 0; i < k; i++) {
                cout << temp_array[i]<<endl;
            }
        }

        void intersect_set(GTUSet<T> added) {
            T array[capacity];
            T array1[added.getCapacity()];
            int flag = 0;
            create_array(array);
            sort(array, array + capacity);
            sort(array1, array1 + added.getCapacity());
            cout << endl << "Intersection array is : " << endl;
            for (int i = 0; i < added.getCapacity(); i++) {
                for (int j = 0; j < capacity; j++) {
                    if (ptr.get()[j] == added.ptr.get()[i]) {
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    cout << added.ptr.get()[i] << endl;
                }
                flag = 0;
            }

        }

    private:
        shared_ptr<T> ptr;
        int Size;
        int capacity;
    };
};

#endif //CSE241_HW6_GTUSET_H
