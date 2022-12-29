#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    int roll;
    float key;
    float sgpa;
    string name;
    string kname;
    int res;

    void getdata(){
        cout<<"Enter Roll no.: "<<endl;
        cin>>roll;
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter SGPA: "<<endl;
        cin>>sgpa;
    }
    
    void display(student s[], int n ){
        for(int i=0;i<n;i++){
            cout<<"Roll no: "<<s[i].roll<<endl;
            cout<<"Name: "<<s[i].name<<endl;
            cout<<"SGPA: "<<s[i].sgpa<<endl;
            cout<<endl;
        }
    }

    // linearsearch on sgpa
    void linearSearch(student s[], int n){
        int key;
        cout<<"Enter the sgpa to be searched : ";
        cin>>key;
        int cnt=0;
        cout<<endl;
        for(int i=0;i<n;i++){
            if(s[i].sgpa==key){
                cout<<"Roll no: "<<s[i].roll<<endl;
                cout<<"Name: "<<s[i].name<<endl;
                cout<<"SGPA: "<<s[i].sgpa<<endl;
                cout<<endl;
                cnt++;
            }
        }
        if(cnt==0){
                cout<<"Not Found"<<endl;
            }
    }

    //binarysearch on name
    int binarySearch( student s[],int n){
        int f,e,mid;
        string kname;
        cout<<"Enter name of student"<<endl;
        cin>>kname;
        f=0;
        e=n-1;
        mid=(f+e)/2;
        while(f<=e){
            mid=(f+e)/2;
            if(s[mid].name==kname){
                res=mid;
                return res;
            }
            else if(s[mid].name>kname){
                e=mid-1;
            }
            else if(s[mid].name<kname){
                f=mid+1;
            }
        }
        return res=-1;
    }
    void displaybinary(student s[],int n){
        cout<<"Searched Student is"<<endl;
        cout<<"Roll no: "<<s[res].roll<<endl;
        cout<<"Name: "<<s[res].name<<endl;
        cout<<"SGPA: "<<s[res].sgpa<<endl;
        cout<<endl;
    }

    // bubble sort on roll number
    void bubbleSort(student s[], int n){
        int temp;
        cout<<"Sorted List according to roll no. : "<<endl;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(s[j].roll>s[j+1].roll){
                    temp=s[j].roll;
                    s[j].roll=s[j+1].roll;
                    s[j+1].roll=temp;
                }
                
            }
        }
        for(int x=0;x<n;x++){
            cout<<"Roll no: "<<s[x].roll<<endl;
            cout<<"Name: "<<s[x].name<<endl;
            cout<<"SGPA: "<<s[x].sgpa<<endl;
            cout<<endl;
        }
    }

    //insertion sort on names
    void insertionSort(student s[], int n){
        string temp;
        cout<<"Sorted List according to names : "<<endl;
        
            for(int k=1;k<n;k++){
                temp=s[k].name;
                int t=k-1;
                while(s[t].name>temp && t>=0){
                    s[t+1].name=s[t].name;
                    t--;
                }
                s[t+1].name=temp;
            }
        
         for(int x=0;x<n;x++){
            cout<<"Roll no: "<<s[x].roll<<endl;
            cout<<"Name: "<<s[x].name<<endl;
            cout<<"SGPA: "<<s[x].sgpa<<endl;
            cout<<endl;
        }
    }

    //quicksort on sgpa
    int partition(student s[],int l , int h){
        int pivot= s[l].sgpa;
        int start = l;
        int end = h;
        while(start<end){
            while(s[start].sgpa<=pivot){
                start++;
            }
            while(s[end].sgpa>pivot){
                end--;
            }
            if(start<end){
                swap(start,end);
            }
        }
        swap(l,end);
        return end;
    }

    void quickSort(student s[], int l , int h){
         if(l<h){
            int loc=partition(s,l,h);
            quickSort(s,l,loc-1);
            quickSort(s,loc+1,h);
        }
    }

    void displayquick(student s[],int n){
    int num;
    cout<<"NO. OF TOPPERS YOU REQUIRE";
    cin>>num;
    cout<<"Toppers of the class are\n";
    for(int i=n-1;i>=n-num;i--){
        cout<<"Roll no: "<<s[i].roll<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"SGPA: "<<s[i].sgpa<<endl;
        cout<<endl;
    }
}

};

int main(){
    int n;
    cout<<"Enter the number of students: "<<endl;
    cin>>n;
    student s[n],s1;
    int ans;
    for(int i=0;i<n;i++){
        s[i].getdata();
    }
    do{
        cout<<"Menu: "<<endl;
        cout<<"1.Linear Search \n2.Binary Search \n3.Bubble sort \n4.Insertion sort \n5.Quick sort \n6.Display"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                s1.linearSearch(s,n);
                break;

            case 2:
                int res;
                if(s1.binarySearch(s,n)==-1){
                    cout<<"Not Found"<<endl;
                }
                else{
                    s1.binarySearch(s,n);
                    s1.displaybinary(s,n);
                }
                break;

            case 3:
                s1.bubbleSort(s,n);
                break;

            case 4:
                s1.insertionSort(s,n);
                break;

            case 5:
                s1.quickSort(s,0,n-1);
                s1.displayquick(s,n);
                break;
        }
        cout<<"To continue press 1 else 0"<<endl;
        cin>>ans;
    }while(ans);
    return 0;
}

