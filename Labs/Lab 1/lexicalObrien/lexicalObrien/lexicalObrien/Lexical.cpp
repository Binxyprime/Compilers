#include "Lexical.h"
#define FIRST_CHAR 0

/*****************************************************************
*	  Function: cLexical(string file)
*
*	  Purpose:  Initializes cLexical class
*
*         Entry:  string file is a file path used to create the
*				  string buffer.
*
*          Exit:  Returns after starting Analyze function
******************************************************************/
cLexical::cLexical(std::string file){ //constructor
	std::ifstream t(file);
	
	//copy file into buffer	
	std::string buffer((std::istreambuf_iterator<char>(t)), 
		std::istreambuf_iterator<char>());

	buffer += EOF; //apend end of file twice to account for some special cases
	buffer += EOF; 

	Display(buffer); //display file
	Analyze(buffer, FIRST_CHAR); //start cLexical analysis

	string keywords[26];

	//initialize keywords
	keywords[0] = "int";
	keywords[1] = "double";
	keywords[2] = "float";
	keywords[3] = "for";
	keywords[4] = "while";
	keywords[5] = "if";
	keywords[6] = "else";
	keywords[7] = "char";
	keywords[8] = "bool";
	keywords[9] = "break";
	keywords[10] = "return";
	keywords[11] = "private";
	keywords[12] = "public";
	keywords[13] = "protected";
	keywords[14] = "new";
	keywords[15] = "class";
	keywords[16] = "struct";
	keywords[17] = "true";
	keywords[18] = "false";
	keywords[19] = "switch";
	keywords[20] = "case";
	keywords[21] = "continue";
	keywords[22] = "default";
	keywords[23] = "virtual";
	keywords[24] = "void";
	keywords[25] = "enum";
}

cLexical::~cLexical(){ //destructor

}

/***********************************************************************
*	  Function: Analyze(string buffer, int index)
*
*	  Purpose:  Directs flow of tokenizing functions
*
*         Entry:  string buffer is the buffer containing the file to be 
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Analyze can call any of the tokenizing functions
*				  if EOF then it displays EOF message and returns
***********************************************************************/

void cLexical::Analyze(string buffer, int index){
	char c = buffer.at(index);

	if (c != EOF){
		if (isalpha(c) || c == '_') { //if character is a character (identifier)
			std::cout << "Analyze: <" << c << "> is alpha (a character), in place: [" << index << ']' << endl;
			isIdentifier(buffer, index);
		}
		else if (isdigit(c)) { //if character is an digit (number)
			std::cout << "Analyze: <" << c << "> is a digit, in place: [" << index << ']' << endl;
			isInteger(buffer, index);
		}
		else if (c == '+' ||
				 c == '-' ||
				 c == '/' ||
				 c == '%' ||
				 c == '*'){ //if character is a +,-,*,/,% (operator) 
			std::cout << "Analyze: <" << c << "> is an operator, in place: [" << index << ']' << endl;
			isOperator(buffer, index);
		}
		else if (c == '(' ||
			 	 c == ')' ||
				 c == '[' ||
				 c == ']' ||
				 c == ';' ||
				 c == '{' ||
				 c == '}') { //if character is (),[],{}, ; (symbol)
			std::cout << "Analyze: <" << c << "> is a delimiter, in place: [" << index << ']' << endl;
			isSymbol(buffer, index);
		}
		else if (c == '#') { //if character is #define, #include, etc. (directive)
			std::cout << "Analyze: <" << c << "> is a preprocessor directive, in place: [" << index << ']' << endl;
			isDirective(buffer, index);
		}
		else if (c == '<' ||
				 c == '>' ||
				 c == '=' ||
				 c == '!' ||
				 c == '|' ){ //Is a relational operator
			std::cout << "Analyze: <" << c << "> is a relational operator, in place: [" << index << ']' << endl;
			isRelational(buffer, index);
		}
		else if (c == '"'){ //is a string literal
			std::cout << "Analyze: <" << c << "> is a string literal, in place: [" << index << ']' << endl;
			isStringLiteral(buffer, index);
		}
		else if (c == ' ' ||
				 c == '\t' ||
				 c == '\n'){
			isWhiteSpace(buffer, index);
		}
	}
	else std::cout << "Analyzer: End of File" << endl;
	return;
}

