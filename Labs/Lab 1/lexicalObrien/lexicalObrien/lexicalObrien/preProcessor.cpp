#include "preProcessor.h"

preProcessor::preProcessor(list<listToken> tokenList){
	// for each token in tokenList
	// add it to table
	symbol aSymbol;
	for (std::list<listToken>::const_iterator i = tokenList.begin(); i != tokenList.end(); ++i){
		aSymbol.type = i->name; //change listToken to be a symbol?
		aSymbol.value = i->type;
		table.addSymbol(aSymbol);
	}
}

preProcessor::~preProcessor(){

}

void preProcessor::failure(std::string msg){
	std::cout << "Failure: " << msg << endl;
	std::cout << "press any key to exit" << endl;
	cin.clear();
	cin.get();
	exit(0);
}

void preProcessor::run(){
	// Search through table for #defines and handle them appropriately
	// call failure if something goes wrong.
}

symbolTable preProcessor::getTable(){
	return table;
}
