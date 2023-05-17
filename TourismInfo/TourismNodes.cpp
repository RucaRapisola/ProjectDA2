#include "TourismNodes.h"
#include "bits/stdc++.h"

TourismNodes::TourismNodes(int id, string name){
    this->id= id;
    this->name = name;
}

int TourismNodes::getID() const {
    return id;
}
string TourismNodes::getName() const{
    return name;
}

TourismNodes::TourismNodes() {}