#include <bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
#define SIZE 100105
using namespace std;

vector <int> adj[SIZE];
int d[SIZE], low[SIZE], par[SIZE];
int col[SIZE];
int timeCOunter=0,cnt=0;

void dfs(int p, bool isRoot,int parent){
    timeCOunter++;
    d[p]=timeCOunter;
    low[p]=timeCOunter;
    col[p]=GREY;
    int c;
    int childCount=0;
    bool isArticulationPoint=false;
    for(int i=0; i<adj[p].size(); i++){
        c=adj[p][i];
        if(col[c]==WHITE){
            dfs(c, false,p);
            if(d[p]<low[c]){
                cout<<p<<"--"<<c<<" is a Bridge"<<endl;
                cnt++;
            }
            if(low[c]<low[p]){
                low[p]=low[c];
            }
        }
        if(col[c]==GREY&&c!=parent){
            if(d[c]<low[p]){
                low[p]=d[c];
            }
        }
    }
    col[p]=BLACK;
}

int main(){
    int n, e, u, v;
    cin>>n>>e;
    while(e--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(col[i]==WHITE){
            dfs(i, true,-1);
        }
    }
    cout<<"Number of Bridge: "<<cnt<<endl;
}
