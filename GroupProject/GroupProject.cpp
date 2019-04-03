// GroupProject.cpp : Defines the entry point for the console application.
//Array manipulation program
//Takes a .dat file with a number of integers
//fills out an Array with them
//shows examples of what can be done with a simple integer array

#include "stdafx.h"

using namespace std;

int main()
{
	//load data from file
	ifstream infile("data.dat");
	ofstream outfile("output.dat");

	const int CONST_SIZE = 12; //length of anArray variable
	
	//variable declarations
	int anArray[CONST_SIZE], input, average;
	bool flag = false;

	//import data from data.dat to anArray
	for (int i = 0; i < CONST_SIZE; i++) 
	{

		
		infile >> anArray[i]; //input data into anArray

	}

	
	system("color 1F"); //change output visuals

	//menu loop
	do
	{

		//Variable Declarations
		int counter = 0, temp = anArray[0], total = 0, i = 0, j = CONST_SIZE - 1;

		//output menu main body
		cout << "\t\tPlease choose one of the following options:\n\n"
			<< "\t1) Show array\n"
			<< "\t2) Total\n"
			<< "\t3) Average\n"
			<< "\t4) Largest\n"
			<< "\t5) Smallest\n"
			<< "\t6) Occurrences of Value\n"
			<< "\t7) Scale Up\n"
			<< "\t8) Reverse\n"
			<< "\t9) Zero Base\n"
			<< "\t10) Exit\n\n";

		cout << endl << endl; //output formatting
		
		
		cin >> input; //input

		//the menu backbone code
		switch (input) 
		{
		
		case 1:

			cout << "\nThe array currently consists of: \n"; //output
				

			//outputs original array
			for (int i = 0; i < CONST_SIZE; i++) 
			{

				cout << anArray[i] << " "; //output of array

			}
			
			cout << endl << endl; //output formatting

			break; //end of case
		
		case 2:

			//go through array
			for (int i = 0; i < CONST_SIZE; i++) 
			{

				total = total + anArray[i]; // Calculate the Array

			}

			cout << "\nThe Sum of 12 Numbers in the array is: " << total << endl << endl; // Display the Result

			break;

		case 3:

											//Average	

			for (int i = 0; i < CONST_SIZE; i++) // iniatilize array

			{

				total = total + anArray[i]; // calculate the array contents

			}

			average = total / CONST_SIZE; // how to calculate average formula
								
			cout << "\nThe Average number in the array is: " << average << endl << endl; // Display the Result

			break; //end of case

		case 4:


			for (int i = 0; i < 12; i++) // initialise the array
			{

				// condition in array
				if (anArray[i] > temp) 
				{ 

					temp = anArray[i]; //save current value in temp

				}
			}

			cout << endl << "The largest number is: " << temp << endl << endl; // output the result

			break; //end of case

		case 5:

														//SMALLEST

			//using a variable with for loop to find the smallest value 
			for (int i = 1; i < CONST_SIZE; i++)
			{
				if (anArray[i] < temp)
				{
					temp = anArray[i];

				}
			}

			cout << "\nThe Smallest Number is: " << temp << "\n\n"; //Output the smallest number

			break; //end of case

		case 6:

														//OCCURANCES OF VALUE
			
			cout << "\nPlease pick a value in the collection: "; //User is asked to pick a number in the array

			cin >> input; //user input

			//For loop counts number of occurances
			for (int i = 0; i < CONST_SIZE; i++)
			{
				if (anArray[i] == input)
				{
					counter++;
				}
			}

			cout << "\nNumber of Occurances: " << counter << "\n\n"; //Number of occurances is outputted

			break; //end of case

		case 7:

														//SCALE UP

			cout << "\nPlease enter a scale up factor: "; //User is asked to input a number for scale up

			cin >> input; //user input

			//Variable inputted number is multiplied by the numbers of the array in the for loop
			for (int i = 0; i < CONST_SIZE; i++)
			{

				anArray[i] *= input; //updates the array

				cout << anArray[i] << "  "; //output results

			}

			cout << "\n\n"; //output formatting

			flag = true; //set flag to true

			break; //end of case

		case 8:

														//REVERSE

			//continue until the counters meet in the middle
			while(i < j) 
			{
				
				temp = anArray[i]; //store first value in array into temporary variable

				anArray[i] = anArray[j]; //overwrite value at first position with value at last position in array

				anArray[j] = temp; //overwrite value at last position with value from temp variable

				i++, j--; //increment counter values
			}

			cout << "\nThe reversed array is:\n"; //output

			//count loop going through each position in anArray
			for (int i = 0; i < CONST_SIZE; i++) 
			{

				cout << anArray[i] << " "; //outputs every value in anArray after reverse

			}

			cout << endl << endl; //format output

			flag = true; //set flag to true

			break; //end of case

		case 9:

														//ZERO BASE

			//count loop going through each position in anArray
			for (int i = 0; i < CONST_SIZE; i++)
			{

				//checks if value at current position is smaller than value in temp
				if (anArray[i] < temp)
				{

					temp = anArray[i]; //assigns value from anArray at current position to temp

				}

			}

			cout << "\nThe new array is:\n"; //output

			//count loop going through every position in anArray
			for (int i = 0; i < CONST_SIZE; i++)
			{

				anArray[i] -= temp; //lowers the value in each position of anArray by value of temp

				cout << anArray[i] << " "; //outputs every single value in anArray with a space after

			}

			cout << endl << endl; //output formatting

			flag = true; //flag set to true

			break; //end of case

		case 10:
												//EXIT

			//checks if flag is true
			if (flag)
			{

				//count loop going through each position in anArray saving it in output.dat file
				for (int i = 0; i < CONST_SIZE; i++)
				{

					outfile << anArray[i] << " "; //output data into output.dat file

				}
			}

			cout << endl; //output formatting
			
			return 0; //exit program

		default:

												//ERROR

			cout << "\nOnly number between 1 and 10 are acceptable.\nTry again.\n\n"; //error message

		}
		
	} while (input != 10); //loops until option 9 is chosen
}

