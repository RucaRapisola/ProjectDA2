#include "Gestor.h"
#include <fstream>
#include <sstream>
#include "Graph.h"

using namespace std;

void Gestor::gestor_stadiums(Graph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Toy-Graphs/stadiums.csv");
    string line;
    int i=0;
    getline(stationf,line);
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        Nodes Nodes1(stoi(Origem));
        Nodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void Gestor::gestor_travel_stadiums(Graph &aux1) {
    ifstream travelf("Toy-Graphs/stadiums.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        Nodes Nodes1(nodes.at(stoi(Origem)));
        Nodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void Gestor::gestor_shipping(Graph &aux2){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Toy-Graphs/shipping.csv");
    string line;
    int i=0;
    getline(stationf,line);
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        Nodes Nodes1(stoi(Origem));
        Nodes Nodes2(stoi(Destino));
        if(i==0){
            aux2.addVertex(stoi(Origem));
            nodes2.insert({stoi(Origem),Nodes1});
            aux2.addVertex(stoi(Destino));
            nodes2.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes2.begin();itr!=nodes2.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes2.begin();itr!=nodes2.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux2.addVertex(stoi(Origem));
            nodes2.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux2.addVertex(stoi(Destino));
            nodes2.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void Gestor::gestor_travel_shipping(Graph &aux2) {
    ifstream travelf("Toy-Graphs/shipping.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        Nodes Nodes1(nodes2.at(stoi(Origem)));
        Nodes Nodes2(nodes2.at(stoi(Destino)));

        aux2.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

unordered_map<int, Nodes> Gestor::getNodes() const {
    return nodes;
}

unordered_map<int, Nodes> Gestor::getNodes2() const {
    return nodes2;
}