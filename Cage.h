// Begüm Filiz Öz, 22203470, Sec 3

#ifndef ASSGN4_CAGE_H
#define ASSGN4_CAGE_H
#include <iostream>
#include <string>
using namespace std;


class Cage {
private:
    double prob;
    string name;
public:
    Cage();
    //Cage(const Cage& cage);
    Cage(string name, double prob);
    string getName() const;
    double getProb() const;
    void setName(string cageName);
    void setProb(double cageProb);
    //Cage& operator= (const Cage& cage);
};


#endif //ASSGN4_CAGE_H
