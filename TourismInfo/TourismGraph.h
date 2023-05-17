#ifndef PROJECT2GRAPHS_TOURISMGRAPH_H
#define PROJECT2GRAPHS_TOURISMGRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "TourismNodes.h"
#include "TourismVertexEdge.h"
#include <unordered_set>

///This class contains the implementation of the graph class and all related functions.

class TourismGraph {
public:

    TourismGraph(TourismGraph &copiar){
        this->vertexSet = copiar.vertexSet;
        this->distMatrix = copiar.distMatrix;
        this->pathMatrix = copiar.pathMatrix;
    }

    ~TourismGraph();
    TourismGraph()=default;

    Vertex *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const int &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const int &distancia);

    int getNumVertex() const;

    vector<Vertex *> getVertexSet() const;
    /*
    vector<Vertex*> findPath(Vertex *start, Vertex *target);

    pair<double, vector<Vertex*>> findShortestPath(Vertex* start, Vertex* end);

    void backtracking(Vertex* currentVertex, Vertex* end, std::vector<Vertex*>& currentPath, double currentWeight,vector<Vertex*>& shortestPath, double& shortestWeight, unordered_set<Vertex*>& visitedVertices);
    */
    double backtrack(Vertex *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex *start_vertex,std::vector<int> &min_path, std::vector<int> &current_path);
protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;

    };


#endif //PROJECT2GRAPHS_TOURISMGRAPH_H
