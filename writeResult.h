#pragma once

#include <vector>
#include <iostream>
#include "studentas.h"
#include <iomanip>
#include <algorithm>

using namespace std;

void atvaizd(vector<Studentas>& studentai, int rikiavimas);
bool rikiavimasVardu(Studentas& s1, Studentas& s2);
bool rikiavimasPavarde(Studentas& s1, Studentas& s2);
bool rikiavimasPaz(Studentas& s1, Studentas& s2);