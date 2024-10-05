#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(){
    
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
    //created a boolean queue for tracking the visited nodes
    vector<bool> visited(vertices,false);

    //calling for BFS for each component of the graph
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            cout<<"BFS staring from vertex "<<i<<": ";
            BFS(i,adj,visited);
            cout<<endl;
        }
    }
    return 0;
}