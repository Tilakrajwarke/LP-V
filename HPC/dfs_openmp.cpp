#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void parallelDFS(int node){
    #pragma omp critical
    {
        if(visited[node])
            return;
        visited[node]=true;
        cout<<node<<" ";
    }

    for (int i= 0; i< graph.size();i++){
        if (graph[node][i]==1){
            #pragma omp task 
            {
                parallelDFS(i);
            }
        }
    }
    #pragma omp taskwait

}

int main(){
    int n;
    cout<<"Enter number of vertices:";
    cin>>n;

    graph.resize(n, vector<int>(n));
    visited.resize(n,false);

    cout<<"Enter adjacency matrix:\n";
    for(int i = 0; i< n; i++){
        for( int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    int start;
    cout<<"Enter starting vertex: ";
    cin>>start;

    #pragma omp parallel
    {
        #pragma omp single
        {
            parallelDFS(start);
        }
    }
    cout<<endl;
    return 0;
}