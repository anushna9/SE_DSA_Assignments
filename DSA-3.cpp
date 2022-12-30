#include <bits/stdc++.h>
using namespace std;

//ENQUEUE
void enqueue(int queue[], int x , int n , int &f , int &r){
    if(f==-1 && r==-1){
        f=0;
        r=0;
        queue[r]=x;
    }
    else if((r+1)%n==f){
        cout<<"Queue is full"<<endl;
    }
    else{
        r=(r+1)%n;
        queue[r]=x;
    }
}

//DEQUEUE
void dequeue(int queue[], int n , int &f , int &r){
    if(f==-1 && r==-1){
        cout<<"Queue is empty"<<endl;
    }
    else if(f==r){
        f=-1;
        r=-1;
        cout<<"Deleted number is: "<<queue[f]<<endl;
    }
    else{
        cout<<"Deleted number is: "<<queue[f]<<endl;
        f=(f+1)%n;
    }
}

//DISPLAY
void display(int queue[], int n, int &f , int &r ){
    int cnt=f;
    if(f==-1 && r==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is: ";
        while(cnt!=r){
            cout<<queue[cnt]<<" ";
            cnt=(cnt+1)%n;
        }
        cout<<queue[r];
    }
}


int main(){
    int n;
    cout<<"Enter the length of Queue"<<endl;
    cin>>n;
    int queue[n];
    int f=-1;
    int r=-1;
    int t=1;
    while(t==1){
        cout<<"Menu: "<<endl;
        cout<<"1.Enqueue \n2.Dequeue \n3.Display \n4.Exit"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
                int x;
                cout<<"Enter the value you want to add: ";
                cin>>x;
                cout<<endl;
                enqueue(queue,x,n,f,r);
                break;

            case 2:
                dequeue(queue,n,f,r);
                break;

            case 3:
                display(queue,n,f,r);
                break;
            
            case 4: 
                break;

            default:
            cout<<"Invalid choice"<<endl;
        }
        cout<<"If u want to continue press 1 else press 0";
        cin>>t;
        if(t==0){
            cout<<"-------------Program ends-------------"<<endl;
            break;
        }

    }
}
