#include <iostream>
#include <fstream>
#include <string>
#include <cctype>   // For isdigit
#include <cstdlib>  // For std::exit
#include <cmath>    // For std::abs

const int ALPHABET_LENGTH = 26;

int number_from_letter(char letter) {
    int offset = letter - 'a';
    if (offset < 0 || offset >= ALPHABET_LENGTH) {
        std::cerr << "number_from_letter called with invalid argument ('" << letter << "').\n";
        std::exit(EXIT_FAILURE);
    }
    return offset;
}

char letter_from_number(int number) {
    if (number < 0 || number >= ALPHABET_LENGTH) {
        std::cerr << "letter_from_number called with an invalid argument (" << number << ").\n";
        std::exit(EXIT_FAILURE);
    }
    return 'a' + number;
}

/*
This program implements a simple Caesar cipher encryption and decryption system.
    It reads input from a file named "input.txt", which contains:
    - A direction character ('l' for left shift, 'r' for right shift)
    - A numeric shift value
    - A lowercase string to be encrypted or decrypted.

    The program performs the shift operation based on the direction and value, 
    wrapping around the alphabet as needed. It then outputs the transformed string.

    If the input file is missing or contains invalid data, appropriate error messages are displayed.
*/

int main() {
    // Declaration of required variables
    int shift_val = 0, character_number, new_character_number;
    char shift_dir, character, output_character;
    std::string requirements;
    std::string input_str;
    std::string output_string;

    // Accessing requirements from input.txt file
    std::ifstream inp_file("input.txt");
    if (!inp_file) {
        std::cerr << "Error: Unable to open input.txt file.\n";
        return 1;
    }

    std::getline(inp_file, requirements);
    inp_file.close();

    // Check if the input file is empty or doesn't have enough data
    if (requirements.length() < 2) {
        std::cout << "Oops: Could not read the shift number from the input file." << std::endl;
        return 1;
    }

    // Assigning values to required variables
    shift_dir = requirements.at(0);
    size_t index = 1;

    // Validate shift direction
    if (shift_dir != 'l' && shift_dir != 'r') {
        std::cout << "Oops: Invalid direction in the input file." << std::endl;
        return 1;
    }

    // Extracting the full shift value
    while (index < requirements.length() && std::isdigit(static_cast<unsigned char>(requirements.at(index)))) {
        shift_val = shift_val * 10 + (requirements.at(index) - '0');
        ++index;
    }

    // Check if shift number was read
    if (shift_val == 0) {
        std::cout << "Oops: Could not read the shift number from the input file." << std::endl;
        return 1;
    }

    // The rest of the string is the input string to be processed
    input_str = requirements.substr(index);

    // Normalize the shift value to ensure it's within the range of the alphabet length
    shift_val = shift_val % ALPHABET_LENGTH;

    // Performing required tasks for encryption/decryption
    for (index = 0; index < input_str.length(); index++) {
        character = input_str.at(index);
        character_number = number_from_letter(character);

        if (shift_dir == 'l') {
            new_character_number = character_number - shift_val;
        } else {
            new_character_number = character_number + shift_val;
        }

        // Handle wraparound for negative or large shifts
        if (new_character_number < 0) {
            new_character_number = (new_character_number + ALPHABET_LENGTH) % ALPHABET_LENGTH;
        } else if (new_character_number >= ALPHABET_LENGTH) {
            new_character_number = new_character_number % ALPHABET_LENGTH;
        }

        // Convert back to a character and append to the output string
        output_character = letter_from_number(new_character_number);
        output_string += output_character;
    }

    // Output the encrypted string
    std::cout << output_string << std::endl;

    return 0;
}