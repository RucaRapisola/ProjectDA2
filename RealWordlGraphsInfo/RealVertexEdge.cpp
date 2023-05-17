#include "RealVertexEdge.h"

/************************* Vertex  **************************/

Vertex3::Vertex3(int id): id(id) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge3 * Vertex3::addEdge(Vertex3 *d, float distancia) {
    auto newEdge = new Edge3(this, d, distancia);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex3::removeEdge(int destID) {
    bool removedEdge=false;
    auto it= adj.begin();
    while(it!=adj.end()){
        Edge3 *edge= *it;
        Vertex3 *dest = edge->getDest();
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

bool Vertex3::operator()(Vertex3 &vertex1, Vertex3 &vertex2) const {
    return vertex1.getDist() < vertex2.getDist();
}

int Vertex3::getId() const {
    return this->id;
}

std::vector<Edge3*> Vertex3::getAdj() const {
    return this->adj;
}

bool Vertex3::isVisited() const {
    return this->visited;
}

bool Vertex3::isProcessing() const {
    return this->processing;
}

unsigned int Vertex3::getIndegree() const {
    return this->indegree;
}

double Vertex3::getDist() const {
    return this->dist;
}

Edge3 *Vertex3::getPath() const {
    return this->path;
}

std::vector<Edge3 *> Vertex3::getIncoming() const {
    return this->incoming;
}

void Vertex3::setId(int id) {
    this->id = id;
}

void Vertex3::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex3::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex3::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex3::setDist(double dist) {
    this->dist = dist;
}

void Vertex3::setPath(Edge3 *path) {
    this->path = path;
}

/********************** Edge  ****************************/

Edge3::Edge3(Vertex3 *orig, Vertex3 *dest, float distancia): orig(orig), dest(dest), distancia(distancia) {}

Vertex3 * Edge3::getDest() const {
    return this->dest;
}

int Edge3::getDistancia()const {
    return this->distancia;
}

Vertex3 * Edge3::getOrig() const {
    return this->orig;
}

Edge3 *Edge3::getReverse() const {
    return this->reverse;
}

bool Edge3::isSelected() const {
    return this->selected;
}

double Edge3::getFlow() const {
    return flow;
}

void Edge3::setSelected(bool selected) {
    this->selected = selected;
}

void Edge3::setReverse(Edge3 *reverse) {
    this->reverse = reverse;
}

void Edge3::setFlow(double flow) {
    this->flow = flow;
}
bool Edge3::operator>(const Edge3& other)const{
    return distancia > other.distancia;
}