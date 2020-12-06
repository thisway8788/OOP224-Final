
/*Final Project Milestone FP
Module: CovidPatient
Filename: CovidPatient.h
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"
namespace sdds {

   class CovidPatient: public Patient {
   
   public:
       CovidPatient();
       char type() const;
       std::ostream& csvWrite(std::ostream& os) const;
       std::istream& csvRead(std::istream& is);
       std::ostream& write(std::ostream& os) const;
       std::istream& read(std::istream& is);
       
   };
}
#endif // !SDDS_COVIDPATIENT_H_
