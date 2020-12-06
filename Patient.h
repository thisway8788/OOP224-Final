
/*Final Project Milestone FP
Module: Patient
Filename: Patient.h
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/



#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {


class Patient: public IOAble {
  
    char* m_patientName;
    int m_ohipNumber;
    Ticket m_ticket;
    bool m_fileIOFlag;
    
public:
    Patient(int ticketNumber = 0, bool fileIOFlag = false);
    Patient(const Patient&) = delete;
    Patient& operator=(const Patient&) = delete;
    ~Patient();
    
    virtual char type() const = 0;
    
    bool fileIO() const;
    void fileIO(bool fileIOFlag);
    
    bool operator==(char c) const;
    bool operator==(const Patient& p) const;
    
    void setArrivalTime();
    operator Time()const;
    int number() const;
    
    std::ostream& csvWrite(std::ostream& os) const;
    std::istream& csvRead(std::istream& is);
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
};



}
#endif