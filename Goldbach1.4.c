#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
unsigned int *NumberPrimesCalculator(unsigned int UserNumber, unsigned int *count);
unsigned int GetUserNumber();

void main (void){
	
    // Variable declarations
    unsigned int UserNumber, NumberPrimes, i = 0, j, NumberSolutions = 0;
    unsigned int *p_PrimeMatrix; // Pointer to store prime numbers
    short int Flag;
	
    // Get a valid user input number (even number > 2)
    UserNumber = GetUserNumber();

    // Generate prime numbers up to UserNumber and store them in an array
    p_PrimeMatrix = NumberPrimesCalculator(UserNumber, &NumberPrimes);

    // Set j to point to the last prime in the array
    j = NumberPrimes - 1;

    printf ("\nNumberPrimes = %i", NumberPrimes);
		
    // Two-pointer approach to find pairs of primes that sum up to UserNumber
    while (i <= j) {
        unsigned int sum = p_PrimeMatrix[i] + p_PrimeMatrix[j];
		
        if (sum == UserNumber) {
            // If a valid pair is found, print it and move both pointers
            NumberSolutions++;
            printf("\n%u + %u = %u\n", p_PrimeMatrix[i], p_PrimeMatrix[j], UserNumber);
            i++;
            j--;
        } else if (sum < UserNumber) {
            // If the sum is too small, increase the lower pointer
            i++;
        } else { 
            // If the sum is too large, decrease the upper pointer
            j--;
        }
    }
	
    // Print the total number of solutions found
    printf("\nSolution Number: %u\n", NumberSolutions);
		
    // Free dynamically allocated memory
    free(p_PrimeMatrix);	
	
}

unsigned int GetUserNumber(){

    unsigned int IntUserNumber = 0;
    float FloatUserNumber = 0;
    short int LogicSelector, LogicFlag;
			
    do{
        // Ask user to input a number
        printf("\n\nSet n: "); 
        LogicSelector = scanf("%f", &FloatUserNumber);

        // Convert float to integer
        IntUserNumber = FloatUserNumber;
        LogicFlag = 0;
		
        // Validation: number must be an even integer greater than 2
        if (LogicSelector == 1 && FloatUserNumber - IntUserNumber == 0 && IntUserNumber%2 == 0 && IntUserNumber > 2){
            LogicFlag = 1;
        }
        else{
            // Clear invalid input buffer
            while(getchar() != '\n'); 		
        }
		
    }while(LogicSelector != 1 || LogicFlag != 1);
	
    return IntUserNumber;

}

unsigned int *NumberPrimesCalculator(unsigned int UserNumber, unsigned int *count){
	
    unsigned int NumberPrimes = 0, DivisorCounter;
    
    // Estimate the number of primes up to UserNumber using approximation
    unsigned int EstimateNumber = (UserNumber > 10) ? (unsigned int)(UserNumber / log(UserNumber)) : 10;
    unsigned int MatrixCapacity = (unsigned int)(EstimateNumber * 1.2);
	
    if (MatrixCapacity < 1000) MatrixCapacity = 1000;
	
    // Allocate initial memory for storing primes
    unsigned int *p_PrimeMatrix = malloc(MatrixCapacity * sizeof(unsigned int));
	
    if (!p_PrimeMatrix){
        printf ("Error: NoMemoryToAlloc");
        free(p_PrimeMatrix);
        exit(1);
    }
	
    // Generate prime numbers up to UserNumber
    for (unsigned int i = 2; i <= UserNumber; i++){
		
        if (i == 2){
            // Special case: 2 is the first prime
            p_PrimeMatrix[NumberPrimes++] = 2;
            continue;
        }

        // Skip even numbers greater than 2
        if (i % 2 == 0) continue;
		
        DivisorCounter = 0;
				
        // Check divisibility only up to sqrt(i)
        for(unsigned int j=3; j<=sqrt(i); j += 2){	
            if(i%j == 0){
                DivisorCounter = 1;
                break;
            }
        }
		
        if(DivisorCounter == 0) {
            // If prime, store it
            if (NumberPrimes == MatrixCapacity){
                // If array is full, reallocate with double capacity
                MatrixCapacity *=2;
                unsigned int *tmp = realloc(p_PrimeMatrix, MatrixCapacity * sizeof(unsigned int));
                if (!tmp){
                    printf ("Error: NoMemoryToFirstRealloc");
                    free (p_PrimeMatrix);
                    exit(1);
                }
                p_PrimeMatrix = tmp;
            }
			
            p_PrimeMatrix[NumberPrimes++] = i;
        }
    }
	
    // Reallocate memory to exact size needed
    unsigned int *final = realloc(p_PrimeMatrix, NumberPrimes * sizeof(unsigned int));
	
    if (!final){
        printf ("Error: NoMemoryToSecondRealloc");
        free (p_PrimeMatrix);
        exit(1);
    }
    else{
        p_PrimeMatrix = final;
		
        // Set output parameter with total count of primes found
        *count = NumberPrimes;
        return p_PrimeMatrix;
    }	
}














