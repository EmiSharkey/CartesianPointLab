/** Lab6.cpp
 *	
 *   
*	@author:		Emilie Sharkey & Sophia Wajdie
 *	@date:			November 30, 2015
 *	@description:	A C++ program created as a lab 6 submission for OOP-3200. 
 *					This program uses a standard template library (STL) called std::map 
 *					that impliments the processing for stored data from a text file.
 *					A user can enter Cartesian points which will be labeled and saved into
 *					a data file and report to the user the number of pints and the total
 *					distance between them from start to end.
 *
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		https://www.youtube.com/watch?v=w_bMeFFhEwY&hd=1
 *  @see		Classes.Cartesian.cpp - Classes and Objects Example Program for CPRG 3202. 
 *  @see		https://www.youtube.com/watch?v=kiqqxuu1gRk
 *  @see		http://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
 *  @see		https://www.youtube.com/watch?v=lzxWNtjii8U
 *  @see		http://www.cplusplus.com/reference/fstream/ifstream/
 *  @see		http://www.cplusplus.com/reference/string/string/getline/  
 *  @see		https://www.youtube.com/watch?v=POYRev0zk2k
 *  @see		http://www.programmingforums.org/post71311.html
 *  @see		http://stackoverflow.com/questions/4826404/getting-first-value-from-map-in-c 
 *  @see		http://www.cplusplus.com/doc/tutorial/exceptions/
 *  @see		http://www.cplusplus.com/reference/vector/vector/end/

*/

#include <iostream>		 
#include <stdio.h>	
#include <stdlib.h>	
#include <map>
#include <string>
#include <fstream>

#include "CartesianPoint.h"

using namespace std;

