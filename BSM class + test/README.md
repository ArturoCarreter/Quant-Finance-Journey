# Black-Scholes Option Pricing Engine (Python Implementation)

A robust, object-oriented implementation of the **Black-Scholes-Merton (BSM)** model for pricing European options and calculating analytical Greeks. 

## 🚀 Overview

This repository contains a Jupyter Notebook that implements the BSM model using Python classes. The goal is to provide an encapsulated tool for option pricing, risk management (Greeks), and mathematical validation through unit testing.

### Key Features:
- **Object-Oriented Design**: Encapsulates market parameters (S, K, T, r, sigma) within a `BlackScholesModel` class for better state management.
- **Analytical Greeks**: High-precision calculation of Delta, Gamma, Vega (1%), Theta (Daily), and Rho (1%).
- **Mathematical Validation**: Built-in unit tests to verify the **Put-Call Parity** ($C - P = S - K e^{-rt}$), ensuring no-arbitrage consistency.
- **Visualization**: Interactive plots using `matplotlib` to visualize the "Hockey Stick" payoff and the convergence of price towards intrinsic value as time to maturity ($T$) decreases.
