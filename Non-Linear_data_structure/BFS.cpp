#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertices;
    cout<<"Enter the number of vertices : ";
    cin>>vertices;
    vector<vector<int>> adj(vertices,vector<int>(vertices,0));
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}