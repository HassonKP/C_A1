#include <stdio.h>
#include <stdlib.h>

//The shuffle function will take in the pre sshuffled words and an empty array of 'char*' the function will
//randomly fill the empty array
int shuffle(char** wordList,char ** game);

//The play function will carry out the timing of the session aswell as reading out the words and reading in
//the users words
int play(char ** game);

//This is a basic display function to display all the words in an array
void display(char** game);


