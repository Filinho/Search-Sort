#include<cstring>
#include<iostream>
#include<string>
#include <string.h>

using namespace std;

    int * computeFailureFunction(string pattern){
    int patternLength = size(pattern);
    int aux = 0;

    int * FF = new int(patternLength); 
    FF[0] = 0; 
    
    int i = 1;
    while(i <patternLength){
        if(pattern[i] == pattern[aux]){
            aux ++;
            FF[i] = aux;
            i++;
        }
        else{
            if(aux != 0){
                aux = FF[aux -1];
            }
            else{
                FF[i] = 0;
                i++;
            }
        }
    }
    return FF;
}

int * KMP(string pattern, string txt){
    int * foundArray = new int(size(txt)+1);
    foundArray[0] = 0;
    int patternLength = size(pattern);
    int txtLength = size(txt);

    int * FF = computeFailureFunction(pattern);

    int txtIndex = 0;
    int patternIndex = 0;

    while((patternLength - patternIndex) <= (txtLength - txtIndex)){
        if(pattern[patternIndex] == txt[txtIndex]){
            ++txtIndex;
            ++patternIndex;
        }

        if(patternIndex == patternLength){
            ++foundArray[0];
            foundArray[foundArray[0]] = txtIndex - patternIndex;

            patternIndex = FF[patternIndex -1];
        }
        else if(txtIndex < txtLength && pattern[patternIndex] != txt[txtIndex]){
            if(patternIndex != 0) patternIndex = FF[patternIndex-1];
            else ++txtIndex;
        }
    }
    return foundArray;
}

void printtext(int * found, char * txt,int size_txt,  int sz_pattern){
    
    int buff_index = 1;
    int aux = -1;
     
    for(int i = 0; i<= size_txt ;i++){
        if(i == found[buff_index]){
            aux = i + sz_pattern;
            buff_index++;
        }
        if( i<aux) cout<< "\e[31;10m" << txt[i] << "\e[m";
        
        else cout<< "\e[64;10m" << txt[i] << "\e[m";
    }

    cout<<endl<<endl;
}
int main(){

    string pattern,txt;
    cin >> pattern;
    cin >>txt;
    
    int * found = KMP(pattern,txt);
    cout<< "found adresses : ";
    for(int i = 1; i <= found[0]; i++){
        if(i!=1) cout << ", ";
        cout<<found[i];
    }
    

    char *aux = &txt[0];
    cout << ";"<< endl<< "pattern : " << pattern<<endl;
    printtext(found,aux,size(txt),size(pattern));
    delete(found);
    
}