CC:=gcc
CFLAGS:=-Iinclude
CFLAGS+=-c


bin/main:obj/main.o obj/user_link.o obj/user_lottery.o obj/issue_link.o obj/view_contronal.o obj/view.o obj/game.o
	$(CC) -o $@ $^  
obj/%.o:src/%.c      
	gcc -o $@ $(CFLAGS) $^
	
.PHONY:clean  
clean:
	rm -rf obj/main.o obj/user_link.o obj/user_lottery.o obj/issue_link.o obj/view_contronal.o obj/view.o obj/game.o

# $@目标文件 $^全部依赖文件
#.PHONY:clean  防止重名记住大写
# make 默认makefile    如果文件名不是makefile 需要加-f指定文件
