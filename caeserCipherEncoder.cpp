// Caesar Cipher Encoder
// Jacob Kirchner

/*

The Caeser Cipher is considered to be the first method of encryption. It takes plaintext
and shifts each letter by a specified number. Caeser used the number 3 for his shift integer,
therefore A would become D, B would become E and so on. This program steps away from the
traditional approach and allows the generation of a random number between 1 and 25 or the
user can input a desired value. 

Note: plaintext is traditionally all lowercase, while ciphertext is all capitalized

Note: Any user-provided number above 25 will undergo a modulo 26 operation since there
are only 26 letter in the alphabet. Entering a shift of 26 will provided a shift of zero,
therefore the message is not encoded. 

*/

#include <iostream>
#include <string>
#include <random>
#include <cctype>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int generateRandomNumber() {

	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<int> distribution(1, 25);

	int randomNumber = distribution(gen);

	return randomNumber;

}

string caesarEncode(string plainText, const int& shiftValue) {

	// loop to shift each character by the designated shift value
	for (int i = 0; i < plainText.size(); i++) {

		if (plainText[i] + shiftValue > 'z') {

			int newShiftValue = shiftValue - ('z' - plainText[i]) - 1;
			plainText[i] = 'a' + newShiftValue;

		}
		else {

			plainText[i] = plainText[i] + shiftValue;

		}

	}

	// turns the cipher text into uppercase
	for (int i = 0; i < plainText.size(); i++) {

		plainText[i] = toupper(plainText[i]);

	}

	return plainText;

}

int main() {

	string plainText;
	string cipherText;
	char prompt;
	int shiftValue;

	cout << "Would you like a random shift value? (y/n) ";
	while (cin >> prompt) {

		if (toupper(prompt) == 'Y') {
			shiftValue = generateRandomNumber();
			break;
		}
		else if (toupper(prompt) == 'N') {
			cout << "Enter shift value: ";
			cin >> shiftValue;
			break;
		}
		else {
			cout << "Please Enter a valid command." << endl << "Would you like a random shift value? (y/n) ";
		}

	}

	cout << endl << "Enter an all lowercase phrase to be encoded: ";
	cin >> plainText;
	cout << endl;

	cipherText = caesarEncode(plainText, shiftValue);

	cout << plainText << " with a caesar cipher with a shift of " << shiftValue
		<< " is " << cipherText << endl;

}