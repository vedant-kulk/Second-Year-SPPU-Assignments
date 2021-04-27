/* 
Problem Statement
====================================================================================================
    Beginning with an empty binary tree, Construct binary tree by inserting the values in 
    the order given. After constructing a binary tree perform following operations on it-
            • Perform inorder / preorder and post order traversal
            • Change a tree so that the roles of the left and right pointers are swapped at every node 
            • Find the height of tree
            • Copy this tree to another [operator=] 
            • Count number of leaves, number of internal nodes. 
            • Erase all nodes in a binary tree. 
    (Implement both Recursive and Non-Recursive methods)
====================================================================================================


*/
#include <iostream>
using namespace std;
#define Max 20


class Node{
    int data;
    Node *lchild;
    Node *rchild;
    
public:
    Node(){
        data=0;
        lchild=NULL;                                //Node class
        rchild=NULL;
    }
    Node(int n){
        data=n;
        lchild=NULL;
        rchild=NULL;
    }
    int getData(){
        return data;
    }
    void set(int n){
        data=n;
    }
    
   
    friend class Queue;
    friend class Stack;
    friend class Binary;                       //Declaration of Friend Class
};

class Queue{
    int front,rear;
    Node *item[Max];
    
public:
    Queue(){
        front=rear=-1;
    }
    void insert(Node *d);                            //Queue class
    
    Node* Delete();
    
    bool qfull();
    
    bool qempty();
    
    int size();
    
     void display(){
         for (int i = front; i <= rear; i++){
            cout<<item[i]->getData()<<" ";
            cout<<endl;
         
         }
     }
        
        
};
class Stack{
    int top;
    Node *item[Max];
    
public:
    Stack(){
        top=-1;                                                 //Stack Class
    }
    void push(Node *d);
    
    Node* pop();
    
    bool sfull();
    
    bool sempty();
    
   
};

class Binary{
    Node *root;
public:
    Binary(){
        root=NULL;
    }                                                          //Binary tree class
    
    Binary(const Binary&b1){
        Queue q1;
        Queue q2;
        root=new Node();
        q1.insert(b1.root);
        q2.insert(root);
        while(!q1.qempty()){
            Node *temp1=q1.Delete();
            Node *temp2=q2.Delete();
            if(temp1!=NULL){
                int n=temp1->data;
                temp2->data=n;
                if(temp1->lchild!=NULL){
                    q1.insert(temp1->lchild);
                    Node *l=new Node();
                    temp2->lchild=l;
                    q2.insert(l);
                }
                else{
                    temp2->lchild=NULL;
                }
                if(temp1->rchild!=NULL){
                    q1.insert(temp1->rchild);
                    Node *r=new Node();
                    temp2->rchild=r;
                    q2.insert(r);
                }
                else{
                    temp2->rchild=NULL;
                }
            }
            else{
                temp2=NULL;
            }
        }
        
    }
    
    Node *copyRecursive(Node *t){
		if(t==NULL)
			return NULL;
		Node* temp = new Node(t->data);
		temp->lchild = copyRecursive(t->lchild);
		temp->rchild = copyRecursive(t->rchild);
		return temp;
	}

	void operator=(Binary &b1){
		root=copyRecursive(b1.getRoot());
	}
    
    
    void createTree();
    
    Node* getRoot();
    
    void setRoot(Node *t){
        root=t;
    }
    
    void recursiveInorder(Node *t);
    
    Node* recursiveCreateTree(); 
    
    void recursivePostorder(Node *t);
    
    void recursivePreorder(Node *t);
    
    void NonrecursiveInorder(Node *rt);
    
    void NonrecursivePreorder(Node *rt);
    
    void NonrecursivePostorder(Node *rt);
    
    int NonrecursiveHeight(Node *t);
    
    int recursiveHeight(Node *t);
    
    void recursiveInvert(Node *t);
    
    void NonrecursiveInvert(Node *t);
    
    int countLeafRecursive(Node *t);
    
    void countLeafIterative(Node *t);
    
    int countInternalRecursive(Node *t);
    
    void countInternalIterative(Node *t);
    
    void deleteIterative();
    
