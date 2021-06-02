#include<bits/stdc++.h>

std::vector<int>dp(1005,-1);

int fibonacci(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return dp[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<fibonacci(n);
}