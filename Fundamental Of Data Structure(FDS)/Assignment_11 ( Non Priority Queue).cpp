/*
    Problem Statement::
        Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
        If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++
        program for simulating job queue. Write functions to add job and delete job from queue.



*/



#include <iostream>
#include <string>

using namespace std;
class Node{
public:
        string job;
        Node *next;
        
        Node(){
            next=NULL;      //class Node
        }
};
class Queue{
public:    
    Node *front;
    Node *rear;
    
    Queue(){
        front=NULL;
        rear=NULL;         //class Queue
    }
    void add_job(string j);
    void delete_job();
    bool isempty();
    void display();
    
};
bool::Queue::isempty(){
    if(front==NULL){
        return true;      //function to check if queue is empty
    }
    return false;
}
void Queue::add_job(string j){
    Node *temp= new Node();          //function to add job at rear of queue
    temp->job=j;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
void Queue::delete_job(){
    Node *p;
    if(isempty()){
        cout<<"Queue is Empty"<<endl;  //function to delete first element of queue
    }
    else{
        p=front;
        front=front->next;
        delete p;
    }
    
}
void Queue::display(){
    Node *p=front;
    if(p==NULL){                                //function to display queue
        cout<<"Display Queue is empty"<<endl;
    }
    else{
    int i=1;
    while(p){
        cout<<i<<"->"<<p->job<<endl;
        p=p->next;
        i=i+1;
    }
    
    }
}
int main(){
    Queue q;
    int ch;
    string j;

    cout<< " _______________________________________________________" << endl;
    
    cout<<"    MENU"<<endl;
    cout<<"    1: ADD A JOB"<<endl;
    cout<<"    2: DELETE A JOB"<<endl;
    cout<<"    3: DISPLAY JOB QUEUE"<<endl;
    cout<<"    -1 :EXIT"<<endl;
    cout << " _______________________________________________________" << endl;
    while(1){
        cout<<"Enter your choice -> ";
        cin>>ch;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
                cout<<"\n\n";
            }
        
        else if(ch==1){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the name of job -> ";
            getline(cin, j);
            q.add_job(j);
            cout<<"-------------------------------------------"<<endl;
            cout<<" \n\n";
        }
        else if(ch==2){
            q.delete_job();
            cout<<"-------------------------------------------"<<endl;
            cout<<" \n\n";
        }
        else if(ch==3){
            q.display();
            cout<<"-------------------------------------------"<<endl;
            cout<<" \n\n";
            
        }
        else if(ch==-1){
            break;
        }
        else{
            cout<<"Wrong Choice"<<endl;
        }
    }    
}
   