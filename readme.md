# C Source Code Obfuscator(CSCO) 
by 4con. v1.0

此软件为混淆C语言（C89）源代码级的混淆器，是本人在大学时的小作品。
此软件输入为一个C语言源代码文件，输出为一个经过混淆后的C语言源代码文件。
混淆后的C语言源代码文件可以正常编译，程序功能与混淆前一样。

支持的功能

- 名称变换功能，可自定义要混淆的内容：常量数值、常量字符串、标识符。
- 循环语句混淆功能。
- 控制流混淆功能，可以将顺序执行的代码语句位置打乱。
- 自动分辨可混淆标识符，导入的函数与变量不会进行混淆。
- 可自定义混淆时使用的字符。
- 可自定义不想混淆的标识符。
- 可以参考并自行添加新的混淆功能。

尚未支持功能（很久以后可能也不支持 XD）

- C语言预处理相关部分不能混淆，暂时只支持对#define的混淆。
- 不支持同时对多个文件的混淆。

## Design & Code

（有些年头了，可能记不得很多细节。）

1. C语言源文件输入会经过flex bison作为词法语法分析器（lex/yacc的C++版）进行词法语法分析。
词法分析主要用于分辨标识符的类型，通过词法分析功能可以实现名称变换混淆功能。
语法分析功能支持了更进一步的循环与控制流的混淆，也能够自动分辨可混淆标识符。

2. 经过语法分析后，会构建AST抽象语法树与符号表。通过符号表可以对标识符进行混淆。
通过语法树遍历，并找到特定的语法节点后（如循环或顺序结构），对节点进行混淆替换，
最后能够得到语法上的混淆效果。

简单代码说明：
- CLexer.l/CParser.y为词法/语法文件，可以使用flex++/bison++进行编译生成对应代码文件CLexer.h/CLexer.cc/CParser.h/CParser.cc。
- CAnalys是分析器类，结合了词法分析与语法分析功能。
- Node表示抽象语法树节点。Symbol表示标识符，SymbolTable为符号表。
- 由ON开始的文件名对应某种混淆功能，如ONString.h/ONString.cpp里是对常量字符串的混淆。

## Build

1. 此工程是使用VS2010 RC版本建立的。
2. flex_bison目录下是，flex++与bison++，通过CLexer.l与CParser.y生成CLexer.h，CLexer.cc，CParser.h，CParser.cc的工具。

命令是：
cd $(ProjectDir)
..\flex_bison\bison++ -d  -o CParser.cc -h CParser.h CParser.y
..\flex_bison\flex++ -8 -hCLexer.h -oCLexer.cc CLexer.l

每次修改CLexer.l与CParser.y后，通过上述命令生成对应的头文件与代码文件。
（如果使用VS2010，此部分已经在工程设定里设定了，每次编译前会执行上面的命令，然后进行编译。）

## Usage

```
Useage: obfusc.exe [-o output] [-t table] [-c] [-s] [-i METHOD] [-m] [-l] [-k] [
-p type] [-n not] file
Options:
  -o FILE         Set output filename
  -t FILE         Output before-after obfuscated table file
  -c              Obfuscate constante number
  -s              Obfuscate const string
  -i METHOD       Obfuscate identifier.
                     METHOD is one of: N, O0, l1, or a custom string
                     N: normal charactor set. [0-9a-zA-Z]
                     O0: use charactor [O0]
                     l1: use charactor in [l1]
                     [string]: use charactors in [[string]]
  -m              Remove Typeset charactors.
  -l              Obfuscate the loop statement.
                  for, while, do while statement will be replace by if and goto.

  -k              Obfuscate the Control Flow.
  -p FILE         Input TYPE_NAME file.
                  word in file will be considered as a TYPE_NAME,like int.
  -n FILE         Input Not Obfuscate Identifier table
                  FILE should (separate with a space or enter).

```

```
中文参数说明：
-o FILE 输出文件名称
-t FILE 输出标识符的混淆前后对比表文件名
-c 数值常量混淆
-s 字符串常量混淆
-i METHOD 标识符重命名
-m 去除格式以及注释
-l 循环变换成if与goto的结构
-k 顺序结构变换
-p FILE 输入存储类型名称列表文件
-n FILE 输入不混淆标识符列表文件
```

## Result example （PART）

used flag -csmlk -i O0

before:
```
int partition(int low, int high) 
{
	int tmp,pivotkey;
	tmp = array[low];
	pivotkey = array[low];
	while (low < high) 
	{
		while (low < high && array[high] >= pivotkey) 
			--high;
		array[low] = array[high];
		while (low < high && array[low] <= pivotkey) 
			++low;
		array[high] = array[low];
	}
	array[low] = tmp;
	return low;
}
```

after:
```
int OOO000OO(int OO0OOO00,int O000OO0O){int OO000O0O,OOOOO0O0;OO000O0O=OOOO0000[OO0OOO00];OOOOO0O0=OOOO0000[OO0OOO00];O00O000O:if(!(OO0OOO00<O000OO0O))goto O0OO0O0O;{O0O0000O:if(!(OO0OOO00<O000OO0O&&OOOO0000[O000OO0O]>=OOOOO0O0))goto O0O0OOO0;--O000OO0O;goto O0O0000O;O0O0OOO0:;OOOO0000[OO0OOO00]=OOOO0000[O000OO0O];O000OOOO:if(!(OO0OOO00<O000OO0O&&OOOO0000[OO0OOO00]<=OOOOO0O0))goto OOOO00O0;++OO0OOO00;goto O000OOOO;OOOO00O0:;OOOO0000[O000OO0O]=OOOO0000[OO0OOO00];}goto O00O000O;O0OO0O0O:;OOOO0000[OO0OOO00]=OO000O0O;return OO0OOO00;}
```

## License

MIT License.
