#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "studentas.h"
#include <string>
#include <vector>

TEST_CASE("Studentas class default constructor test") {
    Studentas studentas;

    CHECK(studentas.vardas() == "");
    CHECK(studentas.pavarde() == "");
    CHECK(studentas.n() == 0);
    CHECK(studentas.nd().empty());
    CHECK(studentas.egz() == 0);
    CHECK(studentas.vid() == 0);
    CHECK(studentas.mediana() == 0);
}

TEST_CASE("Studentas class param constructor test") {
    std::string vardas = "vardas";
    std::string pavarde = "pavarde";
    int n = 10;
    std::vector<int> nd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int egz = 8;
    Studentas studentas(vardas, pavarde, n, nd, egz);
    studentas.calcSetMediana();
    studentas.calcSetVid();

    CHECK(studentas.vardas() == "vardas");
    CHECK(studentas.pavarde() == "pavarde");
    CHECK(studentas.n() == 10);
    CHECK(studentas.egz() == 8);
    CHECK(studentas.vid() == 5.5);
    CHECK(studentas.mediana() == 5.5);
}

TEST_CASE("Studentas copy constructor test") {
    std::string vardas = "vardas";
    std::string pavarde = "pavarde";
    int n = 10;
    std::vector<int> nd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int egz = 8;
    Studentas studentas(vardas, pavarde, n, nd, egz);
    studentas.calcSetMediana();
    studentas.calcSetVid();
    Studentas studentas2(studentas);

    CHECK(studentas2.vardas() == "vardas");
    CHECK(studentas2.pavarde() == "pavarde");
    CHECK(studentas2.n() == 10);
    CHECK(studentas2.egz() == 8);
    CHECK(studentas2.vid() == 5.5);
    CHECK(studentas2.mediana() == 5.5);
}

TEST_CASE("Studentas copy operator test") {
    std::string vardas = "vardas";
    std::string pavarde = "pavarde";
    int n = 10;
    std::vector<int> nd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int egz = 8;
    Studentas studentas(vardas, pavarde, n, nd, egz);
    studentas.calcSetMediana();
    studentas.calcSetVid();
    Studentas studentas2;
    studentas2 = studentas;

    CHECK(studentas2.vardas() == "vardas");
    CHECK(studentas2.pavarde() == "pavarde");
    CHECK(studentas2.n() == 10);
    CHECK(studentas2.egz() == 8);
    CHECK(studentas2.vid() == 5.5);
    CHECK(studentas2.mediana() == 5.5);
}

TEST_CASE("Studentas move constructor test") {
    std::string vardas = "vardas";
    std::string pavarde = "pavarde";
    int n = 10;
    std::vector<int> nd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int egz = 8;
    Studentas studentas(vardas, pavarde, n, nd, egz);
    studentas.calcSetMediana();
    studentas.calcSetVid();
    Studentas studentas2(std::move(studentas));

    CHECK(studentas2.vardas() == "vardas");
    CHECK(studentas2.pavarde() == "pavarde");
    CHECK(studentas2.n() == 10);
    CHECK(studentas2.egz() == 8);
    CHECK(studentas2.vid() == 5.5);
    CHECK(studentas2.mediana() == 5.5);

    CHECK(studentas.vardas() == "");
    CHECK(studentas.pavarde() == "");
    CHECK(studentas.n() == 0);
    CHECK(studentas.nd().empty());
    CHECK(studentas.egz() == 0);
    CHECK(studentas.vid() == 0);
    CHECK(studentas.mediana() == 0);
}

TEST_CASE("Studentas move operator test") {
    std::string vardas = "vardas";
    std::string pavarde = "pavarde";
    int n = 10;
    std::vector<int> nd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int egz = 8;
    Studentas studentas(vardas, pavarde, n, nd, egz);
    studentas.calcSetMediana();
    studentas.calcSetVid();
    Studentas studentas2;
    studentas2 = std::move(studentas);

    CHECK(studentas2.vardas() == "vardas");
    CHECK(studentas2.pavarde() == "pavarde");
    CHECK(studentas2.n() == 10);
    CHECK(studentas2.egz() == 8);
    CHECK(studentas2.vid() == 5.5);
    CHECK(studentas2.mediana() == 5.5);

    CHECK(studentas.vardas() == "");
    CHECK(studentas.pavarde() == "");
    CHECK(studentas.n() == 0);
    CHECK(studentas.nd().empty());
    CHECK(studentas.egz() == 0);
    CHECK(studentas.vid() == 0);
    CHECK(studentas.mediana() == 0);
}