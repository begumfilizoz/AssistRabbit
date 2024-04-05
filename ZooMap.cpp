// Begüm Filiz Öz, 22203470, Sec 3

#include "ZooMap.h"
#include "Cage.h"
#include "LabelledInt.h"
#include "LabelledString.h"
#include <string>
#include <iomanip>

using namespace std;
ZooMap::ZooMap(const string cageFile, const string zooFile) {
    in.open(cageFile);
    string cageLine;
    verticeNum = 0;
    while (getline(in, cageLine))
    {
        int lastIndex = cageLine.find(';');
        string name = cageLine.substr(0, lastIndex);
        double prob = stod(cageLine.substr(lastIndex + 1, string::npos));
        verticeNum++;
        Cage cage;
        cage.setName(name);
        cage.setProb(prob);
        LinkedList<Cage> cageList;
        cageList.setName(name);
        int pos = verticeLists.getPosition(name, false);
        verticeLists.insert(pos, cageList);
        int cagePos = cages.getPosition(name, false);
        cages.insert(cagePos, cage);
    }
    in.close();
    in.open(zooFile);
    string edgeLine;
    int edgenum = 0;
    while (getline(in, edgeLine))
    {
        int lastIndex = edgeLine.find(';');
        string origin = edgeLine.substr(0, lastIndex);
        string des = edgeLine.substr(lastIndex + 1, string::npos);
        int orPos = verticeLists.getPosition(origin, true);
        int desCagePos = cages.getPosition(des, true);
        int desPos = verticeLists.getNodeAt(orPos)->getItem().getPosition(des, false);
        verticeLists.getNodeAt(orPos)->getItem().insert(desPos, cages.getNodeAt(desCagePos)->getItem());
        edgenum++;
    }
    cout << verticeNum << " cages and " << edgenum << " connections have been loaded." << endl;
    //cout << endl;
    /*for (int i = 1; i <= verticeLists.getLength(); i++)
    {
        cout << cages.getNodeAt(i)->getItem().getName() << " " << cages.getNodeAt(i)->getItem().getProb() << " List:" << endl;
        for (int k = 1; k <= verticeLists.getNodeAt(i)->getItem().getLength(); k++)
        {
            cout << verticeLists.getNodeAt(i)->getItem().getNodeAt(k)->getItem().getName() << " " << verticeLists.getNodeAt(i)->getItem().getNodeAt(k)->getItem().getProb() << endl;
        }
        cout << endl;
    }*/
}
ZooMap::~ZooMap()
{
    verticeLists.clear();
    cages.clear();
    allPaths.clear();
}

