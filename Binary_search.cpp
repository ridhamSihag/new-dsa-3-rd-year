#include <bits/stdc++.h>
using namespace std;
class BS{
    int* arr;
    int n;
public:
    BS(int a[], int size){
        arr = a;
        n = size;
    }
    int binarysearch(int key){
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] > key){
                high = mid-1;

            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }


};
int main(){
    int n;
    cout<<"enter number of element in array";
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i<n; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;

    BS obj(arr,n);
    int key;
    cin>>key;
    int result = obj.binarysearch(key);
    if(result == -1){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found at index"<<result;
    }


}
    
