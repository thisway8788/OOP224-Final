
/*Final Project Milestone FP
Module: Ticket
Filename: Ticket.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/



#include "Ticket.h"
namespace sdds {
   Ticket::Ticket(int number) {
      m_number = number;
   }
   Ticket::operator Time() const {
      return m_time;
   }
   int Ticket::number() const {
      return m_number;
   }
   void Ticket::resetTime() {
      m_time.reset();
   }
   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
       return ostr << m_number << "," << m_time;
   }
   std::istream& Ticket::csvRead(std::istream& istr) {
      istr >> m_number;
      istr.ignore();
      istr >> m_time;       
      return istr;
   }
   std::ostream& Ticket::write(std::ostream& ostr) const {
       return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
   }
   std::istream& Ticket::read(std::istream& istr) {
      return csvRead(istr);
   }
}


