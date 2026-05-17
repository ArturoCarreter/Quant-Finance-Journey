#include "EuropPrice.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#define PI std::acos(-1.0)

EuropPrice::EuropPrice(double S0, double K, double r, double sigma, double T, int steps, std::string type)
    : S0(S0), K(K), r(r), sigma(sigma), T(T), steps(steps), type(type) {
}
double EuropPrice::normal(double x) const { // We define some functions that will be of use later
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}
double EuropPrice::n(double x) const {
    return  std::exp(-0.5 * x * x) / std::sqrt(2.0 * PI);
}

double EuropPrice::calculate() const {
    // Calculate model parameters
    double dt = T / steps;
    double u = std::exp(sigma * std::sqrt(dt)); // Up factor
    double d = 1.0 / u;                         // Down factor (u*d = 1 for recombining tree)
    double a = std::exp(r * dt);                // Growth factor
    double p = (a - d) / (u - d);               // Risk-neutral probability
    double discount = std::exp(-r * dt);        // Discount factor per step

    // Initialize payoff vector at maturity (Step N)
    // We only need a single vector of size N+1 to save memory O(N) instead of O(N^2)
    std::vector<double> v(steps + 1);

    for (int i = 0; i <= steps; ++i) {
        // Price at node (steps, i) = S0 * u^(steps-i) * d^i
        double priceAtMaturity = S0 * std::pow(u, steps - i) * std::pow(d, i);
        if (type == "call") {
            v[i] = std::max(priceAtMaturity - K, 0.0);
        }
        else {
            v[i] = std::max(K - priceAtMaturity, 0.0);
        }
    }

    // Backward Induction
    for (int j = steps - 1; j >= 0; --j) {
        for (int i = 0; i <= j; ++i) {
            // Risk-neutral expectation discounted back one step
            v[i] = discount * (p * v[i] + (1.0 - p) * v[i + 1]);
            }
        }
    return v[0];
}

double EuropPrice::BSM() const {
    double d1 = (std::log(S0 / K) + (r + sigma * sigma / 2.0) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (type == "call") {
        return S0 * normal(d1) - K * std::exp(-r * T) * normal(d2);
    }
    else if (type == "put") {
        return -S0 * normal(-d1) + K * std::exp(-r * T) * normal(-d2);
    }
    else {
        std::cout << "Error: Type of option not recognised";
        return 0.0;
    }
}
Greeks EuropPrice::calcBSMgreeks() const { // Greeks for European call and put options
    Greeks g;
    double d1 = (std::log(S0 / K) + (r + sigma * sigma / 2) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    g.gamma = n(d1) / (S0 * sigma * std::sqrt(T));
    g.vega = S0 * n(d1) * std::sqrt(T);

    if (type == "call") {
        g.delta = normal(d1);
        double term1 = -(S0 * n(d1) * sigma) / (2.0 * std::sqrt(T));
        double term2 = -r * K * std::exp(-r * T) * normal(d2);
        g.theta = term1 + term2;
    }
    else if (type == "put") {
        g.delta = normal(d1) - 1.0;
        double term1 = -(S0 * n(d1) * sigma) / (2.0 * std::sqrt(T));
        double term2 = +r * K * std::exp(-r * T) * normal(-d2);
        g.theta = term1 + term2;

    }
    return g;
}

