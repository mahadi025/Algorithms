#include<iostream>
using namespace std;

int fastExp(int n,int k)
{
    if(k==0){
        return 1;
    }
    if(k==1){
        return n;
    }
    int val=fastExp(n,k/2);
    if(k%2==0){
        return val*val;
    }
    return val*val*n;
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<fastExp(n,k);
}
