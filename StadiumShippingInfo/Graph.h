#ifndef PROJECT2GRAPHS_GRAPH_H
#define PROJECT2GRAPHS_GRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "Nodes.h"
#include "VertexEdge.h"
#include <unordered_set>

///This class contains the implementation of the graph class and all related functions.

class Graph {
public:

    Graph(Graph &copiar){
        this->vertexSet = copiar.vertexSet;
        this->distMatrix2 = copiar.distMatrix2;
        this->pathMatrix2 = copiar.pathMatrix2;
    }

    ~Graph();
    Graph()=default;

    Vertex2 *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const float &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const float &distancia);

    int getNumVertex() const;

    vector<Vertex2 *> getVertexSet() const;
    /*
    vector<Vertex2*> findPath(Vertex2 *start, Vertex2 *target);

    pair<double, std::vector<Vertex2*>> findShortestPath(Vertex2* start, Vertex2* end);

    void backtracking(Vertex2* currentVertex, Vertex2* end, vector<Vertex2*>& currentPath, double currentWeight,vector<Vertex2*>& shortestPath, double& shortestWeight, unordered_set<Vertex2*>& visitedVertices);
    */
    double backtrack(Vertex2 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex2 *start_vertex,std::vector<int> &min_path, std::vector<int> &current_path);


protected:
    std::vector<Vertex2 *> vertexSet;    // vertex set

    double ** distMatrix2 = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix2 = nullptr;   // path matrix for Floyd-Warshall

    int findVertexIdx(const int &id) const;

};


#endif //PROJECT2GRAPHS_GRAPH_H
