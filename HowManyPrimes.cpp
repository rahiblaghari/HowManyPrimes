// Author:     Rahib R Laghari

// Description:
// This program will print out as many prime numbers as the user input specifies, starting from 2

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

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
