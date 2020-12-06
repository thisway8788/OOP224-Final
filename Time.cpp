
/*Final Project Milestone FP
Module: Time
Filename: Time.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/



#include "Time.h"
#include "utils.h"

using namespace std;

namespace sdds {
 
Time& Time::reset() {
    m_min = getTime();
    return *this;
}

Time::Time(unsigned int min) {
    m_min = min;
}

ostream& Time::write(ostream& ostr) const {
 
    int hour = m_min / 60; // 2
    int mins = m_min % 60;
    
    
    ostr.width(2);
    ostr.fill('0');
    ostr << hour << ":";
    ostr.width(2);
    ostr << mins;
    
    return ostr;
}

istream& Time::read(istream& istr) {
    int hour;
    int min;
    istr >> hour;
    char c = 'X';
    istr >> c;
    if (c != ':') {
        istr.setstate(ios::failbit);
    }
    else {
        istr >> min;
        m_min = hour*60 + min;
    }    
    return istr;
}

Time::operator int()const {
    return m_min;
}

Time& Time::operator *= (int val) {
    m_min *= val;
    return *this;
}

Time& Time::operator-=(const Time& D) {
  
    if (m_min < D.m_min) {
        m_min += 24*60;
    }
    m_min -= D.m_min;
    return *this;
}

Time Time::operator-(const Time& ROperand) {
     Time LOperand = *this;
     LOperand -= ROperand;
     return LOperand;
}

ostream& operator<<(ostream& os, const Time& t) {
    return t.write(os);
}

istream& operator>>(istream& is, Time& t) {
    return t.read(is);
}

}
