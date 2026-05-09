# C++ Portfolio Valuation Engine

A high-performance tool implemented in C++17 to manage asset portfolios and perform real-time valuations by cross-referencing market data feeds.

## 🚀 Overview
This project addresses a common challenge in quantitative finance: reconciling a private portfolio with external market data. It implements a robust "lookup and cache" logic to ensure every asset in the portfolio is valued, even when initial market data is incomplete.

## 🛠️ Technical Features
- **STL Maps**: Uses `std::map` for logarithmic search complexity ($O(\log n)$), ensuring the system remains efficient as the number of assets grows.
- **C++17 Structured Bindings**: Implements modern syntax for clean and readable container iteration.
- **Data Integrity**: Uses `.find()` instead of `operator[]` for initial lookups to prevent accidental mutation of market data (avoiding "default insertion" side effects).
- **Lazy Loading / Cache Filling**: Automatically updates the market data map when missing prices are provided by the user, optimizing future lookups.

## 📈 Financial Logic
1. **Lookup**: Iterates through the portfolio tickers.
2. **Validation**: Checks if a valid market price exists.
3. **Manual Override**: If data is missing, the system prompts for manual input and updates the "source of truth" (the market map).
4. **Valuation**: Calculates position value and total portfolio AUM (Assets Under Management).

## 💻 How to run
Requires a C++17 compiler.
