//
// Created by mingmeng on 2020/2/27.
//
int partition(int *arr,int left,int right){
    int p=arr[left],i=left,j=right;
    while (i<j){
        while (arr[j]>=p&&i<j)
            j--;
        while (arr[i]<=p&&i<j)
            i++;
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    int temp=arr[left];
    arr[left]=arr[i];
    arr[i]=temp;
    return i;
}

void fastSort(int *arr,int left,int right ){
    if(left<right){
        int index=partition(arr,left,right);
        fastSort(arr,left,index-1);
        fastSort(arr,index+1,right);
    }
}



