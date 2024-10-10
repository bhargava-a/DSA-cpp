#include<iostream>
#include<vector>
using namespace std;
int main(){
  int vertices;
  cout<<"Enter the no of Vertices : ";
  cin>>vertices;
  cout<<"Enter the adjaceny matrix "<<endl;
  vector<vector<int>> adj(vertices,vector<int>(vertices,0));
  for(int i=0;i<vertices;i++){
    for(int j=0;j<vertices;j++){
      cin>>adj[i][j];
    }
  }
  
  return 0;
}
