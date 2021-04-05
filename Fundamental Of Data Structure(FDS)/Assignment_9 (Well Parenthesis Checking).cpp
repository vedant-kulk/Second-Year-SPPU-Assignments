/*
    Problem Statement::
        In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well
        parenthesized or not

*/



#include <iostream>
#include <cstring>

using namespace std;


class stack{
public:
    int size;
    int top;
    char *s;
    
    stack(){
        top=-1;
    }
    
    void create(int n);
    void push(char x);
    void pop();
    void display();
    int isempty();
    int isfull();
    char stackTop();
    
    

        
};
void stack::create(int n){
    size=n;
    s=new char[size];
}

void stack::push(char x){
    if(top==size-1){
        cout<<"Stack overflow"<<endl;
    }
    else{
        top=top+1;
        s[top]=x;
    }
}
char stack::stackTop() {
    if (top==-1){
        return -1;
    }
    return s[top];
}
 

void stack::pop(){
    
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        top=top-1;
    }
}

    
    
    

 
int stack::isfull(){
    if(top==size-1){
        return 1;
    }
    return 0;
}

int stack::isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void stack::display() {
    for (int i=top; i>=0; i--){
        cout << s[i] << "  " ;
    }
    cout << endl;
}

bool isbalanced(char *a,int n){
    stack st;
    char temp;
    st.create(n);
    for(int i=0;i<n;i++){
       
         if (a[i] == '(' || a[i] == '[' || a[i] == '{')  
        { 
            st.push(a[i]); 
            continue; 
        } 
        else if (a[i] == '}' || a[i] == ']' || a[i] == ')'){
            if (st.isempty()){
                return false;
            } 
            else if(a[i]==')') {
                temp = st.stackTop();
                st.pop();
                if (temp == '{' || temp == '[') 
                return false;
            }
            else if(a[i]==']') {
                temp = st.stackTop();
                st.pop();
                if (temp == '{' || temp == '(') 
                return false;
            }
            else if(a[i]=='}') {
                temp = st.stackTop();
                st.pop();
                if (temp == '(' || temp == '[') 
                return false;
            }    
        }
    }
    return (st.isempty());
}





int main(){
    int ch;
    char a[100];
    int n=0;


        cout<<"--------------------------------------------"<<endl;
        cout<<"MENU"<<endl;
        cout<<"1 : Enter a expression"<<endl;

        cout<<"-1: Exit"<<endl;
        cout<<"--------------------------------------------"<<endl;
        while(1){
        cout<<"Enter choice -> ";
        cin>>ch;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"!!! You have entered character   "<<endl;
                cout<<"--------------------------------------------"<<endl;
                cout<<" \n\n";
        }
        
        else if(ch==1){
            cout<<"Enter the expression"<<endl;
            cin>>a;
            n=strlen(a);
            if(isbalanced(a,n)){
                cout<<" Expression is Balanced"<<endl;
                cout<<" \n\n";
            }
            else{
                cout<<" Expression is Unbalanced"<<endl;
                 cout<<" \n\n";
            }
            cout<<"--------------------------------------------"<<endl;
            cout<<" \n\n";
            

        }
    
        else if(ch==-1){
            break;
        }
        
        else{
            cout<<"Wrong choice Try again"<<endl;
            cout<<" \n\n";
        }
        
        
        }
        
}
   