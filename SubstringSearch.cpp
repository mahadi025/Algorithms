#include <bits/stdc++.h>
using namespace std;

void find(string text,string pattern)
{
    int i,j;
    for(i=0;text[i]!='\0';i++){
        int matched=1;
        for(j=0;pattern[j]!='\0';j++){
            if(text[i+j]!=pattern[j]){
                matched=0;
                break;
            }
        }
        if(matched==1){
            cout<<"Match found from index "<<i<<endl;
        }
    }
}

int main()
{
    //Can also be done using char[]
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    find(text,pattern);
}
