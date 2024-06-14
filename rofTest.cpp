#include "rofTest.h"

void runTests() {
    std::cout << "constructorTest status: " << constructorTest() << std::endl;
    std::cout << "paramConstructorTest status: " << paramConstructorTest() << std::endl;
    std::cout << "copyConstructorTest status: " << copyConstructorTest() << std::endl;
    std::cout << "copyOperatorTest status: " << copyOperatorTest() << std::endl;
    std::cout << "moveConstructorTest status: " << moveConstructorTest() << std::endl;
    std::cout << "moveOperatorTest status: " << moveOperatorTest() << std::endl;
    std::cout << "destructorTest status: " << destructorTest() << std::endl;
}
std::string constructorTest() {
    std::stringstream ss("Vardas Pavarde 1 2 3 4 5 10");
    Studentas s(ss);

    if(s.vardas() != "Vardas") {
        return "Vardas failure";
    } else if(s.pavarde() != "Pavarde") {
        return "Pavarde failure";
    } else if(s.vid() != 3) {
        return "Vid failure";
    } else if(s.mediana() != 3) {
        return "Mediana failure";
    } else {
        return "success";
    }
}
std::string paramConstructorTest() {
    std::vector<int> nd = {1, 2, 3, 4, 5};
    Studentas s("Vardas", "Pavarde", 5, nd, 10);

    if(s.vardas() != "Vardas") {
        return "Vardas failure";
    } else if(s.pavarde() != "Pavarde") {
        return "Pavarde failure";
    } else if(s.vid() != 3.0) {
        return "Vid failure";
    } else if(s.mediana() != 3.0) {
        return "Mediana failure";
    } else {
        return "success";
    }
}
std::string destructorTest() {
    Studentas *sPtr = new Studentas;

    sPtr->~Studentas();
    try {
        //sPtr->vardas();

    } catch(const std::bad_alloc& e){
        return "success";
    }

    return "failure";
}
std::string copyConstructorTest() {
    std::vector<int> nd = {1, 2, 3, 4, 5};
    Studentas s1("Vardas", "Pavarde", 5, nd, 10);

    Studentas s(s1);

    if(s.vardas() != "Vardas") {
        return "Vardas failure";
    } else if(s.pavarde() != "Pavarde") {
        return "Pavarde failure";
    } else if(s.vid() != 3) {
        return "Vid failure";
    } else if(s.mediana() != 3) {
        return "Mediana failure";
    } else {
        return "success";
    }
}
std::string copyOperatorTest() {
    std::vector<int> nd = {1, 2, 3, 4, 5};
    Studentas s1("Vardas", "Pavarde", 5, nd, 10);

    Studentas s;
    s = s1;

    if(s.vardas() != "Vardas") {
        return "Vardas failure";
    } else if(s.pavarde() != "Pavarde") {
        return "Pavarde failure";
    } else if(s.vid() != 3) {
        return "Vid failure";
    } else if(s.mediana() != 3) {
        return "Mediana failure";
    } else {
        return "success";
    }
}
std::string moveConstructorTest() {
    std::vector<int> nd = {1, 2, 3, 4, 5};
    Studentas s1("Vardas", "Pavarde", 5, nd, 10);

    Studentas s(std::move(s1));

    if(s.vardas() != "Vardas") {
        return "Vardas failure";
    } else if(s.pavarde() != "Pavarde") {
        return "Pavarde failure";
    } else if(s.vid() != 3) {
        return "Vid failure";
    } else if(s.mediana() != 3) {
        return "Mediana failure";
    } else if(s1.vardas() != "") {
        return "Vardas failure";
    } else if(s1.pavarde() != "") {
        return "Pavarde failure";
    } else if(s1.vid() != 0) {
        return "Vid failure";
    } else if(s1.mediana() != 0) {
        return "Mediana failure";
    } else {
        return "success";
    }
}
std::string moveOperatorTest() {
    std::vector<int> nd = {1, 2, 3, 4, 5};
    Studentas s1("Vardas", "Pavarde", 5, nd, 10);

    Studentas s;
    s = std::move(s1);

    if(s.vardas() != "Vardas") {
        return "Vardas failure";
    } else if(s.pavarde() != "Pavarde") {
        return "Pavarde failure";
    } else if(s.vid() != 3) {
        return "Vid failure";
    } else if(s.mediana() != 3) {
        return "Mediana failure";
    } else if(s1.vardas() != "") {
        return "Vardas failure";
    } else if(s1.pavarde() != "") {
        return "Pavarde failure";
    } else if(s1.vid() != 0) {
        return "Vid failure";
    } else if(s1.mediana() != 0) {
        return "Mediana failure";
    } else {
        return "success";
    }
}