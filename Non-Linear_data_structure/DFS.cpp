#include<iostream>
#include<stack>
#include<vector>
using namespace std;

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