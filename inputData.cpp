#include "inputData.h"

void ivestis() {
    vector<Studentas> studentai;

    int cInput = 0;
    while(cInput != 5) {
        std::cout<< "Pasirinkite įvedimo būdą:" << std::endl
            << "(1) Duomenų įvedimas ranka" << std::endl
            << "(2) Generuoti pažymius" << std::endl
            << "(3) Generuoti vardą, pavardę ir pažymius" << std::endl
            << "(4) Atvaizduoti duomenis" << std::endl
            << "(5) Baigti darbą" << std::endl;

        cInput = intIvestis(1, 5);

        if(cInput == 1) {
            bool ndLoop = true;
            string line;

            std::cout << "Įveskite studento vardą: ";
            line += stringIvestis() + " ";
            std::cout << "Įveskite studento pavardę: ";
            line += stringIvestis() + " ";
            std::cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";
            while(ndLoop) {
                int temp = intIvestis(0, 10);
                if(temp != 0) {
                    line += to_string(temp) + " ";
                } else {
                    std::cout << "Įveskite studento egzamino pažymį: ";
                    temp = intIvestis(1, 10);
                    line += to_string(temp);

                    stringstream ss(line);
                    Studentas studentas(ss);
                    studentai.push_back(studentas);
                    ndLoop = false;
                }
            }
        } else if(cInput == 2) {
            string line;

            std::cout << "Įveskite studento vardą: ";
            line += stringIvestis() + " ";
            std::cout << "Įveskite studento pavardę: ";
            line += stringIvestis() + " ";

            for(int i = 0; i < randGen(1, 10); i++) {
                line += to_string(randGen(1, 10));
            }
            line += to_string(randGen(1, 10));

            stringstream ss(line);
            Studentas studentas(ss);
            studentai.push_back(studentas);
        } else if(cInput == 3) {
            string line;

            vector<std::string> vardai = {"Rokas", "Karolis", "Nojus", "Edgaras", "Martynas", "Gytis", "Justas"};
            vector<std::string> pavardes = {"Kazlauskas", "Stankevicius", "Petrauskas", "Jankauskas", "Zukauskas", "Butkus", "Balciunas"};

            line += vardai[randGen(0, 6)];
            line += pavardes[randGen(0, 6)];

            for(int i = 0; i < randGen(1, 10); i++) {
                line += to_string(randGen(1, 10));
            }
            line += to_string(randGen(1, 10));

            stringstream ss(line);
            Studentas studentas(ss);
            studentai.push_back(studentas);
        } else if(cInput == 4) {
            std::cout<<"Pasirinkite rikiavimo būdą: " << std::endl
                <<"(1) Pagal studento vardą" << std::endl
                <<"(2) Pagal studento pavarde" << std::endl
                <<"(3) Pagal studento galutinį pažymį" << std::endl;

            int rikiavimoBudas = intIvestis(1, 3);

            std::cout<<"Pasirinkite atvaizdavimo buda: " << std::endl
                <<"(1) Komandineje eiluteje" << std::endl
                <<"(2) Issaugoti i du failus (rikiavimas pagal pasiekimus)" << std::endl;

            int atvaizdBudas = intIvestis(1, 2);
            
            if(atvaizdBudas == 2) {
                studSort(studentai, rikiavimoBudas);
            } else {
                atvaizd(studentai, rikiavimoBudas);
            }
        }
    }
}