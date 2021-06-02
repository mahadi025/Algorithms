//including mid point
#include<iostream>
#include<tuple>
using namespace std;

tuple<int,int,int> maxCrossingSubArray(int arr[],int low,int mid,int high)
{
    int leftSum=-100000,rightSum=-1000000,i,j,sum=0,maxLeft,maxRight;
    for(i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>leftSum){
            leftSum=sum;
            maxLeft=i;
        }
    }
    sum=0;
    for(j=mid+1;j<high;j++){
        sum+=arr[j];
        if(sum>rightSum){
            rightSum=sum;
            maxRight=j;
        }
    }
    return{maxLeft,maxRight,leftSum+rightSum};
}

tuple<int,int,int>maxSubArray(int arr[],int low,int high)
{
    tuple<int,int,int>tmp1,tmp2,tmp3;
    int mid,leftLow,leftHigh,leftSum,rightLow,rightHigh,rightSum,crossLow,crossHigh,crossSum;
    if(high==low){
        return{low,high,arr[low]};
    }
    else{
        mid=(low+high)/2;
        tmp1=maxSubArray(arr,low,mid);
        leftLow=get<0>(tmp1);
        leftHigh=get<1>(tmp1);
        leftSum=get<2>(tmp1);
        tmp2=maxSubArray(arr,mid+1,high);
        rightLow=get<0>(tmp2);
        rightHigh=get<1>(tmp2);
        rightSum=get<2>(tmp2);
        tmp3=maxCrossingSubArray(arr,low,mid,high);
        crossLow=get<0>(tmp3);
        crossHigh=get<1>(tmp3);
        crossSum=get<2>(tmp3);
        if(leftSum>=rightSum&&leftSum>=crossSum){
            return{leftLow,leftHigh,leftSum};
        }
        else if(rightSum>=leftSum&&rightSum>=crossSum){
            return{rightLow,rightHigh,rightSum};
        }
        else{
            return{crossLow,crossHigh,crossSum};
        }

    }
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    tuple<int,int,int>result=maxSubArray(arr,0,n-1);
    cout<<get<0>(result)<<" "<<get<1>(result)<<" "<<get<2>(result)<<endl;;
}