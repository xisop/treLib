
BIN = ../bin
INC = ../include
LIB = ../lib

CFLAG = -I$(INC) -g -pipe -W -Wall -pedantic -fPIC -Werror
OBJS = treArchive.o treClass.o treFileRecord.o treDataBlock.o md5.o
LIBS = -L$(LIB) -ltreLib -lz

all: $(BIN)/treDump $(BIN)/treBuild $(BIN)/testArchive \
	$(LIB)/libtreLib.so $(LIB)/libtreLib.a

$(LIB)/libtreLib.so: $(OBJS)
	$(CXX) -shared $(OBJS) -o $(LIB)/libtreLib.so

$(LIB)/libtreLib.a: $(OBJS)
	$(AR) cr $(LIB)/libtreLib.a $(OBJS)

$(BIN)/testArchive: testArchive.cpp $(LIB)/libtreLib.a
	$(CXX) $(CFLAG) testArchive.cpp $(LIBS) -o $(BIN)/testArchive

$(BIN)/treDump: treDump.cpp $(LIB)/libtreLib.a
	$(CXX) $(CFLAG) treDump.cpp $(LIBS) -o $(BIN)/treDump

$(BIN)/treBuild: treBuild.cpp $(LIB)/libtreLib.a
	$(CXX) $(CFLAG) treBuild.cpp $(LIBS) -o $(BIN)/treBuild

treClass.o: treClass.cpp $(INC)/treLib/treClass.hpp \
	$(INC)/treLib/treFileRecord.hpp
	$(CXX) $(CFLAG) -c treClass.cpp -o treClass.o

treArchive.o: treArchive.cpp $(INC)/treLib/treArchive.hpp \
	$(INC)/treLib/treClass.hpp
	$(CXX) $(CFLAG) -c treArchive.cpp -o treArchive.o

treFileRecord.o:  treFileRecord.cpp $(INC)/treLib/treFileRecord.hpp
	$(CXX) $(CFLAG) -c treFileRecord.cpp -o treFileRecord.o

treDataBlock.o:  treDataBlock.cpp $(INC)/treLib/treDataBlock.hpp
	$(CXX) $(CFLAG) -c treDataBlock.cpp -o treDataBlock.o

md5.o:  md5.c $(INC)/md5.h
	$(CXX) $(CFLAG) -c md5.c -o md5.o

clean:
	rm -f *.o *~ $(LIB)/*.so $(LIB)/*.a $(BIN)/*
