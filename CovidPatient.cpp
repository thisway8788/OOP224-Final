
/*Final Project Milestone FP
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
  
CovidPatient::CovidPatient(): Patient(nextCovidTicket) {
    nextCovidTicket++;
}

char CovidPatient::type() const {
    return 'C';
}

ostream& CovidPatient::csvWrite(ostream& os) const {
    return Patient::csvWrite(os);
}

istream& CovidPatient::csvRead(istream& is) {
    Patient::csvRead(is);
    nextCovidTicket = number()+1;
    return is;
}

ostream& CovidPatient::write(ostream& os) const {
    if (fileIO()) {
        csvWrite(os);
    }
    else {
        os << "COVID TEST" << endl;
        Patient::write(os);
        os << endl;
    }
    return os;
}

istream& CovidPatient::read(istream& is) {
    if (fileIO()) {
        csvRead(is);
    }
    else {
        Patient::read(is);
    }
    return is;
}

}
