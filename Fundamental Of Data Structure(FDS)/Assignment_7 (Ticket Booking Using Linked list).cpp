/* Problem Statement ::
    The ticket booking system of Cinemax theater has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand
        a)	The list of available seats is to be displayed
        b)	The seats are to be booked
        c)	The booking can be cancelled.
*/


#include<iostream>
#include<iomanip>
using namespace std;

int total_booked=0;
class Node{
public:
    char data;
    Node *prev;
    Node *next;                                    //class Node
    
    Node()
    {
        data='0';
        next=NULL;
        prev=NULL;
    }
    
};
class LL{
public:    
    Node *first;
    
    LL(){
        first=NULL;
    }
    
    
    void create();                                                //class LL
    void display();
    void book_one(int n);
    void book_many(int n,int m);
    void cancel_one(int n);
    void cancel_many(int n,int m);
    
};
void LL::create(){
    Node *last,*temp;
    
    first=new Node();
    first->data='_';
    first->next=first;
    first->prev=NULL;
    last=first;
                                        //create function creates a doubly circular linked list
    for(int i=0;i<6;i++){
        temp=new Node();
        temp->data='_';
        temp->next=first;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }
    first->prev=last;
}

void LL::display(){
    Node *p=first;
    
        do
        {
            cout<<setw(10)<<p->data;
            p=p->next;
        }                                          //display the linked list
        while(p!=first);
        cout<<endl;
    
}
void LL::book_one(int n){
    Node *p=first;
    int c=1;
    while(c!=n){
        c=c+1;
        p=p->next;
    }
    if(p->data=='_'){
        p->data='#';
        total_booked++;
        cout<<"\n Booking was successfull"<<endl;
    }
    else{
        cout<<"\n This seat is already Booked !!! Try Again"<<endl;
    }
    
    
}

void LL::book_many(int n,int m){
    bool check=true;
    Node *p =first;
    Node *q=first;
    int x=1;
    int y=1;
    while(x!=n){
        x=x+1;
        p=p->next;
    }
    while(y!=m){
        y=y+1;
        q=q->next;
    }
    while(p!=q->next){
        if(p->data=='#'){
            check=false;
            break;
        }
        p=p->next;
    }
    if(!check){
        cout<<" \n There is a Booked seat in This series "<<endl;
    }
    else{
        p=first;
        int c=1;
        while(c!=n){
            c=c+1;
            p=p->next;
            
        }
        while(c!=m+1){
            p->data='#';
            p=p->next;
            total_booked++;
            c=c+1;
            
        }
        cout<<"\n Booking was successfull"<<endl;
        
        
        
        
    }
    
}


void::LL::cancel_one(int n){
    Node *p=first;

        int c=1;

        while(c!=n)
        {
            c++;
            p=p->next;
        }

        if(p->data=='#')
        {
            p->data='_';
            total_booked--;
            cout<<endl<<"CANCELLATION  WAS  SUCCESSFUL"<<endl;
        }
        else
        {
            cout<<endl<<"You Have Entered a Seat Which is not Booked \n\n"<<endl;
            cout<<"--------------------------------------------------------------------------"<<endl;
        }
        
    }


void LL::cancel_many(int n,int m){
    bool check=true;
    Node *p =first;
    Node *q=first;
    int x=1;
    int y=1;
    while(x!=n){
        x=x+1;
        p=p->next;
    }
    while(y!=m){
        y=y+1;
        q=q->next;
    }
    while(p!=q->next){
        if(p->data=='_'){
            check=false;
            break;
        }
        p=p->next;
    }
    if(!check){
        cout<<" \n There is a seat you have entered which is not Booked \n\n "<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
    }
    else{
        p=p->prev;
        int c=m;
        while(c!=n-1){
            p->data='_';
            p=p->prev;
            total_booked--;
            c--;
            
        }
    }
    
    
}

void display_status(LL arr[]){
    //cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<setw(50)<<"-:Status Of Seats:-"<<endl;
    cout<<" '#' - Booked seats  '_' - Vacant seats"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<("r/c");
    for(int i=0;i<7;++i)
    {
    	cout<<setw(10)<<(i+1);
	}
	cout<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;	
    for(int i=65; i<75; i++)
    {
    	cout<<char(i)<<"-";
        arr[i-65].display();
	}
    
        
	cout<<"--------------------------------------------------------------------------"<<endl;	
}



