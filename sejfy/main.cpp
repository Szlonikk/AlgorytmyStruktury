#include <iostream>
#include "Graph.hpp"


void DFS(int vertex, bool* visited,Graph& graph) {
    visited[vertex] = true;

    Set<int> neighbors = graph[vertex];
    for (int i = 0; i < neighbors.size(); ++i) {
        int neighbor = neighbors[i];
        if (!visited[neighbor]) {
            DFS(neighbor, visited, graph);
        }
    }
}


int componentCounter(Graph& graph, int vertices) {
    
    bool visited[vertices];
    std::fill_n(visited, vertices, false);

    int count = 0;

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            DFS(i, visited, graph);
            count++;
        }
    }

    return count;
}

int main(){
    Graph graf;
    int n;
    std::cin>>n;
    
    int x;
    for(int i=0;i<n;++i){
        std::cin>>x;
        x-=1;

        graf.addEdge(i,x);
        graf.addEdge(x,i);
      
    }
    printf("\n");
    std::cout<<componentCounter(graf,n);
    printf("\n");


}