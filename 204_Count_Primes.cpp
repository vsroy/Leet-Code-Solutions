/*Count the number of prime numbers less than a non - negative number, n.*/

#include<iostream>
using namespace std;

/*Function to count the number of primes till a given number 'n'*/
int countPrimes(int n)
{
	// Base cases
	if (0 == n) { return 0; }
	else if (1 == n) { return 0; }
	else if (2 == n) { return 0; }

	auto bIsPrime = true;
	auto nPrimeCount = 1; // Includes '2'. No need to divide by 2.

	for (auto i = 3; i < n; i += 2) { // We'll check only odd numbers :)

		for (auto j = 3; (j * j) <= i; j++) { // We'll check only upto its square root 

			if ((0 == (i % j)) && (i != j)) {
				bIsPrime = false;
				break;
			}

		} // End inner for loop
		if (bIsPrime) {
			nPrimeCount++;
		}
		else {
			bIsPrime = true; // Reset flag
		}
	} // End outer for loop

	return nPrimeCount;
}

int main()
{
	std::cout << countPrimes(2);
	return 0;
}