int main(){
    LL arr[10];
    
     for(int i=0; i<10; i++)
    {
        
        arr[i].create();
        
    }
    display_status(arr);
    
    while(1){
        
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"MENU:-"<<endl;
        cout<<"                                               1: Booking a Seat"<<endl;
        cout<<"                                               2: Cancelling a Seat"<<endl;
        cout<<"                                               -1: Exit"<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        int ch;
        cout<<"Enter your choice -> ";
        cin>>ch;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"!!! You have entered character   "<<endl;
        }
        else{
        try
		{
        	if(ch != -1 and ch !=1 and ch!=2 ){
        		throw(ch);
			}
		}
		catch(int x){
			cout<<" !!  Wrong choice , Please choose correct option"<<endl;
            cout<<"-----------------------------------------------------------------------------------"<<endl;
            cout<<"\n\n";
		}
        
        }
        
    
    if(ch==1){
        if(total_booked>70){
            cout<<"!! HOSUEFULL ";
        }
        else{
            int choice;
            cout<<"1 : Book a single seats \n2 : Book multiple seats "<<endl;
            cout<<"Enter choice -> ";
            cin>>choice;
            cout<<"\n\n";
            
            if(choice==1){
                char row;
                int col;
                cout<<"Enter the row (A - J) -> ";
                cin>>row;
                if(row=='A' or row=='B' or row =='C' or row=='D' or row == 'E' or row =='F' or row=='G' or row =='H' or row =='I' or row=='J'){
                    while(1){
                    cout<<"Enter the coloumn -> ";
                    cin>>col;
                    if(!cin){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout<<" !! Entered a character "<<endl;
                        cout<<" BOOKING FAILED Try Again"<<endl;
                        cout<<"\n\n";
                    }
                    else if(col<1 or col>7){
                        cout<<" Wrong coloumn number" <<endl;
                        cout<<" BOOKING FAILED Try Again"<<endl;
                        cout<<"\n\n";
                    }
                    
                    else{
                        int d= int(row)-65;
                        arr[d].book_one(col);
                        display_status(arr);
                        break;
                    }
                    
                }
                }
                else{
                    cout<<" !! Entered a Wrong row character "<<endl;
                    cout<<" BOOKING FAILED"<<endl;
                    cout<<"\n\n";
                    
                }
                
            }
            else if(choice==2){
                char row;
                int col1,col2;
                cout<<"Enter the row (A-J) -> ";
                cin>>row;
                if(row=='A' or row=='B' or row =='C' or row=='D' or row == 'E' or row =='F' or row=='G' or row =='H' or row =='I' or row=='J'){
                    while(1){
                    cout<<"Enter the first coloumn -> ";
                    cin>>col1;
                    cout<<endl;
                    cout<<"Enter the second coloumn -> ";
                    cin>>col2;
                    cout<<endl;
                    if(col1>col2){
                        cout<<"Column1 cannot be greater than column 2 !! Try different value \n  "<<endl;
                        cout<<"\n\n";
                        
                    }
                    else if(col1==col2){
                        cout<<"Columns are equal !! Try different value \n "<<endl;
                        cout<<"\n\n";
                    }
                    else if(col1<=0 or col1>7 or col2<=0 or col2>7 ){
                        cout<<"Enter column value in range \n "<<endl;
                        cout<<"\n\n";
                    }
                    else{
                        int d= int(row)-65;
                        arr[d].book_many(col1,col2);
                        display_status(arr);
                        cout<<"\n\n";
                        break;
                        
                    }
                    
                }
            }
            else{
                    cout<<" !! Entered a Wrong row character "<<endl;
                    cout<<" BOOKING FAILED \n"<<endl;
                    
                
            }
            
            
        }
        
    }
    }
    else if(ch==2){
        if(total_booked<=0){
            cout<<" NO SEATS ARE BOOKED YET "<<endl;;
        }
        else{
            int choice;
            cout<<"1 : Cancel a single seats \n2 : Cancel multiple seats "<<endl;
            cout<<"Enter choice -> ";
            cin>>choice;
            cout<<"\n\n";
            if(choice==1){
                char row;
                int col;
                cout<<"Enter the row (A-J) -> ";
                cin>>row;
                if(row=='A' or row=='B' or row =='C' or row=='D' or row == 'E' or row =='F' or row=='G' or row =='H' or row =='I' or row=='J'){
                    cout<<"Enter the colounm -> ";
                    cin>>col;
                    if(!cin){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout<<" !! Entered a character "<<endl;
                        cout<<" BOOKING FAILED Try Again"<<endl;
                        cout<<"\n\n";
                    }
                    else if(col<=0 or col>7){
                        cout<<" !! Entered a Wrong coloum number "<<endl;
                        cout<<" CANCELLATION FAILED"<<endl;
                        cout<<"\n\n";
                        
                    }
                    else{
                        int d= int(row)-65;
                        arr[d].cancel_one(col);
                        display_status(arr);
                    }   
                }
                else{
                    cout<<" !! Entered a Wrong row character "<<endl;
                    cout<<" CANCELLATION FAILED"<<endl;
                    cout<<"\n\n";
                    
                }
                
            
            
        }
        else if(choice==2){
                char row;
                int col1,col2;
                cout<<"Enter the row (A-J)  -> ";
                cin>>row;
                if(row=='A' or row=='B' or row =='C' or row=='D' or row == 'E' or row =='F' or row=='G' or row =='H' or row =='I' or row=='J'){
                    while(1){
                    cout<<"Enter the first coloumn -> ";
                    cin>>col1;
                    cout<<endl;
                    cout<<"Enter the second coloumn -> ";
                    cin>>col2;
                    cout<<endl;
                    if(col1>col2){
                        cout<<"Column1 cannot be greater than column 2 !! Try different value \n  "<<endl;
                        cout<<"\n\n";
                        
                    }
                    else if(col1==col2){
                        cout<<"Columns are equal !! Try different value \n "<<endl;
                        cout<<"\n\n";
                    }
                    else if(col1<=0 or col1>7 or col2<=0 or col2>7 ){
                        cout<<"Enter column value in range \n "<<endl;
                        cout<<"\n\n";
                    }
                    else{
                        int d= int(row)-65;
                        arr[d].cancel_many(col1,col2);
                        display_status(arr);
                        cout<<"\n\n";
                        break;
                        
                    }
                    
                }
            }
            else{
                    cout<<" !! Entered a Wrong row character "<<endl;
                    cout<<" CANCELLATION FAILED \n"<<endl;
                    
                
            }
            
            
            
        }
        
        
    }
    
}
        else if(ch==-1){
            break;
        }
    }
}