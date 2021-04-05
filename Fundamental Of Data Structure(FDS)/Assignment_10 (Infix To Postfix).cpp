/*
    Problem Statement::
        Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
            1.	Operands and operator, both must be single character.
            2.	Input Postfix expression must be in a desired format.
            3.	Only '+', '-', '*' and '/ ' operators are expected.

*/



#include <iostream>
#include <cstring>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;
class stack{
public:
    int size;
    int top;                    //class to implement stack data structure
    char *s;
    
    stack(){
        top=-1;
    }
    
    void create(int n);
    void push(char x);
    char pop();
    void display();
    int isempty();
    int isfull();
    char stackTop();
    
    

        
};
class eval{
public:
    int size;
    int top;
    int *s;
    
    eval(){
        top=-1;
    }
    void create(int n){
    size=n;
    s=new int[size];
    }
    void push(int x){
    if(top==size-1){
        cout<<"Stack overflow"<<endl;
    }
    else{
        top=top+1;
        s[top]=x;
    }
    }
    int pop(){
    int x;
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        x=s[top];
        top=top-1;
    }
    return x;
}
    
};



void stack::create(int n){
    size=n;                              //function to create stack
    s=new char[size];
}

void stack::push(char x){
    if(top==size-1){
        cout<<"Stack overflow"<<endl;
    }
    else{                                //function to implement push
        top=top+1;
        s[top]=x;
    }
}
char stack::stackTop() {
    if (top==-1){
        return -1;
    }                                  //function to retrieve stack top element
    return s[top];
}
 

char stack::pop(){
    char x;
    if(top==-1){
        cout<<"Stack is empty"<<endl;  //function to implement pop
    }
    else{
        x=s[top];
        top=top-1;
    }
    return x;
}
 
int stack::isfull(){
    if(top==size-1){
        return 1;                     //function to check whether stack is full or not
    }
    return 0;
}

int stack::isempty(){
    if(top==-1){
        return 1;                //function to check whether stack is empty or not
    }
    return 0;
}

void stack::display() {
    for (int i=top; i>=0; i--){
        cout << s[i] << "  " ;
    }
    cout << endl;
}

int prec(char c){
    if(c == '*' || c == '/')
	    return 2;
	    else if(c == '+' || c == '-')
	    return 1;
	    else
	    return 0;
}
int valid_operator(char x){
    
        if (x == '+' || x == '-' || x == '*' || x == '/' )
        {
        return 1;
    }
    return 0;
    
}

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}


bool is_valid(char *e){
		int i=0;
		int operators=0,operands=0;
		while(e[i]!='\0'){
            if(e[i]== ' ' || e[i]=='\t'){
            i++;
            continue;
        }
			if(valid_operator(e[i])){
				operators++;
			}
			else if(isOperand(e[i])){
				operands++;
			}

            i=i+1;
		}
		if(operators==operands-1){
			return true;
		}
		else{
			return false;
		}
	}

void to_post(char *a,int n){
    stack st;
    int check=0;
    st.create(n);
    char post[n+1];
    int i=0;
    int j=0;
    while(a[i]!='\0'){
        if(a[i]== ' ' || a[i]=='\t'){
            i++;                                   //function to convert infix expression to postfix expression
            continue;
        }
        if(isOperand(a[i])){
            post[j++] = a[i++];
        }
        else if(a[i]=='('){
            st.push(a[i++]);
        }
        else if(a[i] == ')') 
        { 
            while(st.top != -1 && st.stackTop() != '(') 
            { 
                char c = st.stackTop(); 
                st.pop(); 
                post[j++]=c;
            } 
            if(st.stackTop() == '(') 
            { 
                
                st.pop(); 
            }
            i=i+1;
 
        }
        else{
            if(valid_operator(a[i])){
            while(st.top!=-1 && prec(a[i]) <=  prec(st.stackTop())) 
            { 
                char c = st.stackTop(); 
                st.pop(); 
                post[j++]=c;
            } 
            st.push(a[i++]); 
        }
        else{
            check=1;
            cout<<"Operator is not valid Try different expression "<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<" \n\n";
            break;
        }
    }
 
    }
    if(check==0){
     while(st.top!=-1){
            char c = st.stackTop(); 
            st.pop(); 
            post[j++]=c;
        }
        post[j]='\0';
        cout<<"Postfix expression is -> "<<post<<endl;
        
        cout<<"-------------------------------------------"<<endl;
        cout<<" \n\n";
    }
}
int evaluate(char *s,int n){
    eval ev;
    ev.create(n);
    int i=0;
    int x1,x2,r=0;
    for(i=0;s[i]!='\0';i++){
        if(isOperand(s[i])){
            ev.push(s[i]-'0');
        }
        else{
            x2=ev.pop();
            x1=ev.pop();                 //function to evaluate postfix expression
            switch(s[i])
            {
                case '+':r=x1+x2;break;
                case '-':r=x1-x2;break;
                case '*':r=x1*x2;break;
                case '/':r=x1/x2;break;
            }
            ev.push(r);
        }
    }
    return ev.s[ev.top];
    
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
    
    cout<<" \n\n";
    cout<<"-------------------------------------------"<<endl;
    cout<<"MENU"<<endl;
    cout<<" 1:  Convert Infix to Postfix"<<endl;
    cout<<" 2:  Evaluate Postfix expression"<<endl;
    cout<<" -1: To Exit"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<" \n\n";
    while(1){
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        if(ch==1){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter a infix expression -> ";
            cin.getline(a,100);
            if(is_valid(a)){
                if(isbalanced(a,strlen(a))){
                to_post(a,strlen(a));
                }
                else{
                    cout<<"Expression is not balanced Try Different Expression"<<endl;
                    cout<<"-------------------------------------------"<<endl;
                    cout<<" \n\n";
                }
            
            }
            else{
                cout<<"Expression is not valid Try Different Expression"<<endl;
                cout<<"-------------------------------------------"<<endl;
                cout<<" \n\n";
            }
            
            
            
        }
        else if(ch==2){
            cout<<"Enter a Postfix expression to evaluate -> ";
            cin>>a;
            cout<<"Value of expression is -> "<<evaluate(a,strlen(a))<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<" \n\n";
        }
        else if(ch==-1){
            break;
        }
        else{
            cout<<"!! ERROR - Enter a valid choice"<<endl;
            cout<<"-------------------------------------------"<<endl;
            cout<<" \n\n";
        }
    }
}
   