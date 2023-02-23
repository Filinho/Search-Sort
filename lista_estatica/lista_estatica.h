#include <iostream>

using namespace std;

class Student{
public:
    string Name;
    int Key;
    Student(){
        Name = "Dummy";
        Key = 0;
    }
    Student(string Name, int Key){
        this->Key = Key;
        this->Name = Name;
    }
};
                                 
class StaticList{

public:
    int SizeofList;
    int N_Valid_Element;
    Student * List;
    StaticList(){
        SizeofList = 0;
        N_Valid_Element = 0;
        List = NULL;
    }
    StaticList(int Size){
        this->List = new Student[Size];
        N_Valid_Element = 0;
        SizeofList = Size;
    }
    ~StaticList();
};


