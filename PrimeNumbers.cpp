#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isPrime[100005];
ll sum=0;

void prime(ll n)
{
    ll i,j;
    isPrime[0]=isPrime[1]=false;
    for(i=2;i<=n;i++){
        isPrime[i]=true;
    }
    for(i=2;i<sqrt(n);i++){
        if(isPrime[i]){
            for(j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

int main()
{
    ll n,i;
    cin>>n;
    prime(n);
    for(i=0;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
     for(i=0;i<=n;i++){
        if(isPrime[i]){
           sum+=i;
        }
    }
    cout<<sum<<endl;
}