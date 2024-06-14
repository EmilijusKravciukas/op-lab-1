#pragma once

#include <string>

/**
         * @brief Abstract class that Studentas is derived from
         */

class Zmogus {
    protected:
        std::string vardas_; ///< Name 
        std::string pavarde_; ///< Surname 
    public:
        /** 
        * @brief Default constructor for Zmogus class
        */
        Zmogus(const std::string& vardas, const std::string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

        Zmogus() = default;

        /** 
        * @brief Virtual destructor
        */
        virtual ~Zmogus() = default;

        /** 
        * @brief Getter for name
        */
        const std::string& vardas() const {
            return vardas_;
        }

        /** 
        * @brief Getter for surname
        */
        const std::string& pavarde() const {
            return pavarde_;
        }

        virtual void calcSetVid() = 0;
};