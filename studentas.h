#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

class Studentas {
    private:
        std::string vardas_;
        std::string pavarde_;
        int n_ = 0;
        std::vector<int> nd_;
        int egz_;
        double vid_ = 0;
        double mediana_ = 0;

    public:
        Studentas() : egz_(0) {}
        Studentas(std::istream& is) {
            readStudent(is);
        }
        ~Studentas() {};
        inline std::string vardas() const { return vardas_; }
        inline std::string pavarde() const { return pavarde_; }
        inline int egz() const { return egz_; }
        inline double vid() const { return vid_; }
        inline double mediana() const { return mediana_; }

        std::istream& readStudent(std::istream& is) {
            is >> vardas_ >> pavarde_;
            int num;
            while(is >> num){
                n_++;
                nd_.push_back(num);
            }
            n_--;
            egz_ = nd_.back();
            nd_.pop_back();
            calcSetVid();
            calcSetMediana();

            return is;
        }

        void calcSetVid() {
            for(int i = 0; i < n_; i++) {
                vid_ += nd_[i];
            }
            vid_ /= n_;
        }

        void calcSetMediana() {
            std::sort(nd_.begin(), nd_.end());

            if(n_ % 2 == 0) {
                mediana_ = double(nd_[n_/2 - 1] + nd_[n_/2]) / 2;
            } else {
                mediana_ = nd_[n_/2];
            }
        }
};

