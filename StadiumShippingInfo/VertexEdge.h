#ifndef PROJECT2GRAPHS_VERTEXEDGE_H
#define PROJECT2GRAPHS_VERTEXEDGE_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"
using namespace std;

class Edge2;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Vertex2 {
public:
    Vertex2(int id);

    bool operator()(Vertex2 &vertex1 , Vertex2 &vertex2) const; // // required by MutablePriorityQueue

    int getId() const;

    std::vector<Edge2 *> getAdj() const;

    bool isVisited() const;
    bool isProcessing() const;

    unsigned int getIndegree() const;

    double getDist() const;

    Edge2 *getPath() const;

    std::vector<Edge2 *> getIncoming() const;

    void setId(int info);

    void setVisited(bool visited);
    void setProcesssing(bool processing);

    void setIndegree(unsigned int indegree);

    void setDist(double dist);

    void setPath(Edge2 *path);

    Edge2 * addEdge(Vertex2 *dest, double distancia);
    bool removeEdge(int destID);

    bool operator<(const Vertex2& other) const {
        return dist < other.dist;
    }

    friend class MutablePriorityQueue<Vertex2>;
protected:
    int id;                // identifier
    std::vector<Edge2 *> adj;  // outgoing edges
    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge2 *path = nullptr;
    std::vector<Edge2 *> incoming; // incoming edges
    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Edge2 {
public:

    Edge2(Vertex2 *orig, Vertex2 *dest, double distancia);

    Vertex2 * getDest() const;

    double getDistancia() const;

    bool isSelected() const;

    Vertex2 * getOrig() const;

    Edge2 *getReverse() const;

    double getFlow() const;
    void setSelected(bool selected);

    void setReverse(Edge2 *reverse);

    void setFlow(double flow);

    bool operator>(const Edge2& other)const;
protected:
    Vertex2 * dest; // destination vertex
    float distancia;
    // auxiliary fields
    bool selected = false;
    // used for bidirectional edges
    Vertex2 *orig;
    Edge2 *reverse = nullptr;
    double flow; // for flow-related problems
};


#endif //PROJECT2GRAPHS_VERTEXEDGE_H
