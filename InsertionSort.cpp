#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}