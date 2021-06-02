#include <bits/stdc++.h>
using namespace std;

long long hashcreate(string str ,long long b,long long m)
{
    long long  i,res=0;
    for(i=0;str[i]!='\0';i++){
        res*=b;
        res%=m;
        res+=str[i]-'a'+1;
        res%=m;
    }
    return res;
}

int main()
{
    string str;
    long long  b,m;
    cin>>str>>b>>m;
    cout<<hashcreate(str,b,m)<<endl;
}