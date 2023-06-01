#include <iostream>

using namespace std;

typedef int DataType;

class StaticList{
public:

    static constexpr unsigned int MAX = 1000;

    DataType  list[MAX];
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

            list[i] = i;
        }

        /*A permutation of the elements occurs to randomize the positions.*/
        int elem1, elem2;
        for(int i=0; i<sz; ++i){

            elem1 = rand()%sz;
            elem2 = rand()%sz;
            swap(elem1, elem2);
        }
    }
    
    void swap(const unsigned int posA, const unsigned int posB){

        DataType aux = list[posA];

        list[posA] = list[posB];
        list[posB] = aux;
    }
    /*insert the value on position pos overwriting the element in pos.*/
    void overwrite_position(const unsigned int pos, const DataType value){

        if(pos >= size) return;

        list[pos] = value;
    }

    void sort(){
        heapSort();
    } 

    void heapify(int i){
        int l = (2*i) + 1;
        int r = (2*i) + 2;
        int max = i;
         
        if(size > l && list[l] > list[max]) max = l;
        if(size > r && list[r] > list[max]) max = r;
        
        if(max != i){
            swap(i,max);
            heapify(max);
        }
    }

    void createHeap(){
        int m=  (((int) size)-1)/2;

        for(int i = m; i >=0; i--){
            heapify(i);
        }
    }

    void heapSort(){

        createHeap();
        int aux = size; 
        for(int i = aux-1; i>0 ;i--){
            swap(0,i);
            size--;
            heapify(0);
        }
        size = aux;
    }
};