/**********************************************************************
*	  Function: isIdentifier(string buffer, int index)
*
*	  Purpose:  Tokenizing function for idenifiers, examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into 
*				  Analyze(buffer, index)
**********************************************************************/
void cLexical::isIdentifier(string buffer, int index){
	string keywords[NUM_KEYWORDS];

	//initialize keywords
	keywords[0] = "int";
	keywords[1] = "double";
	keywords[2] = "float";
	keywords[3] = "for";
	keywords[4] = "while";
	keywords[5] = "if";
	keywords[6] = "else";
	keywords[7] = "char";
	keywords[8] = "bool";
	keywords[9] = "break";
	keywords[10] = "return";
	keywords[11] = "private";
	keywords[12] = "public";
	keywords[13] = "protected";
	keywords[14] = "new";
	keywords[15] = "class";
	keywords[16] = "struct";
	keywords[17] = "true";
	keywords[18] = "false";
	keywords[19] = "switch";
	keywords[20] = "case";
	keywords[21] = "continue";
	keywords[22] = "default";
	keywords[23] = "virtual";
	keywords[24] = "void";
	keywords[25] = "enum";
	
	string tempStr = "";
	int i = index;
	
	while (isalpha(buffer.at(i)) || buffer.at(i) == '_'){
		if (buffer.at(i) == EOF)
			break;
		tempStr += buffer.at(i);
		++i;
	}
	
	//if identifier is also a keyword
	for (int j = 0; j < NUM_KEYWORDS; ++j){
		if ( tempStr == keywords[j] ) {
			addToken('<' + keywords[j] + '>', tempStr);
			Analyze(buffer, i);
			return;
		}
	}

	addToken("<identifer>", tempStr);
	if(buffer.at(i) != EOF)
		Analyze(buffer, i);
}
/*************************************************************************
*	  Function: isRelation(string buffer, int index)
*
*	  Purpose:  Tokenizing function for relations, examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into
*				  Analyze(buffer, index)
************************************************************************/
void cLexical::isRelational(string buffer, int index){
	string tempStr;
	int i = index;
	int j = index + 1;
	char c = buffer.at(i);
	char c2 = buffer.at(j);

	switch (c){
		case '=':
			if (c2 == '=')
				tempStr = "==";
			else
				tempStr = '=';
			break;
		case '!':
			if (c2 == '=')
				tempStr = "!=";
			else
				tempStr = '!';
			break;
		case '<':
			if (c2 == '<')
				tempStr = "<<";
			else if (c2 == '=')
				tempStr = "<=";
			else
				tempStr = '<';
			break;
		case '>':
			if (c2 == '>')
				tempStr = ">>";
			else if (c2 == '=')
				tempStr = ">=";
			else
				tempStr = '>';
			break;
		case '|':
			if (c2 == '|')
				tempStr = "||";
			else
				tempStr = '|';
			break;
		default:
			std::cout << "error incorrect symbol in isRelational" << endl;
	}
	i += tempStr.length();
	addToken("<relational>", tempStr);
	Analyze(buffer, i);
}

/**************************************************************
*	  Function: isOperator(string buffer, int index)
*
*	  Purpose:  Tokenizing function for operators, examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into
*				  Analyze(buffer, index)
****************************************************************/
void cLexical::isOperator(string buffer, int index){// +,-,*,/,%
	string tempStr;
	int i = index;
	int j = index + 1;
	char c = buffer.at(i);
	char c2 = buffer.at(j);

	//if comment don't add it as a token, just move to the new line and return
	if (c == '/' && c2 == '/') {
		while (buffer.at(i) != '\n' && buffer.at(i) != EOF){
			++i;
		}
		++i;
		Analyze(buffer, i);
	}
	else {
		tempStr += buffer.at(i);
		++i;
		//std::cout << "Operator: at index ["<<i<<"] => " << tempStr << endl;
		addToken("<operator>", tempStr);
		if (buffer.at(i) != EOF)
			Analyze(buffer, i);
	}
}

/**************************************************************
*	  Function: isSymbol(string buffer, int index)
*
*	  Purpose:  Tokenizing function for symbols, examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into
*				  Analyze(buffer, index)
****************************************************************/
void cLexical::isSymbol(string buffer, int index){ // (),[],{}
	string tempStr;
	int i = index;
	tempStr += buffer.at(i);
	++i;
	//std::cout << "Symbol: at index [" << i << "] => " << tempStr << endl;
	addToken("<symbol>", tempStr);
	if(buffer.at(i) != EOF) 
		Analyze(buffer, i);
}

