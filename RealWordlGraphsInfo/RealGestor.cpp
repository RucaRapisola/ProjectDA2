#include "RealGestor.h"
#include <fstream>
#include <sstream>
#include "RealGraph.h"

using namespace std;

void RealGestor::gestor_nodes_1(RealGraph &aux1){
    bool confirm_repeated=false;
    ifstream nodesf("Real-World-Graphs/graph1/nodes.csv");
    string line;
    int i=0;
    getline(nodesf,line);
    while(getline(nodesf,line)){
        istringstream iss(line);
        string id,longitude,latitude;
        getline(iss,id,',');
        getline(iss,longitude,',');
        getline(iss,latitude,',');

        Node Node(stoi(id), stod(longitude),stod(latitude));
        if(i==0){
            aux1.addVertex(i);
            nodes_id_1.insert({stoi(id),i});
            nodes.insert({i,Node});
        }

        for(auto itr=nodes_id_1.begin();itr!=nodes_id_1.end();itr++){
            if(Node.getID()==itr->first){
                confirm_repeated=true;
                break;
            }
        }
        if(confirm_repeated==false){
            aux1.addVertex(i);
            nodes_id_1.insert({stoi(id),i});
            nodes.insert({i,Node});
        }

        i++;
        confirm_repeated=false;
    }
}

void RealGestor::gestor_travel1(RealGraph &aux1) {
    ifstream travelf("Real-World-Graphs/graph1/edges.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string node_from_id, node_to_id, distancia;

        getline(iss,node_from_id,',');
        getline(iss,node_to_id,',');
        getline(iss,distancia,',');

        Node node_from = nodes.at(nodes_id_1.at(stoi(node_from_id)));
        Node node_to = nodes.at(nodes_id_1.at(stoi(node_to_id)));

        aux1.addBidirectionalEdge(nodes_id_1.at(stoi(node_from_id)),nodes_id_1.at(stoi(node_to_id)),stof(distancia));
    }
}

void RealGestor::gestor_nodes_2(RealGraph &aux2){
    bool confirm_repeated=false;
    ifstream nodesf("Real-World-Graphs/graph2/nodes.csv");
    string line;
    int i=0;
    getline(nodesf,line);
    while(getline(nodesf,line)){
        istringstream iss(line);
        string id,longitude,latitude;
        getline(iss,id,',');
        getline(iss,longitude,',');
        getline(iss,latitude,',');

        Node Node(stoi(id),stod(longitude),stod(latitude));
        if(i==2){
            aux2.addVertex(i);
            nodes_id_2.insert({stoi(id),i});
            nodes_2.insert({i, Node});
        }

        for(auto itr=nodes_id_2.begin();itr!=nodes_id_2.end();itr++){
            if(Node.getID()==itr->second){
                confirm_repeated=true;
                break;
            }
        }
        if(confirm_repeated==false){
            aux2.addVertex(i);
            nodes_id_2.insert({stoi(id),i});
            nodes_2.insert({i,Node});
        }

        i++;
        confirm_repeated=false;
    }
}

void RealGestor::gestor_travel2(RealGraph &aux2) {
    ifstream travelf("Real-World-Graphs/graph2/edges.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string node_from_id, node_to_id, distancia;

        getline(iss,node_from_id,',');
        getline(iss,node_to_id,',');
        getline(iss,distancia,',');

        Node node_from = nodes_2.at(nodes_id_2.at(stoi(node_from_id)));
        Node node_to = nodes_2.at(nodes_id_2.at(stoi(node_to_id)));

        aux2.addBidirectionalEdge(nodes_id_2.at(stoi(node_from_id)),nodes_id_2.at(stoi(node_to_id)),stof(distancia));
    }
}

void RealGestor::gestor_nodes_3(RealGraph &aux3){
    bool confirm_repeated=false;
    ifstream nodesf("Real-World-Graphs/graph3/nodes.csv");
    string line;
    int i=0;
    getline(nodesf,line);
    while(getline(nodesf,line)){
        istringstream iss(line);
        string id,longitude,latitude;
        getline(iss,id,',');
        getline(iss,longitude,',');
        getline(iss,latitude,',');

        Node Node(stoi(id),stod(longitude),stod(latitude));
        if(i==0){
            aux3.addVertex(i);
            nodes_id_3.insert({stoi(id),i});
            nodes_3.insert({i,Node});
        }

        for(auto itr=nodes_id_3.begin();itr!=nodes_id_3.end();itr++){
            if(Node.getID()==itr->second){
                confirm_repeated=true;
                break;
            }
        }
        if(confirm_repeated==false){
            aux3.addVertex(i);
            nodes_id_3.insert({stoi(id),i});
            nodes_3.insert({i,Node});
        }

        i++;
        confirm_repeated=false;
    }
}

void RealGestor::gestor_travel3(RealGraph &aux3) {
    ifstream travelf("Real-World-Graphs/graph3/edges.csv");
    string line;
    getline(travelf,line);
    while(getline(travelf,line)){
        istringstream iss(line);
        string node_from_id, node_to_id, distancia;

        getline(iss,node_from_id,',');
        getline(iss,node_to_id,',');
        getline(iss,distancia,',');

        Node node_from = nodes_3.at(nodes_id_3.at(stoi(node_from_id)));
        Node node_to = nodes_3.at(nodes_id_3.at(stoi(node_to_id)));

        aux3.addBidirectionalEdge(nodes_id_3.at(stoi(node_from_id)),nodes_id_3.at(stoi(node_to_id)),stof(distancia));
    }
}

unordered_map<int, int> RealGestor::getNodesID_1() const{
    return nodes_id_1;
}
unordered_map<int, int> RealGestor::getNodesID_2() const{
    return nodes_id_2;
}
unordered_map<int, int> RealGestor::getNodesID_3() const{
    return nodes_id_3;
}

unordered_map<int, Node> RealGestor::getStations() const{
    return nodes;
}