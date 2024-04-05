// Begüm Filiz Öz, 22203470, Sec 3

#ifndef ASSGN4_ZOOMAP_H
#define ASSGN4_ZOOMAP_H
#include <iostream>
#include <string>
#include <fstream>
#include "Cage.h"
#include "LinkedList.h"
#include "Stack.h"
#include "LabelledInt.h"
#include "LabelledString.h"
using namespace std;


class ZooMap {
public:
    ZooMap(const string cageFile, const string zooFile);
    ~ZooMap();
    void displayAllCages() const;
    void displayAdjacentCages(const string cageName) const;
    void displayZooMap() const;
    void findSafestPath(const string startCage, const string endCage);
    void findMostDangerousPath(const string startCage, const string endCage);
    void findAllPaths(const string startCage, const string endCage);
    //void print();
private:
    bool pathsFoundBefore;
    ifstream in;
    int verticeNum;
    LinkedList<LinkedList<Cage>> verticeLists;
    LinkedList<Cage> cages;
    LinkedList<LabelledString> allPaths;
};


#endif //ASSGN4_ZOOMAP_H
