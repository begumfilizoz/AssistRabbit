// Begüm Filiz Öz, 22203470, Sec 3

#ifndef ASSGN4_LABELLEDINT_H
#define ASSGN4_LABELLEDINT_H
#include <string>
using namespace std;


class LabelledInt {
private:
    string name;
    int num;
public:
    LabelledInt();
    LabelledInt(string newName, int newNum);
    ~LabelledInt();
    string getName();
    int getNum();
    void setNum(int newNum);


};


#endif //ASSGN4_LABELLEDINT_H
