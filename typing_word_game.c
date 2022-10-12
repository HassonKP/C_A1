/*name: Killian Hasson          Class: CS201            Date: 01/19/21

For assignment 1 we were tasked with creating a word game, it must have preset words that are shuffled and
read out to the user who then attempts to correctly type them. The user is timed in their playing of the game
and their spelling is ofcourse checked. Some issues I did notice when compelteing this program is that if
the user backspaces to correct their spelling it will still read back as untrue, also my use of a static array
of characters for users input could be a serious issue.
*/

#include <stdio.h>
#include "A1.h"
#include "A1.c"

int main()
{
        //The words that will be utilized in this game
        char* wordList[9] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
        //Empty array, will be passed into shuffle function and filled at random
        char* game[9];

        //shuffle function call, passing in the words and the empty array
        shuffle(wordList,game);

	printf("This is a game that tests typing speed\n");
	printf("Type the following words: \n");

        //play function, takes in the shuffled words
	play(game);

        //Testing functions
        //display(wordList);
        //display(game);
        printf ("\nFinished Program...\n");
        return 1;
}


