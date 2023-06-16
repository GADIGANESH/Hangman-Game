#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>

int main() {
  char words[][100] = {
    "television",
    "clock",
    "chair",
    "fan",
    "table"
  };
  int num = sizeof(words) / sizeof(words[0]);
  char word[100];
  char guessed[100];
  int wrongGuesses = 0;
  int maxWrongGuesses = 7;
  srand(time(NULL));
  int randomIndex = rand() % num;
  strcpy(word, words[randomIndex]);
  memset(guessed, '_', sizeof(strlen(word)));
  printf("HINT:The random words are objects which are basically there at any home::::::\n");
  printf("START  -->\n");
  while (wrongGuesses < maxWrongGuesses) {
    printf("The word is:%s\n", guessed);
    char guess;
    printf("Enter your guess: ");
    scanf(" %c", &guess);
    getchar();
    int found = 0;
    for (int i = 0; i < strlen(word); i++) {
      if (word[i] == guess) {
        guessed[i] = guess;
        found = 1;
      }
    }
    if (!found) {
      wrongGuesses++;
    }
    if (strchr(guessed, '_') == NULL) {
      printf("Congratulations! You win!\n");
      break;
    }
    if (wrongGuesses == maxWrongGuesses) {
      printf("You lose! The word was: %s\n", word);
      break;
    }
  }
 return 0;
}