    void deleteRecursive(Node *t);

    
};

void Binary::createTree(){
    Queue q;
    int x;
    char ch;
    int num;
    cout<<"Enter root data ->";                    //Function to create Binary Tree by Non Recursive Approach using Queue class
    cin>>x;
    Node *temp=new Node(x);
    if(root==NULL){
        root=temp;
        q.insert(root);
        
    }
    while(!q.qempty()){
        
        Node *t =q.Delete();
        cout<<"Does "<<t->getData() <<" has Left child ('y' or 'n') -> ";
        cin>>ch;
        cout<<"\n";
        if(ch=='Y' or ch=='y'){
            
            cout<<"Enter data for Left child -> ";
            cin>>num;
            t->lchild=new Node(num);
            q.insert(t->lchild);
        }
        cout<<"\n";
        cout<<"Does "<<t->getData() <<" has Right child ('y' or 'n') -> ";
        cin>>ch;
        cout<<"\n";
        if(ch=='Y' or ch=='y'){
            
            cout<<"Enter data for Right child -> ";
            cin>>num;
            t->rchild=new Node(num);
            q.insert(t->rchild);
        }
        
    }
    
}


Node*Binary::recursiveCreateTree(){
    
    int num;
    cout<<"Enter data or -1 for no data -> ";
    cin>>num;
    if(num==-1){
        return NULL;
    }
    cout<<"\n\n";
    Node* p =new Node(num);                                            //Function to Create Binary Tree by Recursive Approach 
    cout<<"Enter Left child data of "<<p->data<<endl;
    p->lchild= recursiveCreateTree();
    cout<<"\n\n";
    cout<<"Enter Right child data of "<<p->data<<endl;
    p->rchild= recursiveCreateTree();
    
    return p;
    
    
}

Node* Binary::getRoot(){
    return root;                                    //Function to get root of Binary tree
}

void Binary::recursiveInorder(Node *t){
    if(t!=NULL){
        recursiveInorder(t->lchild);                  //Recursive Inorder Traversal
        cout<<t->data<<" ";
        recursiveInorder(t->rchild);
    }
}

void Binary::recursivePostorder(Node *t){
    if(t!=NULL){
        recursivePostorder(t->lchild);
        recursivePostorder(t->rchild);                //Recursive Post Order Traversal
        cout<<t->data<<" ";
    }
}

void Binary::recursivePreorder(Node *t){
     if(t!=NULL){
        cout<<t->data<<" ";
        recursivePreorder(t->lchild);               //Recursive Pre Order Traversal
        recursivePreorder(t->rchild);
        
    }
}

void Binary::NonrecursiveInorder(Node *rt){
    Stack s;
    Node *current = rt;
    while (current != NULL || !s.sempty()){                    //Non-Recursive Inorder Traversal Using Stack Class
    while(current!=NULL){
        s.push(current);
        current=current->lchild;
    } 
        if(current==NULL and !s.sempty()){
            current=s.pop();
            cout<<current->data<<" ";
            current=current->rchild;
        }
        
    } 
    
}

void Binary::NonrecursivePreorder(Node *rt){
    if(rt==NULL){
        return;
    }
    Node *current;                                                 //Non-Recursive Pre order Traversal Using Stack Class
    Stack s;
    s.push(rt);
    while(!s.sempty()){
        current=s.pop();
        
        cout<<current->data<<" ";
        
        if(current->rchild){
            s.push(current->rchild);
        }
        if(current->lchild){
            s.push(current->lchild);
        }
    }
    

    
}

void Binary::NonrecursivePostorder(Node *rt){
    Stack s1;
    Stack s2;
    Node *temp=NULL;
    s1.push(rt);
    while(!s1.sempty()){
        temp=s1.pop();                                                  //Non-Recursive Post order Traversal Using Stack Class
        s2.push(temp);
        if(temp->lchild){
            s1.push(temp->lchild);
        }
        if(temp->rchild){
            s1.push(temp->rchild);
        }
    }
    while(!s2.sempty()){
        temp=s2.pop();
        cout<<temp->data<<" ";
    }
}


