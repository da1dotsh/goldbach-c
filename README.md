# Goldbach's Conjecture — C Implementation

## Authors

**da1dotsh, shiradrock**

-----

## Abstract

Este proyecto presenta una implementación en lenguaje C inspirada en la **Conjetura de Goldbach**, que afirma que todo número par mayor que 2 puede expresarse como la suma de dos números primos.

El objetivo es didáctico: introducir a los estudiantes a los conceptos fundamentales de la programación en C, mientras se explora un problema clásico y abierto de la teoría de números.

-----

## Mathematical Background

La Conjetura de Goldbach puede expresarse formalmente como:

$$\forall n \in \mathbb{N}, \quad n > 2 \ \wedge \ n \equiv 0 \pmod{2} \quad \Rightarrow \quad \exists \ p, q \in \mathbb{P} : n = p + q$$

Donde:

  - $\\mathbb{N}$ = conjunto de números naturales
  - $\\mathbb{P}$ = conjunto de números primos

Aunque no ha sido probada en general, la conjetura ha sido verificada por computadoras hasta valores extremadamente grandes de $n$.

-----

## Implementation Overview

El programa incluye:

1.  **Validación de entrada**
    Asegura que el usuario ingrese un número entero par mayor que 2.

2.  **Generación de números primos**
    Utiliza la división por prueba hasta $\\sqrt{n}$ para verificar la primalidad, con asignación dinámica de memoria para la escalabilidad.

3.  **Algoritmo de búsqueda de pares**
    Dada una lista ordenada de primos, el programa emplea una **técnica de dos punteros** para encontrar eficientemente todos los pares $(p, q)$ tales que:

    $$
    $$$$p + q = n

    $$
    $$$$
    $$
4.  **Salida**
    Imprime todos los pares válidos, junto con el número total de soluciones encontradas.

-----

## Example Run

```
Set n: 26
NumberPrimes = 9
3 + 23 = 26
7 + 19 = 26
13 + 13 = 26
Solution Number: 3
```

-----

## Compilation and Execution

Para compilar:

```bash
gcc -o goldbach Goldbach1.4.c -lm
```

El flag `-lm` enlaza la biblioteca matemática (`sqrt`, `log`).

Para ejecutar:

```bash
./goldbach
```

-----

## Future Work

  * Reemplazar la división por prueba con la **Criba de Eratóstenes** para un mejor rendimiento.
  * Extender el programa para manejar entradas más grandes de manera eficiente.
  * Comparar la efectividad de diferentes métodos de generación de primos.
  * Añadir pruebas formales y *benchmarking*.

-----

## License

Este proyecto está licenciado bajo la **Licencia AGPL-3.0**.
Consulta el archivo [LICENSE](https://www.google.com/search?q=LICENSE) para más detalles.
