#ifndef GRAPH_H
#define GRAPH_H
#include "set.hpp"
#include <queue>
#include <vector>
#define N 100

class Graph{
    
private:
Set<int> NeighList[N];

public:
void addEdge(int i,int j){     // dodaje krawędź pomiędzy wierzchołkami i i j
    NeighList[i].insert(j);
}
void removeEdge(int i,int j){  // usuwa krawędź pomiędzy wierzchołkami i i j
    NeighList[i].remove(j);

}
bool hasEdge(int i,int j){     // sprawdza czy krawędź pomiędzy wierzchołkami i i j istnieje
    return NeighList[i].isMember(j);
}
Set<int>  inConnections(int i) { // zwraca wszystkie wierzchołki od których istnieją połączenia do wierzchołka i
    Set<int> res;

    for(int j=0;j<N;j++){
        if(NeighList[j].isMember(i)){
            res.insert(j);
        }
    }
    
    return res;
}
Set<int> outConnections(int i){ // zwraca wszystkie wierzchołki do których prowadzą krawędzie wychodzące z i
    return NeighList[i].allElements();
}
Set<int>  allConnections(int i){ // zwraca wszystkie wierzchołki które są połączone z i lub z którymi i jest połączony
    return inConnections(i).union_(outConnections(i));
}



};
void BFS(Graph& G, int s, int distances[]) {
    std::queue<int> Q;
    Q.push(s);
    Set<int>* set;
    bool visited[N] = {false};
    // Ustawiamy odległości początkowe na -1 dla wierzchołków, które nie są osiągalne z wierzchołka s
    memset(distances, -1, sizeof(*distances));
    distances[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        set=new Set<int>;
        *set=G.outConnections(u);
        set->for_each([&](int v){if (!visited[v]) {
                visited[v] = true;
                distances[v] = distances[u] + 1;
                Q.push(v);
            }});
        delete set;
    }
}
#endif