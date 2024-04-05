// Begüm Filiz Öz, 22203470, Sec 3

#ifndef ASSGN4_LABELLEDSTRING_H
#define ASSGN4_LABELLEDSTRING_H
#include <string>
using namespace std;

class LabelledString {
private:
    string name;
    string content;
public:
    LabelledString();
    LabelledString(string newName, string newContent);
    ~LabelledString();
    string getName();
    string getContent();
};


#endif //ASSGN4_LABELLEDSTRING_H
