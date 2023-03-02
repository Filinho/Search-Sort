#include "DoubleLinkedList.h"

int main(){

    using namespace std::chrono;
    using namespace std::chrono;
    

    LinkedList * l = new LinkedList(10);
    l->printList();
    cout << endl;
    steady_clock::time_point t1 = steady_clock::now();
    l->bubbleSort();
    steady_clock::time_point t2 = steady_clock::now();
    l->printList();
    delete(l);
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout <<endl << "Timer = "<< time_span.count()<<endl;
}