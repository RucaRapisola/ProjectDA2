#ifndef PROJECT2GRAPHS_TOURISMGESTOR_H
#define PROJECT2GRAPHS_TOURISMGESTOR_H

#include <unordered_set>
#include <unordered_map>
#include "TourismNodes.h"
#include "TourismGraph.h"


class TourismGestor{
    unordered_map<string, int> Tourism_nodes_names;
    unordered_map<int, TourismNodes> Tourism_nodes;

public:
    void gestor_tourism(TourismGraph &aux);
    void gestor_travel(TourismGraph &aux);

    unordered_map<string, int> getTourismNodesNames() const;

    unordered_map<int, TourismNodes> getTourismNodes() const;

};


#endif //PROJECT2GRAPHS_TOURISMGESTOR_H
