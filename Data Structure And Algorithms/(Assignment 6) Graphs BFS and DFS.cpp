/*
Problem Statement
    Represent a given graph using adjacency matrix/list to perform DFS and using 
    adjacency list to perform BFS. Use the map of the area around the college as the 
    graph. Identify the prominent land marks as nodes and perform DFS and BFS on 
    that.
*/




#include <iostream>
#include<vector>
#include<queue>
#include<iterator>
#include<stack>
using namespace std;

class Graph{
    int vertex,edge;
    vector <int> *adjlist;
public:
    Graph(){
        vertex=0;
        edge=0;
        adjlist=NULL;
    }
    Graph(int v,int e){
        vertex=v;
        edge=e;
        adjlist=new vector <int> [v];
    }
    
    void input(){
        int v1,v2;
        for(int i=0;i<edge;i++){
            cout<<"Edge No "<<i+1<<" "<<endl;
            cout<<"Enter the Vertices Separated by Space -> ";
            cin>>v1>>v2;
            cout<<"________________________________\n"<<endl;
            adjlist[v1].push_back(v2);
            adjlist[v2].push_back(v1);
        }
    }
    void display_graph(){
        for(int i=0;i<vertex;i++){
            cout<<i<<"-->";
            for(auto x: adjlist[i]){
                cout<<x<<" ";
            }
            cout<<endl;
            
        }
        cout<<"________________________________"<<endl;
    }
    void BFS(int v){
        bool visited[vertex] ={false};
        cout<<"BFS is --> ";
        
        queue <int> q;
        visited[v]=true;
        q.push(v);
        
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            cout<<temp<<"  ";
            
            vector <int>::iterator it;
			for (it = adjlist[temp].begin(); it != adjlist[temp].end(); ++it) {
				if(!visited[*it]){
                    visited[*it]=true;
                    q.push(*it);
                }
			}
        }
        cout<<endl;
        cout<<"________________________________"<<endl;
       
    }
    
    
    void DFS(int v){
        bool visited[vertex] ={false};
        cout<<"DFS is --> ";
        
        
        stack <int> s;
        
        visited[v]=true;
        s.push(v);
        
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            cout<<temp<<" ";
            
            vector <int>::iterator it;
			for (it = adjlist[temp].begin(); it != adjlist[temp].end(); ++it) {
                    if(!visited[*it]){
                        visited[*it]=true;
                        s.push(*it);
                    }
                }
        }
        cout<<endl;
        cout<<"________________________________"<<endl;
    }
    
    
};

int main(){
    int choice;
    Graph *g;
        cout<<"_________________________________________"<<endl;
        cout<<"1: Enter Edges of graph"<<endl;
        cout<<"2: Display  Adjacency List  " <<endl;
        cout<<"3: Breadth First Traversal (BFS)"<<endl;
        cout<<"4: Depth First Traversal (DFS)"<<endl;
        cout<<"_________________________________________\n"<<endl;
    while(1){
        cout<<"Enter choice -> ";
        cin>>choice;
        cout<<"\n\n";
        if(choice==1){
            int v,e;
            cout<<"Enter number of vertices -> ";
            cin>>v;
            cout<<"enter number of edges - > ";
            cin>>e;
            cout<<"\n\n";
            g=new Graph(v,e);
            g->input();
        }
        else if(choice==2){
            g->display_graph();
        }
        else if(choice==3){
            int v;
            cout<<"Enter the vertex to start with BFS -> ";
            cin>>v;
            g->BFS(v);
        }
        else if(choice==4){
            int v;
            cout<<"Enter the vertex to start with DFS -> ";
            cin>>v;
            g->DFS(v);
        }
        else{
            break;
        }
        
        
    }
}
   
