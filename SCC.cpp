#include<bits/stdc++.h>
int WHITE =1;
int GREY= 2;
int BlACK= 3;
using namespace std;

vector<int>adj[100005];
vector<int>rev[100005];
stack<int>topOrder;
int col[1000005],revCol[1000005];

void dfs(int u){
  col[u]=GREY;
  for(int i=0;i<adj[u].size();i++){
    int v=adj[u][i];
    if(col[v]==WHITE){
        dfs(v);
    }
  }
  col[u]=BlACK;
  topOrder.push(u);
}
void revDfs(int u,int comp){
  revCol[u]=GREY;
  for(int i=0;i<rev[u].size();i++){
    int v=rev[u][i];
    if(revCol[v]==WHITE){
        revDfs(v,comp);
    }
  }
  revCol[u]=BlACK;
}
int main(){
  int n,e;
  cin>>n>>e;
  for(int i=1;i<=e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }
  for(int i=1;i<=n;i++){
    col[i]=WHITE;
      revCol[i]=WHITE;
  }
  for(int i=1;i<=n;i++){
    if(col[i]==WHITE){
      dfs(i);
    }
  }
  int comp=0;
  while(!topOrder.empty()){
    int top=topOrder.top();
      topOrder.pop();
      if(revCol[top]==WHITE){
        revDfs(top,comp);
        comp++;
      }
  }
  cout<<"Number of SCC: "<<comp<<endl;
}