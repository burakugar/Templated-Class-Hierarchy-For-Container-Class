#include <iostream>
#include "GTUIterator.h"
#include "GTUVector.h"
#include "GTUSet.h"
#include "GTUArray.h"
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int m[5]={20,30,40,50,60};
     cout<< "First array for testing iterator"<< endl;
     for(int i=0;i<5;i++){
         cout<< m[i]<<endl;
     }
    int *x=m;
  cout<< "Testing * operator for iterator" << endl;
    cout<<*x<<endl;
    x++;
    cout<< "Moving one element further" << endl;
    cout<<*x<<endl;

    GTUIterator<int> i1(x);

    GTUIterator<int> i2;
    cout<< "Testing = operator for iterator"<< endl;
    i2=i1;

    cout<<*i2<<endl;

    cout<< "Testing -- operator for iterator"<< endl;
    --i2;
    cout<<*i2<<endl;

    cout<< "Testing == for iterator"<< endl;
    cout<<(i1==i2)<<endl;

    /********************** TESTING GTUSET CLASS *************************/
    shared_ptr<int> str_2 (new int [4],array_deleter<int>());
    for(int i=0;i<4;i++){
        str_2.get()[i]=i;
    }
    int w=1;
    int* pt3= &w;
    GTUIterator<int> iter3(pt3);
    burak::GTUSet<int> a2(str_2,4,4);
    cout<< "Testing set class"<<endl;
    cout<<"First set is: "<< endl;
    for(iter3=a2.cbegin();iter3!= a2.cend();++iter3){
        cout<< *iter3<< endl;
    }
    cout<<"Erasing the element from the set: "<< endl;
    a2.erase(iter3);
    for(iter3=a2.cbegin();iter3!= a2.cend();++iter3){
        cout<< *iter3<< endl;
    }
    cout<< "Testing whether the set is empty"<< endl;
    cout<<!a2.empty()<<endl;
    cout<< "Testing add function with adding -2 inside the set "<< endl;
    a2.add(-2);
    cout<< "After adding -2 to the set "<< endl;
    for(iter3=a2.cbegin();iter3!= a2.cend();++iter3){
        cout<< *iter3<< endl;
    }
    cout<< "Testing find for set class"<<endl;
    iter3= std::find (a2.begin(), a2.end(), 7);
    cout<< "Searching for 7 in the set" << endl;
    if (iter3 != a2.end())
    {
        std::cout << "Element found at position : "<< *iter3 ;
    }
    else
        std::cout << "Element not found.\n";
    cout<< "Searching for 2 in the set" << endl;
    iter3= std::find (a2.begin(), a2.end(), 2);
    if (iter3 != a2.end())
    {
        std::cout << "Element found at position : "<< *iter3 ;
    }
    else
        std::cout << "Element not found.\n";

    cout<< endl<< "Testing for each loop for set:"<< endl;
    for(auto & t: a2 ){
        cout<< t << endl;
    }
    int array[a2.getCapacity()];
    a2.create_array(array);
    sort(array,array+a2.getCapacity());
    cout<< "Testing the sorting function:"<<endl;
    for(int i=0;i<a2.getCapacity();i++){
        cout<<" "<<array[i];
    }
    cout<< endl<< "Testing the union of the set"<< endl;
    shared_ptr<int> str_3 (new int [4],array_deleter<int>());
    int z=0;
    for(int i=1;i<4;i++){
        str_3.get()[z]=i;
        z++;
    }
    burak::GTUSet<int> a3(str_3,4,4);
    a2.union_set(a3);
    a2.intersect_set(a3);
    cout<< "Testing the delete function for set with deleting 1 from set: "<< endl;
    a2.delete_element(1);
    cout<< "After delete operation, set is: "<< endl;
    for(auto & l: a2 ){
        cout<< l << endl;
    }
    cout<< endl<< "After clearing the array: "<<endl;
    a2.clear();
    for(auto & l: a2 ){
        cout<< l << endl;
    }



    /********************** TESTING GTUVECTOR CLASS *************************/

    shared_ptr<int> str (new int [4],array_deleter<int>());
    for(int i=0;i<4;i++){
        str.get()[i]=i;
    }
    int y=1;
    int* pt= &y;
    GTUIterator<int> iter(pt);
    GTUVector<int> a(str,4,4);
    //int* temp=a.getElement(0);
    a.erase(iter);
    for(iter=a.cbegin();iter!= a.cend();++iter){
        cout<< *iter<< endl;
    }
    cout<< "Testing add function with adding -2 inside the vector "<< endl;
    a.add(-2);
    cout<< "After adding -2 to the vector "<< endl;
    for(iter=a.cbegin();iter!= a.cend();++iter){
         cout<< *iter<< endl;
     }
    cout<< "Testing find for vector class"<<endl;
    iter= std::find (a.begin(), a.end(), 7);
    cout<< "Searching for 7 in the vector" << endl;
    if (iter != a.end())
    {
        std::cout << "Element found at position : "<< *iter ;
    }
    else
        std::cout << "Element not found.\n";
    cout<< "Searching for 2 in the vector" << endl;
    iter= std::find (a.begin(), a.end(), 2);
    if (iter != a.end())
    {
        std::cout << "Element found at position : "<< *iter ;
    }
    else
        std::cout << "Element not found.\n";

    cout<< endl<< "Testing for each loop for vector:"<< endl;
    for(auto & t: a ){
        cout<< t << endl;
    }
    cout<< "Testing whether the vector is empty"<< endl;
    cout<<!a.empty()<<endl;
    int array4[a.getCapacity()];
    a.create_array(array4);
    sort(array4,array4+a.getCapacity());
    cout<< "Testing the sorting function:"<<endl;
    for(int i=0;i<a.getCapacity();i++){
        cout<<" "<<array4[i];
    }
    cout<< endl<< "After clearing the array: "<<endl;
    a.clear();
    for(auto & l: a ){
        cout<< l << endl;
    }
    /********************** TESTING GTUARRAY CLASS *************************/

    int t=1;
    int* pt1= &t;
    GTUIterator<int> iter_array(pt1);
    shared_ptr<int> str1 (new int [6],array_deleter<int>());
    for(int i=0;i<5;i++){
        str1.get()[i]=i;
    }
    burak::GTUArray<int,6> array2(str1,5);
    //array2.erase(iter);
    cout<< endl<<  "Array is: "<<endl;
    for(iter_array=array2.cbegin();iter_array!= array2.cend();++iter_array){
        cout<< *iter_array<< endl;
    }
   array2.add(-1);
    cout<< "After adding the element, array will be :"<<endl;
    for(iter_array=array2.cbegin();iter_array!= array2.cend();++iter_array){
         cout<< *iter_array<< endl;
     }

    cout<< "Testing find for array"<<endl;
    iter_array= std::find (array2.begin(), array2.end(), 4);
    cout<< "Finding 4 in the array" <<endl;
    if (iter_array != array2.end())
    {
        std::cout << "Element found at index : "<< *iter_array ;
    }
    else
        std::cout << "Element not found.\n";
    cout<< endl<< "Testing for each loop for array:"<< endl;
    for(auto & l: array2 ){
        cout<< l << endl;
    }

    int array3[array2.getCapacity()];
    array2.create_array(array3);
    sort(array3,array3+array2.getCapacity());
    cout<< "Testing the sorting function for array:"<<endl;
    for(int i=0;i<array2.getCapacity();i++){
        cout<<" "<<array3[i];
    }
    cout<< endl;
    cout<< "Final array is:"<<endl;
    for(auto & l: array3 ){
        cout<< l << endl;
    }
    cout<< "Testing whether the array is empty"<< endl;
    cout<<!array2.empty()<<endl;
    cout<< "After clearing the array: "<<endl;
    array2.clear();
    for(auto & l: array2 ){
        cout<< l << endl;
    }
    return 0;
}
