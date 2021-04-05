/*
    Problem Statement::
        Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number,
        Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. Construct the database
        with suitable member functions. Make use of constructor, default constructor, copy constructor,destructor, static member functions, 
        friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
*/


#include <iostream>
#include <cstring>
#include<iomanip>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <fstream>
using namespace std;

class check;
class student{
public:
    static int studcount;
    char name[30];
    int roll_no;
    char class_[4];
    int div;
    char dob[11];
    char blood[10];
    char tel[12];
    char driv_no[20];
    char cont_add[40];
    static int x;

    
    student &operator=(const student &obj);
    
    static int getcount() {
         return studcount;                                                  //static function to get student count
      }
      
    inline void displayall(){                                                 //inline display all function
		
		cout<<setw(6)<<x<<setw(20)<<name<<setw(15)<<roll_no<<setw(15)<<class_<<setw(15)<<div<<setw(20)<<dob<<setw(15)<<blood<<setw(40)<<cont_add<<setw(20)<<tel<<setw(20)<<driv_no<<endl;
		x++;
	}  
    
    student(){
        roll_no=0;
        div=0;                                                                            //default constructor
    }
    
    void get_data(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the name : ";
        cin.getline(name,20);                                                      //use of getline function
        cout<<"Enter the roll number :";
        cin>>roll_no;
        cout<<"Enter the class : ";
        cin>>class_;
        cout<<"Enter the div :";
        cin>>div;
        cout<<"Enter the Date of Birth(DD-MM-YYYY) :";
        cin>>dob;
        cout<<"Enter the blood group :";
        cin>>blood;                                                                      //Expection handling for blood group
        while(true){
            if( strcmp(blood,"A+")==0 or strcmp(blood,"B+")==0  or strcmp(blood,"O+")==0 or strcmp(blood,"AB+")==0 or strcmp(blood,"AB-")==0 or strcmp(blood,"B-")==0 or strcmp(blood,"A-")==0 or strcmp(blood,"O-")==0 ){
                break;
            }
            else{
                cout<<"Invalid blood group please enter the correct blood group :";
                cin>>blood;
            }
        }    
        cout<<"Enter the telephone number : ";
        cin>>tel;
        while(true){
            if(tel[0]=='-'){                                                               //expection handling for  telephone number
                cout<<"Invalid input!! Enter correct telephone number :";
                cin>>tel;
            }
            else{
                break;
            }
        }
        cout<<"Enter the driving licensce no : ";
        cin>>driv_no;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the address : ";
        cin.getline(cont_add,20);
        
    }
    friend void display(student &obj){
        cout<<"The name of student is -> "<<obj.name<<endl;
        cout<<"The Roll number is -> "<<obj.roll_no<<endl;
        cout<<"THe class of student is -> "<<obj.class_<<endl;
        cout<<"The div of student is -> "<<obj.div<<endl;
        cout<<"The date of birth is -> "<<obj.dob<<endl;                       //friend display function
        cout<<"THe blood group is -> "<<obj.blood<<endl;
        cout<<"The telephone is -> "<<obj.tel<<endl;
        cout<<"The driving licensce no is ->"<<obj.driv_no<<endl;
        cout<<"The address of student is  ->"<<obj.cont_add<<endl;
    }
    
    void modify(){
        
		 
        cout<<"1:name\n2:Roll number\n3:Class\n4:Division\n5:Date of birth\n6:Blood group\n7:telophone number\n8:Driving licensce number\n9:To modify whole profile"<<endl;
        while(1<2){
		cout<<"What you want to modify"<<endl;
		int ch,o;
        cin>>ch;
        if(ch==1){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the new name"<<endl;
            cin.getline(name,30);
        }
        else if(ch==2){
            cout<<"Enter the new roll number"<<endl;
            cin>>roll_no;
        }
        else if(ch==3){
            cout<<"Enter the new class"<<endl;
            cin>>class_;
        }
        else if(ch==4){
            cout<<"Enter the new divison"<<endl;
            cin>>div;
        }
        else if(ch==5){
            cout<<"Enter the new date of birth"<<endl;
            cin>>dob;
        }
        else if(ch==6){
            cout<<"Enter the new blood group"<<endl;
            cin>>blood;
        }else if(ch==7){
            cout<<"Enter the new telephone number"<<endl;
            cin>>tel;
            while(true){
            if(tel[0]=='-'){
                cout<<"Invalid input!! Enter correct telephone number"<<endl;
                cin>>tel;
            }
            else{
                break;
            }
        }
        }
        else if(ch==8){
            cout<<"Enter new Driving licensce number"<<endl;
            cin>>driv_no;
        }
        else if (ch==9){
        	this->get_data();
		}
		while(1<2){
			char wish;
			cout<<"Do you wish to change further? Y/N"<<endl;
			cin>>wish;
			if(wish=='N'){
				o=1;
				break;
			}
			else if(wish=='Y'){
				o=0;
				break;
			}	
			else{
				cout<<"Please give correct input"<<endl;
				continue;
			}
		}
		if(o==1){
			cout<<"---------------------------------------------------\n"<<endl;
			break;
		}		
	}	
}
    student (const student & obj)

	{   cout<<"copy assignment "<<endl;
        strcpy(name,obj.name);
		roll_no=obj.roll_no;                                      //copy constructor
		strcpy(dob,obj.dob);
		strcpy(class_,obj.class_);
        strcpy(driv_no,obj.driv_no);
		div=obj.div;
		strcpy(tel,obj.tel);
        strcpy(blood,obj.blood);
        strcpy(cont_add,obj.cont_add);
		
		                               //friend class;
	}
    friend class check; 
};



