
/*Final Project Milestone FP
Module: Time
Filename: Time.h
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/



#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
   class Time {
      unsigned int m_min;
   public:
      Time& reset();
      Time(unsigned int min = 0);
      std::ostream& write(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);
      operator int()const;
      Time& operator *= (int val);
      Time& operator-=(const Time& D);
       Time operator-(const Time& ROperand);
   };
   // helper operator << and >> prototypes
std::ostream& operator<<(std::ostream& os, const Time& t);
std::istream& operator>>(std::istream& is, Time& t);

}

#endif // !SDDS_TIME_H

