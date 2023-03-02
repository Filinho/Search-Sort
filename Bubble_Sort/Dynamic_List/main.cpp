#include "DoubleLinkedList.h"

int main(){

    using namespace std::chrono;
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();

    LinkedList * l = new LinkedList(1000);
    l->printList();
    cout << endl;
    l->bubbleSort();
    l->printList();
    delete(l);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << time_span.count();
}