int main() 
{	

	/********************
	CONSTANT DECLARATIONS
	*********************/
	
	//Declare constant for prompt message
	const string USER_PROMPT_LABEL = "\n\nEnter the label of the point you wish to go to (\"quit\" to end): "; 
	//Declare constant for prompt message
	const string USER_PROMPT_FILE = "\nEnter the file name storing the cartesian point(s) and their respected label(s): "; 	
	//Declare constant for exit message
	const string EXIT = "quit"; 
	//Declare constant for message
	const string SUCCESS_FILE_POINTS = "\nThe maps contains ";
	//Declare constant for message
	const string SUCCESS_INPUT = "\n\nThe distance between ";
	//Declare constant for error message
	const string NO_DATA = "The map is empty. Check that the file contains valid data in the correct format.\n\n"; 
	//Declare constant for error message
	const string NO_LABEL_1 = "\nThere is no point labelled \"";
	//Declare constant for error message
	const string NO_LABEL_2 = "\" in the map.";
	//Declare constant for error message
	const string RUN_TIME_ERROR = "An error occurred at run-time: ";
	//Declare constant for error message
	const string NO_FILE = " could not be opened for input. Check that the file exists.\n\n";
	//Declare constant for minimum number of points
	const int MINIMUM_NUMBER_OF_POINTS = 1;
	
	
	/******************************
		VARIABLE DECLARATIONS
	*******************************/	

	//Declare integer variable for the total number of initial points
	int numberPoints = 0 ; 
	//Declare string variable for the number of inputted points
	string inputtedPoint = "";	
	//Declare string variable to store the data file's name
	string fileName = "";	
	//Declare string variable to store line
	string line ;
	//Declare string variable for the first point
	string pointFirst = "";
	//Declare string variable for the second point
	string pointSecond = "";
	//Declare string variable for the conditional label
	string labelGoTo = ""; 
	//Declare string variable for the first element 
	string firstElement  = "";
	//Declare double variable to set intial distance points
	double distancePoints = 0 ;  
	//Declare string variable to set blank label variable
	string label;  
	//Declare STL map to hold labels and Cartesian points and save the points
	map<string, CartesianPoint> mapCartesianPoint ; 
	//Declare STL map to hold labels and Cartesian points and save the points
	map<string, CartesianPoint> calculation ; 
 	//Declare double variable for the intial distance between points from start to end
	double distanceBetweenPoints = 0; 
 	//Declare string variable to store the last element
	string lastElement = "";
	//Declare double variable to store total distance between points
	double totalDistance = 0;
 	
	 /********************
			PROCESS
	*********************/		

//Start a try-catch statement for user input and console customization
 try
 {
 		
	/********************
			OUTPUT
	*********************/	

	//Changes the color of the console's text and background 
	system("color 57");

	//Prompts user to input the file name storing the labels and the cartesian points to be read
	cout << USER_PROMPT_FILE;  
 
	/********************
			INPUT
	*********************/		

	//Stores user specified file name into variable fileName as a string
	cin >> fileName; 
	
	/********************
			PROCESS
	*********************/			

	//readFile is created as an object used to open up fileName
	ifstream readFile(fileName.c_str());
	
	//If readFile can be opened 
	if(readFile.is_open())
	{
			//Stores each line within label until readFile end has been reached 
			while (!(readFile.eof()))  
			{	
				readFile >> label;
				
				readFile >> mapCartesianPoint[label];
			}
		
		//Close the object readFile
		readFile.close();
		  map<string, CartesianPoint>::const_iterator calculation = mapCartesianPoint.begin();
		   map<string, CartesianPoint>::const_iterator end = mapCartesianPoint.end();
		   
	
	/*	for (calculation = mapCartesianPoint.begin(); calculation != mapCartesianPoint.end); mapCartesianPoint++ )
		{
				calculation->first; 
				calculation->second; 
		}*/
		 
		 //If the numberPoints is not empty
		if (mapCartesianPoint.size() >= MINIMUM_NUMBER_OF_POINTS)
		{

			//Collect all the coordinates from the beginning of the first iteration
			map<string,CartesianPoint>::iterator firstIteration =  mapCartesianPoint.begin();
			
			//Collect all the coordinates from the seciond iteration
			map<string,CartesianPoint>::iterator secondIteration = ++firstIteration;
			
			//Use the overloading substraction operator 
			--firstIteration;
			
			//Iteratre the first and second iteration points and subtract each set to determine
			//the total distance between the points
			for(;secondIteration!=mapCartesianPoint.end();++secondIteration,++firstIteration)
			{
				totalDistance += (secondIteration->second-firstIteration->second);
			}
			    
			/********************
					OUTPUT
			*********************/		
			
			//Clear the console
			system("cls"); 
			
			//Output the number of Cartesian points and the total distance between them
			cout << SUCCESS_FILE_POINTS << mapCartesianPoint.size() << " points for a total distance of "  << totalDistance <<"."; 

			//Prompt the user for input
			cout <<  USER_PROMPT_LABEL;
			
			//Read the input and store it in the variable inputtedPoint
			cin >> inputtedPoint;
			 
			//If mapCartesianPoint.find(inputtedPoint) is not an actual element of mapCartesianPoint 
			if (!(mapCartesianPoint.find(inputtedPoint) == mapCartesianPoint.end()))
			{
				//The user inputted data is stored within firstElement to be used as the key indentifier for the first point
				firstElement = inputtedPoint;
			}
			
			//If user wants to exit
			else if (inputtedPoint == EXIT)
			{
					
			}
			//If the above conditions are not the case, then
			else 
			{
				//The first key for mapCartesianPoint is stored within firstElement to be used as the 
				//key indentifier for the first point
				firstElement = mapCartesianPoint.begin()->first;
				
				//Display that there is no point on the map for the inputted point
				cout << NO_LABEL_1 << inputtedPoint << NO_LABEL_2;
			}
			
			
			/********************
					PROCESS
			*********************/			
				
			//If the input does not match the exit prompt string reloop
			while(inputtedPoint != EXIT)
			{
				
				//Prompts user to input the label regarding the point they would like to enter
				cout << USER_PROMPT_LABEL;  
				
				//Stores user input into inputtedPoint
				cin >> inputtedPoint;  
				
				//If inputed point cannot be found on the map
				if(mapCartesianPoint.find(inputtedPoint) == mapCartesianPoint.end())
				{
	 				/********************
						OUTPUT
					*********************/	
					 
					//User is prompted to enter in a valid label 
					 cout << NO_LABEL_1 << inputtedPoint << NO_LABEL_2; 
					
				}
			 	//If user wants to exit
				else if (inputtedPoint == EXIT)
				{
					
				}
			 
			 	//If user's input is valid and found on the map
				else
				{

				//Calculate the distance between the first point and inputted point
				distanceBetweenPoints = mapCartesianPoint[inputtedPoint]-mapCartesianPoint[firstElement];

				/********************
						OUTPUT
				*********************/		

				//Output the distance between the first point and the inputted point and its respective labels.
				cout << "The distance between " << firstElement << " " << mapCartesianPoint[firstElement] << " and "<< inputtedPoint << " " << mapCartesianPoint[inputtedPoint] 
					 << " is " << distanceBetweenPoints;

				}

			}	
				
		} 
		
		else 
		{
			//Displays error message to user specifying that no data has been found
			system("cls");
			cout << NO_DATA;
		}
	} 
	
	//If readFile cannot be opened 
	else
	{	
		//Clears console of previous output 
		system("cls"); 
		
		//Displays error message to user specifying that file does not exist 
		cout << fileName << NO_FILE;
	} 
} 

//Catch the standard exception
catch (const std::exception& e)
{
	//Clear the console
	system("cls");
	//Output the error for run time
	cout << RUN_TIME_ERROR << e.what() << endl << endl; 
}
return 0; 	 

}


