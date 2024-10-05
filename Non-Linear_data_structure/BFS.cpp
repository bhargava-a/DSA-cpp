#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertices;
    cout<<"Enter the number of vertices : ";
    cin>>vertices;
    vector<vector<int>> adj(vertices,vector<int>(vertices,0));
    cout<<"Enter the adjency matrix values :"<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>adj[i][j];
        }
    }
    
    return 0;
}