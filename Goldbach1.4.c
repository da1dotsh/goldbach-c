#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int *NumberPrimesCalculator(unsigned int UserNumber, unsigned int *count);
unsigned int GetUserNumber();


void main (void){
	
	unsigned int UserNumber, NumberPrimes, i = 0, j, NumberSolutions = 0;
	unsigned int *p_PrimeMatrix;
	short int Flag;
	
		UserNumber = GetUserNumber();
		p_PrimeMatrix = NumberPrimesCalculator(UserNumber, &NumberPrimes);
		j = NumberPrimes - 1;
		printf ("NumberPrimes = %i", NumberPrimes);
		
		while (i <= j) {
		    unsigned int sum = p_PrimeMatrix[i] + p_PrimeMatrix[j];
		
		    if (sum == UserNumber) {
		        NumberSolutions++;
		        printf("%u + %u = %u\n", p_PrimeMatrix[i], p_PrimeMatrix[j], UserNumber);
		        i++;
		        j--;
		    } else if (sum < UserNumber) {
		        i++;
		    } else { 
		        j--;
		    }
		}
	
		printf("Solution Number: %u\n", NumberSolutions);
		
		free(p_PrimeMatrix);	
	
}

unsigned int GetUserNumber(){

	unsigned int IntUserNumber = 0;
	float FloatUserNumber = 0;
	short int LogicSelector, LogicFlag;
			
	do{
		
		printf("\n\nSet n: "); 
		LogicSelector = scanf("%f", &FloatUserNumber);
		IntUserNumber = FloatUserNumber;
		LogicFlag = 0;
		
		if (LogicSelector == 1 && FloatUserNumber - IntUserNumber == 0 && IntUserNumber%2 == 0 && IntUserNumber > 2){
			LogicFlag = 1;
		}
		
		else{
			while(getchar() != '\n'); 		
		}
		
	}while(LogicSelector != 1 || LogicFlag != 1);
	
	return IntUserNumber;

}

unsigned int *NumberPrimesCalculator(unsigned int UserNumber, unsigned int *count){
	
	unsigned int NumberPrimes = 0, DivisorCounter;
	unsigned int EstimateNumber = (UserNumber > 10) ? (unsigned int)(UserNumber / log(UserNumber)) : 10;
	unsigned int MatrixCapacity = (unsigned int)(EstimateNumber * 1.2);
	
	if (MatrixCapacity < 1000) MatrixCapacity = 1000;
	
	unsigned int *p_PrimeMatrix = malloc(MatrixCapacity * sizeof(unsigned int));
	
	if (!p_PrimeMatrix){
		printf ("Error: NoMemoryToAlloc");
		free(p_PrimeMatrix);
		exit(1);
	}
	
	for (unsigned int i = 2; i <= UserNumber; i++){
		
		if (i == 2){
			
			p_PrimeMatrix[NumberPrimes++] = 2;
			continue;
			
		}

	
		if (i % 2 == 0) continue;
		
		DivisorCounter = 0;
				
		for(unsigned int j=3; j<=sqrt(i); j += 2){	
			if(i%j == 0){
				DivisorCounter = 1;
				break;
			}
		}
		
		if(DivisorCounter == 0) {
			
			if (NumberPrimes == MatrixCapacity){
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
	
	unsigned int *final = realloc(p_PrimeMatrix, NumberPrimes * sizeof(unsigned int));
	
	if (!final){
		
		printf ("Error: NoMemoryToSecondRealloc");
		free (p_PrimeMatrix);
		exit(1);
		
	}
	
	else{
		p_PrimeMatrix = final;
		
	*count = NumberPrimes;
	return p_PrimeMatrix;
	
	}	
	
}












