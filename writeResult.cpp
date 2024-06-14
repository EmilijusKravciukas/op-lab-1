#include "writeResult.h"

bool rikiavimasVardu(Studentas& s1, Studentas& s2){
    return s1.vardas() < s2.vardas();
}

bool rikiavimasPavarde(Studentas& s1, Studentas& s2){
    return s1.pavarde() < s2.pavarde();
}

bool rikiavimasPaz(Studentas& s1, Studentas& s2){
    return (s1.vid() * 0.4 + double(s1.egz() * 0.6)) > (s2.vid() * 0.4 + double(s2.egz() * 0.6));
}

void atvaizd(Vector<Studentas>& studentai, int rikiavimas){
    if(rikiavimas == 1){
        sort(studentai.begin(), studentai.end(), rikiavimasVardu);
    } else if(rikiavimas == 2){
        sort(studentai.begin(), studentai.end(), rikiavimasPavarde);
    } else if(rikiavimas == 3){
        sort(studentai.begin(), studentai.end(), rikiavimasPaz);
    }

    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė" << left << setw(20) << "Galutinis (Vid.)" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << setprecision(2) << fixed;
    for(int i = 0; i < studentai.size(); i++){
        cout << studentai[i];
    }
}