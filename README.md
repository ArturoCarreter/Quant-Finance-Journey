# 📈 Quantitative Finance Journey: Physics to HFT

This repository documents my transition from **Theoretical Physics** to **Quantitative Finance**. Following an intensive roadmap, I am implementing financial models with a focus on **High-Performance Computing (HFT standards)**, stochastic calculus, and derivatives pricing.

**Academic Background:** Physics Degree (GPA: 9.53/10)  
**Core Tech Stack:** C++17 (STL, Memory Management), Python (NumPy, Pandas, Numba), Debian Linux, Git.

---

## 🚀 Roadmap & Progress

### 🏗️ Part 1: Quantitative Foundations (Python) - [COMPLETED]
* **Monte Carlo Engines:** Manual implementation of **Box-Muller Transform** and Geometric Brownian Motion (GBM).
* **Performance Optimization:** Large-scale simulations optimized with **Numba (@njit)**.
* **Risk & Strategies:** Backtesting of Moving Average strategies, handling look-ahead bias, and implementation of the **Kelly Criterion**.
* **Volatility Analysis:** Historical volatility estimation and real-world data cleaning.

### ⚙️ Part 2: High-Performance C++ for Quants - [IN PROGRESS]
* **Memory & Performance:** Mastery of references, pointers, and **pointer invalidation** (safe handling of `std::vector` reallocations).
* **STL & Data Structures:** Implementation of an efficient **Portfolio Valuation Engine** using `std::map` and C++17 **Structured Bindings**.
* **Derivative Pricing (OOP):** * *In Progress:* Analytical **Black-Scholes Engine** (Option class, Greeks/Delta calculation).
    * *Upcoming:* **Binomial Tree models** (Cox-Ross-Rubinstein) and Futures/Forwards pricing (Cost of Carry).
* **Tooling:** Compilation optimization using `g++ -O3 -march=native` and memory safety audits with **AddressSanitizers**.

### 🧪 Part 3: Advanced Stats & Portfolio Polishing - [UPCOMING]
* **Applied Statistics:** OLS Regression and R² analysis for factor models.
* **Production Readiness:** Unit testing for financial engines and CLI interface for the Black-Scholes pricer.
* **Interview Prep:** Stochastic calculus, probability puzzles (Bayes, combinatorics), and LeetCode-style C++ optimizations.

---

## 🛠️ Key Technical Highlights (C++)
* **Memory Safety:** Deep understanding of the Stack vs. Heap and avoiding dangling pointers during container resizing.
* **Efficient Lookups:** Using `std::map::find` to avoid mutative side effects during data reconciliation.
* **Modern C++:** Leveraging `auto`, structured bindings, and the `<cmath>` library for high-precision financial constants.

---

