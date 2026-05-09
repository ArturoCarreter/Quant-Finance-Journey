#include <iostream>
#include <string>
#include <map>

/**
 * Portfolio Management with STL Maps
 * 1. A Portfolio (Asset -> Quantity)
 * 2. Market Data (Asset -> Price)
 */

int main() {
    // Portfolio map: Ticker -> Units held
    std::map<std::string, double> portfolio = {
        {"AAPL", 10.0},
        {"TSLA", 20.0},
        {"NVDA", 5.0}
    };

    // Market Prices map: Ticker -> Current Price
    std::map<std::string, double> market_prices = {
        {"AAPL", 100.0},
        {"NVDA", 190.0}
        // TSLA price is missing on purpose to test our error handling logic
    };

    double total_value = 0.0;

    std::cout << "--- Portfolio Valuation Report ---" << std::endl;

    // We use C++17 Structured Bindings for clean iteration
    for (const auto& [ticker, amount] : portfolio) {

        // If we used market_prices[ticker] and it did not exist, it would create a new entry with value 0.0
        auto it = market_prices.find(ticker);  // We search for our asset in price feed

        if (it != market_prices.end()) {
            // Price found in our market data source
            double price = it->second;
            double position_value = amount * price;
            total_value += position_value;

            std::cout << "Ticker: " << ticker << " | Units: " << amount
                << " | Price: $" << price << " | Value: $" << position_value << std::endl;
        }
        else {
            // Asset found in portfolio but missing in price feed
            std::cout << "Warning: No price found for " << ticker << ". Please enter price manually: ";
            double manual_price;
            std::cin >> manual_price;
            market_prices[ticker] = manual_price; //we include the missing price in the map 
            double position_value = (manual_price * amount);
            total_value += position_value;
            std::cout << "Ticker: " << ticker << " | Units: " << amount
                << " | Price: $" << manual_price << " | Value: $" << position_value << std::endl;
        }
    }

    std::cout << "----------------------------------" << std::endl;
    std::cout << "Total Portfolio Value: $" << total_value << std::endl;

    return 0;
}