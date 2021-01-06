// Author:     Rahib R Laghari
// Course:     CS1336.010
// Date:       11/2/2020
// Assignment: Homework #8 Exercise #1
// Compiler:   Xcode

// Description:
// This program will print out as many prime numbers as the user input specifies, starting from 2
// The user can, at maximum, only print out the first 100 prime numbers, and at minimum only the first prime number

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
/* pseudocode for an isprime function:
 if num == 2
 - return true (it will help stop the outlier, and 2 will be the first printed prime
 else
 for not prime number (tested with remainder function: %)
 return false and make sure to increment number
 else
 return true
 if any of values above give zero, it's not a prime number
 */
// isPrime checks to see if input number is a prime number
bool isPrime(int num){
   if (num == 2){
      return true;
   }
   else{
      for (int i=2; i<num; i++){
         if ((num%i)==0){
            return false;
         }
      }
      return true;
   }
}

int main() {
   // start with creating variables to be used throughout
   ofstream OutputFile;
   OutputFile.open("PrimeOut.txt");
   int count = 0;
   int currNum = 2;
   // verify file opens
   if(OutputFile){
      int num;
      cout << "Enter an integer greater than 1 (prints this many prime numbers): ";
      cin >> num;
      while (num < 1){
         cout << "Invalid value \nEnter an integer above 1: ";
         cin >> num;
      }
      while (count < num){
         // test to see if number is prime, if so count adds one so when it gets equal to num (starting from 0), program will stop printing
         if(isPrime(currNum)){
            cout << setw(5) << right << currNum;
            OutputFile << setw(5) << right << currNum;
            count +=1;
            currNum +=1;
            // check to see if 10 numbers have been printed to make a new line
            if (count % 10 == 0){
               cout << endl;
               OutputFile << endl;
            }
         }
         else{
            currNum+=1;
         }
      }
   
   }
   // else in case error in opening output file
   else{
      cout << "Error opening output file PrimeOut.txt";
   }
   cout << endl;
   OutputFile.close();
   return 0;
} // end function main
