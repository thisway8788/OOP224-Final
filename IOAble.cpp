
/*Final Project Milestone FP
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
   
IOAble::~IOAble() { }



std::ostream& operator<<(std::ostream& os, const IOAble& ioa) {
    return ioa.write(os);
}

std::istream& operator>>(std::istream& is, IOAble& ioa) {
    return ioa.read(is);
}

}
