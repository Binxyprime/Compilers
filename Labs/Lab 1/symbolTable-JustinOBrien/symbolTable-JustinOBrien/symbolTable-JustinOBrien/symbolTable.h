#include "symbol.h"
#include <vector>
#include <list>
/*****************************************************************
* Author:				Justin O'Brien							 *
* Date Created:			01/14/2016								 *
* Last Modification Date: 01/14/2016							 *
* Lab Number:			Lab 1 CS 328							 *
* Filename:				symbolTable.h							 *
*																 *
* Overview:														 *
*	This program will add symbols to the symbolTable			 *
* Input:														 *
*	User defined symbols for use in compilers lab				 *
*																 *
* Output:														 *
*	The output of is a list of user defined symbols				 *
*																 *
*****************************************************************/
using namespace std;
class symbolTable{
	public:
		symbolTable();
		~symbolTable();
		void addSymbol(symbol aSymbol); //adds and edits a symbol.
		void removeSymbol(symbol aSymbol);
		std::list<symbol> returnList();
	private:
		std::list<symbol> symbolList;
};