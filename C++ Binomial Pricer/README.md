# Binomial Option Pricing Engine (C++)

A high-performance implementation of the **Cox-Ross-Rubinstein (CRR)** Binomial Model for pricing European and American options.

## 🚀 Overview
This project implements a lattice-based pricer that converges to the Black-Scholes-Merton model as the number of steps increases. Unlike Black-Scholes, this model allows for the valuation of **American Options** by solving the optimal stopping problem at each node of the tree.

### Key Features
- **Memory Optimized**: Uses an $O(N)$ space complexity implementation by utilizing a single state vector instead of a full $N \times N$ matrix.
- **American Exercise Logic**: Implements backward induction to account for early exercise premiums.

## 📈 Mathematical Context
The model discretizes the continuous-time Brownian motion into $N$ steps. 
- **Up factor ($u$):** $e^{\sigma\sqrt{\Delta t}}$
- **Down factor ($d$):** $e^{-\sigma\sqrt{\Delta t}}$
- **Risk-neutral probability ($p$):** $\frac{e^{r\Delta t} - d}{u - d}$
