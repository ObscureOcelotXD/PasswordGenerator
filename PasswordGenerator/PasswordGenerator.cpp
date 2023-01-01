#include <string>
#include <time.h>
#include <random>

std::string GetPassword(int length) {

	std::string newString = "";
	const int LOWER_BOUND = 32;
	const int UPPER_BOUND = 126;

	//more randomness
	std::random_device rd;
	std::mt19937 gen(rd());

	//somehow Generates a random seed for the rand function.
	srand(time(NULL));

	for (int i = 0; i < length; i++) {
		char charToAppend;

		//adding cesar shit for even more randomness
		int randomAsciiCesarShit = rand() % 20;

		//check if even or odd switching methods for potential increased randomness
		if (i % 2 == 0) {
			//somehow generates a number between 32 and 126, these are the ascii characters I want.
			std::uniform_int_distribution<> dist(LOWER_BOUND, UPPER_BOUND);
			int number = dist(gen);
			charToAppend = char(number);
		}
		else {
			//somehow generates a number between 32 and 126, these are the ascii characters I want.
			int number = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;


			charToAppend = char(number);
		}

		newString += charToAppend;
	}
	return newString;
}