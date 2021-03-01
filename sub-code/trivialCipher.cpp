#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
/**
Author: Collin Sipple
Date Created: February 28, 2021
Purpose: Using a trivial substitution to decrypt a given ciphertext.
 **/

using namespace std;

string alphabetTable = "abcdefghijklmnopqrstuvwxyz";

int getPosInStr(char);

bool swapUsed(char *, int, char);

int main(int argc, char **argv) {
  string ciphertext;
  //First read in the ciphertext as a string, with spaces included
  if(argc < 2) {
    cout << "Input ciphertext (all lowercase): ";
    cin >> ciphertext;
  } else {
    fstream fs;
    fs.open(argv[1], fstream::in);
    getline(fs, ciphertext);
    fs.close();
  }
  cout << "First iteration: " << ciphertext << endl;
  //Next, loop through substitutions chosen by user multiple times
  char continueChar = 'Y';
  string toPlaintext(ciphertext);
  //Trivial substitutions are only one-to-one
  char usedChar[26];
  for(int i = 0; i < 26; i++) {
    usedChar[i] = ' ';
  }
  while(continueChar != 'N') {
    char changeChar = ' ';
    char intoChar = ' ';
    while(changeChar == ' ') {
      cout << "Type character to be changed: ";
      cin >> changeChar;
      if(usedChar[getPosInStr(changeChar)] != ' ') {
	cout << "That character is already used!" << endl;
	changeChar = ' ';
      }
    }
    while(intoChar == ' ') {
      cout << "Type character it should turn into: ";
      cin >> intoChar;
      if(intoChar == changeChar) {
	cout << "That is the same character!" << endl;
	intoChar = ' ';
      } else if(swapUsed(usedChar, 26, intoChar)) {
	cout << "That character is already used!" << endl;
	intoChar = ' ';
      }
    }
    for(int i = 0; i < toPlaintext.length(); i++) {
      if(ciphertext[i] == changeChar) {
	toPlaintext[i] = intoChar;
      }
    }
    usedChar[getPosInStr(changeChar)] = intoChar;
    printf("First Iteration: \t%s\nCurrent Iteration: \t%s\n", ciphertext.c_str(), toPlaintext.c_str());
    cout << "Continue? (Y)es/(N)o/(R)eset: ";
    cin >> continueChar;
    if(continueChar == 'R') {
      toPlaintext = ciphertext;
      for(int i = 0; i < 26; i++) {
	usedChar[i] = ' ';
      }
    }
  }
  return 0;
}

/**
Using the alphabet string as a table, gets the position of a character for other
uses.
 **/
int getPosInStr(char c) {
  for(int i = 0; i < alphabetTable.length(); i++) {
    if(c == alphabetTable[i]) {
      return i;
    }
  }
  return -1;
}

/**
Test to see if a certain character has already been swapped.
 **/
bool swapUsed(char *arr, int n, char c) {
  for(int i = 0; i < n; i++) {
    if(arr[i] == c) {
      return true;
    }
  }
  return false;
}
