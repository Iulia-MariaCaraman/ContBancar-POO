# ContBancar

A simple C++ project focused on Object-Oriented Programming (OOP) concepts, dynamic arrays, and enums by modeling a bank account system.

## About the project

The program defines a `ContBancar` class that manages bank account details like the account holder, current balance, deposit limit, account type (via enum), and a dynamically allocated history of transactions
### Key features:
- **Enum account types**: Supports `CURENT`, `ECONOMII`, and `INVESTITII`
- **Transaction filtering & validation**: Converts negative values to positive amounts, caps transactions at a set deposit limit, replaces null values with a default amount, and computes the initial balance
- **Statistics**: Method `nrTranzactiiDepasindMedia` counts how many transactions are strictly above the average transaction value
- **Dynamic memory management**: Handles deep allocation and cleanup using `new[]` and `delete[]` in the destructor to prevent leaks
- **External array processing**: Includes a standalone function (`stergerePrimaTranzactieMin`) that finds and deletes the first minimum value from a dynamic array by reallocating it

