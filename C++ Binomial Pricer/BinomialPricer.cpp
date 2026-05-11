#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>

/**
 * Binomial Option Pricing Model (Cox-Ross-Rubinstein)
 * Efficient implementation using O(N) space complexity.
 */
class BinomCRR {
private:
    const double S0;       // Underlying asset price at t=0
    const double K;        // Strike price
    const double r;        // Risk-free interest rate (annualized)
    const double sigma;    // Volatility of the underlying asset
    const double T;        // Time to maturity (in years)
    const int steps;       // Number of time steps (N)
    const std::string type; // "call" or "put"

public:
    BinomCRR(double S0, double K, double r, double sigma, double T, int steps, std::string type)
        : S0(S0), K(K), r(r), sigma(sigma), T(T), steps(steps), type(type) {}

    /**
     * @param exerciseStyle "American" or "European"
     * @return Theoretical option price
     */
    double calculate(std::string exerciseStyle) const {
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
            } else {
                v[i] = std::max(K - priceAtMaturity, 0.0);
            }
        }

        // Backward Induction
        for (int j = steps - 1; j >= 0; --j) {
            for (int i = 0; i <= j; ++i) {
                // Risk-neutral expectation discounted back one step
                v[i] = discount * (p * v[i] + (1.0 - p) * v[i + 1]);

                // Check for early exercise (American Option logic)
                if (exerciseStyle == "American") {
                    double currentSpotPrice = S0 * std::pow(u, j - i) * std::pow(d, i);
                    double intrinsicValue = 0.0;
                    if (type == "call") {
                        intrinsicValue = std::max(currentSpotPrice - K, 0.0);
                    } else {
                        intrinsicValue = std::max(K - currentSpotPrice, 0.0);
                    }
                    // Optimal Stopping: Choose the max between continuation and immediate exercise
                    v[i] = std::max(v[i], intrinsicValue);
                }
            }
        }
        return v[0];
    }
};

int main() {
    // Market parameters example
    int N = 1000;
    BinomCRR call(100.0, 105.0, 0.03, 0.2, 1.0, N, "call");
    BinomCRR put(100.0, 105.0, 0.03, 0.2, 1.0, N, "put");

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "--- Binomial Option Pricing Engine (N = " << N << ") ---" << std::endl;
    std::cout << "European Call: $" << call.calculate("European") << std::endl;
    std::cout << "American Call: $" << call.calculate("American") << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "European Put:  $" << put.calculate("European") << std::endl;
    std::cout << "American Put:   $" << put.calculate("American") << std::endl;

    return 0;
}
