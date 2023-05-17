#include "RealGraph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int RealGraph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex3 *> RealGraph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex3 * RealGraph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int RealGraph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool RealGraph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex3(id));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool RealGraph::addEdge(const int &sourc, const int &dest, const float &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool RealGraph::addBidirectionalEdge(const int &sourc, const int &dest,const float& distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2,distancia);
    auto e2 = v2->addEdge(v1, distancia);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void deleteMatrix3(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix3(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

RealGraph::~RealGraph() {
    deleteMatrix3(distMatrix3, vertexSet.size());
    deleteMatrix3(pathMatrix3, vertexSet.size());
}
//4.1
double RealGraph::backtrack(Vertex3 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex3 *start_vertex,std::vector<int> &min_path, std::vector<int> &current_path) {
    visited[current_vertex->getId()] = true;
    current_path.push_back(current_vertex->getId());
    count++;

    if (count == visited.size()) {
        for (Edge3 *edge : current_vertex->getAdj()) {
            if (edge->getDest() == start_vertex) {
                double total_distance = distance + edge->getDistancia();
                if (total_distance < min_distance) {
                    min_distance = total_distance;
                    min_path = current_path;
                }
                break;
            }
        }
    } else {
        for (Edge3 *edge : current_vertex->getAdj()) {
            Vertex3 *adj_vertex = edge->getDest();
            if (!visited[adj_vertex->getId()]) {
                double new_distance = distance + edge->getDistancia();
                min_distance = backtrack(adj_vertex, visited, count, new_distance, min_distance, start_vertex,min_path,current_path);
            }
        }
    }

    visited[current_vertex->getId()] = false;
    current_path.pop_back();
    count--;

    return min_distance;
}
//4.2
vector<Edge3> RealGraph::primMST() {
    vector<Edge3> mst;
    unordered_set<int> visited;
    int numVertices = this->getNumVertex();

    // Create a vector to store the minimum weight for each vertex
    vector<double> minWeight(numVertices, INF);

    // Choose a starting vertex arbitrarily
    Vertex3* startVertex = this->getVertexSet()[0];
    minWeight[startVertex->getId()] = 0;

    // Custom binary heap implementation for efficient operations
    MutablePriorityQueue<Vertex3> pq;
    pq.insert(startVertex);

    while (!pq.empty()) {
        Vertex3* currentVertex = pq.extractMin();
        visited.insert(currentVertex->getId());

        for (Edge3* edge : currentVertex->getAdj()) {
            Vertex3* neighbor = edge->getDest();
            double weight = edge->getDistancia();

            if (visited.count(neighbor->getId()) == 0 && weight < minWeight[neighbor->getId()]) {
                // Update the minimum weight and path
                minWeight[neighbor->getId()] = weight;
                neighbor->setPath(edge);

                // Update the priority queue
                if (pq.contains(neighbor))
                    pq.decreaseKey(neighbor);
                else
                    pq.insert(neighbor);
            }
        }
    }
    return mst;
}

void RealGraph::preorderTraversal(Vertex3* startVertex) {
    stack<Vertex3*> stack;
    stack.push(startVertex);

    while (!stack.empty()) {
        Vertex3* currentVertex = stack.top();
        stack.pop();

        // Process the current vertex
        cout << currentVertex->getId() << " ";

        for (Edge3* edge : currentVertex->getAdj()) {
            Vertex3* neighbor = edge->getDest();
            stack.push(neighbor);
        }
    }
}


