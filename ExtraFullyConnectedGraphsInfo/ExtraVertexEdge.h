#ifndef PROJECT2GRAPHS_EXTRAVERTEXEDGE_H
#define PROJECT2GRAPHS_EXTRAVERTEXEDGE_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
using namespace std;

class Edge4;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Vertex4 {
public:
    Vertex4(int id);

    bool operator()(Vertex4 &vertex1 , Vertex4 &vertex2) const; // // required by MutablePriorityQueue

    int getId() const;

    std::vector<Edge4 *> getAdj() const;

    bool isVisited() const;
    bool isProcessing() const;

    unsigned int getIndegree() const;

    double getDist() const;

    Edge4 *getPath() const;

    std::vector<Edge4 *> getIncoming() const;

    void setId(int info);

    void setVisited(bool visited);
    void setProcesssing(bool processing);

    void setIndegree(unsigned int indegree);

    void setDist(double dist);

    void setPath(Edge4 *path);

    Edge4 * addEdge(Vertex4 *dest, double distancia);
    bool removeEdge(int destID);

    friend class MutablePriorityQueue<Vertex4>;
protected:
    int id;                // identifier
    std::vector<Edge4 *> adj;  // outgoing edges
    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge4 *path = nullptr;
    std::vector<Edge4 *> incoming; // incoming edges
    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Edge4 {
public:

    Edge4(Vertex4 *orig, Vertex4 *dest, double distancia);

    Vertex4 * getDest() const;

    double getDistancia() const;

    bool isSelected() const;

    Vertex4 * getOrig() const;

    Edge4 *getReverse() const;

    double getFlow() const;
    void setSelected(bool selected);

    void setReverse(Edge4 *reverse);

    void setFlow(double flow);
protected:
    Vertex4 * dest; // destination vertex
    float distancia;
    // auxiliary fields
    bool selected = false;
    // used for bidirectional edges
    Vertex4 *orig;
    Edge4 *reverse = nullptr;
    double flow; // for flow-related problems
};


#endif //PROJECT2GRAPHS_EXTRAVERTEXEDGE_H
