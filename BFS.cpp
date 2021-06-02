#include<bits/stdc++.h>
using namespace std;

int INF=10000000;
int dis[10005],parent[10005],n,e;
queue<int>q;
vector<int>adj[1005];

void bfs(int src){
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[src]=0;
    q.push(src);
    parent[src]=src;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(dis[v]==INF){
                dis[v]=dis[u]+1;
                q.push(v);
                parent[v]=u;
            }
        }
    }
}

void pathPrint(int src,int des){
    if(des==src){
        cout<<src<<endl;
        return;
    }
    pathPrint(src,parent[des]);
    cout<<des<<endl;
}

int main(){
    cin>>n>>e;
    int u,v;
    while(e--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src,des;
    cout<<"Source: ";
    cin>>src;
    cout<<"Destination: ";
    cin>>des;
    bfs(src);
    pathPrint(src,des);
}