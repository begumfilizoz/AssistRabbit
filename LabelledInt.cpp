// Begüm Filiz Öz, 22203470, Sec 3

#include "LabelledInt.h"
LabelledInt::LabelledInt(string newName, int newNum) {
    name = newName;
    num = newNum;
}
LabelledInt::LabelledInt()
{
}
LabelledInt::~LabelledInt()
{
}
void LabelledInt::setNum(int newNum) {
    num = newNum;
}
string LabelledInt::getName() {
    return name;
}
int LabelledInt::getNum() {
    return num;
}