// AUTHOR: Marshall Patterson
// FILENAME: encryption.c
// SPECIFICATION: encrypt and decrypt a string
// FOR: CS 1412 Programming Principles 2 Section 504 


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STRSIZ 255
#define ENCRYPT 1

void decrypt(char string[], int length);
void encrypt(char string[], int length);
int toInt(char c);
char charConvert(int num);
int encryptNumberCheck(int number);
int decryptNumberCheck(int number);

int main(void) {
// if (ENCRYPT) {
  //CREATE FILE
  freopen("encrypt.txt","w+",stdout);

  FILE *fp;
  char buff[STRSIZ];

  fp = fopen("input.txt", "r+");
  fgets(buff, STRSIZ, (FILE*)fp);
  encrypt(buff, STRSIZ);
  fclose(fp);
// } else {
  //CREATE FILE
  freopen("decrypt.txt","w+",stdout);

  FILE *file;
  char decr[STRSIZ];
  //OPEN FILE TO READ
  file = fopen("encrypt.txt", "r+");
  fgets(decr, STRSIZ, (FILE*)file);
  decrypt(decr, STRSIZ);
  
  fclose(file);
// }


  return 0;
}

// NAME: encrypt
// INPUT Param.: string length
// OUTPUT Param.: void
// PURPOSE: encrypt a string
void encrypt(char string[], int length) {
  int i;
  char encryptedString[STRSIZ];
  for (i = 0; i <= length &&  tolower(string[i]) != '\0'; i++) {
    if (isspace(string[i])) {
      printf(" ");
    } else if (isalpha(string[i])){
    int number = tolower(string[i]) + 20;

    printf("%c", encryptNumberCheck(number));
    } else {
      printf("%c", string[i]);
    }
    
  }
}

// NAME: decrypt
// INPUT Param.: string length
// OUTPUT Param.: void
// PURPOSE: decrypt a string
void decrypt(char string[], int length) {
  int i;
  for (i = 0; i <= length &&  tolower(string[i]) != '\0'; i++) {
    if (isspace(string[i])) {
      printf(" ");
    } else if (isalpha(string[i])){
    int number = tolower(string[i]);

    printf("%c", decryptNumberCheck(number));
    } else {
      printf("%c", string[i]);
    }
  }

}

// NAME: encryptNumberCheck
// INPUT Param.: int umber
// OUTPUT Param.: lower case ascii code number
// PURPOSE: loop through nubmers and check if in range
int encryptNumberCheck(int number) {
  int newNumber;
  if (number > 122) {
      number = number - 122;
      newNumber = 96 + number;
      return newNumber;
    } else if (number < 97) {
      number = number + 96;
      return newNumber;
    } else {
      return number;
    }
}

// NAME: decryptNumberCheck
// INPUT Param.: int umber
// OUTPUT Param.: lower case ascii code number
// PURPOSE: loop through nubmers and check if in range
int decryptNumberCheck(int number) {
  int newNumber;
  if (number > 116) {
    return number - 20;
    } else {
      newNumber = number + 6;
      return newNumber;
    }
}

