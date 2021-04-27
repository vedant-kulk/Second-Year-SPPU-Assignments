/*
====================================================================================================
Problem Statement
    A Dictionary stores keywords and its meanings. Provide facility for adding new 
    keywords, deleting keywords, updating values of any entry. Provide facility to 
    display whole data sorted in ascending/ Descending order. Also find how many 
    maximum comparisons may require for finding any keyword. Use Binary Search 
    Tree for implementation.
====================================================================================================

*/

#include <iostream>
using namespace std;


class Node{
    string key;
    string value;
    Node *lchild;
    Node *rchild;

public:
    Node(){
        key="";
		value="";
        lchild=NULL;                                //Node class
        rchild=NULL;
    }
    Node(string a, string b){
        key=a;
        value=b;
        rchild=NULL;
        lchild=NULL;
    }
    string getData(){
        return value;
    }
    void set(string a,string b){
        key=a;
        value=b;
    }


    friend class BST;                       //Declaration of Friend Class
};

class BST{
    Node *root;

public:
    BST(){
        root=NULL;

    }
    void search(string s,Node *&loc,Node *&par);
    void insert(string s,string v);
    void delete1(string s,Node *loc,Node *par);
    void delete2(string s,Node *loc,Node *par);
    void deletebst(string s);
    Node *getRoot();
    void disp_ascending(Node *t);
    void disp_descending(Node *t);
    void update(string s);
    void comparison(string s);
};

void BST::search(string s,Node *&loc,Node *&par){
    Node *ptr=NULL;
    if(root==NULL){
//        cout<<"Tree Doesn't Exit"<<endl;
        loc=par=NULL;
        return;
    }
    par=NULL;
    loc=NULL;
    ptr=root;
    while(ptr!=NULL){
        if(s==ptr->key){
            loc=ptr;
//            cout<<"Found"<<endl;
            return;
        }
        else if(s<ptr->key){
            par=ptr;
            ptr=ptr->lchild;
        }
        else{
            par=ptr;
            ptr=ptr->rchild;
        }
    }
//    if(loc==NULL){
//       cout<<"Not Found"<<endl;
//    }
}

void BST::insert(string s,string v ){
    Node *loc=NULL;
    Node *par=NULL;
    search(s,loc,par);
    if(loc!=NULL){
        cout<<"Node is already Present"<<endl;
        return;
    }
     Node *temp=new Node(s,v);
     if(par==NULL){
         root=temp;
     }
     else if(temp->key<par->key){
         par->lchild=temp;
     }
     else{
         par->rchild=temp;
     }

}

void BST::delete1(string s,Node *loc,Node *par){

    Node *child=NULL;
    if(loc->lchild==NULL and loc->rchild==NULL){
        child=NULL;
    }
    else if(loc->lchild!=NULL){
        child=loc->lchild;
    }
    else{
        child=loc->rchild;
    }
    if(par!=NULL){
        if(loc==par->lchild){
            par->lchild=child;
        }
        else{
            par->rchild=child;
        }
    }
    else{
        root=child;
    }
    delete loc;
}

void BST::delete2(string s,Node *loc,Node *par){

    Node *ptr1=loc;
    Node *ptr2=loc->rchild;
    while(ptr2->lchild!=NULL){
        ptr1=ptr2;
        ptr2=ptr2->lchild;
    }
    string newkey=ptr2->key;
    string newvalue=ptr2->value;
    delete1(ptr2->key,ptr2,ptr1);
    loc->key=newkey;
    loc->value=newvalue;
}
void BST::deletebst(string s){
    Node *loc=NULL;
    Node *par=NULL;
    search(s,loc,par);
    if(root==NULL){
        cout<<"Tree is Not Created"<<endl;
    }
    if(loc==NULL){
        cout<<"Node Doesn't Exit"<<endl;
    }
    else if(loc->lchild!=NULL and loc->rchild!=NULL){
        delete2(s,loc,par);
    }
    else{
        delete1(s,loc,par);
    }
}
void BST::disp_ascending(Node *t){
    if(t->lchild!=NULL)
		disp_ascending(t->lchild);
	cout<<"\n" << t->key<<" \t" << t->value;
	if(t->rchild!=NULL)
		disp_ascending(t->rchild);
}

