/*
    Problem Statement::
        Implement a class Complex which represents the Complex Number data type. Implement the following
            1.	Constructor (including a default constructor which creates the complex number 0+0i).
            2.	Overload operator+ to add two complex numbers.
            3.	Overload operator* to multiply two complex numbers.
            4.	Overload operators << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;
class complex{
public:
    double real,img;
    complex(){
        real=0;                                                              // default constructor
        img=0;

    }
    complex operator+(const complex &c);
    complex operator*(const complex &c );
    complex operator-(const complex &c);
    complex operator/(const complex &c);
    friend std::ostream &operator<<(std::ostream &os, const complex &c){
        if(c.img<0){
            cout<<c.real<<"-"<<abs(c.img)<<"i"<<"\n";                            //over loading stream insertion operator
            return os;
        }
        else {
            cout<<c.real<<"+"<<c.img<<"i"<<"\n";
            return os;
        }
    }
    friend std::istream &operator>>(std::istream &in,complex &c)
    {
        in>>c.real>>c.img;													//over loading stream extraction operator
        return in;
    }
	void show(){
    	if(img<0){
    	   cout<<real<<"-"<<abs(img)<<"i"<<"\n";
    	      }
    	 else {
    	   cout<<real<<"+"<<img<<"i"<<"\n";
    	        }
	}


    ~complex(){};

};
complex complex::operator+(const complex &c)
{
    complex temp;
    temp.real=real+c.real;													//  overloading + operator
    temp.img=img+c.img;
    return temp;
}


complex complex::operator*(const complex &c)

{
    complex temp;
    temp.real=(real*c.real)-(img*c.img);
    temp.img=(real*c.img)+(img*c.real);										//  overloading * operator
    return temp;

}

complex complex::operator-(const complex &c)
{
    complex temp;
    temp.real=real-c.real;													//  overloading - operator
    temp.img=img-c.img;
    return temp;
}

complex complex::operator/(const complex &c)
{
    complex temp;
    temp.real=((real*c.real)+(img*c.img))/((c.real*c.real)+(c.img*c.img));
    temp.img=((img*c.real)-(real*c.img))/((c.real*c.real)+(c.img*c.img));		//  overloading / operator
    return temp;
}
int main(){
    complex c1,c2;
    complex c4;
    cout<<"c4 is the complex number which is not taken as input and uses default constructor \n ";
    c4.show();
    char choice;
    cout<<"Enter 1st Complex number in a+ib (separated by space) \n";
    cin>>c1;
    cout<<"Enter 2nd Complex number in a+ib (separated by space) \n";
    cin>>c2;
    cout<<"The complex numbers are"<<endl;
    cout<<"The first complex number entered is : ";
    c1.show();
    cout<<"The second complex number entered  is : ";
    c2.show();

    while(true){
        cout<<"operations involved are \n";
        cout<<"'+' to add \n '*' to multiply \n '/' to divide\n '-' to subtract ";
        cin>>choice;
        if(choice=='+')
        {
            complex C3;
            C3=c1+c2;
            cout<<"The addition of two complex numbers is ->  ";
            cout<<C3;
        }
        else if(choice=='*')
        {
            complex C3;
            C3=c1*c2;
            cout<<"The multiplication of two complex number is -> ";
            cout<<C3;
        }
        else if(choice=='-'){
            complex c3;
            c3=c1-c2;
            cout<<"The Subtraction  of two complex number is -> ";
            cout<<c3;
        }
        else if(choice=='/'){
            complex c3;
            c3=c1/c2;
            cout<<"The divison of two complex number is -> ";
            cout<<c3;
        }
        else{
            break;
        }
    }
}
