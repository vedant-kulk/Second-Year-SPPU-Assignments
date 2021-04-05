/*
Problem Statement::
    Write a function template for selection sort that inputs, sorts and outputs an integer array and
    a float array.
*/


#include <iostream>
#include <limits>
using namespace std;

template <class D>
void display(D array[],int n){
    int ch;
    char con;
    while(1){                                                                 //template function for displaying array in aescending
                                                                              // and desending order 
    cout<<"Enter your choice \n 1:Aescending order \n 2:Descending order-->";
    cin>>ch;
    if(ch==1){
        cout<<"[";
        for(int i=0;i<n;i++){
            if(i!=n-1)
                cout<<array[i]<<" , ";
            else
                cout<<array[i]<<" ";
        }
        cout<<"]";
        cout<<"\n\n";
        cout<<"------------------"<<endl;
    }
    else{
        cout<<"[";
        for(int i=n-1;i>=0;i--){
            if(i!=0)
                cout<<array[i]<<" , ";
            else
                cout<<array[i]<<" ";
        }
        cout<<"]";
        cout<<"\n\n";
        cout<<"------------------"<<endl;
            
    }
    cout<<"Do you wish to continue Y/N --> ";
    cin>>con;
    if(con=='N' or con =='n'){
        cout<<"------------------"<<endl;
        break;
    }
    }
}


template <class S>
void swap(S *x,S *y){
    S temp= *x;
    *x=*y;                                              //template function for swapping elements
    *y=temp;
}


template <class T>
void selection_sort(T a[],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=k=i;j<n;j++){
            if(a[j]<a[k]){
                k=j;                                        //template function for selection sort
            }
        }
        swap(&a[i],&a[k]);
    }
    
    
}

int main(){
    int n=0;
    int m=0;
    int a1[100];
    float a2[100];
    int flagi=0;
    int flagf=0;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Menu"<<endl;
    cout<<"1: Enter the Integer array"<<endl;
    cout<<"2: Enter the Float array"<<endl;
    cout<<"3: Sort the array"<<endl;
    cout<<"4: Display the Sorted array"<<endl;
    cout<<"-----------------------------------------------"<<endl;

    
    while(true){
        int choice;
        cout<<"Enter your choice ->";
        cin>>choice;
        if(choice==1){
            int data;
            cout<<"Enter the number of elements-->";
            cin>>n;
            while(1){
            
            if(n<0){
                cout<< " !! ENTER  A POSITIVE NUMBER"<<endl;
                cout<<"Enter the number of elements-->";
                cin>>n;
            }
            else{
                break;
            }
            }
            cout<<"Enter the elements"<<endl;
            for(int i=0;i<n;i++){
                cout<<"array["<<i+1<<"]->";
                cin>>data;                                                 //takes input as integer array
                while(1){
                if(cin.fail())
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"You have entered wrong input"<<endl;
                cout<<"array["<<i+1<<"]->";
                cin>>data;
                }
                if(!cin.fail()){
                    a1[i]=data;

                    break;                                               //exception handling for characters
                
                }
                }
            }
            cout<<"-----------------------------------------------"<<endl;
            flagi=1;
            
            
        
        }
        else if(choice==2){
            float d;
            cout<<"Enter the number of elements -> ";
            cin>>m;
            while(1){
                if(m<0){
                cout<< " !! ENTER  A POSITIVE NUMBER"<<endl;
                cout<<"Enter the number of elements-->";
                cin>>m;
            }
            else{
                break;
            }
                
            }
                                                                    //take input as float array
            cout<<"Enter the elements"<<endl;
            for(int i=0;i<m;i++){
                cout<<"array["<<i+1<<"]->";
                cin>>d;
                while(1){
                if(cin.fail())
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"You have entered wrong input"<<endl;
                cout<<"array["<<i+1<<"]->";
                cin>>d;
                }
                if(!cin.fail()){
                    a2[i]=d;                                              // exception handling for characters
                    break;
                
                }
            }
        }
        cout<<"-----------------------------------------------"<<endl;
        flagf=1;
        
        
         
    }
        else if(choice==3){
            if(flagi==1 or flagf==1){
             if(flagi==1 and flagf==1){
                selection_sort<int>(a1,n);
                selection_sort<float>(a2,m);
                
            }
            else if(flagi==1){
                selection_sort<int>(a1,n);
            }
            else{
                selection_sort<float>(a2,m);
            }
            cout<<"-----------------------------------------"<<endl;
            cout<<"SORTING HAS BEEN COMPLETED"<<endl;
            cout<<"-----------------------------------------"<<endl;
            }
            else{
                cout<<"No element of either integer or float type are entered"<<endl;
                cout<<"-----------------------------------------------"<<endl;
            }
        }

        else if(choice==4){
            if(flagi==1 or flagf==1){
            if(flagi==1 and flagf==1){
                cout<<"INTEGER array is being displayed"<<endl;
                display<int>(a1,n);
                cout<<"-----------------------------------------------"<<endl;
                cout<<"FLOAT array is being displayed"<<endl;
                display<float>(a2,m);
                
                
            }
            else if(flagi==1){
                display<int>(a1,n);
            }
            else{
                
                display<float>(a2,m);
                
            }
            }
            else{
                cout<<"No element of either integer or float type are entered"<<endl;
                cout<<"-----------------------------------------------"<<endl;
            }
            
        }
        
        else if(choice==-1){
            cout<<" THANK YOU "<<endl;
            break;
        }
        
    }

}

    