int Binary::NonrecursiveHeight(Node *t){
    int height=-1;
    Node *temp=NULL;
    if(t==NULL){                                                     //Function For height of Tree NON Recursive Method
        return -1;
    }
    Queue q;
    q.insert(t);
    while(!q.qempty()){
        int node_count=q.size();
        height++;
        while(node_count>0){
            temp=q.Delete();
            if(temp->lchild){
                q.insert(temp->lchild);
            }
            if(temp->rchild){
                q.insert(temp->rchild);
            }
            node_count--;
        }
    }
    return height;
}

int Binary::recursiveHeight(Node *t){
    int x,y=0;
    if(t==NULL){                                   //Recursive Function for Height of Tree(1 Node => Height 0)
        return -1;
    }
    x=recursiveHeight(t->lchild);
    y=recursiveHeight(t->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
    
}

void Binary::recursiveInvert(Node *t){                                       //Recursive Funcion to swap pointers
    if(t==NULL){
        return ;
    }
    Node *temp = t->lchild;
    t->lchild=t->rchild;
    t->rchild=temp;
    recursiveInvert(t->lchild);
    recursiveInvert(t->rchild);
    
}

void Binary::NonrecursiveInvert(Node *t){                                   //Non Recursive Funcion to swap pointers
    if(t==NULL){
        return;
    }
    Node *current;
    Stack s;
    s.push(t);
    while(!s.sempty()){
        current=s.pop();
        Node *temp = current->lchild;
        current->lchild=current->rchild;
        current->rchild=temp;
        if(current->rchild){
            s.push(current->rchild);
        }
        if(current->lchild){
            s.push(current->lchild);
        }
    }
}

int Binary::countLeafRecursive(Node *t){                         //Counting Leaf Node in Recurisve way
    if(t==NULL){
        return 0;
    }
    if(t->lchild==NULL and t->rchild==NULL){
        return 1;
    }
    else{
        return countLeafRecursive(t->lchild)+countLeafRecursive(t->rchild);
    }
}

void Binary::countLeafIterative(Node *t){                      //Counting Leaf Node Iterative
    Node *temp=NULL;
    int cnt=0;
    if(t==NULL){
        return ;
    }
    Queue q;
    q.insert(t);
    while(!q.qempty()){
        temp=q.Delete();
        if(temp->lchild){
            q.insert(temp->lchild);
        }
        if(temp->rchild){
            q.insert(temp->rchild);
        }
        if(temp->lchild==NULL and temp->rchild==NULL){
            cnt++;
        }
    }
    cout<<"Number of leaf Nodes are -> "<<cnt<<endl;
    cout<<"\n\n";
}

int Binary::countInternalRecursive(Node *t){                         //Counting Internal Node in Recurisve way
    if(t==NULL || (!t->lchild and !t->rchild)){
        return 0;
    }
    else{
        return 1+countInternalRecursive(t->lchild)+countInternalRecursive(t->rchild);
    }
}

void Binary::countInternalIterative(Node *t){                      //Counting Internal Node Iterative
    Node *temp=NULL;
    int cnt=0;
    if(t==NULL){
        return ;
    }
    Queue q;
    q.insert(t);
    while(!q.qempty()){
        temp=q.Delete();
        if(temp->lchild){
            q.insert(temp->lchild);
        }
        if(temp->rchild){
            q.insert(temp->rchild);
        }
        if(temp->lchild || temp->rchild){
            cnt++;
        }
    }
    cout<<"Number of Internal Nodes are -> "<<cnt<<endl;
    cout<<"\n\n";
}


void Binary::deleteIterative(){
    if(root==NULL){
        cout<<"Tree Not found to be deleted"<<endl;                             //Iterative Approach to Delete Binary Tree
        return;
    }
    Queue q;
    q.insert(root);
    while(!q.qempty()){
        Node *temp=q.Delete();
        if(temp->lchild){
            q.insert(temp->lchild);
        }
        if(temp->rchild){
            q.insert(temp->rchild);
        }
        delete temp;
    }
    cout<<"Tree has been deleted"<<endl;
    cout<<"\n\n";
    root=NULL;
}

void Binary::deleteRecursive(Node *t){
    
    if(t==NULL){
        return;
    }
    deleteRecursive(t->lchild);                                    //Recursive Approach to Delete Binary Tree
	deleteRecursive(t->rchild);
	if(t==root){
		delete t;
		root=NULL;
		return;
	}
    delete t;
}

void Queue::insert(Node *d){
    if(qfull()){
            cout<<"Queue Overflow"<<endl;                //Function to Insert data in Queue
        }
        else{
            if(front==-1){
                front=0;
            }
            rear=rear+1;
            item[rear]=d;
            
        }
}

Node* Queue::Delete(){
        Node *c=NULL;
        if(qempty()){
            cout<<"Underflow"<<endl;
            return NULL;                                       //Function to delelte data from Queue
        }
        else{
            c=item[front];
            front++;
            return c;
           
        }
         
}

int Queue::size(){
    return (rear-front)+1;
}

void Stack::push(Node *d){
    if(sfull()){
            cout<<"Overflow"<<endl;
        }
        else{                                                     //Function to perform push operation on stack
            top++;
            item[top]=d;
        }
}

Node* Stack::pop(){
     Node* c=NULL;                                                   //Function to perform pop operation on stack
        if(sempty()){
            cout<<"Underflow"<<endl;
            return NULL;
        }
        else{
            c=item[top];
            top--;
            return c;
            
        }
        
}


bool Queue::qfull(){
    if(rear==Max-1){
        return true;
    }
    return false;
}

bool Queue::qempty(){
    if(front==-1 or front ==rear+1){
    return true;
    }
    return false;
    
}

bool Stack::sfull(){
    if(top==Max-1){
        return true;
    }
    return false;
}

bool Stack::sempty(){
    if(top==-1){
        return true;
    }
    return false;
}

int main(){
    int ch;
    Binary b;
    while(1){
    cout<<"---------------------------------------------"<<endl;
    cout<<"Menu "<<endl;
    cout<<"1 Binary Tree By Non Recursive Approach"<<endl;
    cout<<"2 Binary Tree By Recursive Approach"<<endl;
    cout<<"-1 To Exit"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"\n\n";
    cout<<"Enter choice -> ";
    cin>>ch;
    if(ch==1){
        int choice;
        cout<<"---------------------------------------------"<<endl;
        cout<<"\tMenu"<<endl;
        cout<<"\t1: Create a Binary Tree"<<endl;
        cout<<"\t2: Non Recursive Inorder Traversal"<<endl;
        cout<<"\t3: Non Recursive Preorder Traversal"<<endl;
        cout<<"\t4: Non Recursive Postorder Traversal"<<endl;
        cout<<"\t5: Swap Left and Right Child"<<endl;
        cout<<"\t6: Count Leaf Nodes"<<endl;
        cout<<"\t7: Count Internal Nodes"<<endl;
        cout<<"\t8: Height of a Tree"<<endl;
        cout<<"\t9: Copy Tree"<<endl;
        cout<<"\t10: Delete the Tree"<<endl;
        cout<<"\t-1: Exit"<<endl;
        cout<<"---------------------------------------------\n\n"<<endl;
        while(1){
            cout<<"Enter you choice -> ";
            cin>>choice;
            if(choice==1){
                b.createTree();
                cout<<"\n\n";
            }
            else if(choice==2){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Non Recursive Inorder Traversal (L,RT,R)->  ";
                    b.NonrecursiveInorder(root);
                    cout<<"\n\n";
                }
            }
            else if(choice==3){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Non Recursive Preorder Traversal (RT,L,R) -> ";
                    b.NonrecursivePreorder(root);
                    cout<<"\n\n";
                }
            }
            else if(choice==4){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Non Recursive Postorder Traversal (L,R,RT)-> ";
                    b.NonrecursivePostorder(root);
                    cout<<"\n\n";
                }
            }
            else if(choice==5){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    b.NonrecursiveInvert(root);
                    cout<<"\n\n";
                    cout<<"Non Recursive Inorder Traversal (L,RT,R) After Swapping ->  ";
                    b.NonrecursiveInorder(root);
                    cout<<"\n\n";
                }
            }
            else if(choice==6){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    b.countLeafIterative(root);
                }
            }
            else if(choice==7){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    b.countInternalIterative(root);
                }
            }
            else if(choice==8){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                cout<<"Height of tree is "<<b.NonrecursiveHeight(root);
                cout<<"\n\n";
                }
            }
            else if(choice==9){
                Binary b2=b;
                Node* root=b2.getRoot();
                if(root==NULL){
                    cout<<"Tree was not copied"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Copying of tree was Successfull"<<endl;
                    cout<<"Non Recursive Inorder Traversal (L,RT,R)->  ";
                    b.NonrecursiveInorder(root);
                    cout<<"\n\n";
                }
                
            }
            else if(choice==10){
                Node* root=b.getRoot();
                if(root==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    b.deleteIterative();
                }
            }
            else if(choice==-1){
                break;
            }
            else{
                cout<<"Wrong choice \n\n";
            }
        
    }
    }
    else if(ch==2){
        int choice;
        cout<<"---------------------------------------------"<<endl;
        cout<<"\tMenu"<<endl;
        cout<<"\t1: Create a Binary Tree"<<endl;
        cout<<"\t2: Recursive Inorder Traversal"<<endl;
        cout<<"\t3: Recursive Preorder Traversal"<<endl;
        cout<<"\t4: Recursive Postorder Traversal"<<endl;
        cout<<"\t5: Swap Left and Right Child"<<endl;
        cout<<"\t6: Count Leaf Nodes"<<endl;
        cout<<"\t7: Count Internal Nodes"<<endl;
        cout<<"\t8: Height of a Tree"<<endl;
        cout<<"\t9: Copy Tree"<<endl;
        cout<<"\t10: Delete the Tree"<<endl;
        cout<<"\t-1: Exit"<<endl;
        cout<<"---------------------------------------------\n\n"<<endl;
        while(1){
            cout<<"Enter your choice -> ";
            cin>>choice;
            if(choice==1){
                b.setRoot(b.recursiveCreateTree());
                cout<<"\n\n";
            }
            else if (choice==2){
                if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Recursive Inorder Traversal (L,RT,R)->  ";
                    b.recursiveInorder(b.getRoot());
                    cout<<"\n\n";
                }
            }
            else if(choice==3){
                if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Recursive Preorder Traversal (L,R,RT)-> ";
                    b.recursivePreorder(b.getRoot());
                    cout<<"\n\n";
                }
            }
            else if(choice==4){
                if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    cout<<"Recursive Postorder Traversal (L,R,RT)-> ";
                    b.recursivePostorder(b.getRoot());
                    cout<<"\n\n";
                }
            }
            else if(choice==5){
                if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
            }
            else{
                 b.recursiveInvert(b.getRoot());
                cout<<" Recursive Inorder Traversal (L,RT,R) After->  ";
                b.recursiveInorder(b.getRoot());
                cout<<"\n\n";
            }
        }
        else if(choice==6){
            if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
            }
            else{
                cout<<" Number of Leaf Nodes are -> "<<b.countLeafRecursive(b.getRoot());
                cout<<"\n\n";
            }
        }
        else if(choice==7){
            if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
            }
            else{
                cout<<"Number of Internal Nodes are -> "<<b.countInternalRecursive(b.getRoot());
                cout<<"\n\n";
            }
        }
        else if(choice==8){
            if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
            }
            else{
                cout<<"Height of tree is "<<b.recursiveHeight(b.getRoot());
                cout<<"\n\n";
            }
        }
         else if(choice==9){
                Binary b2;
                b2=b;
                
                cout<<"Recursive Inorder Traversal of Copied Tree (L,RT,R)->  ";
                b2.recursiveInorder(b2.getRoot());
                cout<<"\n\n";
                
            }
            else if(choice==10){
 
                if(b.getRoot()==NULL){
                    cout<<"Tree was not created"<<endl;
                    cout<<"\n\n";
                }
                else{
                    b.deleteRecursive(b.getRoot());
                }
            }
            else if(choice==-1){
                break;
            }
            else{
                cout<<"Wrong choice \n\n";
            }
       
   }
    }
    else if(ch==-1){
        break;
    }
    
    }
    
}
   