#include<bits/stdc++.h>
using namespace std;
#define GREY 0
#define WHITE 1
#define BLACK 2
int col[1005];
int d[1005];
int f[1005];
int t;
vector<int>adj[1005];
void dfs(int u){
    col[u]=GREY;
    t++;
    d[u]=t;
    int v;
    for(int i=0;i<adj[u].size();i++){
        v=adj[u][i];
        if(col[v]==WHITE){
            cout<<u<<" --> "<<v<<" Tree edge"<<endl;
            dfs(v);
        }
        else if(col[u]==GREY&&col[v]==GREY){
            cout<<u<<" --> "<<v<<" Back edge"<<endl;
        }
        else{
            if(d[u]<d[v]){
                cout<<u<<" --> "<<v<<" Forward edge"<<endl;
            }
            else{
                cout<<u<<" --> "<<v<<" Cross edge"<<endl;
            }
        }
    }
    col[u]=BLACK;
    t++;
    f[u]=t;
}

int main(){
    int n,e;
    cin>>n>>e;
    int u,v;
    for(int i=0;i<=n;i++){
        col[i]=WHITE;
        d[i]=0;
    }
    while(e--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
}