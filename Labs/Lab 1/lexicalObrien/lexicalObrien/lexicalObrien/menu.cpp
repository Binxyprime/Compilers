//Justin O'Brien
//menu.cpp

#include "menu.h"
#include <windows.h>
#include <iostream>
#include "Shlwapi.h"
#include <iomanip>

using namespace std;
string prompt();
void Display(std::list<listToken> tokens);
bool toExit();

//***************RunMenu******************/
void RunMenu(){
	bool exit = false;
	char choice = 0;
	string completePath;
	list<listToken> vtokens;

	while (exit == false){
		completePath = prompt(); //user enters file name to be analyzed
		
		cLexical Lex(completePath);  //Analyze the selected file for tokens
		vtokens = Lex.getvTokens(); //return all tokenized inputs

		Display(vtokens);
		
		exit = toExit();
	}
}

//Prompt user and return file path
string prompt(){
	std::string fileName;
	std::string name;
	std::string completePath;
	char choice;

	cin.clear();
	std::cout << "//-----------------------Menu-----------------------//" << std::endl;
	std::cout << "Would you like to test from the (d)efault path or user a (c)omplete path?" << std::endl;
	cin >> choice;

	if (choice == 'd'){
		std::cout << "Please select file to be analyzed(partial file path):" << std::endl;
		std::cout << "Premade text files are named as follows, these are located in the debug folder:" << std::endl;
		std::cout << "test1.txt" << std::endl;
		std::cout << "test2.txt" << std::endl;
		std::cout << "test3.txt" << std::endl;
		std::cin.clear(); //clear the buffer
		cin >> name; //to be appended to path

		//get file Path, found online at cplusplus
		TCHAR szEXEPath[2048];
		char actualpath[2048];
		GetModuleFileName(NULL, szEXEPath, 2048);
		for(int i = 0; szEXEPath[i] != 0; i++){
			actualpath[i] = szEXEPath[i];
		}
		cout << endl << endl;
		string path(actualpath);
		//find absolute path of this program and remove the program name from it to get working directory.
		completePath = path.substr(0, path.find_last_of("\\/")) + '\\'; //removes name of program from directory
		completePath += name; //appends user entered data
	}
	else if (choice == 'c'){
		std::cout << "Please select file to be analyzed(complete file path):" << std::endl;
		cin >> completePath;
	}
	return completePath;
}

void Display(list<listToken> tokens){
	//Display Tokens
	cout << endl << "********************ALL TOKENS**********************" << endl;
	for (std::list<listToken>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
		std::cout << setw(20) << left  << i->type << '\t' << left << i->name << endl;
	cout << endl << "****************************************************" << endl << endl;
}

bool toExit(){
	char choice;
	//Ask User if they would like to read another file or Exit the program
	std::cout << "Type (E) to exit, type any other key to run another file" << std::endl;
	std::cin.clear();
	std::cin >> choice;
	if (choice == 'e' || choice == 'E') return true; //exit while loop on choice 'e' or 'E'
	else return false;
}