/**************************************************************
*	  Function: isInteger(string buffer, int index)
*
*	  Purpose:  Tokenizing function for integers, examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into
*				  Analyze(buffer, index)
****************************************************************/
void cLexical::isInteger(string buffer, int index){ // 0-9, allowed a single decimal
	string tempStr;
	string tokenType = "<integer> ";
	int i = index;

	while( isdigit(buffer.at(i)) ){
		tempStr += buffer.at(i);
		++i;
	}
	//std::cout << "Integer: at index [" << i << "] => " << tempStr << endl;
	addToken("<integer>", tempStr);
	if (buffer.at(i) != EOF)
		Analyze(buffer, i);
}

/**************************************************************
*	  Function: isDirective(string buffer, int index)
*
*	  Purpose:  Tokenizing function for preprocessor directives,
*				examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into
*				  Analyze(buffer, index)
****************************************************************/
void cLexical::isDirective(string buffer, int index){ //#define, #include, etc. # is its own token \n matters
	string tempStr;
	int i = index;
	
	while (buffer.at(i) != '\n' && buffer.at(i) != EOF){
		tempStr += buffer.at(i);
		++i;
	}
	addToken("<directive>", tempStr);
	++i;

	if (buffer.at(i) != EOF)
		Analyze(buffer, i);
}

/**************************************************************
*	  Function: isStringLiteral(string buffer, int index)
*
*	  Purpose:  Tokenizing function for string literals, examples in header
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*				  index is an int representing the index of the array
*
*          Exit:  Adds a token to the v_Tokens vector and then
*				  sends the buffer and new index back into
*				  Analyze(buffer, index)
****************************************************************/
void cLexical::isStringLiteral(string buffer, int index){
	string tempStr = "";
	int i = index;

	if (buffer.at(i) == '"'){
		tempStr += buffer.at(i);
		++i;
		while (buffer.at(i) != '"' && buffer.at(i) != EOF){
			tempStr += buffer.at(i);
			++i;
		}
		tempStr += '"';
		//std::cout << "isStringLiteral => at index[" << i << "] => " << tempStr << endl;
		i++;
	}
	addToken("<string literal>", tempStr);
	if (buffer.at(i) != EOF)
		Analyze(buffer, i);
}

void cLexical::isUnidentified(string buffer, int index){
	string tempStr;
	int i = index;
	tempStr += buffer.at(i);
	addToken("<unidentified>", tempStr);
	++i;
	if (buffer.at(i) != EOF)
		Analyze(buffer, i);
}

void cLexical::isWhiteSpace(string buffer, int index){
	char c = buffer.at(index);
	int i = index;
	i++;

	switch (c){
		case '\t': 
			std::cout << "WhiteSpace: tab character in place: [" << index << ']' << endl;
			break;
		case '\n': 
			std::cout << "WhiteSpace: newline character in place: [" << index << ']' << endl;
			break;
		case ' ':
			std::cout << "WhiteSpace: space character in place: [" << index << ']' << endl;
			break;
		default:
			std::cout << "WhiteSpace: unknown character here that was someone mistaken for white space" << endl;
			break;
	}
	
	Analyze(buffer, i); //dont have to check for EOF because this will only ever incriment by 1
}

/**************************************************************
*	  Function: Display(string buffer)
*
*	  Purpose:  Display file being tokenized
*
*         Entry:  string buffer is the buffer containing the file to be
*			      read, it is initialized in the constructor
*
*          Exit:  exits after display
****************************************************************/
void cLexical::Display( string buffer ){
	std::cout << endl << "**************Display File******************" << endl;
	std::cout << buffer << endl;
	std::cout << endl << "******************EOF***********************" << endl << endl;
}

/**************************************************************
*	  Function: addToken(string vToken)
*
*	  Purpose:  add a token to v_Token vector
*
*         Entry:  vToken is a string containing the token information
*
*          Exit:  exits after adding token to vector
****************************************************************/
void cLexical::addToken(string aType, string aName){
	listToken aToken;
	aToken.name = aName;
	aToken.type = aType;
	v_Tokens.push_back(aToken);
}

/**************************************************************
*	  Function: getvTokens()
*
*	   Purpose: return a token to v_Token vector
*
*        Entry: vToken is a string containing the token information
*
*         Exit: exits after returning vector
****************************************************************/
std::list<listToken> cLexical::getvTokens(){
	return v_Tokens;
}
