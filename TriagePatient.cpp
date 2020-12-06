
/*Final Project Milestone FP
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#include <cstring>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
int nextTriageTicket = 1;


TriagePatient::TriagePatient(): Patient(nextTriageTicket) {
    m_symptoms = nullptr;
    nextTriageTicket++;
}

TriagePatient::~TriagePatient() {
    delete [] m_symptoms;
}

char TriagePatient::type() const {
    return 'T';
}

ostream& TriagePatient::csvWrite(ostream& os) const {
    Patient::csvWrite(os);
    os << "," << m_symptoms;
    return os;
}

istream& TriagePatient::csvRead(istream& is) {
    delete [] m_symptoms;
    Patient::csvRead(is);
    is.ignore(2000, ',');
    char temp[511];
    is.get(temp, 511, '\n');
    m_symptoms = new char[strlen(temp)+1];
    strcpy(m_symptoms, temp);
    nextTriageTicket = number() + 1;
    return is;
}

istream& TriagePatient::read(istream& is) {
    if (fileIO()) {
        csvRead(is);
    }
    else {
        delete [] m_symptoms;
        Patient::read(is);
        is.ignore(2000, '\n');
        cout << "Symptoms: ";
        char temp[511];
        is.get(temp, 511, '\n');
        m_symptoms = new char[strlen(temp)+1];
        strcpy(m_symptoms, temp);
        
    }
    return is;
}

ostream& TriagePatient::write(ostream& os) const {
    if (fileIO()) {
        csvWrite(os);
    }
    else {
        os << "TRIAGE" << endl;
        Patient::write(os);
        os << endl;
        os << "Symptoms: ";
        os << m_symptoms << endl;
    }
    return os;
}



}
