/*****************************************************************
* Author:				Justin O'Brien							 *
* Date Created:			01/14/2016								 *
* Last Modification Date: 01/14/2016							 *
* Lab Number:			Lab 1a CS 328							 *
* Filename:				symbolTable-JustinOBrien				 *
*																 *
* Overview:														 *
*	This program is a main used to test symbolTable.cpp			 *
* Input:														 *
*	User will enter a number to create multiple symbolnames		 *
*   user will then enter a number to remove from list.  user     *
*   can then write over symbol 5 to demonstrate changing the	 *
*   value in that special case.  Or after deleting it to add	 *
*   a single item.												 *
*																 *
* Output:														 *
*	The output of is a simple text display						 *
*																 *
*****************************************************************/


#include "stdafx.h"

using namespace std;

int main()
{
	//test cases
	symbolTable table;
	symbol aSymbol;

	string name = "symbolName";
	string type = "symbolType";
	string use = "symbolUse";
	string value = "symbolValue";
	
	int i = 0;
	int n = 0;
	cout << "enter a number for n" << endl;
	cin.clear();
	cin >> n;

	//add symbols to the table
	for (i; i < n; i++){
		aSymbol.name = (name + ' ' + to_string(i));
		aSymbol.type = (type + ' ' + to_string(i));
		aSymbol.use = (use + ' ' + to_string(i));
		aSymbol.value = (value + ' ' + to_string(i));

		table.addSymbol(aSymbol);
	}

	//display
	cout << "// ********************************************** //" << endl << endl;
	list<symbol> testList = table.returnList();
	if (testList.size()){
		for (std::list<symbol>::iterator iterator = testList.begin(); iterator != testList.end(); ++iterator){
			cout << iterator->name << ' ' << iterator->value << endl;
		}
	}
	cout << "// ********************************************** //" << endl << endl;

	cout << "enter a value to remove a symbol from the list" << endl << endl;
	cin.clear();
	cin >> i;
	
	aSymbol.name = (name + ' ' + to_string(i));
	aSymbol.type = (type + ' ' + to_string(i));
	aSymbol.use = (use + ' ' + to_string(i));
	aSymbol.value = (value + ' ' + to_string(i));

	table.removeSymbol(aSymbol);

	//display
	cout << "// ********************************************** //" << endl << endl;
	testList = table.returnList();
	if (testList.size()){
		for (std::list<symbol>::iterator iterator = testList.begin(); iterator != testList.end(); ++iterator){
			cout << iterator->name << ' ' << iterator->value << endl;
		}
	}
	cout << "// ********************************************** //" << endl << endl;

	cout << "Enter a number to change the value of 'symbolName 5'" << endl;
	cin.clear();
	cin >> i;

	aSymbol.name = (name + ' ' + to_string(5));
	aSymbol.type = (type + ' ' + to_string(5));
	aSymbol.use = (use + ' ' + to_string(5));
	aSymbol.value = (value + ' ' + to_string(i));

	table.addSymbol(aSymbol);

	//display
	cout << "// ********************************************** //" << endl << endl;
	
	testList = table.returnList();
	if (testList.size()){
		for (std::list<symbol>::iterator iterator = testList.begin(); iterator != testList.end(); ++iterator){
			cout << iterator->name << ' ' << iterator->value << endl;
		}
	}
	cout << "// ********************************************** //" << endl << endl;
	
	cout << "Any key to exit" << endl;
	std::cin.clear();
	std::cin.get();
	std::cin.clear();
	std::cin.get();

	
	return 0;
}

