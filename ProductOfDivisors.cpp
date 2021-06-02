#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll pod[10000005];

void productOfDivisors(ll n)
{
    ll i,j;
    for(i=1;i<=n;i++){
        pod[i]=1;
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            pod[j]*=i;
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    productOfDivisors(n);
    cout<<pod[n]<<endl;
}