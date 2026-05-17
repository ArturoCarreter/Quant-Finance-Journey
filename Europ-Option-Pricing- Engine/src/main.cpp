#include "EuropPrice.h" // Important: include your header file, not the .cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
#include <cmath>

// Function to run Quality Assurance (QA) and sanity tests before launching the CLI
void runSanityTests() {
    std::cout << "Running automated risk and model tests...\n";

    // Test 1: Known market case (Hull's Options, Futures, and Other Derivatives)
    // S=100, K=100, r=0.05, sigma=0.2, T=1 -> Call should be worth approx 10.4506
    EuropPrice hullCall(100.0, 100.0, 0.05, 0.2, 1.0, 1000, "call");
    assert(std::abs(hullCall.BSM() - 10.4506) < 0.001 && "Test 1 Failed: Call price does not match Hull's benchmark");

    // Test 2: Put-Call Parity validation (C - P = S0 - K * exp(-r * T))
    EuropPrice testCall(100.0, 95.0, 0.06, 0.25, 0.5, 500, "call");
    EuropPrice testPut(100.0, 95.0, 0.06, 0.25, 0.5, 500, "put");
    double parity = testCall.BSM() - testPut.BSM();
    double expected = 100.0 - 95.0 * std::exp(-0.06 * 0.5);
    assert(std::abs(parity - expected) < 0.0001 && "Test 2 Failed: Put-Call Parity violation detected");

    std::cout << "All tests passed successfully! [Model Risk: CLEAR] ✅\n\n";
}

int main() {
    // 1. Run sanity tests first to guarantee engine integrity
    runSanityTests();

    // 2. Command Line Interface (CLI) for user inputs
    double S, K, r, sigma, T;
    int steps;
    std::string type;

    std::cout << "=========================================\n";
    std::cout << "   WELLS QUANT ENGINE v1.0 - BLACK-SCHOLES & CRR\n";
    std::cout << "=========================================\n";

    std::cout << "Option Type (call/put): ";
    std::cin >> type;

    // Convert input to lowercase to handle "CALL", "Put", etc. smoothly
    for (char& c : type) c = std::tolower(c);

    std::cout << "Spot Price (S0):        "; std::cin >> S;
    std::cout << "Strike Price (K):       "; std::cin >> K;
    std::cout << "Risk-free Rate (r):     "; std::cin >> r;
    std::cout << "Volatility (sigma):     "; std::cin >> sigma;
    std::cout << "Time to Maturity (T):   "; std::cin >> T;
    std::cout << "Binomial Steps (N):     "; std::cin >> steps;

    // 3. Instantiate the pricing object with user parameters
    EuropPrice option(S, K, r, sigma, T, steps, type);
    Greeks g = option.calcBSMgreeks();

    // 4. Output the performance and risk reporting metrics
    std::cout << "\n=========================================\n";
    std::cout << "            PRICING REPORT               \n";
    std::cout << "=========================================\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Continuous Price (BSM):   $" << option.BSM() << "\n";
    std::cout << "Discrete Price (Binomial): $" << option.calculate() << "\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "               THE GREEKS                \n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Delta: " << g.delta << "  (Underlying price sensitivity)\n";
    std::cout << "Gamma: " << g.gamma << "  (Delta acceleration / convexity)\n";
    std::cout << "Vega:  " << g.vega << "  (Volatility sensitivity)\n";
    std::cout << "Theta: " << g.theta << "  (Daily time decay)\n";
    std::cout << "=========================================\n";

    return 0;
}