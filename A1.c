#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include "A1.h"

//The shuffle function
int shuffle(char** wordList,char ** game)
{
        //Use computers internal clock to keep the seed random
        srand(time(NULL));
        //num used to properly use the for loop
        int num = 9;
        //initialize the random number index
        int random_index = 0;
        //an array of ints, this is used to tell which correlating words in wordList have been copied already
        int test[9] = {0,0,0,0,0,0,0,0,0};
        //for loop to navigate the 'wordList' and randomly copy the words into the 'game' array
        for(int i = 0; i < num; i++)
        {
                //This loop will loop through the array of ints until it finds an already copied space
                do
                {
                        //Generate a random number between 0 and 9
                        random_index = rand() % num;
                } while(test[random_index] == 1);
                //The below for loop was used to help me visualize the looping process
                /*
                for(int j = 0; j < num; j++)
                {
                        printf("%d ", test[j]);
                }
                printf("\n");*/
                //When an uncopied word index is found we need to set it to copied or '1'
                test[random_index] = 1;
                //Then the word is copied into the empty array 'game' for use
                game[i] = wordList[random_index];
        }
        return 1;
}

//The play function will read out a word and than take in a word, compare them and continue only if the input
//word matches the output word
int play(char ** game)
{
        //Set up the clock to measure the users time to complete the game
        struct timeval t1, t2, tfinal;
        //start the time
        gettimeofday(&t1, NULL);
        //Loop through the array of words 'game'
        for(int i = 0; i < 9; i++)
        {
                //intialize a result integer to not equal 0, will equal 0 on a correct spelling
                int result = 1;
                //intialize a blank array of characters for input
                char str[10];
                //loop while the users input is incorrect
                while(result != 0)
                {
                        //read out the word the user must spell
                        /*printf("%s\n", game[i]);*/
			printf("Word #%d is %s: ", i + 1, game[i]);
                        //read in the users word
                        scanf("%s", str);
                        //compare the words
                        result = strcmp(game[i],str);
                        //print out the comparison result, just used for testing.
                        printf("strcmp(game[i],str) = %d\n", result);
                }
        }
        //get the second time once the loop is complete and all words have been spelled correctly
        gettimeofday(&t2, NULL);
        //finalize the time spent total on the game
        timersub(&t2, &t1, &tfinal);
        //read out the time spent on the game
        printf("You took %ld seconds and %06ld microseconds\n", (long int)tfinal.tv_sec, (long int)tfinal.tv_usec);
	return 1;
}
                            

//A simple display function for testing various shuffle functions
void display(char** game)
{
        //loops through an array and reads out the word
        for(int i = 0; i < 9; i++)
        {
                printf("%s\n", game[i]);
        }

}

