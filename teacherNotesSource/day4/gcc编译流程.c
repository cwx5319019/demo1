/*
	demo.c
	预处理阶段:gcc -E demo.c -o demo.i
		1:展开头文件
		2:简单宏替换
		3:去注释，注释有两种形式
			1/ 行注释，使用，//代表这一行的代码都属于注释
			2/ 段注释，使用/**/，被/*扩起来的所有代码都属于注释

		4:上标记，为每一行的代码，标记上他在源文件中的行号
	编译阶段: gcc -S demo.c -o demo.s
		从预处理开始，只做到编译阶段
		编译阶段是整个编译过程的核心阶段，他会分析代码的词义，语义及语法结构，如果发现任何错误，都会终止编译，并且抛出错误。所以，整个编译过程中，只有编译阶段，会出现错误
		编译阶段会将语法正确的代码编译成汇编语言。汇编语义是一个指针针对内存操作的语言。系统底层的，几个操控驱动的函数，都是由汇编语言直接写成的。
	汇编阶段:gcc -c demo.s -o demo.o
		从预处理开始执行，只执行到汇编阶段
		所有库函数，我们ubuntu中是找不到源码的，因为所有的库函数都是以.o二进制文件的形式存在于库文件当中
		将汇编语言汇编成计算机能够识别的二进制语言
	链接阶段：gcc demo.o -o demo(可执行文件)
		将.o二进制文件，链接上动态库与静态库(包含了绝大部分的库函数的.o文件)
	举例来说：一个简单的程序的.o文件大小在1.2kb左右，但是生成的可执行文件有8.6kb左右，这多出来的7.4kb就是链接的动态库与静态库
	某一些库函数，他的库在编译阶段并不会默认链接到当前.o文件，此时，在编译的时候必须手动链接，在编译的最后加上 -l库名
	如何自己封装库文件:使用shell指令:ar crv lib库名.a + 等待封装的.o文件，如果有多个.o文件封装在一个库中，使用空格隔开
	库名为a的情况下
	也就是: ar crv liba.a -o demo.o
*/
