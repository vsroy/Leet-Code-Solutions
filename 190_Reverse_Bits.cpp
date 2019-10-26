/*Reverse bits of a given 32 bits unsigned integer.*/

#include<iostream>
#include<stdint.h>
#include<vector>
#include<math.h>

uint32_t reverseBits(uint32_t x) {
	int res = 0; // Start with an empty number
	for (uint32_t i{}; i < 32; i++) { // 32 bits...
		if (x & 1) res += pow(2, 31 - i); // If we have a 1 at position 0, we add 2^31 to our //new number.
		x >>= 1; // Shift over so we can check if there is a 1 at position 0 again.
	} // If there is a one there, we add 2^30 to our new number, filling in its bits.
	return res;
}
int main()
{
	uint32_t ipVal = 43261596;
	std::cout << reverseBits(20);
	return 0;
}