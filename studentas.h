#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include "zmogus.h"

/**
 * @brief Class that represents Studentas
 */

class Studentas : public Zmogus {
    private:
        int n_; ///< Homework grades count
        std::vector<int> nd_; ///< Homework grades
        int egz_; ///< Exam grade
        double vid_; ///< Homework grades average
        double mediana_; ///< Homework grades mediana
        
    public:
        /**
         * @brief << operator overload
         */
        friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
            os << std::endl << std::left << std::setw(20) << studentas.vardas_ << std::left << std::setw(20) << studentas.pavarde_ << std::fixed
            << std::setprecision(2) << std::left << std::setw(20) << (studentas.vid_ * 0.4 + double(studentas.egz_) * 0.6);
            
            return os;
        }

        /**
         * @brief >> operator overload
         */
        friend std::istream& operator>>(std::istream& is, Studentas& studentas) {
            studentas.readStudent(is);

            return is;
        }

        /**
         * @brief istream constructor
         */
        Studentas(std::istream& is) {
            readStudent(is);
        }

        /**
         * @brief Parametrized constructor
         */
        Studentas(const std::string& vardas, const std::string& pavarde, int n, const std::vector<int>& nd, int egz)
        : Zmogus(vardas, pavarde), n_(n), nd_(nd), egz_(egz), vid_(0), mediana_(0) {
            this->vardas_ = vardas;
            this->pavarde_ = pavarde;

            calcSetVid();
            calcSetMediana();
        }

        /**
         * @brief Default constructor
         */
        Studentas() : Zmogus("", ""), n_(0), egz_(0), vid_(0), mediana_(0) {}

        /**
         * @brief Default destructor
         */
        ~Studentas() = default;

        /**
         * @brief Copy constructor
         */
        Studentas(const Studentas& other)
        : Zmogus(other), n_(other.n_), nd_(other.nd_), egz_(other.egz_),
        vid_(other.vid_), mediana_(other.mediana_) {}

        /**
         * @brief Copy assignment with = operator
         */
        Studentas& operator=(const Studentas& other) {
            if (this != &other) {
                vardas_ = other.vardas_;
                pavarde_ = other.pavarde_;
                n_ = other.n_;
                nd_ = other.nd_;
                egz_ = other.egz_;
                vid_ = other.vid_;
                mediana_ = other.mediana_;
            }
            return *this;
        }

        /**
         * @brief Move constructor
         */
        Studentas(Studentas&& other) noexcept
            : Zmogus(std::move(other)), n_(other.n_), nd_(std::move(other.nd_)), egz_(other.egz_),
            vid_(other.vid_), mediana_(other.mediana_) {
            vardas_ = std::move(other.vardas_);
            pavarde_ = std::move(other.pavarde_);
            
            other.n_ = 0;
            other.egz_ = 0;
            other.vid_ = 0;
            other.mediana_ = 0;
        }

        /**
         * @brief Move assignment with = operator
         */
        Studentas& operator=(Studentas&& other) noexcept {
            if (this != &other) {
                vardas_ = std::move(other.vardas_);
                pavarde_ = std::move(other.pavarde_);
                n_ = other.n_;
                nd_ = std::move(other.nd_);
                egz_ = other.egz_;
                vid_ = other.vid_;
                mediana_ = other.mediana_;

                other.n_ = 0;
                other.egz_ = 0;
                other.vid_ = 0;
                other.mediana_ = 0;
            }
            return *this;
        }

         inline std::string vardas() const { return vardas_; } ///< Getter for name.
         inline std::string pavarde() const { return pavarde_; } ///< Getter for surname.
         inline int egz() const { return egz_; } ///< Getter for exam grade.
         inline double vid() const { return vid_; } ///< Getter for grade average.
         inline double mediana() const { return mediana_; } ///< Getter for grade mediana.
         inline int n() const { return n_; } ///< Getter for homework grade count.
         inline const std::vector<int>& nd() const { return nd_; } ///< Getter for homework grades.
        
        /**
         * @brief Assigns values to Studentas object from istream
         */
        std::istream& readStudent(std::istream& is) {
            n_ = 0;
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

        /**
         * @brief Calculates and sets the average grade
         */
        void calcSetVid() override {
            vid_ = 0;
            for(int i = 0; i < n_; i++) {
                vid_ += nd_[i];
            }
            vid_ /= n_;
        }

        /**
         * @brief Calculates and sets the mediana
         */
        void calcSetMediana() {
            std::sort(nd_.begin(), nd_.end());

            if(n_ % 2 == 0) {
                mediana_ = double(nd_[n_/2 - 1] + nd_[n_/2]) / 2;
            } else {
                mediana_ = nd_[n_/2];
            }
        }
};