void BST::disp_descending(Node *t){
    if(t->rchild!=NULL)
			disp_descending(t->rchild);
	cout<<"\n" << t->key<<" \t" << t->value;
	if(t->lchild!=NULL)
		disp_descending(t->lchild);
}

void BST::update(string s){
    Node *loc=NULL;
    Node *par=NULL;
    search(s,loc,par);
    string newvalue;
    if(root==NULL){
        cout<<"Tree Not Created"<<endl;
    }
    else if(loc==NULL){
        cout<<"Word Not Found"<<endl;
    }
    else{
        cout<<"Enter the new value of word "<<endl;
        cin>>newvalue;
        loc->value=newvalue;
    }
}

void BST::comparison(string s){
    int count = 0;
    Node *p=root;
	while(p!=NULL)
	{
		if(s < p->key)
		{
			count++;
			p = p->lchild;
		}

		else if(s > p->key)
		{
			count++;
			p = p->rchild;
		}

		else if(s == p->key)
		{
			count++;
            cout<<"Word Found !! -> Number of comparisons -> " << count<<endl;
			return;
		}
	}
    cout<<"Word Not Found !! -> Number of comparisons -> " << count<<endl;


}

Node* BST::getRoot(){
    return root;                                    //Function to get root of Binary tree
}

int main(){
    BST b;
    int choice;
    string key;
    string value;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"MENU"<<endl;
    cout<<"1: Insert New Word"<<endl;
    cout<<"2: Display Words in Ascending Order"<<endl;
    cout<<"3: Display Words in Descending Order"<<endl;
    cout<<"4: Search And Update a Word"<<endl;
    cout<<"5: Delete a Word"<<endl;
    cout<<"6: Find Number of Comparisons"<<endl;
    cout<<"-1: Exit"<<endl;
    cout<<"--------------------------------------------------"<<endl;

    while(1){
        cout<<"Enter your choice -> "<<endl;
        cin>>choice;
        if(choice==1){
            while(true){
			cout<<"Press 0 to exit"<<endl;
			cout<<"Enter key and value -> ";
			cin>>key;
			if(key=="0"){
				cout<<"______________________________"<<endl;
				break;
			}
			else{
				cin>>value;
				b.insert(key,value);
                cout<<"______________________________"<<endl;
                }

          }

        }
        else if(choice==2){
        	if(b.getRoot()==NULL){
        	       cout<<"Tree is Empty"<<endl;
        	        }
        	else{
            b.disp_ascending(b.getRoot());
        	}
        	cout<<"\n";
             cout<<"______________________________"<<endl;
            cout<<"\n\n";
        }
        else if(choice==3){
        	if(b.getRoot()==NULL){
        		cout<<"Tree is Empty"<<endl;
        	}
        	else{
            b.disp_descending(b.getRoot());
        	}
        	cout<<"\n";

             cout<<"______________________________"<<endl;
             cout<<"\n\n";
        }
        else if(choice==4){
            string newkey;
            cout<<"Enter Key to be Updated "<<endl;
            cin>>newkey;
            b.update(newkey);
            cout<<"______________________________"<<endl;
             cout<<"\n\n";

        }
        else if(choice==5){
            string delkey;
            cout<<"Enter the Key to be deleted -> "<<endl;
            cin>>delkey;
            b.deletebst(delkey);
            cout<<"______________________________"<<endl;
             cout<<"\n\n";
        }
        else if(choice==6){
            string comkey;
            cout<<"Enter the key whose comparison are to be found -> ";
            cin>>comkey;
            b.comparison(comkey);
            cout<<"______________________________"<<endl;
            cout<<"\n\n";
        }
        else if(choice==-1){
            break;
        }
        else{
            cout<<"Wrong Choice"<<endl;
            cout<<"______________________________"<<endl;
             cout<<"\n\n";
        }
    }
}
