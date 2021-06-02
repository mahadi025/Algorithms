#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;
ll sod[10000005];

ll nod[10000005];


void sumOfDivisors(ll n)
{
    ll i,j;
    for(i=1;i<=n;i++){
        sod[i]=0;
        nod[i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            sod[j]+=i;
            nod[j]++;
        }
        cout<<nod[i]<<" "<<sod[i]<<endl;
    }
}
int main()
{
    ll n;
    cin>>n;
    sumOfDivisors(n);
    //cout<<sod[n];
}