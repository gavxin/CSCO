#include "ONIdentifier.h"
#include "IdentifierGenerator.h"

ONIdentifier::ONIdentifier(void)
{
	srand((unsigned int)time(0));
}


ONIdentifier::~ONIdentifier(void)
{
}


// see the node type if it is the type which this class to obfuscate.
bool ONIdentifier::JudgeType(Node *node)
{
	if ( node->nodeType == Node::TOKEN
		&&  ( node->tokenId == CParser::IDENTIFIER || node->tokenId == CParser::TYPE_NAME ) ) {
		return true;
	}
	return false;
}
// main function. Obufuscator will call this function
void ONIdentifier::Action(Node *node)
{
	if ( !JudgeType(node) ) {
		return;
	}

	// Do not obfuscate Identifier which in the NotObfusIdTable
	if ( notObfusIdTable->hasId(node->tokenString) ) {
		return;
	}
	
	Symbol *s = symbolTable->findSymbol(node->tokenString);
	////  If Not found the symbol. do not obfuscate the symbol
	//if ( s == NULL ) {

	//	return;
	//}
	assert(s != NULL);
	// Do not obfuscate NOT defined Symbol.
	if ( s->isDeclared == false ) {
		return;
	}

	// If already obfuscated.
	if ( s->isObfusced == true ) {
		node->obfuscatedTokenString = s->nameAfterObfusc;
		node->isObfuscated = true;
	} else {
		// First Met the Symbol.
		beforeObfuscate = node->tokenString;
		// generate name until Not same
		string generated = IdentifierGenerator::get().Generate();
		while( symbolTable->isExistObfusc(generated) ) {
			generated = IdentifierGenerator::get().Generate();
		}

		afterObfuscated = generated;
		// set symbol.
		s->nameAfterObfusc = afterObfuscated;
		s->isObfusced = true;
		// set node
		node->obfuscatedTokenString = afterObfuscated;
		node->isObfuscated = true;
	}
	// save the records.
	recordTable->AddRecord(beforeObfuscate, afterObfuscated,
		node->first_line, node->first_column,
		node->last_line, node->last_column);
}

// generate a Identifier string.
string ONIdentifier::GenerateIdentifier()
{
	char firtable[]="_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char table[] = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12345678901234567890123456789012345678901234567890";
	char digTable[] = "0123456789";
	char Oo0Table[] = "Oo0";

	string result = "";
	int r;
	for (int i = 0 ;i < ID_LEN; i++ ) {
		if ( i == 0 ) {
			//r = rand() % strlen(firtable);
			//result += firtable[r];
			result += "O";
		} else {
			r = rand() % strlen(Oo0Table);
			result += Oo0Table[r];
		}
	}

	return result;
}