#include "ExtraGestor.h"
#include <fstream>
#include <sstream>
#include "ExtraGraph.h"

using namespace std;

void ExtraGestor::gestor_stadiums(ExtraGraph &aux1){
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

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
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

void ExtraGestor::gestor_travel_stadiums(ExtraGraph &aux1) {
    ifstream travelf("Toy-Graphs/stadiums.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

unordered_map<int, ExtraNodes> ExtraGestor::getNodes() const {
    return nodes;
}

unordered_map<int, ExtraNodes> ExtraGestor::getNodes2() const {
    return nodes2;
}
