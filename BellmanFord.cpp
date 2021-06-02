#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000
vector<int>adj[10005];
vector<int>adjW[10005];
int dis[10005];
int n,e;

bool negCycle=false;
void init(int s){
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
}
void bellmanFord(int s){
    init(s);
    int v,w;
    for(int i=1;i<n;i++){
        for(int u=1;u<=n;u++){
            for(int j=0;j<adj[u].size();j++){
                v=adj[u][j];
                w=adjW[u][j];
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }
    }
    for(int u=1;u<=n;u++){
        for(int j=0;j<adj[u].size();j++){
            v=adj[u][j];
            w=adjW[u][j];
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                negCycle=true;
            }
        }
    }
}
int main(){
    int u,v,w;
    cin>>n>>e;
    while(e--){
        cin>>u>>v>>w;
        adj[u].push_back(v);
        //adj[v].push_back(u);
        adjW[u].push_back(w);
        //adjW[v].push_back(u);
    }
    bellmanFord(1);
    if(negCycle){
        cout<<"There is no shortest path"<<endl;
    }
    cout<<dis[n]<<endl;
}