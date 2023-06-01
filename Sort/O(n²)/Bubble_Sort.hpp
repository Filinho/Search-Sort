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

    /*sort a list. If print is true prints the state of the list between the iterations.*/
    void bubbleSort(){
        /*Swap pos indicates where the last position where a swap occurred.*/
        int swapPos = size-1;
        /*If swapPos <= 0 it means the list is sorted because no swap happened.*/
        while(swapPos > 0){
            /*n is the number of times the second loop runs. From where the last swap took place the list is sorted,that is, it is not necessary to check the elements already sorted.*/
            int n = swapPos;
            swapPos = 0;

            for(int j=0; j<n; ++j){
                /*The current element is compared with the next and if it is bigger they swap positions. This means that the bigger element its at the end of the list on the end of this loop.*/
                if(list[j] > list[j+1]){

                    swap(j, j+1);
                    swapPos = j;
                }
            }
        }
    }

    void sort(){
        bubbleSort();
    } 
};