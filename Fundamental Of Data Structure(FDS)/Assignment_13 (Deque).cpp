/* Problem Statement::
    A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. 
    Obtain a data representation mapping a deque into a one- dimensional array.
    Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.


*/


#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Queue{
public:
	string *s;
    int size;                           //class to create a dequeue
    int front,rear;
    Queue(){
        front=-1;
        rear=-1;
        s={};
    }
    void create(int n);
    void add_last(string j);
    void delete_first();
    bool isempty();
    void display();
    void add_first(string j);
    void delete_last();
    bool isfull();
    

};

    
    

void Queue::create(int n){
    size=n;
	s=new string[n];                  //function to dynamically create a queue
}

bool Queue::isempty(){
    if(front==-1){
        return true;
    }                                 //function to check if dequeue is empty
    return false;
}
bool Queue::isfull(){
    if((rear==size-1 && front==0) || front==rear+1 ){     //function to check if dequeue is full
        return true;
    }
    return false;
}

void Queue::add_first(string j){
    
    if (isfull())
    {
    cout << "\n\t Deque is Full...!!!" << endl;
    
    }
    else if (front == -1)
    {
        
    front = 0;
    rear = 0;
    
    }
    else if (front == 0)
        front = size - 1 ;
    else
        front = front-1;
    s[front] = j ;
    
}

void Queue::add_last(string j){
    if(isfull()){
        cout<<"Deque is Full...!!!"<<endl;
        cout<<"\n\n"<<endl;
    }
    else if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear==size-1){
        rear=0;
    }
    else{
    	
    	rear++;
    }
    s[rear]=j;
}

void Queue::delete_first(){
    if(isempty() ){
        cout<<"Queue is Empty"<<endl;
        cout<<"\n\n"<<endl;
        
    }
    else if(front==rear){
        rear=front=-1;
        
    }
    else if(front==size-1){
        front=0;
    }
    else{
        front=front+1;
    }
}
void Queue::delete_last(){
    if(isempty()){
        cout<<"Queue is Empty"<<endl;
        cout<<"\n\n"<<endl;
        
    }
    else if(front==rear){
        rear=front=-1;
        
    }
    else if (rear == 0)
        rear = size-1;
    else{
        rear=rear-1;
    }
}

void Queue::display(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        cout<<"\n\n"<<endl;
    }
    else{
    	int i=front;
    	int j=1;
    	while(i!=rear){
    		cout<<j<<"->"<<s[i]<<endl;
    		i=(i+1)%size;
            j=j+1;
    	}
        cout<<j<<"->"<<s[i]<<endl;
    }
}

int main(){
    Queue q;
    int ch;
    string j;
    q.create(25);
    cout<< " __________________________________________" << endl;

    cout<<"    MENU"<<endl;
    cout<<"    1: ADD A JOB AT FRONT"<<endl;
    cout<<"    2: ADD A JOB AT REAR"<<endl;
    cout<<"    3: DELETE A JOB FROM FRONT"<<endl;
    cout<<"    4: DELETE A JOB FROM REAR"<<endl;
    cout<<"    5: DISPLAY JOB QUEUE"<<endl;
    cout<<"    -1 :EXIT"<<endl;
    cout << " ________________________________________" << endl;
    while(1){
        cout<<"Enter your choice -> ";
        cin>>ch;
        if(!cin){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<" !! Entered a character .Give a integer value "<<endl;
            }

        else if(ch==1){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the name of job -> ";
            getline(cin, j);
            q.add_first(j);
            cout<<"-------------------------------------------"<<endl;
            cout<<"\n\n"<<endl;

        }
        else if(ch==2){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the name of job -> ";
            getline(cin, j);
            q.add_last(j);
             cout<<"-------------------------------------------"<<endl;
             cout<<"\n\n"<<endl;
        }
        else if(ch==3){
        	q.delete_first();
            cout<<"-------------------------------------------"<<endl;
            cout<<"\n\n"<<endl;

        }
        else if(ch==4){
            q.delete_last();
            cout<<"-------------------------------------------"<<endl;
            cout<<"\n\n"<<endl;
            
        }
        else if(ch==5){
            q.display();
            cout<<"-------------------------------------------"<<endl;
            cout<<"\n\n"<<endl;
        }
        else if(ch==-1){
            break;
        }
        else{
            cout<<"Wrong Choice"<<endl;
            cout<<"\n\n"<<endl;
        }
    }
    return 0;
}