#include <iostream>
#include <string>
#include <cmath> // para erf
#define PI std::acos(-1.0)

double normal(double x) { // We define some functions that will be of use later
	return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}
double n(double x) {
	return  std::exp(-0.5 * x * x) / std::sqrt(2.0 * PI);
}

struct Greeks {  // we make a structure with all our Greeks.
	double delta, gamma, vega, theta;
};

class Option { // Our class will give us the posibility to obtain the price/Greeks of our option
private: 
	const double K; // Strike price
	const double T;  // Time to maturity (in years)
	const double S0; // Underlying asset price
	const double r; // Risk-free interest rate
	const double sigma; // Volatility
	const std::string type; // call or put

public:

	Option(double K, double T, double S0, double r, double sigma, std::string type)
		: K(K), T(T), S0(S0), r(r), sigma(sigma), type(type) {
	}
	double price() const {
		double d1 = (std::log(S0 / K) + (r + sigma * sigma / 2.0) * T) / (sigma * std::sqrt(T));
		double d2 = d1 - sigma * std::sqrt(T);

		if(type == "call") {
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
	Greeks calcgreeks() const { // Greeks for European call and put options
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
};

int main(){ 
	Option miCall(105, 1, 100, 0.03, 0.2, "call");
	std::cout << "Price of the option: " << miCall.price() << std::endl;
	Greeks misGriegas = miCall.calcgreeks();
	std::cout << "Delta: " << misGriegas.delta << ", Gamma: " << misGriegas.gamma << std::endl;
	std::cout << "Vega: " << misGriegas.vega << ", Theta: " << misGriegas.theta << std::endl;
	return 0;
}