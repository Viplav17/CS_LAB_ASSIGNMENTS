#include <iostream>
#include <cctype> // For isalpha() function

/*
 * is_vowel
 *
 * This function checks if a given character is a vowel (a, e, i, o, u) 
 * by converting it to lowercase and comparing it with a predefined list.
 *
 * input: char character - The character to check.
 * output: bool - Returns true if the character is a vowel, false otherwise.
 */
bool is_vowel(char character) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    character = tolower(character); // Convert to lowercase for case insensitivity

    int length = sizeof(vowels) / sizeof(vowels[0]);
    for (int i = 0; i < length; i++) {
        if (character == vowels[i]) {
            return true; // Return true if character is a vowel
        }
    }
    return false; // Return false if not found
}

/*
 * is_consonant
 *
 * This function checks if a given character is a consonant by 
 * determining whether it's not a vowel.
 *
 * input: char character - The character to check.
 * output: bool - Returns true if the character is a consonant, false otherwise.
 */
bool is_consonant(char character) {
    return !is_vowel(character); // A consonant is simply not a vowel
}

/*
 * ends_with_double_consonant
 *
 * This function checks if the word ends with two consecutive consonants.
 *
 * input: std::string Word - The word to check.
 * output: bool - Returns true if the word ends with two consonants, false otherwise.
 */
bool ends_with_double_consonant(std::string Word) {
    int len = Word.length();
    if (len >= 2 && Word[len - 1] == Word[len - 2]) {
        if (is_consonant(Word[len - 1]) && is_consonant(Word[len - 2])) {
            return true; // Return true if last two characters are consonants
        }
    }
    return false; // Return false if not found
}

/*
 * ends_with_cvc
 *
 * This function checks if the word ends with a consonant-vowel-consonant (CVC) pattern.
 *
 * input: std::string Word - The word to check.
 * output: bool - Returns true if the word ends with a consonant-vowel-consonant pattern, false otherwise.
 */
bool ends_with_cvc(std::string Word) {
    int len = Word.length();
    if (len >= 3) {
        if (is_consonant(Word[len - 1]) && is_vowel(Word[len - 2]) && is_consonant(Word[len - 3])) {
            return true; // Return true if ends with consonant-vowel-consonant
        }
    }
    return false; // Return false if not CVC
}

/*
 * contains_vowel
 *
 * This function checks if the word contains at least one vowel.
 *
 * input: std::string Word - The word to check.
 * output: bool - Returns true if the word contains at least one vowel, false otherwise.
 */
bool contains_vowel(std::string Word) {
    int len = Word.length();
    for (int i = 0; i < len; i++) {
        if (is_vowel(Word[i])) {
            return true; // Return true if a vowel is found
        }
    }
    return false; // Return false if no vowels are found
}

/*
 * count_consonants_at_front
 *
 * This function counts how many consonants are at the start of the word.
 *
 * input: std::string Word - The word to check.
 * output: int - Returns the number of consonants at the beginning of the word.
 */
int count_consonants_at_front(std::string Word) {
    int len = Word.length();
    int Count_Consonants = 0;
    for (int i = 0; i < len; i++) {
        if (is_consonant(Word[i])) {
            ++Count_Consonants; // Increment count if consonant
        } else {
            break; // Stop counting if a non-consonant is found
        }
    }
    return Count_Consonants; // Return the total count of consonants at the front
}

/*
 * count_vowels_at_back
 *
 * This function counts how many vowels are at the end of the word.
 *
 * input: std::string Word - The word to check.
 * output: int - Returns the number of vowels at the end of the word.
 */
int count_vowels_at_back(std::string Word) {
    int len = Word.length();
    int Count_Vowels = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (is_vowel(Word[i])) {
            ++Count_Vowels; // Increment count if vowel
        } else {
            break; // Stop counting if a non-vowel is found
        }
    }
    return Count_Vowels; // Return the total count of vowels at the back
}

/*
 * ends_with
 *
 * This function checks if the candidate string ends with the specified suffix.
 *
 * input: std::string candidate - The word to check.
 *        std::string suffix - The suffix to match.
 * output: bool - Returns true if the candidate ends with the suffix, false otherwise.
 */
bool ends_with(std::string candidate, std::string suffix) {
    int candidate_len = candidate.length();
    int suffix_len = suffix.length();

    if (candidate_len >= suffix_len) {
        int candidate_index = candidate_len - 1;
        for (int i = suffix_len - 1; i >= 0; i--) {
            if (candidate[candidate_index] == suffix[i]) {
                --candidate_index; // Move backward in the candidate string
            } else {
                return false; // Return false if mismatch occurs
            }
        }
        return true; // Return true if suffix matches
    }
    return false; // Return false if candidate is shorter than suffix
}

/*
 * new_ending
 *
 * This function creates a new string by replacing the last 'suffix_length' 
 * characters of the candidate word with the given replacement string.
 *
 * input: std::string candidate - The word to modify.
 *        int suffix_length - The number of characters to replace.
 *        std::string replacement - The string to append.
 * output: std::string - Returns the modified string with the replacement at the end.
 */
std::string new_ending(std::string candidate, int suffix_length, std::string replacement) {
    std::string New_String = "";
    int candidate_len = candidate.length();
    int New_String_length = candidate_len - suffix_length; // Remove the suffix length from the candidate

    for (int i = 0; i < New_String_length; i++) {
        New_String += candidate[i]; // Copy up to the new ending
    }

    return New_String + replacement; // Append the replacement at the end
}

