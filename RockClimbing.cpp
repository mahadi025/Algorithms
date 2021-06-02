#include<bits/stdc++.h>
using namespace std;

char choice[1005][1005];
int dp[1005][1005];
int arr[1005][1005];
int row,column;

int rockClimbing(int currentRow, int currentColumn){
    if(currentRow==row-1&&currentColumn==column-1){
        return arr[currentRow][currentColumn];
    }
    if(dp[currentRow][currentColumn]!=-1){
        return dp[currentRow][currentColumn];
    }
    if(currentRow==row-1){
        choice[currentRow][currentColumn]='R';
        return arr[currentRow][currentColumn]+rockClimbing(currentRow,currentColumn+1);
    }
    if(currentColumn==column-1){
        choice[currentRow][currentColumn]='D';
        return arr[currentRow][currentColumn]+rockClimbing(currentRow+1,currentColumn);
    }
    int right=arr[currentRow][currentColumn]+rockClimbing(currentRow,currentColumn+1);
    int down=arr[currentRow][currentColumn]+rockClimbing(currentRow+1,currentColumn);
    if(right>down){
        choice[currentRow][currentColumn]='R';
        return dp[currentRow][currentColumn]=right;
    }
    choice[currentRow][currentColumn]='D';
    return dp[currentRow][currentColumn]=down;
}

void path(){
    int cr=0,cc=0;
    rockClimbing(0,0);
    cout<<"Path: ";
    while(cr!=row-1||cc!=column-1){
        if(choice[cr][cc]=='R'){
            cout<<"R ";
            cc++;
        }
        else{
            cout<<"D ";
            cr++;
        }
    }
    cout<<endl;
}

int main(){
    cin>>row>>column;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    path();
    cout<<"Total Coins: "<<rockClimbing(0,0);
}