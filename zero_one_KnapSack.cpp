#include<bits/stdc++.h>
using namespace std;

int choice[1005][1005];
int dp[1005][1005];
int n,cap;
int fixedBox,fixedWeight;
struct BOX {
    int coins,weight;
};

BOX b[1005];

int knapSack(int c,int rem,int noOfBoxes){
    if(c==n){
        return 0;
    }
    if(dp[c][rem]!=-1){
        return dp[c][rem];
    }
    int op1=knapSack(c+1,rem,noOfBoxes);
    int op2=0;
    if(b[c].weight<=rem&&b[c].weight<=fixedWeight&&noOfBoxes<=fixedBox){
        noOfBoxes++;
        op2=b[c].coins+knapSack(c+1,rem-b[c].weight,noOfBoxes);
    }
    if(op1>=op2){
        choice[c][rem]=0;
        return dp[c][rem]=op1;
    }
    choice[c][rem]=1;
    return dp[c][rem]=op2;
}

int main(){
    cout<<"Number of box: ";
    cin>>n;
    cout<<"Maximum weight: ";
    cin>>cap;
    cout<<"Coins weight: "<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"th Box: ";
        cin>>b[i].coins>>b[i].weight;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            dp[i][j]=-1;
        }
    }
    cout<<"Maximum weight of a box that can be taken: ";
    cin>>fixedWeight;
    cout<<"Total box that can be taken: ";
    cin>>fixedBox;
    cout<<"Maximum number of Coin: "<<knapSack(0,cap,0)<<endl;
    int box=0;
    int rem=cap;
    cout<<"The box number ";
    while(box!=n){
        if(choice[box][rem]==0){
            box++;
        }
        else{
            cout<<box+1<<" ";
            rem-=b[box].weight;
            box++;
        }
    }
    cout<<"should be taken"<<endl;
}
