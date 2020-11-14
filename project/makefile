objects=obj/adminIndex.o obj/limitIO.o obj/login.o obj/lotteryOp.o obj/main.o \
obj/menu.o obj/mineSweeper.o obj/myLotteryOp.o obj/runLottery.o obj/userIndex.o \
obj/userOp.o obj/workerIndex.o

bin/a.out:$(objects)
	gcc -Iinclude $(objects) -o bin/a.out -Wall
obj/adminIndex.o:src/adminIndex.c include/adminIndex.h
	gcc -Iinclude -c src/adminIndex.c -o obj/adminIndex.o -Wall
obj/limitIO.o:src/limitIO.c include/limitIO.h
	gcc -Iinclude -c src/limitIO.c -o obj/limitIO.o -Wall
obj/login.o:src/login.c include/login.h
	gcc -Iinclude -c src/login.c -o obj/login.o -Wall
obj/lotteryOp.o:src/lotteryOp.c include/lotteryOp.h
	gcc -Iinclude -c src/lotteryOp.c -o obj/lotteryOp.o -Wall
obj/main.o:src/main.c
	gcc -Iinclude -c src/main.c -o obj/main.o -Wall
obj/menu.o:src/menu.c include/menu.h
	gcc -Iinclude -c src/menu.c -o obj/menu.o -Wall
obj/mineSweeper.o:src/mineSweeper.c include/mineSweeper.h
	gcc -Iinclude -c src/mineSweeper.c -o obj/mineSweeper.o -Wall
obj/myLotteryOp.o:src/myLotteryOp.c include/myLotteryOp.h
	gcc -Iinclude -c src/myLotteryOp.c -o obj/myLotteryOp.o -Wall
obj/runLottery.o:src/runLottery.c include/runLottery.h
	gcc -Iinclude -c src/runLottery.c -o obj/runLottery.o -Wall
obj/userIndex.o:src/userIndex.c include/userIndex.h
	gcc -Iinclude -c src/userIndex.c -o obj/userIndex.o -Wall
obj/userOp.o:src/userOp.c include/userOp.h
	gcc -Iinclude -c src/userOp.c -o obj/userOp.o -Wall
obj/workerIndex.o:src/workerIndex.c include/workerIndex.h
	gcc -Iinclude -c src/workerIndex.c -o obj/workerIndex.o -Wall
clean:
	rm -f $(objects) ./bin/a.out
