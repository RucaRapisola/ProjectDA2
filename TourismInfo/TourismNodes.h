#ifndef PROJECT2GRAPHS_TOURISMNODES_H
#define PROJECT2GRAPHS_TOURISMNODES_H

#include <string>
using namespace std;

class TourismNodes {
private:
    int id;
    string name;
public:
    TourismNodes(int id, std::string name);

    TourismNodes();

    int getID() const;

    std::string getName()const;

};

#endif //PROJECT2GRAPHS_TOURISMNODES_H
