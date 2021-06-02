#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll nod[10000005];

void numberOfDivisors( ll n)
{
    ll i,j;
    for(i=1;i<=n;i++){
        nod[i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            nod[j]++;
        }
    }
}

int main()
{
    ll n,i;
    cin>>n;
    numberOfDivisors(n);
    cout<<nod[n]<<endl;
}