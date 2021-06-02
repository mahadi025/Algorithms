typedef long long int ll;

void mergeSort(ll arr[],ll n)
{
    if(n==1){
        return;
    }
    ll i,idx=0;
    ll leftSize=n/2;
    ll rightSize=n-leftSize;
    ll left[leftSize],right[rightSize];
    for(i=0;i<leftSize;i++){
        left[i]=arr[i];
    }
    for(i=leftSize;i<n;i++){
        right[i-leftSize]=arr[i];
    }
    mergeSort(left,leftSize);
    mergeSort(right,rightSize);
    int leftMarker=0,rightMarker=0;
    while(leftMarker<leftSize&&rightMarker<rightSize){
        if(left[leftMarker]<=right[rightMarker]){
            arr[idx]=left[leftMarker];
            idx++;
            leftMarker++;
        }
        else{
            arr[idx]=right[rightMarker];
            idx++;
            rightMarker++;
        }
    }
    while(leftMarker<leftSize){
        arr[idx]=left[leftMarker];
        idx++;
        leftMarker++;
    }
    while(rightMarker<rightSize){
        arr[idx]=right[rightMarker];
        idx++;
        rightMarker++;
    }
}
