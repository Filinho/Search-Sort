#include "DoubleLinkedList.h"


int main(){

    using namespace std::chrono;
    using namespace std::chrono;
    
    int menu;
    scanf("%d",&menu);
    LinkedList * l;
    switch(menu){
        case 1:{
            int x;
            l = new LinkedList;
            while(scanf("%d",&x) > 0){
                l->PushBack(Person{rand_name(x%29),x});
            }
            l->printList();
            cout << endl;
            steady_clock::time_point t1 = steady_clock::now();
            l->bubbleSort();
            steady_clock::time_point t2 = steady_clock::now();
            l->printList();
            delete(l);
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            cout <<endl << "Timer = "<< time_span.count()<<endl;
        }break;
        case 2:{
            int tamanho;
            scanf("%d",&tamanho);
            for(int i=0;i<tamanho;i++){
                l = new LinkedList(i);
                steady_clock::time_point t1 = steady_clock::now();
                l->bubbleSort();
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                cout<< time_span.count()<<endl;
                delete(l);   
            }
        }break;
    }

   
}