void ZooMap::displayAllCages() const {
    cout << "The cages in the zoo are:" << endl;
    if (cages.isEmpty())
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 1; i <= cages.getLengthConst(); i++)
        {
            if (i != 1)
            {
                cout << " ";
            }
            cout << cages.getNodeAtConst(i)->getItem().getName() << ",";
        }
        cout << endl;
    }
}
void ZooMap::displayZooMap() const {
    cout << "The whole zoo map is:" << endl;
    for (int k = 1; k <= cages.getLengthConst(); k++)
    {
        string cageName = cages.getNodeAtConst(k)->getItem().getName();
        cout << cageName << " ->";
        for (int i = 1; i <= verticeLists.getNodeAtConst(verticeLists.getPositionConst(cageName, true))->getItem().getLength(); i++)
        {
            cout << " ";
            cout << verticeLists.getNodeAtConst(verticeLists.getPositionConst(cageName, true))->getItem().getNodeAt(i)->getItem().getName() << ",";
        }
        cout << endl;
    }
}
void ZooMap::displayAdjacentCages(const string cageName) const {
    cout << "The cages adjacent to " << cageName << " are:" << endl;
    cout << cageName << " ->";
    for (int i = 1; i <= verticeLists.getNodeAtConst(verticeLists.getPositionConst(cageName, true))->getItem().getLength(); i++)
    {
        cout << " ";
        cout << verticeLists.getNodeAtConst(verticeLists.getPositionConst(cageName, true))->getItem().getNodeAt(i)->getItem().getName() << ",";
    }
    cout << endl;
}
void ZooMap::findSafestPath(const string startCage, const string endCage) {
    ZooMap::findAllPaths(startCage, endCage);
    if (allPaths.isEmpty())
    {
        cout << "No path exists from " << startCage << " to " << endCage << "." << endl;
    }
    else
    {
        cout << "Safest path from " << startCage << " to " << endCage << " is:" << endl;
        double max = 0.0;
        string path;
        for (int i = 1; i <= allPaths.getLength(); i++)
        {
            double currProb = 1.0;
            for (int k = 0; k < allPaths.getNodeAt(i)->getItem().getContent().length(); k++)
            {
                string cageName = string() + allPaths.getNodeAt(i)->getItem().getContent()[k];
                currProb = currProb * (cages.getNodeAt(cages.getPosition(cageName, true))->getItem().getProb());
            }
            if (max < currProb)
            {
                path = allPaths.getNodeAt(i)->getItem().getContent();
                max = currProb;
            }
        }
        for (int j = path.length() - 1; j >= 0; j--)
        {
            cout << path[j];
            if (j != 0)
            {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Probability: " << fixed << setprecision(6) << max << endl;
    }
    allPaths.clear();
}
void ZooMap::findAllPaths(const string startCage, const string endCage) {
    Stack newStack;
    int index = 1;
    bool noNext = true;
    bool proceed = true;
    Cage cage = cages.getNodeAt(cages.getPosition(startCage, true))->getItem();
    Cage last = cages.getNodeAt(cages.getPosition(endCage, true))->getItem();
    Cage nextCage;
    newStack.push(cage);
    LinkedList<LabelledInt> nexts;
    for (int i = 1; i <= cages.getLength(); i++)
    {
        LabelledInt label(cages.getNodeAt(i)->getItem().getName(), verticeLists.getNodeAt(verticeLists.getPosition(cages.getNodeAt(i)->getItem().getName(),true))->getItem().getLength());
        nexts.insert(nexts.getPosition(cages.getNodeAt(i)->getItem().getName(), false), label);
    }
    while(!(newStack.isEmpty()))
    {
        while(cage.getName() != endCage)
        {
            while (noNext)
            {
                if (verticeLists.getNodeAt(verticeLists.getPosition(cage.getName(), true))->getItem().isPosEmpty(verticeLists.getNodeAt(verticeLists.getPosition(cage.getName(), true))->getItem().getLength() - nexts.getNodeAt(nexts.getPosition(cage.getName(), true))->getItem().getNum() + 1))
                {
                    newStack.pop();
                    if (newStack.isEmpty())
                    {
                        noNext = false;
                        proceed = false;
                        break;
                    }
                    else
                    {
                        cage = newStack.peek();
                        noNext = true;
                    }
                }
                else
                {
                    nextCage = verticeLists.getNodeAt(verticeLists.getPosition(cage.getName(), true))->getItem().getNodeAt(verticeLists.getNodeAt(verticeLists.getPosition(cage.getName(), true))->getItem().getLength() - nexts.getNodeAt(nexts.getPosition(cage.getName(), true))->getItem().getNum() + 1)->getItem();
                    newStack.push(nextCage);
                    int old = nexts.getNodeAt(nexts.getPosition(cage.getName(), true))->getItem().getNum();
                    int newNum = old - 1;
                    nexts.remove(nexts.getPosition(cage.getName(), true));
                    LabelledInt newlabel(cage.getName(), newNum );
                    nexts.insert(nexts.getPosition(cage.getName(), false), newlabel);
                    noNext = false;
                    proceed = true;
                }
            }

            if (proceed)
            {
                Stack temp(newStack);
                bool ifs = false;
                temp.pop();
                while(!(temp.isEmpty()))
                {
                    if (temp.peek().getName() == nextCage.getName())
                    {
                        newStack.pop();
                        ifs = true;
                        break;
                    }
                    else
                    {
                        temp.pop();
                    }
                }
                if (!ifs && verticeLists.getNodeAt(verticeLists.getPosition(nextCage.getName(), true))->getItem().getLength() == 0 && nextCage.getName() != endCage)
                {
                    newStack.pop();
                }
                else
                {
                    if (!ifs)
                    {
                        cage = nextCage;
                    }
                }
            }
            if (newStack.isEmpty())
            {
                break;
            }
            noNext = true;
        }
        if (cage.getName() == endCage)
        {
            string path = "";
            Stack temp(newStack);
            while (!(temp.isEmpty()))
            {
                path = path + temp.peek().getName();
                temp.pop();
            }
            LabelledString ls(to_string(index), path);
            allPaths.insert(index, ls);
            index++;
            newStack.pop();
            if (!(newStack.isEmpty()))
            {
                cage = newStack.peek();

            }
            else
            {
               break;
            }
        }
    }
}
/*void ZooMap::print() {
    for (int i = 1; i <= allPaths.getLength(); i++)
    {
        cout << allPaths.getNodeAt(i)->getItem().getContent() << endl;
    }
}*/
void ZooMap::findMostDangerousPath(const string startCage, const string endCage) {
    ZooMap::findAllPaths(startCage, endCage);
    if (allPaths.isEmpty())
    {
        cout << "No path exists from " << startCage << " to " << endCage << "." << endl;
    }
    else
    {
        cout << "Most dangerous path from " << startCage << " to " << endCage << " is:" << endl;
        double min = 1.0;
        string path;
        for (int i = 1; i <= allPaths.getLength(); i++)
        {
            double currProb = 1.0;
            for (int k = 0; k < allPaths.getNodeAt(i)->getItem().getContent().length(); k++)
            {
                string cageName = string() + allPaths.getNodeAt(i)->getItem().getContent()[k];
                currProb = currProb * (cages.getNodeAt(cages.getPosition(cageName, true))->getItem().getProb());
            }
            if (min > currProb)
            {
                path = allPaths.getNodeAt(i)->getItem().getContent();
                min = currProb;
            }
        }
        for (int j = path.length() - 1; j >= 0; j--)
        {
            cout << path[j];
            if (j != 0)
            {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Probability: " << fixed << setprecision(6) << min << endl;
    }
    allPaths.clear();
}