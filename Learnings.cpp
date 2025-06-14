#include "Learnings.h"
#include <iostream>
AllLearning::AllLearning( const std::string& Learning)
    : Learning(Learning) {}

string AllLearning::display() const {
    return Learning;
}