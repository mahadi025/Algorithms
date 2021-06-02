#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll binarySearch(ll arr[],ll n,ll target)
{
    ll high=n-1;
    ll low=0;
    ll mid;
    while(high>=low){
        mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main()
{
    ll n,i,x;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    cout<<binarySearch(arr,n,x)<<endl;
    
}
