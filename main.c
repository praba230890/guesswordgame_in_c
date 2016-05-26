#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
    { False, 
        True 
    } bool;

char* grab_word(char *word_list[]);
int calculate_star(char *guess_word, char *word, int word_length);

int main(int argc, char *argv){
    char *word_list[] = {"jack", "back", "cock", "luck", "bang", "tool", "dogs", "bags", "life", "kick"};
    int word_count = 10;
    int word_length = 4;
    bool key = True;

    printf("Welcome to Guess Word game \n");
    char *word = grab_word(word_list);
    printf("Word to guess is %s\n", word);

    while(True == key){
        printf("Enter your guess that must be containing %d words: ", word_length);
        char guess_word[word_length];
        scanf("%s", guess_word);
        printf("%s\n", guess_word);
        int cmp = strcmp(guess_word, word);
        if(0 == cmp){
            printf("You've won the game");
            key = False;
        }
        else{
            int i;
            for(i=0; i<word_length;i++){
                printf("_ ");
            }
            int no_of_stars;
            no_of_stars = calculate_star(guess_word, word, word_length);
            for(i=0; i<no_of_stars; i++){
                printf("*");
            }

            printf("\n");
        }
    }
    return 0;
}

char* grab_word(char *word_list[]){
    // random number generation to get a word from word_list
    srand(time(NULL));
    int r = rand() % 10;

    char *word = word_list[r];
    return word;
}

int calculate_star(char *guess_word, char *word, int word_length){
    int i, j;
    int no_of_stars = 0;
    for (i=0; i<word_length; i++){
        if(guess_word[i] == word[i]){
            no_of_stars++;
        }
    }
    return no_of_stars;
}