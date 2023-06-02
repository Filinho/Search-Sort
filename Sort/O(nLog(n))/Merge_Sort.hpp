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
        StaticList auxL(*this);
        rec_mergesort(0, size, &auxL);
    } 

   void merge(const int left, const int mid, const int right, StaticList* auxL){

        int leftAux = left;
        int midAux = mid;
        
        for(int i=left; i<right; ++i){

            if(leftAux<mid && (!(midAux<right) || list[leftAux]<list[midAux])){

                auxL->overwrite_position(i, list[leftAux++]);
            }else{

                auxL->overwrite_position(i, list[midAux++]);
            }
        }
    }

    void rec_mergesort(const int left, const int right, StaticList* auxL){

        if(left < right-1){
            int mid = (left+right)/2;
            auxL->rec_mergesort(left, mid, this);
            auxL->rec_mergesort(mid, right, this);
            auxL->merge(left, mid, right, this);
        }
    }
};