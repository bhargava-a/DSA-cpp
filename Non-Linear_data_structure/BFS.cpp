#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(int start_vertex,vector<vector<int>>& adj,vector<bool>& visited){
    queue<int> q;
    q.push(start_vertex);
    visited[start_vertex]=true;
    
    while(!q.empty()){
        int current_vertex=q.front();
        q.pop();
        cout<<current_vertex<<"\t";

        for(int i=0;i<adj[current_vertex].size();i++){
            if(adj[current_vertex][i] == 1 && (!visited[i])){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
    int vertices;
    cout<<"Enter the number of vertices : ";
    cin>>vertices;
    //created a adjacency matirx
    vector<vector<int>> adj(vertices,vector<int>(vertices,0));
    cout<<"Enter the adjency matrix values :"<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>adj[i][j];
        }
    }

    //calling for BFS for each component of the graph
    for(int i=0;i<vertices;i++){
        //created a boolean queue for tracking the visited nodes
        vector<bool> visited(vertices,false);
        cout<<"BFS staring from vertex "<<i<<": ";
        BFS(i,adj,visited);
        cout<<endl;
    }
    return 0;
}