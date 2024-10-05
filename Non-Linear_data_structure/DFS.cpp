#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void DFS(int start_vertex,vector<vector<int>>& adj,vector<bool>& visited){
    stack<int> s;
    s.push(start_vertex);
    visited[start_vertex]=true;

    while(!s.empty()){
        int current_vertex=s.top();
        s.pop();
        cout<<current_vertex<<"\t";

        for(int i=0;i<adj[current_vertex].size();i++){
            if(adj[current_vertex][i] == 1 && (!visited[i])){
                s.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
    int vertices;
    cout<<"Enter the no of vertices : ";
    cin>>vertices;
    vector<vector<int>> adj(vertices,vector<int> (vertices,0));
    cout<<"Enter the adjacent matrix values : "<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0;i<vertices;i++){
        vector<bool> visited(vertices,false);
        cout<<"DFS staring from vertex "<<i<<": ";
        DFS(i,adj,visited);
        cout<<endl;
    }
    return 0;
}