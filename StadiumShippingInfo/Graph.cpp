#include "Graph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex2 *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex2 * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex2(id));
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, const float &distancia) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, distancia);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest,const float& distancia) {
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

void deleteMatrix2(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix2(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix2(distMatrix2, vertexSet.size());
    deleteMatrix2(pathMatrix2, vertexSet.size());
}
/*
vector<Vertex2*> Graph::findPath(Vertex2 *start, Vertex2 *target) {
    std::vector<Vertex2*> path;
    start->setVisited(true);
    if (start == target) {
        path.push_back(start);
        return path;
    }
    for (auto edge : start->getAdj()) {
        Vertex2 *dest = edge->getDest();
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

pair<double, vector<Vertex2*>>Graph:: findShortestPath(Vertex2* start, Vertex2* end) {
    vector<Vertex2*> currentPath; // current path being explored
    vector<Vertex2*> shortestPath; // shortest path found so far
    float currentWeight = 0; // current weight of the path being explored
    double shortestWeight = std::numeric_limits<double>::infinity(); // weight of the shortest path found so far
    unordered_set<Vertex2*> visitedVertices; // set of visited vertices

    backtracking(start, end, currentPath, currentWeight, shortestPath, shortestWeight, visitedVertices);

    return make_pair(shortestWeight, shortestPath);
}
 */
double Graph::backtrack(Vertex2 *current_vertex, std::vector<bool> &visited, int count, double distance, double min_distance, Vertex2 *start_vertex, std::vector<int> &min_path, std::vector<int> &current_path) {
    visited[current_vertex->getId()] = true;
    current_path.push_back(current_vertex->getId());
    count++;

    if (count == visited.size()) {
        for (Edge2 *edge : current_vertex->getAdj()) {
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
        for (Edge2 *edge : current_vertex->getAdj()) {
            Vertex2 *adj_vertex = edge->getDest();
            if (!visited[adj_vertex->getId()]) {
                double new_distance = distance + edge->getDistancia();
                min_distance = backtrack(adj_vertex, visited, count, new_distance, min_distance, start_vertex, min_path, current_path);
            }
        }
    }

    visited[current_vertex->getId()] = false;
    current_path.pop_back();
    count--;

    return min_distance;
}

