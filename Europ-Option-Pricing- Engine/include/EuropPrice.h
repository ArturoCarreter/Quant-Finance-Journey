#ifndef EUROPRICE_H
#define EUROPRICE_H

#include <string>
#include <vector>

// Structure for the Greeks
struct Greeks {
    double delta, gamma, vega, theta;
};

class EuropPrice {
private:
    const double S0, K, r, sigma, T;
    const int steps;
    const std::string type;

    // Auxiliar functions
    double normal(double x) const;
    double n(double x) const;

public:
    EuropPrice(double S0, double K, double r, double sigma, double T, int steps, std::string type);

    double calculate() const; // Binomial model
    double BSM() const;       // Black-Scholes model
    Greeks calcBSMgreeks() const;
};

#endif