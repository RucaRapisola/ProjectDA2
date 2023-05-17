#include "TourismInfo/TourismGestor.h"
#include "StadiumShippingInfo/Gestor.h"
#include "RealWordlGraphsInfo/RealGestor.h"
#include <ctime>
#include <cstdlib>
using namespace std;

TourismGestor auxfile;
TourismGraph help;
Gestor auxfile2;
Graph help2;
Graph help3;
RealGestor auxfile4;
RealGraph help4;

//3 functions for exercise 4.1 that show the execution time for a specific graph when doing backtracking funtion
void RealmeasureExecutionTime(RealGraph& graph) {
    clock_t startTime = clock();
    Vertex3* src = graph.findVertex(0);
    vector<bool> visited;
    vector<int> min_path;
    vector<int> currentPath;
    for(int i=0;i<graph.getVertexSet().size();i++){
        visited.push_back(false);
    }
    int count=0;
    double distance=0.0;
    double min_distance=numeric_limits<double>::max();

    // Run the backtracking algorithm
    double minDistance = graph.backtrack(src,visited,count,distance,min_distance,src,min_path,currentPath);

    clock_t endTime = clock();

    // Print the results
    std::cout << "Minimum Distance: " << minDistance << std::endl;
    std::cout << "Execution Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void StadiumsmeasureExecutionTime() {
    clock_t startTime = clock();
    Vertex2* src = help2.findVertex(0);
    vector<bool> visited;
    vector<int> min_path;
    vector<int> currentPath;
    for(int i=0;i<help2.getVertexSet().size();i++){
        visited.push_back(false);
    }
    int count=0;
    double distance=0.0;
    double min_distance=numeric_limits<double>::max();

    // Run the backtracking algorithm
    double minDistance = help2.backtrack(src,visited,count,distance,min_distance,src,min_path,currentPath);

    clock_t endTime = clock();

    // Print the results
    std::cout << "Minimum Distance: " << minDistance << std::endl;
    std::cout << "Execution Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void ShippingmeasureExecutionTime() {
    clock_t startTime = clock();
    Vertex2* src = help3.findVertex(0);
    vector<int> min_path;
    vector<bool> visited;
    vector<int> currentPath;
    for(int i=0;i<help3.getVertexSet().size();i++){
        visited.push_back(false);
    }
    int count=0;
    double distance=0.0;
    double min_distance=numeric_limits<double>::max();

    // Run the backtracking algorithm
    double minDistance = help3.backtrack(src,visited,count,distance,min_distance,src,min_path,currentPath);

    clock_t endTime = clock();

    // Print the results
    std::cout << "Minimum Distance: " << minDistance << std::endl;
    std::cout << "Execution Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void BuildingRealGraphExecutionTime() {
    clock_t startTime = clock();
    auxfile4.gestor_travel2(help4);

    clock_t endTime = clock();
    std::cout << "Execution Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << std::endl;
}



int main(){
    /*
    auxfile.gestor_tourism(help);
    auxfile.gestor_travel(help);

    auxfile2.gestor_stadiums(help2);
    auxfile2.gestor_travel_stadiums(help2);
    auxfile2.gestor_shipping(help3);
    auxfile2.gestor_travel_shipping(help3);
    */
    auxfile4.gestor_nodes_2(help4);
    BuildingRealGraphExecutionTime();

    /*
    RealmeasureExecutionTime(help4);
    StadiumsmeasureExecutionTime();
    ShippingmeasureExecutionTime();
     */
    /*
     //4.1
    Vertex* bruhh = help.findVertex(0);
    std::vector<bool> visited;
    double min_distance=10000000.0;
    vector<int> min_path;
    vector<int> currentPath;
    for (int i=0; i< help.getNumVertex();i++){
        visited.push_back(false);
    }
    double howmany = help.backtrack(bruhh, visited, 0, 0.0, numeric_limits<double>::max(), bruhh,min_path,currentPath);

    cout << "Minimum Path: ";
    for (int vertex : min_path) {
        cout << vertex << " -> ";
    }
    cout <<"0"<< endl;
    cout << "Minimum Path Distance: " << howmany << endl;
     */
    /*
    // Call the primMST function to find the minimum spanning tree
    vector<Edge3> mst = help4.primMST();

    for (const Edge3& edge : mst) {
        cout << edge.getOrig()->getId() << " - " << edge.getDest()->getId() << " : " << edge.getDistancia() << endl;
    }
     */
}

