# Forward Pricing & Basis Risk Analyzer

A C++ implementation for pricing forward contracts and simulating hedging performance under **Basis Risk** conditions.

## 📌 Project Overview
This tool implements the **Cost of Carry** model to determine the theoretical fair value of forward contracts. It further simulates a **Short Hedge** strategy to demonstrate basis fluctuations.

### Mathematical Framework
The forward price $F$ is derived using the continuous compounding formula:
$$F = S_0 e^{cT}$$
Where:
- $S_0$: Current spot price.
- $c$: Net cost of carry ($r + \text{storage} - \text{convenience yield}$).
- $T$: Time to maturity.

The project focuses on the **Basis** ($\text{Basis} = S_t - F_t$), and analysis of the **Net P&L**.
