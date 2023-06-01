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


    void sort(){
        privateQuickSort(0,size-1);
    } 

    private: 
    // get the pivot 
    int partition(int left,int right){
        int pivot = list[right]; // set the pivot element as the elemet in index right
        int center = left; // initialize the center as the index of the left element
        for( int i = left; i < right; i++){
            /*if the pivot key is bigger than the key of the element in index i, the element in center most be swapped with the element in i, and the index center most be incremented*/ 
            
            if(list[i] < pivot){
                
                swap(center,i);
                center++; 

            }
        }
        
        /*after all interactios of the for, the variable center, will points exactly for the index where pivot is the center of the list, that means that, any element after center, is bigger thant the pivot, and any element before center, is smaller thant the center. with the index center, we swapp the center element with the right element*/
        
        swap(center, right);
        return center;
    }
        
    void privateQuickSort(int left, int right){

        if(left < right){
            int center = partition(left, right);// function that define the center
            privateQuickSort(left, center-1); // recursive call for the left of center
            privateQuickSort(center+1, right); // recursive call for the right of center
        }

    } 
};