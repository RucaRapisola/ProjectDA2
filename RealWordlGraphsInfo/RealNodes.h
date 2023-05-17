#ifndef PROJECT2GRAPHS_REALNODES_H
#define PROJECT2GRAPHS_REALNODES_H


#include <string>
using namespace std;


class Node {
private:
    int id;
    double longitude;
    double latitude;
public:
    Node(int id , double longitude , double latitude);
    ///Blank constructor for the Stations class.
    Node();
    int getID()const;
    double getLongitude()const;
    double getLatitude()const;
};

#endif //PROJECT2GRAPHS_REALNODES_H
