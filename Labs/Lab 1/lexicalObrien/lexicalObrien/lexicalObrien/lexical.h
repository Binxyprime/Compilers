/************************************************************************
* Class: cLexical
*
* Constructors:
*	cLexical(file)
*		creates a string buffer that holds the contents of the file, displays them, then calls Analyze()
*
* Mutators:
*	void AddToken(string vToken)
*		adds a token to the vector of tokens
*
* Methods:
*	void Analyze(string buffer, int index)
*		uses the buffer from the constructor and an index to direct the various token functions.
*	void Display(string fileContents)
*		uses the buffer from file to display file
*	void isIdentifier(string buffer, int index)
*		adds an identifier token to the token vector and then sends the buffer along with a new index back to Analyze
*		ex int, main, cat, dog, arm
*	void isRelational(string buffer, int index)
*		adds an relational token to the token vector and then sends the buffer along with a new index back to Analyze
*		ex =, <=, ==, !=, &&
*	void isOperator(string buffer, int index)
*		adds an operator token to the token vector and then sends the buffer along with a new index back to Analyze
*		ex: *, /, -, +
*	void isStringLiteral(string buffer, int index)
*		adds a string literal token to the token vector and then sends the buffer along with a new index back to Analyze
*		ex: "string literal", "this is a231234123hdfj string"
*	void isSymbol(string buffer, int index)
*		adds a symbol token to the token vector and then sends the buffer along with a new index back to Analyze
*		ex: ;, ), (, }, [
*	void isDirective(string buffer, int index)
*		adds a directive token to the token vector and then sends the buffer along with a new index back to Analyze
*		ex: #define, #include
*************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include "listToken.h"
#include "symbolTable.h"

#define NUM_KEYWORDS 26 //number of hard coded keywords
using namespace std;

class cLexical{
	public:
		cLexical(std::string file);
		~cLexical();
		//Directs tokenizing functions
		void Analyze(string buffer, int index);
		//Deplays using cout to monitor
		void Display(string buffer);
		//Tokenizing functions
		void isIdentifier(string buffer, int index); //can being with a letter a-z or an underscore and
													 //can have any number of letters and underscores
													 //keywords are identifiers
		void isRelational(string buffer, int index); // =, ==, <=, >=, <, >, !=
		void isOperator(string buffer, int index);   // +,-,*,/,%
		void isSymbol(string buffer, int index);    // (),[],{}
		void isInteger(string buffer, int index);     // 0-9, allowed a single decimal
		void isDirective(string buffer, int index);  //#define, #include, etc. # is its own token \n matters
		void isStringLiteral(string buffer, int index); //beings and ends with a " mark
		void isUnidentified(string buffer, int index); //all other tokens
		void isWhiteSpace(string buffer, int index); //spaces tabs and newlines

		//Adds a token to v_Tokens vector
		void addToken(string aType, string aName); 
		//Returns the v_Tokens vector
		std::list<listToken> getvTokens();

	private:
		std::list<listToken> v_Tokens; //vector of tokens
		//string keywords[NUM_KEYWORDS]; //keywords
};


