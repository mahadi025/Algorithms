#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n],i,pivot,mark;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(pivot=0;pivot<n;pivot++){
        mark=pivot;
        for(i=pivot+1;i<n;i++){
            if(arr[i]<arr[mark]){
                mark=i;
            }
        }
        if(mark!=pivot){
            swap(arr[mark],arr[pivot]);
        }
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
