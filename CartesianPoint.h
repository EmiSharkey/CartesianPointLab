/** CartesianPoint.h
 *	
 *	In this example, we examine an updated class called CartesianPoint.
 *	- changed toString() to operator sting
 *	- changed getDistanceTo() to operator-
 *	- added IO operators
 *	- converted to a .h file
 *   
 *	@author		Thom MacDonald
 *	@version	2014.02
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		https://www.youtube.com/watch?v=w_bMeFFhEwY&hd=1
 *  @see		Classes.Cartesian.cpp - Classes and Objects Example Program for CPRG 3202. 
*/

#ifndef _CARTESIAN
#define	_CARTESIAN

#include <iostream>
#include <sstream>		// for stringstream
#include <cmath>		// for sqrt()

using namespace std;

// class declaration section
class CartesianPoint
{
  public:
  	/* Constructor: Used to initialize objects
	 *	- always the same name as the class
	 *	- never have a return type
	 *	- called automatically when an obj is instantiated
	 *	- should set values for each member variable
	 */
    CartesianPoint(int x = 1, int y = 1) : myX(x), myY(y) {}
	 
	/* Accessors: Used to query the state of the object
	 *	- never modifies the object
	 *	- should specify const at the end of the prototype/header
	 */    
	int getX() const {return myX;}
	int getY() const {return myY;}
	
	
	double operator-(CartesianPoint pointTo) const;  // get the 
 		   								// distance between this point
 		   								// and a second point
 		   								
	operator string() const; // convert the obj to a string.
	
	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/
	void setX(int x) { myX = x; }
	void setY(int y) { myY = y; }
	void setPoint(int x, int y){ setX(x); setY(y); }
	
	// IO Operator friends
	// IO Operator friends
	friend ostream& operator<< (ostream& out, const CartesianPoint& point);
	friend istream& operator>> (istream& in, CartesianPoint& point);	
	
  private: // private data members for the dimensions of the point
    int myX; // x-axis (horizontal) value
    int myY;  // y-axis (vertical) value
    
};

// Class defintion section

/** toString Method for CartesianPoint class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
CartesianPoint::operator string() const
{
	// declare a stringstream object
	stringstream strOut; 
	// build the string
	strOut << "(" << myX << ", " << myY << ")";
	// return the string
	return strOut.str();
}

/** getDistanceTo Method for CartesianPoint class
 *	Determines the distance between this point and a second point.
 *	@param	pointTo: CartesianPoint
 *	@return	the distance as a double
 */
double CartesianPoint::operator-(CartesianPoint pointTo) const 
{
    int xDelta = pointTo.myX - myX; // difference between x values
    int yDelta = pointTo.myY - myY; // difference between y values
    // return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
} 

// IO Operator friends
ostream& operator<< (ostream& out, const CartesianPoint& point)
{
	out << (string) point;
	return out;
}
istream& operator>> (istream& in, CartesianPoint& point)
{
	char deliminator;
	in >> deliminator >> point.myX >> deliminator >> point.myY  >> deliminator;
	return in;
}

#endif
