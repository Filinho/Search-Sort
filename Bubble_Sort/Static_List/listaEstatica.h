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

    /*sort a list. If print is true prints the state of the list between the iterations.*/
    void bubblesort(const bool print){

        /*Swap pos indicates where the last position where a swap occurred.*/
        int swapPos = size-1;

        if(print){
            this->print();
            cout << endl;
        }

        /*If swapPos <= 0 it means the list is sorted because no swap happened.*/
        while(swapPos > 0){

            /*n is the number of times the second loop runs. From where the last swap took place the list is sorted,that is, it is not necessary to check the elements already sorted.*/
            int n = swapPos;
            swapPos = 0;

            for(int j=0; j<n; ++j){
                /*The current element is compared with the next and if it is bigger they swap positions. This means that the bigger element its at the end of the list on the end of this loop.*/
                if(list[j].key > list[j+1].key){

                    swap(j, j+1);
                    swapPos = j;
                }
            }

            if(print){
                this->print();
                cout << endl;
            }
        }
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
    void print(){

        for(int i=0; i<size; ++i){

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

};