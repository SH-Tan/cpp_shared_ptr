#定义各个文件夹的目录
DIR_INC = include
DIR_SRC = src
DIR_OBJ = obj
DIR_BIN = bin
 
#获取src目录下的所有cpp文件路径
SRC = $(wildcard ${DIR_SRC}/*.cpp)
#将上边的cpp全部转换为.o
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))
 
#最终的目标文件
TARGET = main
#目标文件目录/bin/main
BIN_TARGET = ${DIR_BIN}/${TARGET}
#使用g++编译
CC = g++
# -g调试选项 -wall输出警告 -I 包含的头文件目录
CFLAGS = -g -Wall -I ${DIR_INC}
 
#目标文件main,依赖/obj下的所有.o文件
${BIN_TARGET}:${OBJ}
	$(CC) $^ -o $@
 
#目标文件obj下的.o,依赖src文件下的.cpp -c是只编译不链接
${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@
 
.PHONY:clean
clean:
	rm -f /obj/*.o
	rm -f /bin/main