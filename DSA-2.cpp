#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    struct node *next;
};
class Stack{
    public:
        node *top;
        Stack(){
            top=NULL;
        }
    node create(int x){
        node *p;
        p=new node;
        p->data=x;
        p->next=NULL;
        return *p;
    }
    void push(char x){
        node *newnode;
        newnode=new node;
        *newnode=create(x);
        if(top==NULL){
            top=newnode;
            return;
        }
        newnode->next=top;
        top=newnode;
        return;
    }
    char pop(){
        if(top==NULL){
            cout<<"Stack is empty!!"<<endl;
            return 1;
        }
        node *temp;
        temp=top;   
        top=top->next;
        return temp->data;
    }
    void display(){
        node *temp;
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl<<endl;
    }
    bool empty(){
    	return top==NULL;
    }
    char topElement(){
    	return top->data;
    }

};

int preferance(char x){
	if(x=='*'){
        return 4;
    }
	else if(x=='/'){
        return 3;
    }
	else if(x=='+'){
        return 2;
    }
    else if(x=='-'){
        return 1;
    }
	else{
        return 0;
    }
}
int evalution(int a,int b,char x){
    if(x=='*'){
        return b*a;
    }
    else if(x=='/'){
        return b/a;
    }
    else if(x=='+'){
        return b+a;
    }
    else if(x=='-'){
        return b-a;
    }
}
string infix_to_postfix(string infix){
    Stack s;
    int j=0;
    char x,y;
    string str;
    char postfix[infix.length()];
    for(int i=0;i<infix.length();i++){
        x=infix[i];
        if(isalnum(x)){
            postfix[j]=x;
            j++;
        }
        else if(x=='('){
            s.push(x);
        }
        else if(x==')'){
            y=s.pop();
            while(y!='('){
            	postfix[j]=y;
            	j++;
                y=s.pop();
            }
        }
        else{
        	while(!s.empty() && preferance(x)<preferance(s.topElement())){
        		y=s.pop();
        		postfix[j]=y;
        		j++;
        	}
        	s.push(x);
        }

    }
    while(! s.empty()){
        y = s.pop();
        postfix[j]=y;
        j++;
    }
    for(int i=0;i<j;i++){
    	str+=postfix[i];
    }
    return str;
}
string infix_to_prefix(string infix){
    int m=infix.length();
    char prefix[m];
    string str;
    for(int i=0;i<m;i++){
        if(infix[m-i-1]=='('){
            str+=')';
        }
        else if(infix[m-i-1]==')'){
            str+='(';
        }
        else{
            str+=infix[m-i-1];
        }
    }
    string z=infix_to_postfix(str);
    reverse(z.begin(),z.end());
    return z;
}
int postfix_evalution(string postfix){
    Stack s;
    char p,q;
    int a,b;
    int n=postfix.length();
    for(int i=0;i<n;i++){
        p=postfix[i];
        if(isalnum(p)){
            cout<<"Enter the value of "<<p<<":-";
            cin>>q;
            s.push(q);
        }
        else{
            a=s.pop()-'0'; 
            b=s.pop()-'0';
            if(a==0 && p=='/'){
                cout<<"Invalid!"<<endl;
                return 0;
            }
            int z=evalution(a,b,p);
            s.push(z+'0');
        }
    }
    int r=s.pop()-'0';
    return r;
}
int prefix_evalution(string prefix){
    reverse(prefix.begin(),prefix.end());
    Stack s;
    char x,q;
    int a,b;
    int n=prefix.length();
    for(int i=0;i<n;i++){
        x=prefix[i];
        if(isalnum(x)){
            cout<<"Enter the value of "<<x<<": ";
            cin>>q;
            s.push(q);
        }
        else{
            a=s.pop()-'0';
            b=s.pop()-'0';
            if(b==0  && x=='/'){
                cout<<"Invalid"<<endl;
                return 0;
            }
            int z=evalution(b,a,x);
            s.push(z+'0');
        }
    }
    int r=s.pop()-'0';
    return r;

}
int main(){
    Stack s;
    int choice=11,ans;
    string infix,str;
    while(choice!=0){
        cout<<"Choose any option from the given menu:\n"
            <<"1. Infix to Postfix\n"
            <<"2. Infix to Prefix\n"
            <<"3. Evaluation of Postfix\n"
            <<"4. Evaluation of Prefix\n\n"
            <<"Enter your choice: ";
        cin>>choice;
        switch (choice){
        case 1:
            cout<<"Enter the infix expression: ";
            cin>>infix;
            cout<<"Postfix expression is: ";
            cout<<infix_to_postfix(infix)<<endl<<endl;
            break;
        
        case 2:
            cout<<"Enter the infix expression: ";
            cin>>infix;
            cout<<"Prefix expression is: ";
            cout<<infix_to_prefix(infix)<<endl<<endl;
            break;
        
        case 3:
            cout<<"Enter the postfix expression: ";
            cin>>infix;
            ans=postfix_evalution(infix);
            if(ans!=0){
                cout<<"Evaluated expression is: ";
                cout<<ans<<endl<<endl;
            }
            break;
        case 4:
            cout<<"Enter the prefix expression: ";
            cin>>infix;
            ans=prefix_evalution(infix);
            if(ans!=0){
                cout<<"Evaluated expression is: ";
                cout<<ans<<endl<<endl;
            }
            break;
        
        default:
            cout<<"Uh oh! Invalid choice!\n";
            break;
        }
    }
return 0; 
}