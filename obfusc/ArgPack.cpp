#include "ArgPack.h"
#include "getopt.h"

ArgPack::ArgPack(int argc, char *const argv []) :
	output(""),
	isError(false),
	isOutputBAfile(false),
	isObfuscateConstant(false),
	isObfuscateString(false),
	isObfuscateIdentifier(false),
	isRemoveTypeset(false),
	isNotObfuscateFile(false),
	isObfuscateLoopStatement(false),
	isObfuscateControlFlow(false),
	isTYPE_NAMEFile(false)
{
	char c;
	int err = 0;
	string tmp;
	while ( (c = getopt(argc, argv, "o:t:csmlki:n:y:p:")) != EOF)
	{
		switch (c)
		{
			case 'o':
				output = optarg;
				break;
			case 't':
				isOutputBAfile = true;
				baFile = optarg;
				break;
			case 'c':
				isObfuscateConstant = true;
				break;
			case 's':
				isObfuscateString = true;
				break;
			case 'm':
				isRemoveTypeset = true;
				break;
			case 'i':
				isObfuscateIdentifier = true;
				tmp = optarg;
				if ( tmp == "N" ) {
					IdentifierGenerator::get().idLookLike = IdentifierGenerator::LL_NORMAL;
				} else if ( tmp == "O0" ) {
					IdentifierGenerator::get().idLookLike = IdentifierGenerator::LL_O0;
				} else if ( tmp == "l1" ) {
					IdentifierGenerator::get().idLookLike = IdentifierGenerator::LL_l1;
				} else {
					IdentifierGenerator::get().idLookLike = IdentifierGenerator::LL_CUSTOM;
					// remove same char
					string table;
					bool isFind = false;
					for ( int i = 0; i < (int)tmp.size() - 1; i++ ) {
						char p = tmp[i];
						string t = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
						if ( t.find(p) == -1 ) {
							cout << "-i custom charactor table should [0-9a-zA-Z]" << endl;
							err++;
							break;
						}
						for ( int j = 0; j < (int)table.size() - 1; j++) {
							if ( table[j] == p ) {
								isFind = true;
								break;
							}
						}
						if ( !isFind ) {
							table += p;
						} else {
							cout << "-i custom charactor table can't has same charactor" << endl;
							err++;
							break;
						}
					}

					if ( table.size() < 2 ) {
						cout << "-i custom charactor table size can't < 2" << endl;
						err++;
					}
				}
				break;
			case 'n':
				isNotObfuscateFile = true;
				noFile = optarg;
				break;
			case 'l':
				isObfuscateLoopStatement = true;
				break;
			case 'k':
				isObfuscateControlFlow = true;
				break;
			case 'p':
				isTYPE_NAMEFile = true;
				typeNameFile = optarg;
				break;
			default:
				err++;
				break;
		}

	}
	//for (int index = optind; index < argc; index++)
 //        printf ("Non-option argument %s\n", argv[index]);
	if ( argc != optind + 1 ) {
		cout << "wrong count of args" << endl;
		err++;
	} else {
		input = argv[optind];
	}
	if ( input.empty() ) {
		
		err++;
	}
	if ( output.empty() && err == 0 ) {
		output = input + ".ob";
	}
	if ( err > 0 ) {
		useage(argv[0]);
		isError = true;
	}
}


ArgPack::~ArgPack(void)
{
}

void ArgPack::useage(char *proc)
{
	printf(
	"C Source Code Obfuscator(CSCO). By falcon. v1.0\n"
	"Useage: %s [-o output] [-t table] [-c] [-s] [-i METHOD] [-m] [-l] [-k] [-p type] [-n not] file\n"
	"Options:\n"
	"  -o FILE         Set output filename\n"
	"  -t FILE         Output before-after obfuscated table file\n"
	"  -c              Obfuscate constante number\n"
	"  -s              Obfuscate const string\n"
	"  -i METHOD       Obfuscate identifier.\n"
	"                     METHOD is one of: N, O0, l1, or a custom string\n"
	"                     N: normal charactor set. [0-9a-zA-Z]\n"
	"                     O0: use charactor [O0]\n"
	"                     l1: use charactor in [l1]\n"
	"                     [string]: use charactors in [[string]]\n"
	"  -m              Remove Typeset charactors.\n"
	"  -l              Obfuscate the loop statement.\n"
	"                  for, while, do while statement will be replace by if and goto.\n"
	"  -k              Obfuscate the Control Flow.\n"
	"  -p FILE         Input TYPE_NAME file.\n"
	"                  word in file will be considered as a TYPE_NAME,like int.\n"
	"  -n FILE         Input Not Obfuscate Identifier table\n"
	"                  FILE should (separate with a space or enter).\n"
	//"  -y FILE        Output Symbol table\n"
		, proc);
}