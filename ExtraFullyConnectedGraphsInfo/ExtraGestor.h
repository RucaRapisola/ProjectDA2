#ifndef PROJECT2GRAPHS_EXTRAGESTOR_H
#define PROJECT2GRAPHS_EXTRAGESTOR_H

#include <unordered_set>
#include <unordered_map>
#include "ExtraNodes.h"
#include "ExtraGraph.h"


class ExtraGestor{
    unordered_map<int, ExtraNodes> nodes;
    unordered_map<int, ExtraNodes> nodes2;

public:
    void gestor_stadiums(ExtraGraph &aux);
    void gestor_travel_stadiums(ExtraGraph &aux);

    void gestor_shipping(ExtraGraph &aux1);
    void gestor_travel_shipping(ExtraGraph &aux1);

    unordered_map<int, ExtraNodes> getNodes() const;
    unordered_map<int, ExtraNodes> getNodes2() const;

};


#endif //PROJECT2GRAPHS_EXTRAGESTOR_H
