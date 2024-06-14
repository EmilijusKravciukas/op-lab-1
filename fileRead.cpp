#include "fileRead.h"

void duomSkait(){
    Vector<Studentas> studentai;

    try{
        string command = "dir *.txt 2>" "NUL";

        int directoryCheck = system(command.c_str());

        if(directoryCheck != 0){
            throw runtime_error("Nerasta duomenu failu");
        }

        cout<<"Pasirinkite duomenų failą: ";

    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }

    string duomPav = fileIvestis();

    try{
        auto tStart = chrono::steady_clock::now();

        ifstream DF(duomPav);
        string line;

        if(!DF.is_open()){
            throw runtime_error("Nepavyko atidaryti failo");
        }

        string tempString;

        getline(DF, line);

        if(DF.fail()){
            throw runtime_error("Nepavyko nuskaityti duomenis");
        }

        while(getline(DF, line)){
            stringstream ss(line);
            Studentas studentas(ss);
            studentai.push_back(studentas);
        }

        auto tEnd = chrono::steady_clock::now();
        auto tDuration = chrono::duration_cast<chrono::milliseconds>(tEnd - tStart);

        cout << "Failo skaitymas uztruko: " << double(tDuration.count())/1000 << " sekundziu" << endl;

        cout<<"Pasirinkite rikiavimo būdą: " << endl
            <<"(1) Pagal studento vardą" << endl
            <<"(2) Pagal studento pavarde" << endl
            <<"(3) Pagal studento galutinį pažymį" << endl;

        int rikiavimoBudas = intIvestis(1, 3);

        cout<<"Pasirinkite atvaizdavimo buda: " << endl
            <<"(1) Komandineje eiluteje" << endl
            <<"(2) Issaugoti i du failus (rikiavimas pagal pasiekimus)" << endl;

        int cInput = intIvestis(1, 2);

        if(cInput == 1){
            atvaizd(studentai, rikiavimoBudas);
        } else {
            studSort(studentai, rikiavimoBudas);
        }
    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }
}