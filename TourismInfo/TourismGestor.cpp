#include "TourismGestor.h"
#include <fstream>
#include <sstream>
#include "TourismGraph.h"

using namespace std;

void TourismGestor::gestor_tourism(TourismGraph &aux){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Toy-Graphs/tourism.csv");
    string line;
    int i=0;
    getline(stationf,line);
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia,LabelOrigem,LabelDestino;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');
        getline(iss,LabelOrigem,',');
        getline(iss,LabelDestino,',');

        TourismNodes tourismNodes1(stoi(Origem),LabelOrigem);
        TourismNodes tourismNodes2(stoi(Destino),LabelDestino);
        if(i==0){
            aux.addVertex(stoi(Origem));
            Tourism_nodes_names.insert({LabelOrigem,stoi(Origem)});
            Tourism_nodes.insert({stoi(Origem),tourismNodes1});
            aux.addVertex(stoi(Destino));
            Tourism_nodes_names.insert({LabelDestino,stoi(Destino)});
            Tourism_nodes.insert({stoi(Destino),tourismNodes2});
        }

        for(auto itr=Tourism_nodes.begin();itr!=Tourism_nodes.end();itr++){
            if(tourismNodes1.getName()==itr->second.getName() and tourismNodes1.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=Tourism_nodes.begin();itr!=Tourism_nodes.end();itr++){
            if(tourismNodes2.getName()==itr->second.getName() and tourismNodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux.addVertex(stoi(Origem));
            Tourism_nodes_names.insert({LabelOrigem,stoi(Origem)});
            Tourism_nodes.insert({stoi(Origem),tourismNodes1});
        }
        if(confirm_repeated2==false){
            aux.addVertex(stoi(Destino));
            Tourism_nodes_names.insert({LabelDestino,stoi(Destino)});
            Tourism_nodes.insert({stoi(Destino),tourismNodes2});
        }

        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void TourismGestor::gestor_travel(TourismGraph &aux) {
    ifstream travelf("Toy-Graphs/tourism.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia,LabelOrigem,LabelDestino;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');
        getline(iss,LabelOrigem,',');
        getline(iss,LabelDestino,',');

        TourismNodes tourismNodes1(Tourism_nodes.at(Tourism_nodes_names.at(LabelOrigem)));
        TourismNodes tourismNodes2(Tourism_nodes.at(Tourism_nodes_names.at(LabelDestino)));

        aux.addBidirectionalEdge(Tourism_nodes_names.at(LabelOrigem),Tourism_nodes_names.at(LabelDestino),stoi(Distancia));
    }
}

unordered_map<string, int> TourismGestor::getTourismNodesNames() const {
    return Tourism_nodes_names;
}

unordered_map<int, TourismNodes> TourismGestor::getTourismNodes() const {
    return Tourism_nodes;
}

