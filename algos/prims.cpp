#include<iostream>
#include<vector>
using namespace std;
int main(){
  int vertices;
  cout<<"Enter the no of Vertices : ";
  cin>>vertices;
  cout<<"Enter the cost matrix 0 for self loop and 999 for no path"<<endl;
  vector<vector<int>> cost(vertices,vector<int>(vertices,0));
  for(int i=0;i<vertices;i++){
    for(int j=0;j<vertices;j++){
      cin>>cost[i][j];
    }
  }
  

  return 0;
}
