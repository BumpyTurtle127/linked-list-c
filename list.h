//--------------------------------------------------------------------------------------------------
//
//                                 Linked List by Arnav Revankar
//                                  Last Modified: May 8th 2024
//
//                      Available at github.com/BumpyTurtle127/linked-list-c
//
//--------------------------------------------------------------------------------------------------
//
//	Instructions for use:
//	
//		1) First create list using initializer as follows: List * <listname> = createList();
//		
//		2) Add Integers, Doubles, Characters, and Strings to the list using addInt(),
//		   addDouble(), addChar(), and addString(). Parameters are the data first, then a 
//		   pointer to the list.
//
//		   It is worth noting that a list can contain any format of data at any position.
//		   For instance, the first position could hold an integer, the second a string, and
//		   so on.
//
//		3) Insert data in a certain position in the list using insertInt(), insertDouble(), 
//		   insertChar(), and insertString(). Parameters are, first the data, second the 
//		   position in the list, and finally a pointer to the list. 0th position is at the 
//		   very beginning of the list. If you input a negative position, the data will not 
//		   insert. If you input a position larger than the current size of the list, the 
//		   space will be filled by empty nodes.
//
//		4) To delete a certain position in the list, use deletePos(). First parameter is 
//		   position as an integer, second is pointer to the list.
//
//		5) To delete all instances of a certain entry, use deleteInt(), deleteDouble(), 
//		   deleteChar(), or deleteString(). The parameter is the int, double, char, or 
//		   string to be deleted. All instances of the parameter in the list will be deleted.
//
//		6) To view the frequency of an entry, use freqInt(), freqDouble(), freqChar(), 
//		   or freqString(). The parameter is the int, double, char, or string to be counted, 
//		   followed by a pointer to a pointer to the list. For freqDouble(), the second 
//		   parameter specifies the acceptable variance from the first parameter (as a 
//		   double), and the third is the pointer to the list. Return value of each is the 
//		   number of times that the parameter shows up in the list.
//
//		7) To view a certain entry at a known position, use getInt(), getDouble(), 
//		   getChar(), or getString(). The first parameter is the position, and the second 
//		   is a pointer to the list. Return value is the entry. For getString(), the second 
//		   parameter is a pointer to a char, and the third is the pointer to the list.
//
//		8) To delete a list all together, use destroy(). Only parameter is a  pointer to 
//		   the list. All nodes will be deleted, leaving only the empty list.
//
//		9) Finally, display() will print all contents of the list, separated by commas.

#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
typedef struct node Node;

List * createList();

void addInt(int a, List * list);
void addDouble(double a, List * list);
void addChar(char a, List * list);
void addString(char * a, List * list);

void insertInt(int a, int pos, List * list);
void insertDouble(double a, int pos, List * list);
void insertChar(char a, int pos, List * list);
void insertString(char * a, int pos, List * list);

int deletePos(int pos, List * list);

void deleteInt(int a, List * list);
void deleteDouble(double a, double tol, List * list);
void deleteChar(char a, List * list);
void deleteString(char * a, List * list);

int freqInt(int a, int ** positions, List * list);
int freqDouble(double a, double tol, int ** positions, List * list);
int freqChar(char a, int ** positions, List * list);
int freqString(char * a, int ** positions, List * list);

int getInt(int pos, List * list);
double getDouble(int pos, List * list);
char getChar(int pos, List * list);
void getString(int pos, char ** entry, List * list);

void destroy(List * list);

void display(char * a, List * list);
