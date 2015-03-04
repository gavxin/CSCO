#include "pre.h"

#include "CAnalys.h"
#include "Tree.h"
#include "CodeFile.h"
#include "Obfuscator.h"
#include "ONConstant.h"
#include "ONString.h"
#include "ONIdentifier.h"
#include "ONWhile.h"
#include "NotObfusIdTable.h"
#include "IdentifierGenerator.h"
#include "ArgPack.h"
#include "ONBlockItemList.h"
#include "ONDoWhile.h"
#include "ONFor.h"

using namespace std;


void main(int argc, char* argv[]) {
	try {
		CAnalys analys;
		ArgPack arg(argc,argv);
		if ( arg.isError ) {
			return;
		}
		CodeFile file(arg.input, arg.output, arg.isRemoveTypeset);
		if ( file.isError ) {
			return ;
		}
		// import type_name File
		if ( arg.isTYPE_NAMEFile ) {
			if ( !file.symbolTable->InputTYPE_NAMEFile(arg.typeNameFile) ) {
				throw "Error!";
			}
		}

		analys.setCurrentCodeFile(file);
		//analys.SetDebug(1);
		analys.Parse();

		IdentifierGenerator::get().SetSymbolNum(file.symbolTable->GetSize());
		
		// Read not obfuscate identifier file
		NotObfusIdTable noIdTable;
		if ( arg.isNotObfuscateFile ) {
			if ( !noIdTable.InputNotObfusIdFile(arg.noFile) ) {
				throw "Error!";
			}
		}

		// Obfuscator.
		Obfuscator obf(file,&noIdTable);
		if ( arg.isObfuscateConstant ) {
			obf.Register(new ONConstant());
		}
		if ( arg.isObfuscateIdentifier ) {
			obf.Register(new ONIdentifier());
		}
		if ( arg.isObfuscateString ) {
			obf.Register(new ONString());
		}
		if ( arg.isObfuscateLoopStatement ) {
			obf.Register(new ONWhile(arg.isRemoveTypeset));
			obf.Register(new ONDoWhile(arg.isRemoveTypeset));
			obf.Register(new ONFor(arg.isRemoveTypeset));
		}
		if ( arg.isObfuscateControlFlow ) {
			obf.Register(new ONBlockItemList(arg.isRemoveTypeset,arg.isObfuscateConstant));
		}

		obf.Obfuscate();

		// out put the output file.
		ofstream outfile(file.outputfilename);
		if ( !outfile ) {
			cerr << "Can't output file: \"" << file.outputfilename << "\"" << endl;
			throw "Can't output file";
		}
		outfile << file.Output() ;
		outfile.close();

		// output the before-after obfuscated table.
		if ( arg.isOutputBAfile ) {
			ofstream bafilestream(arg.baFile);
			if ( !bafilestream ) {
				cerr << "Can't output baFile: \"" << arg.baFile << endl;
				throw "baFile";
			}
			bafilestream << obf.PrintObfuscRecordTable(true);
			bafilestream.close();
		}

		/*cout<< "---------------------------" << endl
			<< file.Output() << endl
			<< "---------------------------" << endl;*/

		//cout<< "---------------------------" << endl
		//	<< analys.getCurrentTree()->ToCodeTree() << endl
		//	<< "---------------------------" << endl;
		
		/*cout<< "---------------------------" << endl
			<< analys.getCurrentSymbolTable()->PrintSymbolTable() << endl
			<< "---------------------------" << endl;*/

		//cout<< "---------------------------" << endl
		//	<< analys.getCurrentTree()->ToCode() << endl
		//	<< "---------------------------" << endl;

		//cout<< "---------------------------" << endl
		//	<< analys.getCurrentTree()->ToSourceCode(true) << endl
		//	<< "---------------------------" << endl;
		//
		/*cout<< "---------------------------" << endl
			<< obf.PrintObfuscRecordTable(true) << endl
			<< "---------------------------" << endl;*/

		
		

		//string after;
		//strstream strm;
		//strm.setf(ios::showbase | ios::uppercase);
		//strm << std::hex << 1234 << endl;
		//strm >> after;

		//string s = "'0f'";
		//double a;
		//strm.clear();
		//strm << s;
		//strm >> a;

		//printf("-------%d--------",(int)s[1]);
		//

		//cout<< "---------------------------" << endl
		//	<< a << endl
		//	<< "---------------------------" << endl;
		//int a;


		//// 4debug
		//CAnalys analys2;
		//analys2.Parse();
		cout << "Success! Please see the file " << file.outputfilename << endl ;
	} catch (string e) {
		cout << e << endl;
		return;
	}
}
