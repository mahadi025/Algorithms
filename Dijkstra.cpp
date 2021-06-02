#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

struct element{
    int node=0, weight=0;
    element(){}

    element(int n, int w){
        node=n;
        weight=w;
    }
    bool operator <(const element &a)const{
        return weight<a.weight;
    }
    bool operator >(const element &a)const{
        return weight>a.weight;
    }
};

priority_queue <element, vector <element>, greater <element> > pq;
int dis[1000005];
bool vis[1000005];
vector <int> adj[10000005];
vector <int> adjW[10000005];
int n, e;
void init(int source){
    for(int i=1; i<=n; i++){
        dis[i]=INF;
        vis[i]=false;
    }
    dis[source]=0;
}

void dijkstra(int source){
    init(source);
    pq.push(element(source, 0));
    int u, v;
    while(!pq.empty()){
        u=pq.top().node;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0; i<(int)adj[u].size(); i++){
            v=adj[u][i];
            if(dis[v]>dis[u]+adjW[u][i]){
                dis[v]=dis[u]+adjW[u][i];
                pq.push(element(v, dis[v]));
            }
        }
    }
}
int main(){
    int u,v,w;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjW[u].push_back(w);
        adjW[v].push_back(w);
    }
    int src;
    cout<<"Source: ";
    cin>>src;
    dijkstra(src);
    cout<<"Shortest Distance form "<<src<<" to "<<n<<" is "<<dis[n]<<endl;
}
