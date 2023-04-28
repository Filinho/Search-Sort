#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int array[]={1,2,3,4,5,6,7,8,9};
    int sz = 9;

    int h = log(sz);
    int k =0;
    for(int i = 0; k <=sz || h > i;i++){
        int n_ele = (int) pow(2,i);
        for(int j = 0 ; j < h*(sz-i)-i; j++){
            cout << " ";
        }
        int j;
        for(j = k; j < n_ele && j < sz ;j++){
            cout<< array[j];
            cout << "     ";
        }
        k = j;
        cout <<endl;
    }

}