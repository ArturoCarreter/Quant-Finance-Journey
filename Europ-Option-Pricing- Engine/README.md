# Multi-Model European Option Pricer (Black-Scholes & CRR Binomial Tree)

A high-performance, production-grade C++ quantitative pricing engine that computes the theoretical fair value and risk metrics (The Greeks) for European options. This project implements and compares two distinct paradigms: the analytical **Black-Scholes-Merton (BSM)** model and a memory-optimized **Cox-Ross-Rubinstein (CRR) Binomial Tree** numerical method.

## 🌟 Key Features

* **Multi-Model Implementation**: Seamlessly switches between continuous-time analytical solutions (BSM) and discrete-time numerical lattices (CRR).
* **Memory-Optimized Lattice**: The Binomial Tree uses an $O(N)$ space complexity optimization rather than the naive $O(N^2)$ matrix allocation, reusing a single vector across backward induction steps.
* **Exact Analytical Greeks**: Computes first-order and second-order risk sensitivities: Delta ($\Delta$), Gamma ($\Gamma$), Vega ($\mathcal{V}$), and Theta ($\Theta$).
* **Automated QA & Model Risk Controls**: Embedded compile-time and runtime sanity checks utilizing `assert` mechanics to validate market models against academic benchmarks (e.g., Hull) and fundamental financial theorems (Put-Call Parity).
* **Interactive CLI Interface**: User-friendly command-line utility for real-time portfolio pricing simulations.

---

## 📊 Mathematical Foundation

### 1. Black-Scholes-Merton (Analytical)
The continuous price for a vanilla European call option is governed by:

$$C = S_0 N(d_1) - K e^{-rT} N(d_2)$$

Where the probability factors $d_1$ and $d_2$ are defined as:

$$d_1 = \frac{\ln(S_0 / K) + \left(r + \frac{\sigma^2}{2}\right)T}{\sigma \sqrt{T}}$$

$$d_2 = d_1 - \sigma \sqrt{T}$$

### 2. Cox-Ross-Rubinstein Lattice (Numerical)
As the number of discrete steps $N \to \infty$, the binomial random walk converges weakly to the Geometric Brownian Motion (GBM) state variable. This implementation utilizes recombining nodes where the up ($u$) and down ($d$) multipliers satisfy the volatility matching condition:

$$u = e^{\sigma \sqrt{\Delta t}}, \quad d = \frac{1}{u} = e^{-\sigma \sqrt{\Delta t}}$$

---

## 📁 Project Structure

```text
├── include/
│   └── EuropPrice.h       # Class declarations, structs, and interfaces
├── src/
    ├── EuropPrice.cpp     # Analytical/Numerical engines and mathematical implementations
    └── main.cpp           # Automated automated QA suite and interactive CLI loop

