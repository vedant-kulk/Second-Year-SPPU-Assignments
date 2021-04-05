/*
    Problem Statement::
        Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. Create a class that includes the data items 
        (which should be template) and the priority (which should be int). The inorder list should contain these objects, 
        with operator <= overloaded so that the items with highest priority appear at the start of the list (which will make it relatively easy to retrieve the highest item.)

*/
#include <iostream>
#include <iomanip>
using namespace std;
int type=0;
template<class T>

class Node{
public:    
    int priority;                             //class Node
    T data;
    Node<T> *next;
    
    bool operator <= (const Node<T>& n2)
	{
		return this->priority <= n2.priority;   //overloading <=operator
	}
    
};
template<class T>
class Priority_queue{
public:    
    Node<T> *first;                   //Template class for Priority Queue
    
    Priority_queue(){
        first=NULL;
    }
    
    
    
    void insert(T x,int p){
        Node <T>*temp;
        Node <T>*q;                     //function for inserting the job according to priority 
        temp=new Node<T>();
        temp->data=x;
        temp->priority=p;
        temp->next=NULL;
        
        
        if(first==NULL){
            first=temp;
        }
        else{
            q=first;
            while(q->next!=NULL && (*(q->next))<=(*temp)){
                q=q->next;
            }
            if(q==first and (temp->priority)<(first->priority)){
                temp->next=first;
                first=temp;
            }
            else{
                temp->next=q->next;
                q->next=temp;
                
            }
            
        }
    }
    
    void remove(){
        Node <T>*q=first;
        if(q==NULL){                                            //function to remove job
            cout<<"Queue is empty"<<endl;
            cout<<"------------------------------------------"<<"\n\n"<<endl;
        }
        else{
        first=first->next;
        delete(q);
        }
    }
    
    
    void display(){
        Node <T>*q=first;                                     //function to display entire priority queue
        if(first==NULL){
            cout<<"Queue is empty"<<endl;
            cout<<"------------------------------------------"<<"\n\n"<<endl;
        }
        else{
            cout<<'\t'<<left<<setw(25)<<"PRIORITY"<<setw(30)<<"DATA"<<endl;
            
            while(q!=NULL){
                cout<<'\t'<<left<<setw(25)<<q->priority<<setw(30)<< q->data << '\n';
                
                q=q->next;
            }
            cout<<endl;
        }
    }
    
};






