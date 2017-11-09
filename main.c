/*
 header here


 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>


void readProcessControlBlocks();
int isPrime(int n);
int getNextPrimeNumberAfter(int n);

/*
 Our Main function
 */
int main() {
    int input;

    printf("Enter an integer. Enter 0 to exit: ");
    scanf("%d", &input);

    if (input == 0) {
        return 0;
    }
    printf(isPrime(input) == 1 ? "Yes" : "No");

    getchar();

    return 0;
}



/*
 This function reads the text file to get information about the PCBs
 */
/*
void readProcessControlBlocks() {
    //  Open our file containing the process control blocks for reading.
    FILE *fp;
    // fopen_s(&fp, "filenamehere.txt", "r");
    char tempLine[100]; // Temp variable used for reading in the PCBs

    if ((fp = (FILE *) (fopen("list_of_processes.rtf", "r") == (NULL)))) {
        printf("ERROR: Could not open file. \n");
        return;
    }
    while ( fgets(tempLine, sizeof(tempLine), fp) ) {
        sscanf(tempLine, "%d %24[^\n] %19s %119[^\n]", pcb.processId, pcb.processState, pcb.processPriority, pcb.processTime);
    }
    // else {
    // fscanf(fp, "%s", buff);
}
*/



/*
 This function checks to see if a number, n, is prime or not.
 */
int isPrime(int n) {
    int i; // loop variable
    int num_of_factors = 0; // A number is considered prime if it has 2 factors.

    for( i = 1; i <= n; i += 1 ) {
        if (n % i == 0) {
            num_of_factors++;
        }
    }

    if ( num_of_factors == 2 ) {
        return 1; // Yes, n is a prime number.
    }
    else {
        return 0; // No, n is not a prime number.
    }
}


/*
 This function gets the next prime number after n.
 */

int getNextPrimeNumberAfter(int n) {
    int next = n+1; // The number after n

    // If the next number is not prime, go to the next integer.
    while (isPrime(next) != 1 ) {
        next++;
    }

    return next; // There will always be a next prime number after n.
}


/*
 This function serves as our time slice. One unit of time in our case is 1,000 prime numbers.
 With our Round Robin Scheduling, we are using time slices of 4 units for each process.
 Therefore, this function will perform one time slice and print 4,000 prime numbers.

 It will take in the last prime number that was printed and it will return
 the last prime number that it prints.
 */
int printPrimeNumbers(int lastPrimeNumberPrinted) {
    int numberOfPrimesPrinted;

    // Until we have printed 4,000 prime numbers, we need to keep getting
    // the next prime number and printing it.
    while (numberOfPrimesPrinted < 4000) {
        // Print the next prime number after the last printed prime number.
        printf("%4d", getNextPrimeNumberAfter(lastPrimeNumberPrinted));

        // The last printed prime number is now the prime number that was just printed
        // which is the next prime number after the last prime number printed.
        lastPrimeNumberPrinted = getNextPrimeNumberAfter(lastPrimeNumberPrinted);
        numberOfPrimesPrinted++;
    }
    return lastPrimeNumberPrinted;

}