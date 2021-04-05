/*
    Problem Statement::
        Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) 
        of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
        Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the
        data member values with zero values.

*/



#include <iostream>
using namespace std;
#include<string>
#include<iomanip>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits

class pub{
public:
    string title;
    float price;

    void get_data(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(true){  
        cout<<"Enter the title :";
        getline(cin,title);
        bool c=title_valid(title);
        if(c){
            break;
        }
        else{
            cout<<"ERROR !! Enter valid title"<<endl;
            cout<<"-----------------------------"<<endl;
        }
        }
        cout<<"Enter the price :";
        try{
            cin>>price;
            if(price<0)
                throw price;
            
        }
        catch(float &f){
            cout<<"Error!! You entered a invalid price so it assigned to 0"<<endl;
            price=0;
        }
       
    }
    
    bool title_valid(string b){
        bool i=true;                                                     //validation for title
        for (int j=0;j<b.size();j++){
            if(!((b[i]>='A' && b[i]<='Z')||(b[i]>='a' && b[i]<='z')||(b[i]==' '))){
                i=false;
                break;
            }
        }
        return i;
    }
    
};
class book : public pub{
private:
    int pages;
public:    
    static int s;
    void get_data(){                                                          //child class book derived from pub class
        pub::get_data();
        cout<<"Enter pages :";
        try{                                                           
            cin>>pages;
            if(pages<0)
                throw pages;
                                                                                 //Expection handling for pages
           
        }
        catch(int &f){
            cout<<"Error!! You entered a invalid page count so it is assigned to 0"<<endl;
            pages=0;
        }
       
    }

    void display(){
        cout<<"Title of book is ->"<<title<<endl;
        cout<<"Cost of book is ->"<< price<<endl;
        cout<<"Pages are-> "<<pages<<endl;
        
    }
    
    void displayall(){
		cout<<setw(6)<<s<<setw(30)<<title<<setw(15)<<"Rs. "<<price<<" /-"<<setw(15)<<pages<<" pages"<<endl;
		s++;
			
	}
    
   
};
class tape : public pub{

private:
    float min;
    
public:
    static int s1;                                                                        //child class tape derived from class pub
    void get_data(){
        pub::get_data();
        cout<<"Enter min :";
      
        try{
            cin>>min;
            if(min<0)
                throw min;
           
        }                                                                             //expection handling for minutes
        catch(float &f){
            cout<<"Error!! You entered a invalid entry so minutes is assigned to 0"<<endl;
            min=0;
        }
        
        
    }
       void display(){
        cout<<"Title of tape is ->"<<title<<endl;
        cout<<"Cost of tape is ->"<< price<<endl;
        cout<<"Time of tape in minutes is -> "<<min<<endl;
   
    }
    
    void displayall(){
		cout<<setw(6)<<s1<<setw(30)<<title<<setw(15)<<"Rs. "<<price<<" /-"<<setw(15)<<min<<" mins."<<endl;
		s1++;
			
	}
    
};
int book::s=1;
int tape::s1=1;
int main(){
    book b[20];
    tape c[20];
    static int x=0,y=0;
    cout<<"__________________________________________________________________________________________________"<<endl; 
    cout<<"                         Menu"<<endl;
    cout<<"                         1 : Enter data for book"<<endl;
    cout<<"                         2 : Enter data for tape"<<endl;
    cout<<"                         3 : Display for a book"<<endl;
    cout<<"                         4 : Display for a tape"<<endl;
    cout<<"                         5 : Display all"<<endl;
    cout<<"                        -1 : Exit"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
    while(1<2){
        int choice;
        cout<<"Enter a choice"<<endl;
        cin>>choice;
        if(choice==1){
            b[x].get_data();
            x++;
            cout<<"-------------------------------------------------------------------\n"<<endl;
        }
        else if(choice==2){
            
            c[y].get_data();
            y++;
            cout<<"-------------------------------------------------------------------\n"<<endl;
        }
        else if(choice==3){
            string t;
            if(x==0){
                cout<<"!!No data is added "<<endl;
            }
            else{
            int m=0;
            cout<<"Enter the title of the book"<<endl;
            cin>>t;
            for(int i=0;i<x;i++){
                if(b[i].title!=t){
                    m++;
                }
                else{
                    cout<<"-------------------------------------------------------------------\n"<<endl;
                    b[i].display();
                    cout<<"-------------------------------------------------------------------\n"<<endl;
                    break;
                }
            }
            if(m==x){
                cout<<"-------------------------------------------------------------------\n"<<endl;
                cout<<"Book not found"<<endl;
                cout<<"-------------------------------------------------------------------\n"<<endl;
            }
            }
            
        }
        else if(choice==4){
            string t;
            if(y==0){
                cout<<" !! NO data is added "<<endl;
            }
            else{
            int m=0;
            cout<<"Enter the title of the tape"<<endl;
            cin>>t;
            for(int i=0;i<y;i++){
                if(c[i].title!=t){
                    m++;
                }
                else{
                    cout<<"-------------------------------------------------------------------\n"<<endl;
                    c[i].display();
                    cout<<"-------------------------------------------------------------------\n"<<endl;
                    break;
                }
            }
            if(m==y){
                cout<<"-------------------------------------------------------------------\n"<<endl;
                cout<<"Tape not found"<<endl;
                cout<<"-------------------------------------------------------------------\n"<<endl;
            }
            
            }
        }
        else if(choice==5){
            char ch1;
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"Choices\n1-Data of Books\n2-Data of Tapes"<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"Enter your choice from above choices"<<endl;
            cin>>ch1;
            if(ch1=='1'){
                cout<<setw(6)<<"Sr No."<<setw(30)<<"Title of the Book"<<setw(20)<<"Price"<<setw(22)<<"Total Pages"<<endl;
                cout<<"__________________________________________________________________________________________________"<<endl;
                for(int i=0;i<x;i++){
                        b[i].displayall();
                    }
                cout<<"-------------------------------------------------------------------\n"<<endl;
                book::s=1;
                }
                else if(ch1=='2'){
                cout<<setw(6)<<"Sr No."<<setw(30)<<"Title of the Tape"<<setw(20)<<"Price"<<setw(22)<<"Duration"<<endl;
                cout<<"__________________________________________________________________________________________________"<<endl;
                for(int i=0;i<y;i++){
                    c[i].displayall();
                    }
                cout<<"-------------------------------------------------------------------\n"<<endl;
                tape::s1=1;
                    }
                else{
                    cout<<"Please enter proper choice"<<endl;
					}
        }
        else if(choice==-1){
            cout<<"Thank you"<<endl;
            break;
        }
        else{
            cout<<"Enter proper choice"<<endl;
             cout<<"-------------------------------------------------------------------\n"<<endl;
        }
       
    }
    
    
}
   