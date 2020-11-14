G:=gcc    # := 类似起一个别名 使用的时候前面加上$标记符号
TARGET:=bin/main
DEPEND:=obj/main.o
DEPEND+=obj/userLink.o #在原有的模块上继续加一个 

#新加模块直接在这里添加就ok了，别的地方基本不需要改动

FLAGS:=-Iinclude
FLAGS+=-c


$(TARGET):$(DEPEND)
	$G -o $@ $^
obj/%.o:src/%.c
	$G -o $@ $(FLAGS) $^



.PHONY:clean
clean:
	rm -rf obj/*  #定义执行的代码

# $@是目标文件 $^全部依赖文件
#.PHONY:clean  防止文件里有clean名字的文件，记住大写
#clean:  如果想要重新编译，就使用shell指令 make clean 先删除之前编译好的代码，会调用之前定义的代码
# make 默认makefile    如果文件名不是makefile 需要加-f指定文件如 make -f makefile2






