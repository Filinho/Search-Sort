#include "DoubleLinkedList.h"

void timerBuble(LinkedList &l){
    using namespace std::chrono;
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    l.bubbleSort();
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout<< time_span.count()<<endl;
}
int main(){
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
            cout<<endl;
            timerBuble(*l);
            l->printList();
            delete(l);
        }break;
        case 2:{
            int tamanho;
            scanf("%d",&tamanho);
            for(int i=0;i<tamanho;i++){
                l = new LinkedList(i);
                timerBuble(*l);
                delete(l);   
            }
        }break;
    }
}