#include "symbol.h"
#include <vector>

class symbolTable{
	public:
		symbolTable();
		~symbolTable();
		void addSymbol(symbol aSymbol);
		void removeSymbol(symbol aSymbol);
		std::vector<symbol> returnSymbols();
	private:
		std::vector<symbol> symbolsTable;
};