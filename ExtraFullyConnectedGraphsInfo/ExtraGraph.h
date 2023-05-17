#ifndef PROJECT2GRAPHS_EXTRAGRAPH_H
#define PROJECT2GRAPHS_EXTRAGRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "ExtraNodes.h"
#include "ExtraVertexEdge.h"
#include <unordered_set>

///This class contains the implementation of the graph class and all related functions.

class ExtraGraph {
public:
    ~ExtraGraph();
    ExtraGraph()=default;

    Vertex4 *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const float &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const float &distancia);

    int getNumVertex() const;

    vector<Vertex4 *> getVertexSet() const;
    /*
    vector<Vertex4*> findPath(Vertex4 *start, Vertex4 *target);

    pair<double, std::vector<Vertex4*>> findShortestPath(Vertex4* start, Vertex4* end);

    void backtracking(Vertex4* currentVertex, Vertex4* end, vector<Vertex4*>& currentPath, double currentWeight,vector<Vertex4*>& shortestPath, double& shortestWeight, unordered_set<Vertex4*>& visitedVertices);
    */
    double backtrack(Vertex4 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex4 *start_vertex);

protected:
    std::vector<Vertex4 *> vertexSet;    // vertex set

    double ** distMatrix4 = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix4 = nullptr;   // path matrix for Floyd-Warshall

    int findVertexIdx(const int &id) const;

};


#endif //PROJECT2GRAPHS_EXTRAGRAPH_H
