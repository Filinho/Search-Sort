# O(n²) Sort Algorithm

## - Bubble Sort

#### Buble Sort is a sorting algorithm, which works by traversing the vector n times, and in each of them the largest element is placed at the end of the list until it is completely sorted.

```c++
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
```

## - Insertion Sort

```c++
void insertionSort(){
    for(int i = 1; i <size-1; i++){

        int j = i-1;

        DataType  auxdata = list[i];

        while(j>=0 && auxdata <list[j]){
            list[j+1] = list[j];
            j--;
        }

        list[j+1] = auxdata;
    }
}
```

## - Selection Sort

```c++
void selectionSort(){
    for(int i = 0; i <size; i++){
            int min = i;
            for(int j = i +1; j<size;j++){
            if(list[min] >list[j]) min = j;
        }
        swap(i,min);
    }
}
```
