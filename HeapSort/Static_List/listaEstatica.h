#include <iostream>
#include "rand.h"
#include <math.h>

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

    void heapfy(int i){
        int l = (2*i) + 1;
        int r = (2*i) + 2;
        int max = i;
         
        if(size > l && list[l].key > list[max].key) max = l;
        if(size > r && list[r].key > list[max].key) max = r;
        
        if(max != i){
            swap(i,max);
            heapfy(max);
        }
    }

    void creatHeap(bool print){
        int m=  (((int) size)-1)/2;
        if(print) this->print(-100);
        for(int i = m; i >=0; i--){
            if(print) cout << "b = ";
            if(print) this->print(i);
            heapfy(i);
            if(print) cout << "a = ";
            if(print){
                this->print(i);
                cout << endl;
            }
        }
    }

    void heapSort(bool print){

        creatHeap(print);
        int aux = size; 
        for(int i = aux-1; i>0 ;i--){
            swap(0,i);
            size--;
            heapfy(0);
        }
        size = aux;
    }

    //print the elements of a list.
    void print(int x){

        for(int i=0; i<size; ++i){
            if(i==x) cout << "\e[31;10m(" << list[i].key << ")\e[m ";
            else if(i==(x*2)+1) cout << "\e[34;10m(" << list[i].key << ")\e[m ";
            else if(i==(x*2)+2) cout << "\e[33;10m(" << list[i].key << ")\e[m ";
            else cout << "(" << list[i].key << ") ";
        }
        cout <<endl;
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