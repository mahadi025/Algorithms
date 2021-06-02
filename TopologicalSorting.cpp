#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define BLACK 1
#define GREY 2

vector<int>adj[10005];
vector<int>topOrder;
int col[10005];
int n,e;
bool hasCycle=false;
void dfs(int u){
    col[u]=GREY;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(col[v]==WHITE){
            dfs(v);
        }
        if(col[v]==GREY){
            hasCycle=true;
            break;
        }
    }
    col[u]=BLACK;
    topOrder.push_back(u);
}

bool isEdge(int u,int v){
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i]==v){
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n>>e;
    int flag=1;
    for(int i=0;i<=n;i++){
        col[i]=WHITE;
    }
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(col[i]==WHITE){
            dfs(i);
        }
    }
    if(hasCycle){
        cout<<"Graph is not sorted in topological order"<<endl;
    }
    else{
        reverse(topOrder.begin(),topOrder.end());
        cout<<"Topological Order: ";
        for(int i=0;i<topOrder.size();i++){
            cout<<topOrder[i]<<" ";
        }
        for(int i=0;i<n-1;i++){
            bool isUn=isEdge(topOrder[i],topOrder[i+1]);
            if(!isUn){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"Unique"<<endl;
    }
        else{
            cout<<"Not Unique"<<endl;
        }
    }
        cout<<endl;
    
}