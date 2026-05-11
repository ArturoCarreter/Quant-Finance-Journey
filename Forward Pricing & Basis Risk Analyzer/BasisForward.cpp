#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

/**
 * Forward Pricing & Hedging Simulator
 * Based on the No-Arbitrage Principle and the Cost of Carry Model.
 */
class Forward {
private:
    double r;  // Risk-free interest rate (continuous compounding)
    double S0; // Spot price of the asset at t=0
    double c;  // Net Cost of Carry (r + storage_costs - convenience_yield)
    double T;  // Time to maturity in years

public:
    Forward(double r, double S0, double c, double T)
        : r(r), S0(S0), c(c), T(T) {
    }

    /**
     * Calculates the fair value of the forward contract.
     * Formula: F = S0 * exp(c * T)
     */
    double theoreticalForwardPrice() const {
        return S0 * std::exp(c * T);
    }

    /**
     * The Basis represents the difference between the Spot and the Future price.
     * In a perfect market at maturity (t=T), the basis should converge to 0.
     */
    double basis(double St, double Ft) const {
        return St - Ft;
    }

    /**
     * Simulates a Short Hedge strategy.
     * We own the physical asset (Long Spot) and sell the forward (Short Hedge).
     */
    void Hedge(double St, double Ft) const {
        double F0 = theoreticalForwardPrice();
        double inibasis = basis(S0, F0);
        double tbasis = basis(St, Ft);

        // P&L Decomposition
        double pnlSpot = St - S0;     // Gains/Losses from the physical asset
        double pnlHedge = F0 - Ft;    // Gains/Losses from the short forward position
        double netPnL = pnlSpot + pnlHedge;

        std::cout << "--- Hedge Simulation Results ---\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "P&L from Spot Asset (" << T << "y):  $" << pnlSpot << "\n";
        std::cout << "P&L from Short Hedge:       $" << pnlHedge << "\n";
        std::cout << "--------------------------------\n";
        std::cout << "TOTAL NET P&L:              $" << netPnL << "\n";
        std::cout << "--------------------------------\n";
        std::cout << "Initial Basis (t=0):       " << inibasis << "\n";
        std::cout << "Final Basis (t=T):         " << tbasis << "\n";

    }
};

int main() {
    // Scenario: Gold forward contract
    // Gold often has storage costs (u), making c = r + u
    double spot_today = 2000.0;
    double risk_free = 0.05;
    double storage_cost = 0.01;
    double cost_of_carry = risk_free + storage_cost;
    double maturity = 1.0;

    Forward goldForward(risk_free, spot_today, cost_of_carry, maturity);

    std::cout << "Initial Analysis:\n";
    std::cout << "Spot Price: $" << spot_today << "\n";
    std::cout << "Theoretical Forward Price: $" << goldForward.theoreticalForwardPrice() << std::endl;

    // Simulation: At maturity, we observe the market prices St and Ft
    // If the basis is not zero, the hedge was imperfect.
    goldForward.Hedge(2100.0, 2105.0);

    return 0;
}
