
/*Final Project Milestone FP
Module: Patient
Filename: Patient.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {

Patient::Patient(int ticketNumber, bool fileIOFlag): m_ticket(ticketNumber) {
    m_patientName = nullptr;
    m_ohipNumber = 0;
    m_fileIOFlag = fileIOFlag;
}

Patient::~Patient() {
    delete [] m_patientName;
}

bool Patient::fileIO() const {
    return m_fileIOFlag;
}

void Patient::fileIO(bool fileIOFlag) {
    m_fileIOFlag = fileIOFlag;
}

bool Patient::operator==(char c) const {
    return c == type();
}

bool Patient::operator==(const Patient& p) const {
    return type() == p.type();
}

void Patient::setArrivalTime() {
    m_ticket.resetTime();
}

Patient::operator Time()const {
    return Time(m_ticket);
}

int Patient::number() const {
    return m_ticket.number();
}


ostream& Patient::csvWrite(ostream& os) const {
    os << type();
    os << ",";
    os << m_patientName;
    os << ",";
    os << m_ohipNumber;
    os << ",";
    m_ticket.csvWrite(os);
    return os;
}

istream& Patient::csvRead(istream& is) {
    char temp[51];
    is.get(temp, 51, ',');
    delete [] m_patientName;
    m_patientName = new char[strlen(temp)+1];
    strcpy(m_patientName, temp);
    is.ignore(2000, ',');
    is >> m_ohipNumber;
    is.ignore();
    m_ticket.csvRead(is);    
    return is;
}

ostream& Patient::write(ostream& os) const {
    os << m_ticket << endl;
    if (m_patientName[0] == '\n') {

        for (unsigned int i=1; i<strlen(m_patientName); i++) {
            m_patientName[i-1] = m_patientName[i];
        }
        m_patientName[strlen(m_patientName)-1] = '\0';
    }
    os << m_patientName;
    os << ", OHIP: ";
    os << m_ohipNumber;
    return os;
}

istream& Patient::read(istream& is) {
    cout << "Name: ";
    char temp[51];
    is.get(temp, 51);
    delete [] m_patientName;
    
    m_patientName = new char[strlen(temp)+1];
    strcpy(m_patientName, temp);
    is.ignore(2000, '\n');
    
    cout << "OHIP: ";
    bool validate = true;
    do {
        validate = true;
        is >> m_ohipNumber;
        if (cin.fail()) {
            cin.clear();
            cout << "Bad integer value, try again: ";
            cin.ignore(2000, '\n');
            validate = false;
        }
        else if (m_ohipNumber < 100000000 || m_ohipNumber > 999999999) {
            cout << "Invalid value entered, retry[100000000 <= value <= 999999999]: ";
            validate = false;
        }
    } while(!validate);
    return is;
}

}
