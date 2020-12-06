
/*Final Project Milestone FP
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
   class IOAble {
   public:

       virtual std::ostream& csvWrite(std::ostream& os) const = 0;
       virtual std::istream& csvRead(std::istream& is) = 0;
       virtual std::ostream& write(std::ostream& os) const = 0;
       virtual std::istream& read(std::istream& is) = 0;
       
       virtual ~IOAble();
   };

std::ostream& operator<<(std::ostream& os, const IOAble& ioa);
std::istream& operator>>(std::istream& is, IOAble& ioa);


}
#endif // !SDDS_IOABLE_H_
