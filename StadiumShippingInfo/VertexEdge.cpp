#include "VertexEdge.h"

/************************* Vertex  **************************/

Vertex2::Vertex2(int id): id(id) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge2 * Vertex2::addEdge(Vertex2 *d, double distancia) {
    auto newEdge = new Edge2(this, d, distancia);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex2::removeEdge(int destID) {
    bool removedEdge=false;
    auto it= adj.begin();
    while(it!=adj.end()){
        Edge2 *edge= *it;
        Vertex2 *dest = edge->getDest();
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

bool Vertex2::operator()(Vertex2 &vertex1, Vertex2 &vertex2) const {
    return vertex1.getDist() < vertex2.getDist();
}

int Vertex2::getId() const {
    return this->id;
}

std::vector<Edge2*> Vertex2::getAdj() const {
    return this->adj;
}

bool Vertex2::isVisited() const {
    return this->visited;
}

bool Vertex2::isProcessing() const {
    return this->processing;
}

unsigned int Vertex2::getIndegree() const {
    return this->indegree;
}

double Vertex2::getDist() const {
    return this->dist;
}

Edge2 *Vertex2::getPath() const {
    return this->path;
}

std::vector<Edge2 *> Vertex2::getIncoming() const {
    return this->incoming;
}

void Vertex2::setId(int id) {
    this->id = id;
}

void Vertex2::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex2::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex2::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex2::setDist(double dist) {
    this->dist = dist;
}

void Vertex2::setPath(Edge2 *path) {
    this->path = path;
}

/********************** Edge  ****************************/

Edge2::Edge2(Vertex2 *orig, Vertex2 *dest, double distancia): orig(orig), dest(dest), distancia(distancia) {}

Vertex2 * Edge2::getDest() const {
    return this->dest;
}

double Edge2::getDistancia()const {
    return this->distancia;
}

Vertex2 * Edge2::getOrig() const {
    return this->orig;
}

Edge2 *Edge2::getReverse() const {
    return this->reverse;
}

bool Edge2::isSelected() const {
    return this->selected;
}

double Edge2::getFlow() const {
    return flow;
}

void Edge2::setSelected(bool selected) {
    this->selected = selected;
}

void Edge2::setReverse(Edge2 *reverse) {
    this->reverse = reverse;
}

void Edge2::setFlow(double flow) {
    this->flow = flow;
}

bool Edge2::operator>(const Edge2& other)const{
    return distancia > other.distancia;
}