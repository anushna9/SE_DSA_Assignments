#include <bits/stdc++.h>
using namespace std;

//MAX Heap
void heapify_maxheap(int arr[], int n , int i ){
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1 ;

    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify_maxheap(arr,n,largest);
    }
}

//MIN Heap
void heapify_minheap(int arr[], int n , int i ){
    int smallest = i;
    int l = 2*i;
    int r = 2*i + 1 ;

    if(l<n && arr[l]<arr[smallest]){
        smallest=l;
    }
    if(r<n && arr[r]<arr[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify_maxheap(arr,n,smallest);
    }
}

void display(int arr[], int n){
    cout<<"sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Creation of heap and display
void heapSort(){
    int n;
    cout<<"enter the no. of elements"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int t=1;
    while(t==1){
        cout<<"Menu: "<<endl;
        cout<<"1.Max Heap \n2.Min Heap \n3.Exit"<<endl;
        cout<<"your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:{
                for(int i=n/2;i>=1;i--){
                    heapify_maxheap(a,n,i);
                }
                for(int i=n;i>=1;i--){
                    swap(a[1],a[i]);
                    heapify_maxheap(a,i-1,1);
                }
                display(a,n);
            }
            break;
            case 2:{
                for(int i=n/2;i>=1;i--){
                    heapify_minheap(a,n,i);
                }
                for(int i=n;i>=1;i--){
                    swap(a[1],a[i]);
                    heapify_minheap(a,i-1,1);
                }
                display(a,n);
            }
        }
        cout<<"to continue press 1 else press 0"<<endl;
        cin>>t;
        if(t==0){
            cout<<"-------------Program ends-------------"<<endl;
            break;
        }
    }
}

int main(){
    heapSort();
}