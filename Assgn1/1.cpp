#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int low=0, high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        } 
        else if(arr[mid]<target) {
        low=mid+1;
        }
        else {
        high=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=23;
    int index=binarySearch(arr,n,target);
    if(index!=-1) cout<<"Target "<<target<<" found at index "<<index<<endl;
    else cout<<"Target "<<target<<" not found"<<endl;
}
