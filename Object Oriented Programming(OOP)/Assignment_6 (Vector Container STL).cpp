/*
    Problem Statement::
        Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;
static int total=0;
class student{
public:
        char dob[15];
        string name;                    //class student declared
        string tel;
        int age;
        
        bool operator==(const student &s1)
                {                                            //overloading equality operator for implementing searching with 
                                                            //user defined class
                    return(name==s1.name);
                }
       bool operator<(const student &s1)
                {
                   return(age<s1.age);
                }
        
        friend ostream &operator << (ostream &out, const student &s);
        
        void display_all(){
            cout<<setw(20)<<"Name"<<setw(15)<<"Age"<<setw(20)<<"Date Of Birth"<<setw(20)<<"Contact"<<endl;
            cout<<*this<<endl;
            
        }
        
        bool name_valid(){
        bool i=true;                                                       //validation for title
        for (int j=0;j<name.size();j++){
            if(!((name[j]>='A' && name[j]<='Z')||(name[j]>='a' && name[j]<='z')||(name[j]==' '))){
                i=false;
                break;
            }
        }
        return i;
    }
    void Capitalize_first_letter(){
	for (int x = 0; x < name.length(); x++)
	{
		if (x == 0)
		{
			name[x] = toupper(name[x]);
		}                                                //function to capitalize first letter of name and also letter after space
		else if (name[x - 1] == ' ')
		{
			name[x] = toupper(name[x]);
		}
	}
}

        
};
ostream & operator << (ostream &out, const student &s){
     out<<setw(20)<<s.name<<setw(15)<<s.age<<setw(20)<<s.dob<<setw(20)<<s.tel<<endl; //overloading stream insertion operator
     return out;
}

bool name(const student &k, const student &i2)
            {
                        return(k.name<i2.name);       //function which returns boolean value for comparing name 
            }
bool telephone(const student &k, const student &i2)
            {
                        return(k.tel<i2.tel);        //function which returns boolean value for comparing telephone number
            }


bool search_dup(vector<student>&s,string x){
    student k;
    k.name=x;
    vector<student>::iterator it;
    it=find(s.begin(),s.end(),k);                 //function to check whether any duplicate name is present
    if(it==s.end()){
        return true;
    }
    return false;
    
}
void search(vector<student>&s){
    
    student k;
    vector<student>::iterator it;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter the Name of student to be Searched -> ";
    getline(cin,k.name);
    k.Capitalize_first_letter();                       //function to implement searching og student in vector by name
    it=find(s.begin(),s.end(),k);
    if(it!=s.end()){
        cout<<"Student is present Here are details of that student"<<endl;
        cout<<*it<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"\n\n"<<endl;
    }
    
    else{
        cout<<"Student not found"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"\n\n";
    }
    
    
}


void sort_age(vector <student> &s){
    sort(s.begin(),s.end());
}                                                  //these are function which implement sorting by name,age and telephone number
void sort_name(vector <student> &s){
    sort(s.begin(),s.end(),name);
}
void sort_tel(vector <student> &s){
    sort(s.begin(),s.end(),telephone);
}


int main(){
    int choice;
    vector <student> s;              //declaring a vector of student

    cout<<"_______________________________________________________"<<endl;
    cout<<"MENU"<<endl;
    cout<<"1:  ADD DATA"<<endl;
    cout<<"2:  SEARCH FOR A STUDENT"<<endl;
    cout<<"3:  SORT THE DATA"<<endl;
    cout<<"-1: EXIT"<<endl;
    cout<<"_______________________________________________________"<<endl;
    
    while(1){
        cout<<"Enter choice"<<endl;
        cin>>choice;
        if(!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"!!! You have entered character   "<<endl;
                cout<<"--------------------------------------------"<<endl;
                cout<<" \n\n";
        }
        else if(choice==1){
        student d;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(true){  
        cout<<"Enter your name -> ";
        getline(cin,d.name);
        d.Capitalize_first_letter();
        bool c=d.name_valid();
        if(c){
            if(search_dup(s,d.name)){
            break;
            
            }
            else{
                cout<<"Duplicate name found"<<endl;
                cout<<"______________________________________________________________________________________"<<endl;
                cout<<"\n\n";
                continue;
            }
        }
        else{
            cout<<"ERROR !! Enter valid name"<<endl;
            cout<<"-----------------------------"<<endl;
        }
        }

        cout<<"Enter your dob (DD-MM-YYYY) -> ";
        cin>>d.dob;
        cout<<"Enter your age - > ";
        cin>>d.age;
        cout<<"Enter your telephone number -> ";
        cin>>d.tel;
         cout<<"______________________________________________________________________________________"<<endl;
        cout<<"\n\n";
        s.push_back(d);                            //using ush back of vector to append student class object in vector
        total=total+1;
        for(int i=0;i<total;i++){
          s[i].display_all();
        }
        
    }
    else if(choice==2){
        if(total==0){
            cout<<"No data added"<<endl;
        }
        else{
        search(s);
        }
        
        
    }
    else if(choice==3){
        if(total==1){
            cout<<"Atleast add two Entries to be sorted"<<endl;
            cout<<"--------------------------------------------------"<<endl;
        }
        else{
        int c;
        vector<student>d;
        for(int i=0;i<total;i++){
            d.push_back(s[i]);
            }
        cout<<"_______________________________________________________"<<endl;    
        cout<<"1 : BY AGE"<<endl;
        cout<<"2 : BY NAME"<<endl;
        cout<<"3 : TELEPHONE NUMBER"<<endl;
        cout<<"Enter your choice"<<endl;
        cout<<"_______________________________________________________"<<endl;
        cin>>c;
        if(c==1){
            sort_age(d);
            for(int i=0;i<total;i++){
          d[i].display_all();
          
        }
        cout<<"______________________________________________________________________________________"<<endl;
          cout<<"\n\n";
            
        }
        else if(c==2){
            sort_name(d);
            for(int i=0;i<total;i++){
          d[i].display_all();
          
        }
         cout<<"______________________________________________________________________________________"<<endl;
       
        cout<<"\n\n";
            
        }
        else if(c==3){
            sort_tel(d);
            for(int i=0;i<total;i++){
          d[i].display_all();
          
        }
         cout<<"______________________________________________________________________________________"<<endl;
        cout<<"\n\n";
        
        }
        
    }
    }
    else if(choice==-1){
        break;
    }
    else{
        cout<<"Give Proper choice"<<endl;
    }
    
    


}
}
   