#pragma once

#include <iostream>
#include "studentas.h"
#include <iomanip>
#include <algorithm>
#include "vector_custom.h"

using namespace std;

void atvaizd(Vector<Studentas>& studentai, int rikiavimas);
bool rikiavimasVardu(Studentas& s1, Studentas& s2);
bool rikiavimasPavarde(Studentas& s1, Studentas& s2);
bool rikiavimasPaz(Studentas& s1, Studentas& s2);