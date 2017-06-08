CC = g++
CFLAGS = -g -Wall
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
EXTOBJS = $(wildcard ../_TheUnit/src/*.o)
LIBS = -I Include -I ../_TheUnit/Include

all: unit

unit: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS) $(EXTOBJS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f unit

print-%: ; @echo $*=$($*)
