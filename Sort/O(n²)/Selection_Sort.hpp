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

    /*swap the element on index posA with the element on index posB*/
    void swap(const unsigned int posA, const unsigned int posB){

        DataType aux = list[posA];

        list[posA] = list[posB];
        list[posB] = aux;
    }

    void selectionSort(){
        
        for(int i = 0; i <size; i++){
            int min = i;
            for(int j = i +1; j<size;j++){
                if(list[min] >list[j]) min = j;
            }
            swap(i,min);
        }
    }

    void sort(){
        selectionSort();
    } 
};