#include <iostream>
#include "rand.h"

using namespace std;

typedef struct{

    string name;
    int key;
}Person;

typedef Person DataType;

class StaticList{
public:

    static constexpr unsigned int MAX = 1000;

    DataType list[MAX];
    unsigned int size;

    /*initizalize an empty list.*/
    StaticList(){

        size = 0;
    }

    /*initialize an list with sz unique elements in a random order.*/
    StaticList(const int sz){

        size = sz;

        /*First we add the elements sequencially.*/
        for(int i=0; i<sz; ++i){

            list[i].key = i;
            list[i].name = rand_name();
        }

        /*A permutation of the elements occurs to randomize the positions.*/
        int elem1, elem2;
        for(int i=0; i<sz; ++i){

            elem1 = rand()%sz;
            elem2 = rand()%sz;
            swap(elem1, elem2);
        }
    }

    /*insert the value on position pos overwriting the element in pos.*/
    void overwrite_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;

        list[pos] = value;
    }

    /*insert value on position pos moving the element in pos one index foward.*/
    void insert_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;
        
        /*the loop starts at the end of the list moving all the elements one index foward opening the index pos to element value.*/
        for(int i=size; i>pos; --i){

            list[i] = list[i-1];
        }

        list[pos] = value;
        size++;
    }

    /*insert x in the end of the list.*/
    void push_back(const DataType x){

        if(size == MAX) return;

        list[size++] = x; 
    }


/*
    int binary_search(const DataType target){

        int left = 0;
        int right = size-1;
        int targetKey = target.key;

        while(left <= right){

            int middle = (right+left)/2;

            if(list[middle].key == targetKey) return middle;

            else if(list[middle].key < targetKey){

                left = middle+1;
            }else{

                right = middle-1;
            }
        }

        return -1;
    }
*/

    //print the elements of a list.
    void print(int c){

        for(int i=0; i<size; ++i){
            if(i == c && c != -1) cout << "center : ";
            cout << "(" << list[i].key << ")-Nome: " << list[i].name << endl;
        }
    }

    /*swap the element on index posA with the element on index posB*/
    void swap(const unsigned int posA, const unsigned int posB){

        DataType aux = list[posA];

        list[posA] = list[posB];
        list[posB] = aux;
    }

    /*delete the element at index pos*/
    void delete_position(const unsigned int pos){

        /*the loop starts on index pos moving the elements one index back and overwriting the element at pos*/
        for(int i=pos; i<size; ++i){
            list[i] = list[i+1];
        }
        size--;
    }
    void quickSort(bool print){
        privateQuickSort(0,size-1,print);
    }
    private: 
    int partition(int left,int right, bool print){
        int pivot = list[right].key; // set the pivot element as the elemet in index right
        int center = left; // initialize the center as the index of the left element
        for( int i = left; i < right; i++){
            /*if the pivot key is bigger than the key of the element in index i, the element in center most be swapped with the element in i, and the index center most be incremented*/ 
            if(list[i].key < pivot){
                swap(center,i);
                center++;   
            }
            
        }
        /*after all interactios of the for, the variable center, will points exactly for the index where pivot is the center of the list, that means that, any element after center, is bigger thant the pivot, and any element before center, is smaller thant the center. with the index center, we swapp the center element with the right element*/
        swap(center, right);

        if (print) {
        cout << endl ;
        this->print(center);

        cout << endl ;
        }
        
        return center;
    }
        /*sort a list. If print is true prints the state of the list between the iterations.*/
    void privateQuickSort(int left, int right, bool print){

        if(left < right){
            int center = partition(left, right, print);// function that define the center
            privateQuickSort(left, center-1, print); // recursive call for the left of center
            privateQuickSort(center+1, right, print); // recursive call for the right of center
        }

    }  
};