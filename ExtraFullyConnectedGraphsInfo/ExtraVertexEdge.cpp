#include "ExtraVertexEdge.h"

/************************* Vertex  **************************/

Vertex4::Vertex4(int id): id(id) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge4 * Vertex4::addEdge(Vertex4 *d, double distancia) {
    auto newEdge = new Edge4(this, d, distancia);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex4::removeEdge(int destID) {
    bool removedEdge=false;
    auto it= adj.begin();
    while(it!=adj.end()){
        Edge4 *edge= *it;
        Vertex4 *dest = edge->getDest();
        if(dest->getId()==destID){
            it = adj.erase(it);
            delete edge;
            removedEdge=true;
        }
        else{
            it++;
        }
    }
    return removedEdge;
}

bool Vertex4::operator()(Vertex4 &vertex1, Vertex4 &vertex2) const {
    return vertex1.getDist() < vertex2.getDist();
}

int Vertex4::getId() const {
    return this->id;
}

std::vector<Edge4*> Vertex4::getAdj() const {
    return this->adj;
}

bool Vertex4::isVisited() const {
    return this->visited;
}

bool Vertex4::isProcessing() const {
    return this->processing;
}

unsigned int Vertex4::getIndegree() const {
    return this->indegree;
}

double Vertex4::getDist() const {
    return this->dist;
}

Edge4 *Vertex4::getPath() const {
    return this->path;
}

std::vector<Edge4 *> Vertex4::getIncoming() const {
    return this->incoming;
}

void Vertex4::setId(int id) {
    this->id = id;
}

void Vertex4::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex4::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex4::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex4::setDist(double dist) {
    this->dist = dist;
}

void Vertex4::setPath(Edge4 *path) {
    this->path = path;
}

/********************** Edge  ****************************/

Edge4::Edge4(Vertex4 *orig, Vertex4 *dest, double distancia): orig(orig), dest(dest), distancia(distancia) {}

Vertex4 * Edge4::getDest() const {
    return this->dest;
}

double Edge4::getDistancia()const {
    return this->distancia;
}

Vertex4 * Edge4::getOrig() const {
    return this->orig;
}

Edge4 *Edge4::getReverse() const {
    return this->reverse;
}

bool Edge4::isSelected() const {
    return this->selected;
}

double Edge4::getFlow() const {
    return flow;
}

void Edge4::setSelected(bool selected) {
    this->selected = selected;
}

void Edge4::setReverse(Edge4 *reverse) {
    this->reverse = reverse;
}

void Edge4::setFlow(double flow) {
    this->flow = flow;
}