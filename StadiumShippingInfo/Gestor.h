#ifndef PROJECT2GRAPHS_GESTOR_H
#define PROJECT2GRAPHS_GESTOR_H


#include <unordered_set>
#include <unordered_map>
#include "Nodes.h"
#include "Graph.h"


class Gestor{
    unordered_map<int, Nodes> nodes;
    unordered_map<int, Nodes> nodes2;

public:
    void gestor_stadiums(Graph &aux);
    void gestor_shipping(Graph &aux1);
    void gestor_travel_stadiums(Graph &aux);
    void gestor_travel_shipping(Graph &aux1);

    unordered_map<int, Nodes> getNodes() const;
    unordered_map<int, Nodes> getNodes2() const;

};


#endif //PROJECT2GRAPHS_GESTOR_H
