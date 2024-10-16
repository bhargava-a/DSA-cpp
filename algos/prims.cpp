#include<iostream>
#include<vector>
#include<climits> // for INT_MAX
using namespace std;

// Function to find the vertex with the minimum key value
int minKey(vector<int>& key,vector<bool>& inMST,int vertices){
    int min=INT_MAX,minIndex;
    for(int v=0;v<vertices;v++){
        if (!inMST[v]&&key[v]<min){
            min=key[v];
            minIndex=v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(vector<int>& parent,vector<vector<int>>& cost,int vertices) {
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < vertices; i++) {
        cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";
    }
}

void primsAlgorithm(vector<vector<int>>& cost,int source,int vertices) {
    // Array to store the minimum weight edge that connects to the MST
    vector<int> key(vertices,INT_MAX);
    // Array to store constructed MST
    vector<int> parent(vertices,-1);
    // To represent vertices included in MST
    vector<bool> inMST(vertices,false);

    // Start from the source vertex
    key[source]=0;

    for(int count=0;count<vertices-1;count++){
        // Pick the minimum key vertex not yet included in MST
        int u=minKey(key,inMST,vertices);

        // Add the picked vertex to the MST set
        inMST[u]=true;

        // Update key values and parent index of the adjacent vertices
        for(int v=0;v<vertices;v++) {
            // Update key only if cost[u][v] is smaller and v is not in MST
            if (cost[u][v] && !inMST[v] && cost[u][v] < key[v]) {
                key[v]=cost[u][v];
                parent[v]=u;
            }
        }
    }
    // Print the constructed MST
    printMST(parent,cost,vertices);
}
int main(){
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;

    cout<<"Enter the cost matrix (use 0 for self-loop and 999 for no path):\n";
    vector<vector<int>> cost(vertices,vector<int>(vertices,0));

    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++) {
            cin>>cost[i][j];
        }
    }
    int source;
    cout<<"Enter the source vertex: ";
    cin>>source;
    primsAlgorithm(cost,source,vertices);
    return 0;
}
