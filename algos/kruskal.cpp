#include<iostream>
#include<String>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int vertices;
    cout<<"Enter the num of vertices : "<<flush;
    cin>>vertices;
    cout<<"Enter the cost matrix "<<endl;
    vector<vector<int>> cost(vertices,vector<int>(vertices,0));
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>cost[i][j];
        }
    }
    int source;
    cout<<"Enter the source vector : "<<flush;
    cin>>source;
    
    return 0;
}