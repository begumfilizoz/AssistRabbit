// Begüm Filiz Öz, 22203470, Sec 3

#include "Cage.h"
Cage::Cage()
{
}
/*Cage::Cage(const Cage& cage)
{
    this->name = cage.getName();
    this->prob = cage.getProb();
}*/
Cage::Cage(string cageName, double cageProb) : name(cageName), prob(cageProb) {
}
string Cage::getName() const {
    return name;
}
double Cage::getProb() const {
    return prob;
}
void Cage::setName(string cageName) {
    name = cageName;
}
void Cage::setProb(double cageProb) {
    prob = cageProb;
}
/*
Cage& Cage::operator= (const Cage& cage)
{
    this->name = cage.getName();
    this->prob = cage.getProb();
}*/
