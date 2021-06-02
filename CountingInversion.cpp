#include<iostream>
using namespace std;
typedef long long int ll;
ll cnt=0;
void mergeSort(ll arr[],ll n)
{
    if(n==1){
        return;
    }
    ll i,idx=0;
    ll leftSize=n/2;
    ll rightSize=n-leftSize;
    ll left[leftSize],right[rightSize];
    for(i=0;i<leftSize;i++){
        left[i]=arr[i];
    }
    for(i=leftSize;i<n;i++){
        right[i-leftSize]=arr[i];
    }
    mergeSort(left,leftSize);
    mergeSort(right,rightSize);
    int leftMarker=0,rightMarker=0;
    while(leftMarker<leftSize&&rightMarker<rightSize){
        if(left[leftMarker]<=right[rightMarker]){
            arr[idx]=left[leftMarker];
            idx++;
            leftMarker++;
        }
        else{
            arr[idx]=right[rightMarker];
            idx++;
            rightMarker++;
            cnt+=leftSize-leftMarker;
        }
    }
    while(leftMarker<leftSize){
        arr[idx]=left[leftMarker];
        idx++;
        leftMarker++;
    }
    while(rightMarker<rightSize){
        arr[idx]=right[rightMarker];
        idx++;
        rightMarker++;
    }
}

int main()
{
    ll i,n;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,n);
    cout<<cnt<<endl;
}
