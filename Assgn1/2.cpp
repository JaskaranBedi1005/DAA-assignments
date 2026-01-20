#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int m=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[m++];
    }
    m=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[m++];
    }
    int index1=0;
    int index2=0;
    m=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[m++]=first[index1++];
        }
        else{
            arr[m++]=second[index2++];
        }
    }
    while(index1<len1){
         
            arr[m++]=first[index1++];
     
    }
    while(index2<len2){
      
            arr[m++]=second[index2++];
       
    }
}
void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;}
        int mid=(s+e)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,e);
}
int main(){
     int arr[]={12,11,13,5,6,7};
     int n=sizeof(arr)/sizeof(arr[0]);
     mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int arr2[]={38,27,43,3,9,82,10};
    int m=sizeof(arr2)/sizeof(arr2[0]);
        mergeSort(arr2,0,m-1);
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
return 0;}