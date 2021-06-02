#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
char w1[1005],w2[1005];
int l1,l2;
char choice[1005][1005];
int rep=0,del=0,ins=0;

int editDistance(int p1,int p2){
    if(p1==l1){
        return l2-p2;
    }
    if(p2==l2){
        return l1-p1;
    }
    if(dp[p1][p2]!=-1){
        return dp[p1][p2];
    }
    if(w1[p1]==w2[p2]){
        return editDistance(p1+1,p2+1);
    }
    ins=1+editDistance(p1,p2+1);
    rep=1+editDistance(p1+1,p2+1);
    del=1+editDistance(p1+1,p2);
    if(ins<=rep&&ins<=del){
        return dp[p1][p2]=ins;
    }
    else if(rep<=ins&&rep<=del){
        return dp[p1][p2]=rep;
    }
    return dp[p1][p2]=del;
}

int main(){
    cin>>w1>>w2;
    l1=strlen(w1);
    l2=strlen(w2);
    for(int i=0;i<11;i++){
        for(int j=0;j<l2;j++){
            dp[i][j]=-1;
        }
    }
    cout<<"Number of edit: "<<editDistance(0,0)<<endl;
}