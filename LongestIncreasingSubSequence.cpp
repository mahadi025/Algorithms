#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005],arr[1005],n;

int longestIncreaseSubsequence(int idx,int lastIndex){
    if(idx==n)return 0;
    if(dp[idx][lastIndex+1]!=-1)return dp[idx][lastIndex+1];
    if(lastIndex==-1||arr[idx]>arr[lastIndex]){
        int op1=1+longestIncreaseSubsequence(idx+1,idx);
        int op2=longestIncreaseSubsequence(idx+1,lastIndex);
        if(op1>op2){
            return dp[idx][lastIndex+1]=op1;
        }
        return dp[idx][lastIndex+1]=op2;
    }
    else return dp[idx][lastIndex+1]=longestIncreaseSubsequence(idx+1,lastIndex);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<longestIncreaseSubsequence(0,-1)<<endl;
}