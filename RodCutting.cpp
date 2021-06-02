#include<bits/stdc++.h>
using namespace std;

int dp[10005];
int price[10005];
int sell[10005];

int rodCutting(int len){
    if(len==0){
        return 0;
    }
    if(dp[len]!=-1){
        return dp[len];
    }
    int max=price[len];
    int sellingLength=len;
    int value;
    for(int i=1;i<len-1;i++){
        value=price[i]+rodCutting(len-i);
        if(value>max){
            max=value;
            sellingLength=i;
        }
    }
    sell[len]=sellingLength;
    return dp[len]=max;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<"Maximum outcome: "<<rodCutting(n)<<endl;
    cout<<"Rods should sold with length: ";
    int rem=n;
    while(rem!=0){
        cout<<sell[rem]<<" ";
        rem=rem-sell[rem];
    }
    cout<<endl;
}