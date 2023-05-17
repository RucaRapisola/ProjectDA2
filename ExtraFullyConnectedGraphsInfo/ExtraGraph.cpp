#include "ExtraGraph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int ExtraGraph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex4 *> ExtraGraph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex4 * ExtraGraph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int ExtraGraph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool ExtraGraph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex4(id));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool ExtraGraph::addEdge(const int &sourc, const int &dest, const float &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool ExtraGraph::addBidirectionalEdge(const int &sourc, const int &dest,const float& distancia) {
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

void deleteMatrix4(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix4(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

ExtraGraph::~ExtraGraph() {
    deleteMatrix4(distMatrix4, vertexSet.size());
    deleteMatrix4(pathMatrix4, vertexSet.size());
}
/*
vector<Vertex4*> Graph::findPath(Vertex4 *start, Vertex4 *target) {
    std::vector<Vertex4*> path;
    start->setVisited(true);
    if (start == target) {
        path.push_back(start);
        return path;
    }
    for (auto edge : start->getAdj()) {
        Vertex4 *dest = edge->getDest();
        if (!dest->isVisited()) {
            path = findPath(dest, target);
            if (!path.empty()) {
                path.insert(path.begin(), start);
                return path;
            }
        }
    }
    return path;
}

pair<double, vector<Vertex4*>>Graph:: findShortestPath(Vertex4* start, Vertex4* end) {
    vector<Vertex4*> currentPath; // current path being explored
    vector<Vertex4*> shortestPath; // shortest path found so far
    float currentWeight = 0; // current weight of the path being explored
    double shortestWeight = std::numeric_limits<double>::infinity(); // weight of the shortest path found so far
    unordered_set<Vertex4*> visitedVertices; // set of visited vertices

    backtracking(start, end, currentPath, currentWeight, shortestPath, shortestWeight, visitedVertices);

    return make_pair(shortestWeight, shortestPath);
}
 */
double ExtraGraph::backtrack(Vertex4 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex4 *start_vertex) {
    visited[current_vertex->getId()] = true;
    count++;

    if (count == visited.size()) {
        for (Edge4 *edge : current_vertex->getAdj()) {
            if (edge->getDest() == start_vertex) {
                double total_distance = distance + edge->getDistancia();
                if (total_distance < min_distance) {
                    min_distance = total_distance;
                }
                break;
            }
        }
    } else {
        for (Edge4 *edge : current_vertex->getAdj()) {
            Vertex4 *adj_vertex = edge->getDest();
            if (!visited[adj_vertex->getId()]) {
                double new_distance = distance + edge->getDistancia();
                min_distance = backtrack(adj_vertex, visited, count, new_distance, min_distance, start_vertex);
            }
        }
    }

    visited[current_vertex->getId()] = false;
    count--;

    return min_distance;
}