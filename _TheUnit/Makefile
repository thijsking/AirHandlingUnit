CC = g++
CFLAGS = -g -Wall
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
LIBS = -I Include

all: $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@

clean:
	@rm -f $(OBJS)

print-%: ; @echo $*=$($*)
