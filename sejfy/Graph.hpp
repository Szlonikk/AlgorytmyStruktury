#ifndef GRAPH_H
#define GRAPH_H
#include "set.hpp"
#include <queue>
#include <vector>
#include <cstring>
#define N 100000

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

Set<int>& operator[](int index) {
    if (index < 0 || index >= N) {
        throw std::out_of_range("Indeks poza zakresem");
    }
    return NeighList[index];
}





};

#endif