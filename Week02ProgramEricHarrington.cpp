/************************************************************************************
Week 02 Programming Assignment
Eric Harrington
*************************************************************************************
Write a program that prompts the user for the amount of cheese produced and then
calculates the number of containers required to hold the cheese (rounded up), the
cost of producing the number of containers, and the profit from producing the number
of containers.

1: Declare and initialize floating-point constants for the amount of cheese a container
can hold, for the cost of producing one container of cheese, and for the profit derived
from one container of cheese

2: declare and initialize a string for the title

3: declare and initialize an int variable to be used for title formatting

4: declare and initialize strings for output later in the program

5: declare a floating-point variable for the user's input and initialize it to zero

6: convert user's input to type int using static_cast and round it up by adding 0.5

7: declare an int variable and initialize it to the user's input to eliminate problems
with trailing zeros when user's input is converted to a string

8: declare and initialize two string variables and use concatenation to form one string
for each that will then be used in the output later

9: use iomanip to pause the program


************************************************************************************/
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// Step 1
const double cheeseContainer = 2.76;
const double containerCost = 4.12;
const double cheeseProfit = 1.45;

int main()
{
   // Step 2 
   string title = "Welcome to my Cheesy Program";
   //Step 3
   int titleSpacing = (100 - title.length()) / 2; //This value will help center the title while also keeping the number of rows used to 100

   //Step 4 
   string containerCount = "The number of containers to hold the cheese is: ";
   string costOutput1 = "The cost of producing ";
   string costOutput2 = " container(s) of cheese is: $";
   string profitOutput1 = "The profit from producing ";

   //The following string is redundant, but I've kept it for clarity later on
   string profitOutput2 = " container(s) of cheese is: $";

   //Step 5 
   double userInput = 0.0; 

   cout << setw(100) << right << setfill('*') << '*' << endl; 
   cout << setw(titleSpacing) << setfill('*') << '*' << setw(title.length()) << setfill('*') << title << setw(titleSpacing) << setfill('*') << '*' << endl;
   cout << setw(100) << right << setfill('*') << '*' << endl << endl;

   cout << "Please enter the total number of kilograms of cheese produced: ";

   cin >> userInput;

   //Step 6
   userInput = static_cast<int>(userInput / cheeseContainer + 0.5);

   //Step 7 
   int userInputString = userInput;

   cout << setw(containerCount.length()) << containerCount << setw(100 - containerCount.length()) << setfill(' ') << right << userInput << endl;
   
   //Step 8
   string costOutputString = costOutput1 + to_string(userInputString) + costOutput2; //This string is for formatting; it helps manage the number of rows used
   string profitOutputString = profitOutput1 + to_string(userInputString) + profitOutput2;//Same for this string

   //The following two output statement uses the concatenated strings for both the output and for determining the number of rows needed; as with the title output, the number of rows used is 100 
   cout << left << setw(costOutputString.length()) << costOutputString << setw(100 - costOutputString.length()) << setfill(' ') << right << fixed << showpoint << setprecision(2) << userInput * containerCost << endl;
   cout << left << setw(profitOutputString.length()) << profitOutputString << setw(100 - profitOutputString.length()) << right << userInput * cheeseProfit << endl; 

   //Step 9 
   system("pause");
    
    return 0;
}