int main(){
    
    
    int i_type;
    float d_type;
    char c_type;
    int prio;
    

    cout<<"________________________________________"<<endl;
    cout<<"1 : Integer tyoe data"<<endl;
    cout<<"2 : Float type data"<<endl;                                //Menu for selection data type
    cout<<"3 : Character type data"<<endl;
    cout<<"-1 :Exit"<<endl;
    cout<<"________________________________________\n"<<endl;
    while(1){
    cout<<"Enter your choice for data type  -> ";
    cin>>type;
    if(!cin){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<" !! Entered a character .Give a integer value "<<endl;
        }
    else if(type==1){
        int ch=0;
        Priority_queue<int> q;
        cout<<"_________________________________________"<<endl;
        cout<<"1 : Add a element in the queue"<<endl;
        cout<<"2 : Remove element from queue"<<endl;                  //Menu for operation on priority queue
        cout<<"3 : Display Queue"<<endl;
        cout<<"-1: Exit"<<endl;
        cout<<"_________________________________________"<<endl;
        cout<<"\n\n"<<endl;
        while(1){
        cout<<"Enter your choice -> ";
        cin>>ch;
        if(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<" !! Entered a character .Give a integer value "<<endl;
        cout<<"------------------------------------------"<<"\n\n"<<endl;
        }
        else if(ch==1){
            while(1){
            cout<<"Enter a Integer data -> ";
            cin>>i_type;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
                cout<<"\n\n"<<endl;
            
             }
            else{
                break;
            } 
            }
            while(1){
            cout<<"Enter the priority -> ";
            cin>>prio;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
                cout<<"\n\n"<<endl;
            
             }
             else{
                 break;
             }
            
            }
            
            q.insert(i_type,prio);
            cout<<"Element is inserted"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"\n\n"<<endl;
            
            
        }
        else if(ch==2){
            q.remove();
            cout<<"Element has been deleted"<<endl;
            cout<<"\n\n"<<endl;
        }
        else if(ch==3){
            q.display();
            cout<<"__________________________________________"<<endl;
            cout<<"\n\n"<<endl;
            
        }
        else if(ch==-1){
            break;
        }
        else{
            cout<<"Wrong choice "<<endl;
            cout<<"\n\n"<<endl; 
        }
        
        }
        
    }    
    else if(type==2){
        Priority_queue<float> q;
        int ch=0;
        cout<<"_________________________________________"<<endl;
        cout<<"1 : Add a element in the queue"<<endl;
        cout<<"2 : Remove element from queue"<<endl;
        cout<<"3 : Display Queue"<<endl;
        cout<<"-1: Exit"<<endl;
        cout<<"_________________________________________"<<endl;
        cout<<"\n\n"<<endl;
        while(1){
        cout<<"Enter your choice -> ";
        cin>>ch;
        if(!cin){
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<" !! Entered a character .Give a integer value "<<endl;
        }
        else if(ch==1){
            while(1){
            cout<<"Enter a float data -> ";
            cin>>d_type;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
                cout<<"\n\n"<<endl;
            
             }
            else{
                break;
            } 
            }
            while(1){
            cout<<"Enter the priority -> ";
            cin>>prio;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
                cout<<"\n\n"<<endl;
            
             }
             else{
                 break;
             }
            
            }
            
            q.insert(d_type,prio);
            cout<<"Element is inserted"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"\n\n"<<endl;
            
            
        }
        else if(ch==2){
            q.remove();
            cout<<"Element has been deleted"<<endl;
            cout<<"\n\n"<<endl;
        }
        else if(ch==3){
            q.display();
            cout<<"__________________________________________"<<endl;
            cout<<"\n\n"<<endl;
            
        }
        else if(ch==-1){
            break;
        }
        else{
            cout<<"Wrong choice "<<endl;
            cout<<"\n\n"<<endl; 
        }
        
        }
        
    }
    else if(type==3){
        Priority_queue<char> q;
        int ch=0;
        cout<<"_________________________________________"<<endl;
        cout<<"1 : Add a element in the queue"<<endl;
        cout<<"2 : Remove element from queue"<<endl;
        cout<<"3 : Display Queue"<<endl;
        cout<<"-1: Exit"<<endl;
        cout<<"_________________________________________"<<endl;
        cout<<"\n\n"<<endl;
        while(1){
        cout<<"Enter your choice -> ";
        cin>>ch;
        if(!cin){
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<" !! Entered a character .Give a integer value "<<endl;
        }
        else if(ch==1){
            
            cout<<"Enter a charcter data -> ";
            cin>>c_type;
           
            while(1){
            cout<<"Enter the priority -> ";
            cin>>prio;
            if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
                cout<<"\n\n"<<endl;
            
             }
             else{
                 break;
             }
            
            }
            
            q.insert(c_type,prio);
            cout<<"Element is inserted"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"\n\n"<<endl;
            
            
        }
        else if(ch==2){
            q.remove();
            cout<<"Element has been deleted"<<endl;
            cout<<"\n\n"<<endl;
        }
        else if(ch==3){
            q.display();
            cout<<"__________________________________________"<<endl;
            cout<<"\n\n"<<endl;
            
        }
        else if(ch==-1){
            break;
        }
        else{
            cout<<"Wrong choice "<<endl;
            cout<<"\n\n"<<endl; 
        }
        
        }
        
    }
    else if(type==-1){
        break;
    }
    
    
    else{
        cout<<"Wrong choice"<<endl;
        cout<<"\n\n"<<endl;
    }
    }

}