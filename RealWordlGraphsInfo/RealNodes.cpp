#include "RealNodes.h"
#include "bits/stdc++.h"

Node::Node(int id , double longitude , double latitude){
    this->id = id;
    this->longitude= longitude;
    this->latitude = latitude;
}

int Node::getID() const{
    return id;
}
double Node::getLongitude() const {
    return longitude;
}
double Node::getLatitude()const{
    return latitude;
}

Node::Node() {}