#include <stdio.h>
#include <string.h>
#include "words.h"

Sentence readSentence(FILE* file) {
// Initialize a Sentence struct
Sentence sentence;
sentence.numWords = 0;

// Read in the words from the file
char word[MAX_WORD_LENGTH];
while (fscanf(file, "%s", word) == 1) {
// Stop reading when a newline character is encountered
if (word[0] == '\n') {
break;
}

// Add the word to the Sentence struct
if (sentence.numWords < MAX_SENTENCE_LENGTH) {
  strcpy(sentence.words[sentence.numWords].word, word);
  sentence.words[sentence.numWords].position = sentence.numWords;
  sentence.numWords++;
}
}

return sentence;
}

int checkWord(Sentence sentence, char* word) {
// Check if the word is in the sentence
for (int i = 0; i < sentence.numWords; i++) {
if (strcmp(sentence.words[i].word, word) == 0) {
// If the word is in the sentence, return its position
return sentence.words[i].position;
}
}

// If the word is not in the sentence, return -1
return -1;
}