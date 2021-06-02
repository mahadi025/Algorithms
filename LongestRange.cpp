#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   int r=0,l=0,sum=0,limit=0,max=-1;
   cin>>limit;
   while(r<n){
       sum+=arr[r];
       while(sum>limit){
           sum-=arr[l];
           l++;
       }
       if(r-l+1>max){
           max=r-l+1;
       }
       r++;
   }
   cout<<max<<endl;
}