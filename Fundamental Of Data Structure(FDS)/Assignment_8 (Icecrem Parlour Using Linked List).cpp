/*
    Problem Statement::
        Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C++ program to store two sets using linked list. compute and display-
                a)	Set of students who like both vanilla and butterscotch
                b)	Set of students who like either vanilla or butterscotch or not both
                c)	Number of students who like neither vanilla nor butterscotch

*/

#include <iostream>
using namespace std;

class Node{
public:
        int roll_no;                                                // class for node of a link list
        Node *next;
};

class Second_year{
private:
        Node *Head;                                                // class for students of second year
        Node *last;
public:
        Second_year(){
            Head=NULL;
            last=NULL;
        }
        void create(int value);
        void display();
        void intersection(Second_year set2);
        void diff(Second_year set1,Second_year set2);
        void none(Second_year set1,Second_year set2);
        bool search(int roll);
        //~Second_year();
        
        
};

void Second_year::create(int value){                             //create function for creation of a link list
    Node *temp;
    if(Head==NULL){
        Head=new Node();
        Head->roll_no=value;
        Head->next=NULL;
        last=Head;
    }
    else{
        temp=new Node();
        temp->roll_no=value;
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
    
   
   
    
    
}



void Second_year::display(){
    Node *p=Head;
    while(p!=0){
        cout<<p->roll_no<<" ";                           // Iterative display function 
        p=p->next;
    }
}

void Second_year::intersection(Second_year set2){
    Node *p=Head;
    Node *q=set2.Head;
    int c=0;
    while(q!=0){
        p=Head;                                          //Function to find intersection of two link list
        while(p!=0){
            if(p->roll_no==q->roll_no){
                cout<<p->roll_no<<" ";
                c=c+1;
                break;
                
            }
            p=p->next;
            
            
        }
        q=q->next;
    }
    if(c==0){
        cout<<"No common students are found"<<endl;
        cout<<"\n\n";
    }
    cout<<endl;
    
}
void Second_year::diff(Second_year set1,Second_year set2){
    Node *p=Head;
    Node *q=set1.Head;
    Node *r=set2.Head;
    int flag=0;
    int flag1=0;
    while(p!=0){
        while(q!=0){
            if(p->roll_no==q->roll_no){
                flag=1;
                break;
            }
            q=q->next;
        }
        while(r!=0){
            if(p->roll_no==r->roll_no){
                flag1=1;
                break;
                
            }
            r=r->next;
        }
        if(flag==1 and flag1==1){
        
        }
        else{
            cout<<p->roll_no<<" ";
        }
        p=p->next;
        flag=0;
        flag1=0;
        q=set2.Head;
        r=set1.Head;
        
    }
    cout<<endl;
}
void Second_year::none(Second_year set1,Second_year set2){
    Node *p=Head;
    Node *q=set1.Head;
    Node *r=set2.Head;
    int flag=0;
    int flag1=0;
    int c=0;
    while(p!=0){
        while(q!=0){
            if(p->roll_no==q->roll_no){
                flag=1;
                break;
            }
            q=q->next;
        }
        while(r!=0){
            if(p->roll_no==r->roll_no){
                flag1=1;
                break;
                
            }
            r=r->next;
        }
        if(flag==0 and flag1==0){
            cout<<p->roll_no<<" ";
            c=c+1;
        
        }
        
        p=p->next;
        flag=0;
        flag1=0;
        q=set2.Head;
        r=set1.Head;
        
    }
    cout<<endl;
    cout<<"Number of students who neither like vanilla nor butter scotch are-> "<<c<<endl;
}


bool Second_year::search(int roll){
    Node *p=Head;
    while(p){                                             //Search a roll number in the linked list
        if(p->roll_no==roll){
            return false;
            break;
        }
        p=p->next;
        
    }
    return true;
}



int main(){
    int roll,choice,n;
    Second_year vani;
    Second_year butter;
    Second_year all;

    while(1){
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<"1 : Enter student detail"<<endl;
        cout<<"2 : Students who like both vanilla and butterscotch"<<endl;
        cout<<"3 : Students who like either vanilla or butterscotch or not both"<<endl;
        cout<<"4 : Students who like neither vanilla nor butterscotch"<<endl;
        cout<<"-1: To Exit"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<"Enter your choice -> ";
        cin>>choice;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"You have entered character "<<endl;
        }
        if(choice==1){
            char v,b;
            while(1){
            
            cout<<"Enter the number of students -> ";
            cin>>n;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"You have entered character \n "<<endl;
                
            }
            else if(n<=0){
                cout<<"Enter a positive integer \n "<<endl;
            }
            else{
                break;
            }
            
            }
            for(int i=0;i<n;i++){
                cout<<"Enter the roll no-> ";
                cin>>roll;
                if(!cin){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"You have entered character "<<endl;
                    cout<<"\n";
                    i=i-1;
                    continue;
                }
                if(!all.search(roll)){
                        cout<<"!!!  This roll number is already added"<<endl;
                        i=i-1;
                        continue;
                }


                cout<<"Do you like vanilla (Y/N) -> ";
                cin>>v;
                while(1){
                if(v=='Y' or v=='y'){
                    vani.create(roll);
                    break;
                    
                }
                if(v=='n' or v=='N'){
                    break;
                }
               
                else{
                    cout<<" ! ! ! Wrong Choice"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Do you like vanilla (Y/N) -> ";
                    cin>>v;
                }
                }
                cout<<"Do you like butterscotch (Y/N) -> :";
                cin>>b;
                while(1){
               
                if(b=='Y' or b=='y'){
                    butter.create(roll);
                    break;
                    
                }
                if(b=='n' or b=='N'){
                    break;
                    
                    
                }
                else{
                    cout<<" ! ! ! Wrong Choice"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Do you like butterscotch (Y/N) -> :";
                    cin>>b;
                }
                }
                
                all.create(roll);
                cout<<"\n\n";
                
                
            }
            cout<<"Roll numbers of total students are -> ";
            all.display();
            cout<<"\n\n";
            cout<<"Roll numbers who like vanilla are -> ";
            vani.display();
            cout<<"\n\n";
            cout<<"Roll number who like butterscotch are -> ";
            butter.display();
            cout<<"\n\n";
            
        }
        else if(choice==2){
            vani.intersection(butter);
            
        }
        else if(choice==3){
            all.diff(vani,butter);
            
        }
        else if(choice==4){
            all.none(vani,butter);
        }
        else if(choice==-1){
            break;
        }
        else{
            cout<<" ! ! ! Wrong Choice"<<endl;
        }
        
        
    }
    
}
   