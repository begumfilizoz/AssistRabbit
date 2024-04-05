// Begüm Filiz Öz, 22203470, Sec 3

#include "LabelledString.h"
LabelledString::LabelledString(string newName, string newContent) {
    name = newName;
    content = newContent;
}
LabelledString::LabelledString(){}
LabelledString::~LabelledString(){}
string LabelledString::getName() {
    return name;
}
string LabelledString::getContent() {
    return content;
}