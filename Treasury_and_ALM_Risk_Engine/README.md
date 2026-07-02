# Treasury & ALM Risk Engine  
*A modular quantitative risk suite implementing core Treasury, Liquidity, Interest Rate, and ALM models used in banking and fintech.*

---

## 📘 Overview

This repository contains a complete **Treasury & ALM Risk Engine** built in Python and demonstrated through a Jupyter notebook.  
It implements several foundational risk models used in banking, asset–liability management, and regulatory reporting.

The project is designed as a **clean, modular, reproducible quant toolkit**, suitable for interviews, learning, and practical risk analytics.

---

## 🧩 Modules Included

### 1. Liquidity Stress Testing
- Daily cash‑flow gaps  
- Survival horizon  
- Liquidity Coverage Ratio (LCR) style logic  
- Funding shocks and stress scenarios  
- Multi‑bucket liquidity analysis  

### 2. Interest Rate Risk (IRRBB)
- Present Value (PV) engine  
- Macaulay & Modified Duration  
- DV01 computation  
- Parallel and non‑parallel yield curve shocks  
- Sensitivity analysis  

### 3. Multi‑Currency ALM Simulator
- Balance sheet modelling (assets & liabilities)  
- Multi‑entity and multi‑currency support  
- Behavioral assumptions  

### 4. Monte Carlo VaR99 + Basel Backtesting
- Monte Carlo engine using vectorized NumPy  
- VaR99 and Expected Shortfall  
- Basel traffic‑light backtesting  
- P&L distribution diagnostics  

---

## 📁 Repository Structure

