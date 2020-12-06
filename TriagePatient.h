
/*Final Project Milestone FP
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/



#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {

class TriagePatient: public Patient  {
    
    char* m_symptoms;
    
public:
    TriagePatient();
    ~TriagePatient();
    char type() const;
    std::ostream& csvWrite(std::ostream& os) const;
    std::istream& csvRead(std::istream& is);
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
};

}
#endif // !SDDS_