int student::studcount = 0;
int student::x = 1;

student &student::operator=(const student &obj){
    //cout<<"assignment"<<endl;
    strcpy(this->name,obj.name);
    this->roll_no=obj.roll_no;
    strcpy(this->class_,obj.class_);
    this->div=obj.div;                                            //assignment operator and this pointer
    strcpy(this->dob,obj.dob);
    strcpy(this->blood,obj.blood);
    strcpy(this->class_,obj.class_);
    strcpy(this->tel,obj.tel);
    strcpy(driv_no,obj.driv_no);
    strcpy(this->cont_add,obj.cont_add);
}
int main(){
    student *s[20];
    int i {0};
    int choice;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<                               "Menu"<<endl;
    cout<<"                              1 : Enter data"<<endl;
    cout<<"                              2 : Display data"<<endl;
    cout<<"                              3 : Modify the data"<<endl;
    cout<<"                              4:  Delete data"<<endl;
    cout<<"                              5: Count of student"<<endl;                                      //Menu
    cout<<"                              6: Use the copy constructor"<<endl;
    cout<<"                              7: Display all"<<endl;
    cout<<"                              -1: To Exit and delete Entire database"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    while(true){
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        if(choice==1){
            s[i]=new student();                                                                  //use of new keyword
            s[i]->get_data();
            writeToFile(*s[i]);
            i++;
            student::studcount++;
            cout<<"\n";
            cout<<"-----------------------------"<<endl;
        }
        else if(choice==2){
            cout<<"For which roll"<<endl;
            int k=0;
            int r;
            int c=0;
            cin>>r;
            for(k=0;k<i;k++){
                if(s[k]->roll_no!=r){
                    c+=1;
                }
                else{
                    cout<<"-------------------------------------------------------------------\n"<<endl;
                    display(*s[k]);
                    cout<<"-------------------------------------------------------------------\n"<<endl;
                    break;
                }
                
            }
            if(c==i){
                cout<<"There is no student with this roll number"<<endl;
                cout<<"---------------------------------"<<endl; 
            }
            
            cout<<"---------------------------------"<<endl; 
            cout<<"\n";
        }
        
        
        else if(choice==3){
            char opt[40];
            int k=0;
            int c=0;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the name of student for which you want to modify the details"<<endl;
            //cin>>opt;
            cin.getline(opt,20);
            for(k=0;k<i;k++){
                if(strcmp(s[k]->name,opt)!=0){
                    c+=1;
                }
                else{
                    s[k]->modify();
                    break;
                }
            }
            if(c==i){
                cout<<"There is no student with this name"<<endl;
            }
            
            cout<<"---------------------------------------"<<endl;
        }
        
        else if(choice==4){
            int r,k,c;
            cout<<"Enter the roll whose data is to be deleted"<<endl;
            cin>>r;
            for(k=0;k<i;k++){
                if(s[k]->roll_no!=r){
                    c+=1;
                    //ch=k;
                }
              
                else{
                for(int j=k;j<i-1;j++){
                *s[j] =*s[j+1];
                }
                s[i-1]=nullptr;
                i--;
                student::studcount--;
                cout<<"Data is deleted"<<endl;
                cout<<"-------------------------------------------------------------------\n"<<endl;
            }
            }
            if(c==i){
            	cout<<"-------------------------------------------------------------------\n"<<endl;
                cout<<"There is no student with this roll number"<<endl;
                cout<<"-------------------------------------------------------------------\n"<<endl;
            }
            
    }
        else if(choice==5){
            cout<<"Number of students added are ->"<<student::getcount()<<endl;
            cout<<"-------------------------------------------------------------------\n"<<endl;
        }
        
        else if(choice==6){
            int o,r;
			int count=0;
			
			while(1<2){
			cout<<"Enter the Roll No. of student:"<<endl;
			cin>>r;
			for(int k=0;k<i;k++){
                if(s[k]->roll_no!=r){
                    count=count+1;
                }
                else{
                	s[i]=new student(*s[k]);
                	i++;
                    student::studcount++;
                    break;
				}
			}
			 if(count==i){
            	cout<<"-------------------------------------------------------------------\n"<<endl;
                cout<<"There is no student with this roll number"<<endl;
                cout<<"-------------------------------------------------------------------\n"<<endl;
            }
            while(1<2){
			char wish;
			cout<<"Do you wish to copy further? Y/N"<<endl;
			cin>>wish;
			if(wish=='N'){
				o=1;
				break;
			}
			else if(wish=='Y'){
				o=0;
				break;
			}	
			else{
				cout<<"Please give correct input"<<endl;
				continue;
			}
		}
		if(o==1){
			cout<<"---------------------------------------------------\n"<<endl;
			break;
		}
        }
			cout<<"Data is copied\n"<<endl;
		}
     
        else if(choice ==7){
            cout<<setw(6)<<"Sr No."<<setw(20)<<"Name"<<setw(15)<<"Roll No."<<setw(15)<<"Class"<<setw(15)<<"Division"<<setw(20)<<"Date Of Birth"<<setw(15)<<"BloodGroup"<<setw(40)<<"Address"<<setw(20)<<"Contact"<<setw(20)<<"License No.\n"<<endl;
cout<<"________________________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
			for (int j=0;j<i;j++){
				s[j]->displayall();
			}
			cout<<"-------------------------------------------------------------------\n"<<endl;
            student::x=1;
        }   
            
        
        else if(choice==-1){
            for(int m=0;m<i;m++)
        {
            delete (s[m]);                                              //delete keyword
        }
        cout<<"Database is deleted"<<endl;
        cout<<"THANK YOU!!"<<endl;
        break;
        }

}
return 0;

}