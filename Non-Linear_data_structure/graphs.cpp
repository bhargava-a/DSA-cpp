#include<bits/stdc++.h>
using namespace std;
int main(){
    int nodes,edges;
    cout<<"Enter the number of nodes : ";
    cin>>nodes;
    cout<<"Enter the number of edges : ";
    cin>>edges;
    int matrix[nodes][nodes];
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Adjency MAtrix"<<endl;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}