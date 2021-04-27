/*
====================================================================================================
Problem Statement:
    Create an inordered threaded binary tree and perform inorder and preorder traversals. 
    Analyze time and space complexity of the algorithm.
====================================================================================================
*/
#include <iostream>
using namespace std;


class Node{
    int data;
    int lbit;
    int rbit;
    Node *lchild;
    Node *rchild;

public:
    Node(){
        data=0;
        lbit=0;
        rbit=0;
        lchild=NULL;                                //Node class
        rchild=NULL;
    }
    Node(int x){
        data=x;
        lbit=0;
        rbit=0;
        lchild=NULL;                                
        rchild=NULL;
    }
    
    


    friend class TBT;                       //Declaration of Friend Class
};

class TBT{
    Node *root;
    Node *header;

public:
    TBT(){
        root=NULL;
        header=NULL;

    }
    void insert(int key);
    void inorder(Node *t);
    void preorder(Node *t);
    Node *getRoot();
    int search(int key,Node *&loc,Node *&par);
    void delete_tbt(int key);
};
Node* TBT::getRoot(){
    return root;
}
                                  
void TBT::insert(int key){                     //Insert in TBT
    if(root==NULL){
        header=new Node(-99);
        header->rchild=header;
        root=new Node(key);
        root->lchild=header;
        root->rchild=header;
        header->lchild=root;
        header->lbit=1;
    }
    else{
        Node *ptr=root;
        Node *temp=new Node(key);
        while(1){
            if(ptr->data>key){
                if(ptr->lbit!=0){
                    ptr=ptr->lchild;
                }
                else{
                    temp->lchild=ptr->lchild;
                    temp->rchild=ptr;
                    ptr->lchild=temp;
                    ptr->lbit=1;
                    
                    return;
                    
                }
            }
            else{
                if(ptr->rbit!=0){
                    ptr=ptr->rchild;
                }
                else{
                    temp->lchild=ptr;
                    temp->rchild=ptr->rchild;
                    ptr->rchild=temp;
                    ptr->rbit=1;
                    return;
                }
            }
        }
        
    }
}
void TBT::inorder(Node *t){
    cout<<"Inorder Traversal ->";
    while(t->lbit!=0){
        t=t->lchild;
    }
    while(t!=header){
        cout<<t->data<<" ";
        if(t->rbit!=0){
            t=t->rchild;
            while(t->lbit!=0){
                t=t->lchild;
            }
        }
        else{
            t=t->rchild;
        }
    }
}
void TBT::preorder(Node *t){
//    while(t!=header){
//        cout<<t->data<<endl;
//        if(t->lbit==1){
//            t=t->lchild;
//        }
//        else{
//            if(t->rbit==1){
//                t=t->rchild;
//            }
//            else{
//                while(t->rbit!=1){
//                    t=t->rchild;
//                }
//                t=t->rchild;
//            }
//        }
//            
//        
//    }
    int flag=0;
    cout<<"Preorder Traversal ->";
    while(t!=header){
        if(flag==0){
            cout<<t->data<<" ";
            
        }
        if(flag==0 and t->lbit==1){
            t=t->lchild;
        }
        else{
            if(t->rbit==1){
                flag=0;
            }
            else{
                flag=1;
            }
            t=t->rchild;
            
        }
    }
}
int TBT::search(int key,Node *&loc,Node *&par){
    Node *ptr;
    int flag=0;                                 //-1 tree not found
    if(root==NULL){                             // 1 key found ,0 key not found
        loc=par=NULL;
        return -1;
    }
   
    par=NULL;
    loc=NULL;
    ptr=root;
    while(1){
        if(key==ptr->data){
            loc=ptr;
            flag=1;
            break;
        }
        else if(key<ptr->data){
            if(ptr->lbit==1){
            par=ptr;
            ptr=ptr->lchild;
            
            }
            else{
                break;
            }
        }
        else{
            if(ptr->rbit==1){
            par=ptr;
            ptr=ptr->rchild;
            }
            else{
                break;
            }
        }
    }
    return flag;
    
}
void TBT::delete_tbt(int key){
    Node *loc=NULL;
    Node *par=NULL;
    int flag=search(key,loc,par);
    if(flag==-1){
        cout<<"Tree not found"<<endl;
        cout<<"______________________________\n\n";    
    }
    else if(flag==0){
        cout<<"Key not Found"<<endl;
        cout<<"______________________________\n\n";    
    }
    else{
        if(loc->lbit==1 and loc->rbit==1){
            par=loc;
            Node *inorder_succ=loc->rchild;
            while(inorder_succ->lbit!=0){
                par=inorder_succ;                                        // if Node has both left and right child
                inorder_succ=inorder_succ->lchild;
            }
            loc->data=inorder_succ->data;
            loc=inorder_succ;
        }
        
        
        if(loc->lbit==0 and loc->rbit==0){
            if(par!=NULL){
                if(par->lchild==loc){                                            // if Node is leaf Node
                    par->lchild=loc->lchild;
                    par->lbit=0;
                }
                else{
                    par->rchild=loc->rchild;
                    par->rbit=0;
                }
                delete(loc);
            
            }
            else{
                delete(loc);
                header->lchild = NULL;
                root=NULL;                                       //This else is to handle if root was to be deleted and it had no child;
                
            }
            
            
        }
        
        
        if(loc->lbit==1 and loc->rbit==0){
            Node *temp=loc->lchild;
            if(par!=NULL){
               if(par->lchild==loc){                                      //Node has only left child
                    par->lchild=temp;
                }
                else{
                    par->rchild=temp;
                }
            
                while(temp->rbit==1){
                    temp=temp->rchild;
                }
                temp->rchild=loc->rchild;
            
            }
            else{
                while(temp->rbit==1){
                    temp=temp->rchild;
                }
                temp->rchild=loc->rchild;                               //for deleting root 
                root=temp;
                header->lchild=root;
                
            }
            delete(loc);
        }
        
        if(loc->lbit==0 and loc->rbit==1){                          //Node has only right child
            Node *temp=loc->rchild;
             if(par!=NULL){
            if(par->lchild==loc){
                par->lchild=temp;
            }
            else{
                par->rchild=temp;
            }
           
            while(temp->lbit==1){
                temp=temp->lchild;
            }
            temp->lchild=loc->lchild;
            
            }
            else{
                while(temp->lbit==1){
                    temp=temp->lchild;
                }
                temp->lchild=loc->lchild;                         // for deleting root
                root=temp;
                header->rchild=root;
            }
            delete(loc);
            
        }
        
        cout<<"Deleted Succesfully"<<endl;
        cout<<"______________________________\n\n";    }
    
}
int main(){
    TBT b;
    int choice;
    int key;
    
    cout<<"--------------------------------------------------"<<endl;
    cout<<"MENU"<<endl;
    cout<<"1: Insert New Key"<<endl;
    cout<<"2: Display Inorder"<<endl;
    cout<<"3: Display Preorder"<<endl;
    cout<<"4: Delete a Key"<<endl;
    
    cout<<"-1: Exit"<<endl;
    cout<<"--------------------------------------------------"<<endl;

    while(1){
        cout<<"Enter your choice -> ";
        cin>>choice;
        if(choice==1){
            Node *loc=NULL;
            Node *par=NULL;
            while(true){
			cout<<"Press 0 to exit"<<endl;
			cout<<"Enter key  ";
			cin>>key;
			if(key==0){
				cout<<"______________________________"<<endl;
				break;
			}
			else{
				int flag=b.search(key,loc,par);
                if(flag==1){
                    cout<<"Key Already Present "<<endl;
                    cout<<"______________________________"<<endl;
                }
                else{
				b.insert(key);
                cout<<"______________________________"<<endl;
                
                }
                }

          }

        }
        else if(choice==2){
        	if(b.getRoot()==NULL){
        	       cout<<"Tree is Empty"<<endl;
        	        }
        	else{
            b.inorder(b.getRoot());
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
            b.preorder(b.getRoot());
        	}
        	cout<<"\n";
             cout<<"______________________________"<<endl;
            cout<<"\n\n";
        }
        else if(choice==4){
            int delkey;
            cout<<"Enter key to be deleted -> " ;
            cin>>delkey;
            b.delete_tbt(delkey);
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
/*             6
            /    \
           4      10
          /       / \
         3       7  11
*/