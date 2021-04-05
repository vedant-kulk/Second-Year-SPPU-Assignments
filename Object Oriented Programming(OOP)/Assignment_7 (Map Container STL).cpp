/*
    Problem Statement::
        Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states.
        When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and 
        returns the population of the state.
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
string Capitalize_first_letter(string text){
	for (int x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);         //function to capialize first letter of the string
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}
	return text;
}



int main(){
    int choice;
    string s;
    string states[29]={"Uttar Pradesh", "Maharashtra", "Bihar", "West Bengal", "Madhya Pradesh", "Tamil Nadu", "Rajasthan", "Karnataka", "Gujarat",
                        "Andhra Pradesh", "Odisha", "Telangana", "Kerala", "Jharkhand", "Assam", "Punjab", "Chhattisgarh", "Haryana", "Jammu and Kashmir",
                        "Uttarakhand", "Himachal Pradesh", "Tripura", "Meghalaya", "Manipur", "Nagaland", "Goa", "Arunachal Pradesh", "Mizoram",
                        "Sikkim"};
	long long int population[29]={199812341,112374333,104099452,91276115,72626809,72147030,
                                  68548437,61095297,60439692,49577103,41974219,35003674,
								  33406061,32988134,31205576,27743338,25545198,25351462,
                                  12267032,10086292,6864602,3673917,2966889,
								  2570390,1978502,1458545,1383727,1097206,610577};
                             
    map<string,long long int>india;
    for(int i=0;i<29;i++){                                     //declaring a map named as india and using insert function to append states and 
                                                                // its corresponding population
		india.insert({states[i],population[i]});
        
    }
    cout<<"__________________________________________________________"<<endl;
    cout<<"MENU"<<endl;
    cout<<"1: Input a State  to see its population"<<endl;
    cout<<"2: Entire map"<<endl;
    cout<<"-1 : Exit"<<endl;
    cout<<"__________________________________________________________"<<endl;
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
            cout<<"Enter the State"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            s=Capitalize_first_letter(s);
            auto itr = india.find(s);
            if(itr==india.end()){
                cout<<"This is not a state of India"<<endl;
                cout<<"----------------------------------------------------";
                cout<<"\n\n"<<endl;
            }
            else{
            
            cout<<"Population of "<<s<<" is-> "<<india[s]<<endl;
            cout<<"----------------------------------------------------";
            cout<<"\n\n"<<endl;
            }
        }
        else if(choice==2){
            cout<<'\t'<<left<<setw(25)<<"State Name"<<setw(30)<<"Population"<<endl;
            cout<<"----------------------------------------------\n"<<endl;
            for (auto itr = india.begin(); itr != india.end(); ++itr) {
            cout<<'\t'<<left<<setw(25)<<itr->first<<setw(30)<< itr->second << '\n';
            }
            cout<<"----------------------------------------------------";
            cout<<"\n\n"<<endl;
        }
        else{
            cout<<"Wrong choice "<<endl;
        }
        
        
    }
    
    
    
    
    
}
   