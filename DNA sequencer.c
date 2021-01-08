/**
 * Assignment #2: Loops, functions, arrays.
 * This program computes simple DNA matching between 2 sequences.
 **/

#include <stdio.h>
#include <stdbool.h>

#define BASE_SEQ_LEN 20
#define TARGET_SEQ_LEN 5
#define NUM_BASES 4
#define THRESHOLD 3



/* function prototypes */
/*  See function definitions below for documentation */
_Bool read_sequence(char[], int);
_Bool match(const char[], const char[], int, int, int);
void print_sequence_part(const char[], int, int);
void print_sequence(const char[], int);
_Bool is_valid_base(char);

/* external variables */
const char bases[] = {'A', 'T', 'C', 'G'};

/**
 * main: This function needs to read and store a sequence of length
 *       BASE_SEQ_LEN. Then it needs to read and store a sequence of 
 *       TARGET_SEQ_LEN. Finally it needs to call match() with both sequences.
**/
int main() {
    char s1[20], s2[5];

    // 1: Read base input sequence into s1 array
    if (read_sequence(s1, 20) == 0) {
      // if read_sequence returned false then there was an error
      printf("ERROR: sequence 1 is bad.  Exiting\n");
      return -1;
    }

    if (read_sequence(s2, 5) == 0){ //checking for error in 2nd sequence
      printf("ERROR: sequence 2 is bad.  Exiting\n");
      return -1;
    }

    match(s1, s2, 20, 5, THRESHOLD); //calls match function




    return 0;
}

/*Prints a sequence part indicated by the start and end (excluded) indices.*/

void print_sequence_part(const char s[], int start, int end) {
    for (int i=start; i<end; i++) {
        printf("%c", s[i]);
    }
}

/* Prints a sequence of bases.                                              */
void print_sequence(const char s[], int len) {
    print_sequence_part(s, 0, len);
}


_Bool read_sequence(char s[], int seq_len) {
    char b;
    int i = 0;

    printf("Enter a sequence of length %d: ", seq_len);
    // Read first character in to get us started
    scanf("%c", &b);

    
    // Loop until new line 

      while(b != '\n'){
      int valid = is_valid_base(b);
      if(valid == 1){ //checks if the input is valid
        s[i] = b;
        i++;
      }
      scanf("%c", &b); 
      }



    // When we are done looping i should hold the length of valid bases read
    if (i != seq_len) {
      printf("Invalid: input sequence too short\n");
       return 0; // sequence too short
    }
    printf("Valid input sequence: ");
    print_sequence(s, seq_len);
    printf("\n");
    return 1;
}

/* Checks whether the input character represents a valid base.              *
 * Returns false if b is not in the bases array which is preloaded with     *
 *  'A', 'C', 'G', 'T'.                        
 */
_Bool is_valid_base(char b) {
  
  for(int i = 0; i < NUM_BASES; i++ ){
    if (b == bases[i]){ //checking if char is in bases array
       return 1;
    } 
  }
  // if we got here then we must not have matched any of the bases elements
  return 0;
}

/*  This function will do the real work to try and match the two DNA        *
 *  sequences. In this case, the base sequence (variable s1) will be the    * 
 *  DNA sequence we are trying to reconstruct, and its length is stored in  *
 *  the variable len1. The target sequence (s2) will be the DNA sequence    * 
 *  that we are trying to match to the base sequence to determine if it is  *
 *  a part of that sequence, and its length is stored in len2.              *
 *                                                                          *
 **/
_Bool match(const char s1[], const char s2[],
     int len1, int len2, int threshold) {
   // FIXME:  This is where the real work has to happen 
   // implement this function using print_sequence_part as needed
      
      int s2pos = 0;
      for (int i = len1-threshold; i >0; i--){
        if(i <= 15){//check if whole of s2 is inside of s1
          if(s1[i] == s2[4]){
            if(s1[i-1] == s2[3]){
              if(s1[i-2] == s2[2]){
                if(s1[i-3] == s2[1]){
                  if(s1[i-4] == s2[0]){
                    printf("A match was found.\n");//print just s1 because s2 is inside of it
                    print_sequence(s1, 20);
                    printf("\n");
                    return 1;
                  }
                }
              }
            }
          }
        }
         else if(s1[i] == s2[0]){
          if(s1[i+1] == s2[1]){
            if(s1[i+2] == s2[2]){ //only first 3 of s2 in end of s1 add on rest of s2 when printing
              if(i == len1-threshold){
                printf("A match was found.\n");// print if only 3 of s2 are at end of s1
                print_sequence(s1, 20);
                print_sequence_part(s2, 3, 5);            
                printf("\n");
                return 1;
              }
                  if(s1[i+3] == s2[3]){ //only first 4 of s2 in end of s1 and on end of s2 when printing
                    printf("A match was found.\n");//print if 4 of s2 are at end of s1
                    print_sequence(s1, 20);
                    print_sequence_part(s2, 4, 5);
                    printf("\n");
                    return 1;
                  } 
                }
              }
            }
          }

    printf("No match found.\n");
    return 0;
}
