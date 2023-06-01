# nLog(n) Sort Algorithm

## - Quick Sort

#### - (Auxiliar) Partition

```c++
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
```

#### QuickSort

```c++
void quickSort(int left, int right){

    if(left < right){
        int center = partition(left, right);// function that define the center
        privateQuickSort(left, center-1); // recursive call for the left of center
        privateQuickSort(center+1, right); // recursive call for the right of center
    }

}   
}
```

## - Merge Sort

#### - (Auxiliar) Merge

```c++
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
```

#### Merge Sort

```c++
void mergeSort(const int left, const int right, StaticList* auxL){

    if(left < right-1){
        int mid = (left+right)/2;
        auxL->rec_mergesort(left, mid, this);
        auxL->rec_mergesort(mid, right, this);
        auxL->merge(left, mid, right, this);
    }
}

```
