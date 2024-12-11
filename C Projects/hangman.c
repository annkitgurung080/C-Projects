#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define WORDS_COUNT 5
#define WORDS_MAX_LENGTH 20

// Function to randomly select a word
char* getRandomWord() {
    char* words[] = {"programming", "hangman", "computer", "language", "developer"};
    int index = rand() % WORDS_COUNT;
    return words[index];
}
// Function to display the current state of the word
void displayWord(const char* word, const char* guessedLetters) {
    int len = strlen(word);
   for (int i = 0; i<len; ++i) {
        if (strchr(guessedLetters, word[i]) != NULL) {
printf("%c ", word[i]);
        } else {
printf("_ ");
        }
    }
printf("\n");
}

// Function to check if the player has guessed all the letters
int isWordGuessed(const char* word, const char* guessedLetters) {
    int len = strlen(word);
   for (int i = 0; i<len; ++i) {
        if (strchr(guessedLetters, word[i]) == NULL) {
            return 0; // Not all letters guessed
        }
    }
  return 1; // All letters guessed
}
int main() {
srand(time(NULL));
   char* word = getRandomWord();
    int wordLength = strlen(word);
   char guessedLetters[26]; // Assuming only lowercase letters are guessed
    int tries = 0;
   printf("\nWelcome to Hangman!\n");
  do {
printf("\n");
displayWord(word, guessedLetters);
printf("Guessed Letters: %s\n", guessedLetters);
printf("Enter a lowercase letter: ");
        char guess;
scanf(" %c", &guess);
// Check if the letter has already been guessed
        if (strchr(guessedLetters, guess) != NULL) {
printf("You already guessed that letter. Try again.\n");
            continue;
        }

guessedLetters[strlen(guessedLetters)] = guess;
guessedLetters[strlen(guessedLetters) + 1] = '\0';
 // Check if the guessed letter is in the word
        if (strchr(word, guess) == NULL) {
printf("Incorrect guess!\n");
            tries++;
        }
 } while (tries < MAX_TRIES && !isWordGuessed(word, guessedLetters));

printf("\n");
displayWord(word, guessedLetters);

    if (isWordGuessed(word, guessedLetters)) {
printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
printf("\nSorry, you ran out of tries. The word was: %s\n", word);
    }
free(word);
    return 0;
}