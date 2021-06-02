#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll sumOfMaximumSubArray(ll arr[],ll n)
{
    ll max=arr[0];
    ll isAllNegative=1,sum=0,i;
    for(i=0;i<n;i++){
        if(arr[i]>=0){
            isAllNegative=0;
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    if(isAllNegative){
        return max;
    }
    for(i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0){
            sum=0;
        }
        if(sum>max){
            max=sum;
        }
    }
    return max;
}

int main()
{
    ll n,i;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sumOfMaximumSubArray(arr,n)<<endl;
}