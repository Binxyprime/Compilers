#include "stdafx.h"

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
*	The output of is a list of user defined symbols				 *
*																 *
*****************************************************************/

symbolTable::symbolTable(){

}

symbolTable::~symbolTable(){

}

void symbolTable::addSymbol(symbol aSymbol){
	if (symbolList.size()){
		for (std::list<symbol>::iterator iterator = symbolList.begin(); iterator != symbolList.end(); ++iterator){
			if (iterator->name == aSymbol.name && iterator->type == aSymbol.type && iterator->use == aSymbol.use){
				iterator->value = aSymbol.value;
				return;
			}
		}
	}
	symbolList.push_back(aSymbol);
}

std::list<symbol> symbolTable::returnList(){
	return symbolList;
}

void symbolTable::removeSymbol(symbol aSymbol){
	 
	if (symbolList.size()){
		std::list<symbol>::iterator iterator2 = symbolList.begin();
		for (std::list<symbol>::iterator iterator = symbolList.begin(); iterator != symbolList.end(); ++iterator){
			if (iterator->name == aSymbol.name && iterator->type == aSymbol.type && iterator->use == aSymbol.use && iterator->value == aSymbol.value){
				iterator = symbolList.erase(iterator);
				return;
			}
		}
		cout << aSymbol.name << " is not in symbol table" << endl;
	}
	else cout << "symbol table is empty" << endl;
}