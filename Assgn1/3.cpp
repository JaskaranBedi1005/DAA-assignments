#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int index=s+cnt;
    swap(arr[s],arr[index]);
    int i=s,j=e;
    while(i<index && j>index){
        while(arr[i]<arr[index]){
            i++;
        }
        while(arr[j]>arr[index]){
            j--;
        }
        if(i<index && j>index){
            swap(arr[i++],arr[j--]);
        }
    }
    return index;
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

}
int main(){
      int arr[]={4,2,6,9,2};
      int n=sizeof(arr)/sizeof(arr[0]);
      quicksort(arr,0,n-1);
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }
return 0;}