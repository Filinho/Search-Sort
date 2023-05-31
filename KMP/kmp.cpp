#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int * computeFailureFunction(string pattern){
    int patternLength = size(pattern);
    int auxLength = 0;

    int * FF = new int(patternLength);
    FF[0] = 0;
    
    int i = 1;
    while(i <patternLength){
        if(pattern[i] == pattern[auxLength]){
            auxLength ++;
            FF[i] = auxLength;
            i++;
        }
        else{
            if(auxLength != 0){
                auxLength = FF[auxLength -1];
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
    int * foundArray = new int(1000);
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
int main(){
    int * found = KMP("aba","aabababaabcdeab");
    for(int i = 1; i <= found[0]; i++){
        cout << found[i] << endl;
    }
    
}