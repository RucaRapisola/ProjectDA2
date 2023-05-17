#ifndef PROJECT2GRAPHS_REALGRAPH_H
#define PROJECT2GRAPHS_REALGRAPH_H


#include <iostream>
#include <vector>
#include "set"
#include <queue>
#include <limits>
#include <string>
#include <algorithm>
#include "../MutablePriorityQueue.h"
#include "RealVertexEdge.h"
#include <unordered_map>
using namespace std;

///This class contains the implementation of the graph class and all related functions.

class RealGraph {
public:
    ///Destructor for the graph class.
    ~RealGraph();

    Vertex3 *findVertex(const int &id) const;

    bool addVertex(const int &id);

    bool addEdge(const int &sourc, const int &dest, const float &distancia);

    bool addBidirectionalEdge(const int &sourc, const int &dest, const float &distancia);

    int getNumVertex() const;

    vector<Vertex3 *> getVertexSet() const;

    double backtrack(Vertex3 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex3 *start_vertex,std::vector<int> &min_path, std::vector<int> &current_path);

    vector<Edge3> primMST();

    void preorderTraversal(Vertex3* startVertex);


protected:
    vector<Vertex3*> vertexSet;    // vertex set

    double ** distMatrix3 = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix3 = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
};



#endif //PROJECT2GRAPHS_REALGRAPH_H
