#ifndef PROJECT2GRAPHS_TOURISMVERTEXEDGE_H
#define PROJECT2GRAPHS_TOURISMVERTEXEDGE_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Vertex {
public:
    Vertex(int id);

    bool operator()(Vertex &vertex1 , Vertex &vertex2) const; // // required by MutablePriorityQueue

    int getId() const;

    std::vector<Edge *> getAdj() const;

    bool isVisited() const;
    bool isProcessing() const;

    unsigned int getIndegree() const;

    double getDist() const;

    Edge *getPath() const;

    std::vector<Edge *> getIncoming() const;

    void setId(int info);

    void setVisited(bool visited);
    void setProcesssing(bool processing);

    void setIndegree(unsigned int indegree);

    void setDist(double dist);

    void setPath(Edge *path);

    Edge * addEdge(Vertex *dest, int distancia);
    bool removeEdge(int destID);

    friend class MutablePriorityQueue<Vertex>;
protected:
    int id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges
    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;
    std::vector<Edge *> incoming; // incoming edges
    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Edge {
public:

    Edge(Vertex *orig, Vertex *dest, int distancia);

    Vertex * getDest() const;

    int getDistancia() const;

    bool isSelected() const;

    Vertex * getOrig() const;

    Edge *getReverse() const;

    double getFlow() const;
    void setSelected(bool selected);

    void setReverse(Edge *reverse);

    void setFlow(double flow);
protected:
    Vertex * dest; // destination vertex
    int distancia;
    // auxiliary fields
    bool selected = false;
    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;
    double flow; // for flow-related problems
};


#endif //PROJECT2GRAPHS_TOURISMVERTEXEDGE_H
