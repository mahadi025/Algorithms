#include<bits/stdc++.h>
using namespace std;

struct edge{
    int a,b,w;
};
int par[1000005],sz[1000005];
edge arr[200005];
void init(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
}
int findRoot(int u){
    if(par[u]==u) return u;
    return findRoot(par[u]);
}
int merge(int a,int b){
    a=findRoot(a);
    b=findRoot(b);
    if(a==b){
        return 0;
    }
    if(sz[a]>sz[b]){
       par[b]=a;
       sz[a]+=sz[b];
    }
    else{
        par[a]=b;
        sz[b]+=sz[a];
    }
    return 1;
}
bool compare(edge a, edge b){
    return a.w>b.w;
}
int maximumSpanningTree(int v, int e){
    int sum=0;
    init(v);
    sort(arr,arr+e,compare);
    for(int i=0;i<e;i++){
        if(merge(arr[i].a,arr[i].b)==1){
            sum+=arr[i].w;
        }
    }
    return sum;
}
int main(){
    int v,e,a,b,w,sum=0;
    cin>>v>>e;
    init(v);
    for(int i=0;i<e;i++){
        cin>>a>>b>>w;
        arr[i]={a,b,w};
    }
    cout<<maximumSpanningTree(v,e)<<endl;
}