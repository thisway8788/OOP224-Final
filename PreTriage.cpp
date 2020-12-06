
/*Final Project Milestone FP
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/



#include <cstring>
#include <fstream>
#include "Time.h"
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;

namespace sdds {

void PreTriage::reg() {
    if (m_lineupSize == maxNoOfPatients) {
        cout << "Line up full!" << endl;
        return;
    }
        
    int selection;
    while (m_pMenu >> selection) {
        switch (selection) {
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient;
                break;
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient;
                break;
            case 0:
                return;
            default:
                break;
        }
        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        m_lineup[m_lineupSize]->fileIO(false);
        cin >> *m_lineup[m_lineupSize];
        cout << endl << "******************************************" << endl;
        cout << *m_lineup[m_lineupSize];
        cout << "Estimated Wait Time: ";
        cout << getWaitTime(*m_lineup[m_lineupSize]);
        cout << endl << "******************************************" << endl << endl;
        m_lineupSize++;
        break;
    }
    
}

void PreTriage::admit() {
    int selection;
    while (m_pMenu >> selection) {
        char type = 'X';
        switch (selection) {
            case 1:
                type = 'C';
                break;
            case 2:
                type = 'T';
                break;
            case 0:
                return;
        }
        
        int index = indexOfFirstInLine(type);
        if (index == -1) {
            return;
        }
        cout << endl;
        cout << "******************************************" << endl;
        m_lineup[index]->fileIO(false);
        cout << "Calling for " << *m_lineup[index];
        cout << "******************************************" << endl << endl;
        setAverageWaitTime(*m_lineup[index]);
        removePatientFromLineup(index);
        

        break;
    }
    
}

const Time PreTriage::getWaitTime(const Patient& p)const {
    for (int i=0; i<m_lineupSize; i++) {
        if (p.number() == m_lineup[i]->number()) {
           if (p.type() == 'C') {
return (m_lineup[i]->number()-1) * m_averCovidWait;
        }
else {
return (m_lineup[i]->number()-1) * m_averTriageWait;
    }
}
}
    return Time();
}

void PreTriage::setAverageWaitTime(const Patient& p) {
    Time awt;
    if (p.type() == 'C') {
        awt = m_averCovidWait;
        m_averCovidWait = ((getTime() - Time(p)) + (awt * (p.number()-1))) / p.number();
    }
    else {
        awt = m_averTriageWait;
        m_averTriageWait = ((getTime() - Time(p)) + (awt * (p.number()-1))) / p.number();
    }
    
}

void PreTriage::removePatientFromLineup(int index) {
    delete m_lineup[index];
    m_lineup[index] = nullptr;
    removeDynamicElement(m_lineup, index, m_lineupSize);
}

void PreTriage::load() {
    cout << "Loading data..." << endl;
    ifstream ifs(m_dataFilename);
    
    if (!ifs.is_open()) {
        cout << "No data or bad data file!" << endl;
    }
    else {
        ifs >> m_averCovidWait;
        ifs.ignore();
        ifs >> m_averTriageWait;
        ifs.ignore();
        for (int i=0; i<maxNoOfPatients; i++) {
            if (ifs.eof()) {
                break;
            }
            
            char type = 'X';
            ifs >> type;
            Patient *p = nullptr;
            if (type == 'C') {
                p = new CovidPatient;
            }
            else if (type == 'T'){
                p = new TriagePatient;
            }
            else if (type == 'X') {
                break;
            }
            
            ifs.ignore();
            p->fileIO(true);
            ifs >> *p;
            p->fileIO(false);
            m_lineup[m_lineupSize] = p;

            m_lineupSize++;
        }
        
        if (m_lineupSize == 0) {
            cout << "No data or bad data file!" << endl;
        }
        else {
            if (!ifs.eof()) {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
                
            }
            cout << m_lineupSize << " Records imported..." << endl;
        }
    }
    if (m_lineupSize > maxNoOfPatients) {
        m_lineupSize = maxNoOfPatients;
    }
    cout << endl;
}

  
    
int PreTriage::indexOfFirstInLine(char type) const {
    int index = -1;
    for(int i=0; i<m_lineupSize; i++) {
        if (m_lineup[i] != nullptr) {
            if (m_lineup[i]->type() == type) {
                return i;
            }
        }
    }
    return index;
}

PreTriage::PreTriage(const char* dataFilename): m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
    m_averCovidWait = Time(15);
    m_averTriageWait = Time(5);
    m_dataFilename = new char[strlen(dataFilename)+1];
    strcpy(m_dataFilename, dataFilename);
    
    load();
}

PreTriage::~PreTriage() {
    ofstream ofs(m_dataFilename);
    
    cout << "Saving Average Wait Times," << endl;
    cout << "   COVID Test: " << m_averCovidWait << endl;
    cout << "   Triage: " << m_averTriageWait << endl;
    
    ofs << m_averCovidWait << "," << m_averTriageWait << endl;
    
    cout << "Saving m_lineup..." << endl;
    int rowNo = 0;
    for (int i=0; i<m_lineupSize; i++) {
        if (m_lineup[i] != nullptr) {
            m_lineup[i]->fileIO(true);
            ofs << *m_lineup[i] << endl;
            rowNo++;
            cout << rowNo << "- " << *m_lineup[i] << endl;
            delete m_lineup[i];
        }
    }
    delete [] m_dataFilename;
    cout << "done!" << endl;
    
}

void PreTriage::run(void) {
    int selection;
    while (m_appMenu >> selection) {
        switch (selection) {
            case 0:
                return;
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
        }
    }
}

}
