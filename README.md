# Goldbach's Conjecture — C Implementation

## Authors
da1dotsh, shiradrock

## Abstract
This project presents a C language implementation inspired by **Goldbach's Conjecture**, which states that **every even number greater than 2 can be expressed as the sum of two prime numbers**.

The goal is didactic: to introduce students to the fundamental concepts of C programming while exploring a classic and open problem in number theory.

---

## Mathematical Background
Goldbach's Conjecture can be formally expressed: for every even natural number $n$ such that $n > 2$, there exist two prime numbers $p$ and $q$ that satisfy $n = p + q$.

* $N$ = set of natural numbers
* $P$ = set of prime numbers

Although it has not been proven in general, the conjecture has been verified by computers for extremely large values of $n$.

---

## Implementation Overview
The program includes:

1.  **Input Validation:** Ensures that the user enters an even integer greater than 2.
2.  **Prime Number Generation:** Uses trial division up to $\sqrt{n}$ to check for primality, with dynamic memory allocation for scalability.
3.  **Pair-Finding Algorithm:** Given an ordered list of primes, the program uses a two-pointer technique to efficiently find all pairs $(p, q)$ such that $p + q = n$.
4.  **Output:** Prints all valid pairs, along with the total number of solutions found.

---

## Example Run
```

Set n: 26
NumberPrimes = 9
3 + 23 = 26
7 + 19 = 26
13 + 13 = 26
Solution Number: 3

````

---

## Compilation and Execution
To compile:
```bash
gcc -o goldbach Goldbach1.4.c -lm
````

*The `-lm` flag links the math library (for functions like `sqrt`, `log`).*

To execute:

```bash
./goldbach
```

-----

## Future Work

  * Replace trial division with the **Sieve of Eratosthenes** for better performance.
  * Extend the program to efficiently handle larger inputs.
  * Compare the effectiveness of different prime generation methods.
  * Add formal testing and benchmarking.

-----

## License

This project is licensed under the **AGPL-3.0 License**. See the `LICENSE` file for more details.

```
```
