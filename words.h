#include <stdio.h>

#ifndef WORDS_H
#define WORDS_H

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 100

// A struct to represent a word and its position in the sentence
typedef struct {
char word[MAX_WORD_LENGTH];
int position;
} Word;

// A struct to represent a sentence and its words
typedef struct {
Word words[MAX_SENTENCE_LENGTH];
int numWords;
} Sentence;

// A function to read in a sentence from a file
Sentence readSentence(FILE* file);

// A function to check if a word is in the correct position in a sentence
int checkWord(Sentence sentence, char* word);

#endif