/*  Problem Set 9: Scrabble Word Game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define WORDLIST_FILENAME "words.txt"
#define MAX_WORDS 100000 //max number of words in the list
#define MAX_LENGTH    15           //max number of characters in a word
#define HAND_SIZE  7

char VOWELS[]="aeiou";
char CONSONANTS[]="bcdfghjklmnpqrstvwxyz";
int SCRABBLE_LETTER_VALUES[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
/* values for letter a, b, c, d, e, ..., etc. */

int load_words(char filename[], char word_list[MAX_WORDS][MAX_LENGTH+1])
/*  Load all the words from file filename, and same them to word_list;
    return 1 if succeeds, and 0 if fails

*/
{
   // implement code here
}

int get_word_score(char word[], int n)
/*  Returns the score for a word. Assumes the word is a valid word.
    The score for a word is the sum of the points for letters in the word, plus 50 points if all n letters are used on the first go.
    Letters are scored as in Scrabble; a is worth 1, b is worth 3, c is worth 3, d is worth 2, e is worth 1, and so on.
    word: string (lowercase letters)
    n: length of the array that word points to
    returns: int >=0
*/
{
	//implement code here
}

void  display_hand(char hand[], int handCount[])
/* Displays the letters currently in the hand.
    hand: string (lowercase letters)
    handCount: array of number of characters in the string
*/
{	int i=0, j;
	while(hand[i])
	{
		j=0;
		while(j++ <handCount[i])
			printf("%c ", hand[i]);
		i++;
	}
}

void deal_hand(char hand[], int n, int handCount[])
/*  Generate and save a random hand containing n lowercase letters.
    At least n/3 the letters in the hand should be VOWELS.
    Unique letters are saved in 'hand' as a string.
    The number of times the particular letter is repeated in that hand is saved in 'handCount'.
    n: int >= 0, the HAND_SIZE
*/
{	//implement code here
}

void update_hand(char hand[], int handCount[], char word[])
/*  Assumes that 'hand' has all the unique letters in word.
    Updates the hand: uses up the letters in the given word and update the handCount.
    hand: string
    handCount: array
    word: string
*/
{
	int i=0;
	char *p;
	for (i=0; word[i]!='\0'; i++)
	{
		p=strchr(hand, word[i]);
		if(p!=NULL)
			handCount[p-hand]--;
	}

}

int is_valid_word(char word[], char hand[], int handCount[], char word_list[MAX_WORDS][MAX_LENGTH+1])
/* Returns TRUE if word is in the 'word_list' and is entirely composed of letters in the hand. Otherwise, returns FALSE
   Does not alter 'hand' or 'word_list'.
    word: string
    hand: string
    word_list: list of lowercase strings
*/
{
//implement code here

}

void  play_hand(char hand[], int handCount[], char word_list[MAX_WORDS][MAX_LENGTH+1])
/*  Allows the user to play the given hand, as follows:
    - The hand is displayed.
	- The user may input a word.
	- An invalid word is rejected, and a message is displayed asking the user to choose another word.
    - When a valid word is entered, it uses up letters from the hand.
    - After every valid word: the score for that word and the total score so far are displayed, the remaining letters in the hand are displayed, and the user is asked to input another word.
    - The sum of the word scores is displayed when the hand finishes.
    - The hand finishes when there are no more unused letters.The user can also finish playing the hand by inputing a single period ('.') instead of a word.
    -  The final score is displayed.
    hand: a string
    word_list: list of lowercase strings
*/
void  play_hand(char hand[], int handCount[], char **word_list)
{
/*  Allows the user to play the given hand, as follows:
    - The hand is displayed.
	- The user may input a word.
	- An invalid word is rejected, and a message is displayed asking the user to choose another word.
    - When a valid word is entered, it uses up letters from the hand.
    - After every valid word: the score for that word and the total score so far are displayed, the remaining letters in the hand are displayed, and the user is asked to input another word.
    - The sum of the word scores is displayed when the hand finishes.
    - The hand finishes when there are no more unused letters.The user can also finish playing the hand by inputing a single period ('.') instead of a word.
    -  The final score is displayed.
    hand: a string
    word_list: list of lowercase strings
*/
    char word[HAND_SIZE+1];
	int score=0,judge=0,t; 
	while(1)
	{
	  
	  printf("Current Hand: ");
      display_hand(hand, handCount);
      printf("\nEnter word, or a . to indicate that you are finished: ");
      back:
      scanf("%s",word);
    
      if(word[0]=='.')
	  {
	    printf("Total score: %d points.\n",score);
        break;
      }
    
      if(is_valid_word(word, hand, handCount, word_list))
          {
              score=score+get_word_score(word, strlen(word));
			  printf("%s earned %d points. Total: %d points\n",word,get_word_score(word,strlen(word)),score);
              update_hand(hand, handCount, word);
           }
	  else 
	  {
		  printf("\nWrong word. Please enter another word:\n");
		  goto back;
	  }
	  for(t=0;t<strlen(hand);t++)
	  {
	  	if(handCount[t]!=0)
	  	{
	  	  judge=1;           //还有字母 
		  break;	
	  	}
	  }
	  if(judge==0)
	  {
	    printf("Total score: %d points.\n",score);
        break;
      }  
    }
}

void play_game(char word_list[MAX_WORDS][MAX_LENGTH+1])
/*  Allow the user to play an arbitrary number of hands.
    - Asks the user to input 'n' or 'r' or 'e'.
    - If the user inputs 'n', let the user play a new (random) hand. When done playing the hand, ask the 'n' or 'r' or 'e' question again.
    - If the user inputs 'r', let the user play the last hand again.
    - If the user inputs 'e', exit the game.
    - If the user inputs anything else, ask them again.*/
{
/*	Uncomment the code after you've finished Problem 5.
	int handCount[HAND_SIZE];
	char hand[HAND_SIZE+1];
	char temp[HAND_SIZE+1];
	int tempCount[HAND_SIZE];

	char c; int i;
	system("CLS");  //Clear the screen, for Windows only

	printf("Scrabble Word Game begins ...\n");
	deal_hand(hand, HAND_SIZE, handCount);
	do{
		strcpy(temp, hand);
		for (i=0; i<HAND_SIZE; i++)	tempCount[i]=handCount[i];
		play_hand(temp, tempCount, word_list);

		Again:
        printf("\nn - Playe a new game\nr - Play this game again\ne - exit");
		printf("\nEnter your choice, n, r, or e: ");
		fflush(stdin); 	//Clear input buffer, for Windows only

		scanf("%c", &c);
		switch(c)
		{
			case 'n': 	deal_hand(hand, HAND_SIZE, handCount);
						break;
			case 'r':	break;
			case 'e':	break;
			default:    printf("\nInvalid command."); goto Again;
		}
	}while (c!='e');
*/
}

int main( )
{
 //   char word_list[MAX_WORDS][MAX_LENGTH+1];
 //   if(load_words(WORDLIST_FILENAME, word_list))
//	play_game(word_list);
}
