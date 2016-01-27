#pragma once
// preProcessor.h
// Justin O'Brien
// changes #define SYMBOL VALUE in the symbol table.
#include <string>
#include <iostream>
#include "symbolTable.h"
#include "lexical.h"

using namespace std;
class preProcessor {
	public:
		preProcessor(list<listToken> tokenList);
		~preProcessor();
		void failure(std::string msg);
		void run();
		symbolTable getTable();
	private:
		symbolTable table;
};