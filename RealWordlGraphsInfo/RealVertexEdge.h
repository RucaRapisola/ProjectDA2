#ifndef PROJECT2GRAPHS_REALVERTEXEDGE_H
#define PROJECT2GRAPHS_REALVERTEXEDGE_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "../MutablePriorityQueue.h"

class Edge3;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Vertex3 {
public:
    Vertex3(int id);

    bool operator()(Vertex3 &vertex1 , Vertex3 &vertex2) const;

    int getId() const;

    std::vector<Edge3 *> getAdj() const;

    bool isVisited() const;
    bool isProcessing() const;

    unsigned int getIndegree() const;

    double getDist() const;

    Edge3 *getPath() const;

    std::vector<Edge3 *> getIncoming() const;

    void setId(int info);

    void setVisited(bool visited);
    void setProcesssing(bool processing);

    void setIndegree(unsigned int indegree);

    void setDist(double dist);

    void setPath(Edge3 *path);

    Edge3 * addEdge(Vertex3 *dest, float distancia);
    bool removeEdge(int destID);

    bool operator<(const Vertex3& other) const {
        return dist < other.dist;
    }


    friend class MutablePriorityQueue<Vertex3>;
protected:
    int id;                // identifier
    std::vector<Edge3 *> adj;  // outgoing edges
    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge3 *path = nullptr;
    std::vector<Edge3 *> incoming; // incoming edges
    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

///This class implements the vertex and the edge used in Graph.
///Complementary class of the Graph class.

class Edge3 {
public:

    Edge3(Vertex3 *orig, Vertex3 *dest, float distancia);

    Vertex3 * getDest() const;

    int getDistancia() const;

    bool isSelected() const;

    Vertex3 * getOrig() const;

    Edge3 *getReverse() const;

    double getFlow() const;
    void setSelected(bool selected);

    void setReverse(Edge3 *reverse);

    void setFlow(double flow);

    bool operator>(const Edge3& other) const;
protected:
    Vertex3 * dest; // destination vertex
    float distancia;
    // auxiliary fields
    bool selected = false;
    // used for bidirectional edges
    Vertex3 *orig;
    Edge3 *reverse = nullptr;
    double flow; // for flow-related problems
};


#endif //PROJECT2GRAPHS_REALVERTEXEDGE_H
