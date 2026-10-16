# Credit Risk Scorecard Simulator

A Python-based credit risk modelling project that demonstrates the complete development lifecycle of a simple Probability of Default (PD) scorecard using:

Weight of Evidence (WoE) transformations
Logistic Regression
Model discrimination metrics (Gini and KS)
Calibration tests (Binomial Test and Hosmer-Lemeshow)
Population Stability Index (PSI)

The project first illustrates the limitations of using purely random data and then introduces a more realistic synthetic portfolio where borrower characteristics influence default risk.

## Project Objectives

The purpose of this project is to demonstrate the key concepts behind credit scoring and model validation in a simplified environment.

## The workflow includes:

1. Synthetic portfolio generation
2. Data binning
3. Weight of Evidence (WoE) transformation
4. Logistic Regression model fitting
5. Probability of Default (PD) estimation
6. Model discrimination assessment
7. Calibration assessment
8. Population stability monitoring

## Initial Random Portfolio

The first version of the simulator generates a completely random population:

Age
Car value
Province

The target variable (default / non-default) is also generated randomly.

As there is no statistical relationship between the explanatory variables and the target, the model cannot learn any meaningful pattern.

## Improved Portfolio Simulation

To create a more realistic scenario, the target variable is generated using an underlying logistic function.

The following assumptions are introduced:

Younger borrowers have higher default risk.
Lower car values are associated with higher risk.
Provinces contribute differently to the risk profile.
Random noise is added to reflect real-world uncertainty.
