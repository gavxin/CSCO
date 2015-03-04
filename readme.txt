1. 此工程是使用VS2010 RC版本建立的。
2. flex_bison目录下是，flex++与bison++，通过CLexer.l与CParser.y生成CLexer.h，CLexer.cc，CParser.h，CParser.cc的工具。

命令是：
cd $(ProjectDir)
..\flex_bison\bison++ -d  -o CParser.cc -h CParser.h CParser.y
..\flex_bison\flex++ -8 -hCLexer.h -oCLexer.cc CLexer.l

每次修改CLexer.l与CParser.y后，通过上述命令生成对应的头文件与代码文件。
（如果使用VS2010，此部分已经在工程设定里设定了，每次编译前会执行上面的命令，然后进行编译。）
