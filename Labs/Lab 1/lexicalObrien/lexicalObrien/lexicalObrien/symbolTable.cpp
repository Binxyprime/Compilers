#include "symbolTable.h"

/*****************************************************************
* Author:				Justin O'Brien							 *
* Date Created:			01/14/2016								 *
* Last Modification Date: 01/14/2016							 *
* Lab Number:			Lab 1 CS 328							 *
* Filename:				symbolTable.cpp							 *
*																 *
* Overview:														 *
*	This program will add symbols to the symbolTable			 *
* Input:														 *
*	User defined symbols for use in compilers lab				 *
*																 *
* Output:														 *
*	The output of is a vector of user defined symbols			 *		 											 
*																 *
*****************************************************************/


symbolTable::symbolTable(){

}

symbolTable::~symbolTable(){

}

void symbolTable::addSymbol( symbol aSymbol ){
	int i = symbolsTable.size();

	for (i; i >= 0; i--){
		//if symbol exists in table already then change the value.
		if (symbolsTable[i].name == aSymbol.name && symbolsTable[i].type == aSymbol.type && symbolsTable[i].use == aSymbol.use){
			symbolsTable[i].value = aSymbol.value;
			return;
		}
	}
	symbolsTable.push_back(aSymbol);
}

std::vector<symbol> symbolTable::returnSymbols(){
	return symbolsTable;
}

void symbolTable::removeSymbol( symbol aSymbol ){
	int i = symbolsTable.size();
	for (i; i >= 0; i--){
		if (symbolsTable[i].name == aSymbol.name && symbolsTable[i].type == aSymbol.type && symbolsTable[i].use == aSymbol.use && symbolsTable[i].value == aSymbol.value)
			symbolsTable.erase( symbolsTable.begin(), (symbolsTable.begin() + i) );
	}
}


