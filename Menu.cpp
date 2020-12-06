
/*Final Project Milestone FP
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Jeunghak Ham
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {

Menu::Menu(const char* text, int NoOfSelections) {
    m_text = new char[strlen(text)+1];
    strcpy(m_text, text);
    m_noOfSel = NoOfSelections;
}

Menu::~Menu() {
    delete [] m_text;
}

ostream& Menu::display(ostream& ostr) const {
    ostr << m_text << endl;
    ostr << "0- Exit" << endl;
    ostr << "> ";
    return ostr;
}

int& Menu::operator>>(int& Selection) {
    display();
    bool validate = true;
    do {
        validate = true;
        cin >> Selection;
        if (cin.fail()) {
            cin.clear();
            cout << "Bad integer value, try again: ";
            cin.ignore(2000, '\n');
            validate = false;
        }
        else if (Selection < 0 || Selection > m_noOfSel) {
            cout << "Invalid value entered, retry[0 <= value <= ";
            cout << m_noOfSel << "]: ";
            validate = false;
        }
    } while(!validate);
    return Selection;
}


}
