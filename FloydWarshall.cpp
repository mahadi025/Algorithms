#include<bits/stdc++.h>
using namespace std;
#define INF 100000

int dis[10005][10005];
int adj[10005][10005];
int n,e;

void floydWarshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=adj[i][j];
        }
        dis[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    int u,v,w;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adj[i][j];
        }
    }
    floydWarshall();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==INF){
                cout<<"INF ";
            }
            else
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}