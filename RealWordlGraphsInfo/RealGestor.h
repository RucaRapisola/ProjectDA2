#ifndef PROJECT2GRAPHS_REALGESTOR_H
#define PROJECT2GRAPHS_REALGESTOR_H


#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include "RealGraph.h"
#include "RealNodes.h"
using namespace std;

class RealGestor{
    unordered_map<int, int> nodes_id_1;
    unordered_map<int, int> nodes_id_2;
    unordered_map<int, int> nodes_id_3;
    unordered_map<int, Node> nodes;
    unordered_map<int, Node> nodes_2;
    unordered_map<int, Node> nodes_3;

public:
    void gestor_nodes_1(RealGraph &aux1);
    void gestor_travel1(RealGraph &aux1);
    void gestor_nodes_2(RealGraph &aux2);
    void gestor_travel2(RealGraph &aux2);
    void gestor_nodes_3(RealGraph &aux3);
    void gestor_travel3(RealGraph &aux3);
    unordered_map<int, int> getNodesID_1() const;
    unordered_map<int, int> getNodesID_2() const;
    unordered_map<int, int> getNodesID_3() const;
    unordered_map<int, Node> getStations() const;
};


#endif //PROJECT2GRAPHS_REALGESTOR_H
