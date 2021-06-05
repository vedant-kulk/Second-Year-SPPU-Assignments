/*
Problem Statement
    You have a business with several offices; you want to lease phone lines to connect 
    them up with each other; and the phone company charges different amounts of 
    money to connect different pairs of cities. You want a set of lines that connects all 
    your offices with a minimum total cost. Solve the problem by suggesting appropriate 
    data structures.

*/


#include <iostream>
#include <iomanip>
#define INF 9999999
using namespace std;


class Graph{
    int vertex,edge;
    int **adjmatrix;
    
public:
    Graph(){
        vertex=0;
        edge=0;
        adjmatrix=NULL;
    }
    Graph(int v,int e){
        vertex=v;
        edge=e;
        adjmatrix=new int*[v];
        for (int i = 0; i < v; i++) {
            adjmatrix[i] = new int[v];
            for (int j = 0; j < v; j++)
                adjmatrix[i][j] = 0;
        }
     
    }
        
    
    
    void accept(){
        int v1,v2,w;
        for(int i=0;i<edge;i++){
            cout<<"Edge No "<<i+1<<" "<<endl;
            cout<<"Enter the vertex Separated by Space -> ";
            cin>>v1>>v2;
            cout<<"Enter the weight ->";
            cin>>w;
            cout<<"________________________________\n"<<endl;
            adjmatrix[v1][v2]=w;
            adjmatrix[v2][v1]=w;
        }
        
    }
    void display(){
        cout<<"   ";
        for(int i = 0; i < vertex; i++) {
            cout<<i<<"  ";
        }
    
        cout<<"\n\n";
        for(int i = 0; i < vertex; i++) {
            cout<<i<<"| ";
            for(int j = 0; j < vertex; j++) {
                cout << adjmatrix[i][j] << "  ";
            }
            
            cout << endl;
        
        }
        cout<<"________________________________________________________\n\n"<<endl;
    }
    
    void prim(int v){
        int parent[vertex];
        int minweight[vertex];
        bool visited[vertex]={false};
        
        for(int i=0;i<vertex;i++){
            minweight[i]=INF;
        }
        
        minweight[v]=0;
        parent[v]=-1;
        
        
        
        for(int c=0;c<vertex-1;c++){
            int min=INF,min_index;
            
            for(int temp=0;temp<vertex;temp++){
                if(visited[temp]==false and minweight[temp]<min){
                    min=minweight[temp];
                    min_index=temp;
                }
            }
            
            visited[min_index]=true;
            
            for(int x=0;x<vertex;x++){
                if(adjmatrix[min_index][x] && visited[x]==false && adjmatrix[min_index][x]< minweight[x]){
                    parent[x]=min_index;
                    minweight[x]=adjmatrix[min_index][x];
                }
            }
            
       
        }
        
        cout<<"Minimun Spanning Tree by Prim's Algorithm"<<endl;
        cout<<setw(10)<<"Vertex1"<<setw(10)<<"Vertex2"<<setw(10)<<"Weight"<<endl;
        for(int i=0 ;i<vertex;i++){
            if(parent[i]==-1){
                continue;
            }
            cout<<setw(10)<<parent[i]<<setw(10)<<i<<setw(10)<<adjmatrix[i][parent[i]]<<endl;
        }
        cout<<"________________________________________________________"<<endl;
        
        
        
    }
    
    
    void krus(){
        int temp_mat[vertex][vertex];
        for(int i=0; i<vertex; i++)
        {
            for(int j=0; j<i; j++)
            {
                temp_mat[i][j] = adjmatrix[i][j];
                temp_mat[j][i] = adjmatrix[j][i];
            }
        }
        int count = 0, min, weight = 0, t1, t2;
        int parent[vertex];
        for(int i=0; i<vertex; i++)
        {
            parent[i] = -1;
        }
        
        int** result = new int*[vertex];
        
        for(int i=0; i<vertex; i++)
        {
            result[i] = new int[vertex];
        }
        
        for(int i=0; i<vertex; i++)
        {
            for(int j=0; j<vertex; j++)
            {
                result[i][j] = 0;
            }
        }
        
        while(count < vertex-1)
        {
            min = INF;
            for(int v1=0; v1<vertex; v1++)
            {
                for(int v2=0; v2<vertex; v2++)
                {
                    if(temp_mat[v1][v2] != 0 && temp_mat[v1][v2] < min)
                    {
                        min = temp_mat[v1][v2];
                        t1  = v1;
                        t2  = v2;
                    }
                }
            }
            
            int temp1 = t1, root_temp1;
            int temp2 = t2, root_temp2;
            temp_mat[temp1][temp2] = temp_mat[temp2][temp1] = 0;
            while(t1 >= 0)
            {
                root_temp1 = t1;
                t1 = parent[t1];
            }
            while(t2 >= 0)
            {
                root_temp2 = t2;
                t2 = parent[t2];
            }
            if(root_temp1 != root_temp2)
            {
                result[temp1][temp2] = result[temp2][temp1] = min;
                weight += result[temp1][temp2];
                parent[root_temp2] = root_temp1;
                count++;
            }
        }
//        cout<<weight<<endl;
        
        
            cout<<"Minimun Spanning Tree by kruskal's Algorithm"<<endl;
            cout<<setw(10)<<"Vertex1"<<setw(10)<<"Vertex2"<<setw(10)<<"Weight"<<endl;
            for(int i=0; i<vertex; i++)
             {
                for(int j=0; j<i; j++)
                {
                    if(result[i][j]!=0){
                        cout<<setw(10)<<i<<setw(10)<<j<<setw(10)<<result[i][j]<<endl;
                    }
                }
             }
             cout<<"________________________________________________________"<<endl;
    }
};
int main(){

    int choice;
    Graph *g;
        cout<<"_________________________________________"<<endl;
        cout<<"1: Enter Edges of graph"<<endl;
        cout<<"2: Display  Adjacency Matrix  " <<endl;
        cout<<"3: Minimum Spanning tree by Prim's"<<endl;
        cout<<"4: Minimun Spanning Tree by Kruskal's"<<endl;
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
            g->accept();
        }
        else if(choice==2){
            g->display();
        }
        else if(choice==3){
            int v;
            cout<<"Enter the vertex to start Prim's Algorithm -> ";
            cin>>v;
            g->prim(v);
        }
        else if(choice==4){
            g->krus();
        }
        else{
            break;
        }
    
    }
}
   
