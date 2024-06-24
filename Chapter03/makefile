CC = g++ #GNU C++ Compiler
CFLAGS = -std=c++17 -Wall #Compiler:c++17 Standard with warnings
LDFLAGS = -lGLEW -lSDL2 -lSOIL -lglfw -lSDL2_image #Libraries

INCDIR = -I/usr/include/GLFW -I/usr/include/SDL2 #Include directories, Path to header Files.

SRCS = $(wildcard *.cpp) #All .cpp -> SRCS
OBJS = $(SRCS:.cpp=.o) #.cpp -> .o
EXEC = spaceship_game
ASSETDIR = Assets
TARGETDIR = build

all: assets $(EXEC)

#EXEC depends on OBJS
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(TARGETDIR)/$(EXEC) $(LDFLAGS) #-o flag -> place where it will be saved

#.cpp-> .o
.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@ #-c flag instructs compiler to compile the source code into object code without linking it -> .o

assets:
	@echo "Copying assets folder..."
	@mkdir -p $(TARGETDIR)/Assets #-p flag = parent -> recursive creation of directories
	@cp -r $(ASSETDIR)/* $(TARGETDIR)/Assets #copies recursively ASSETDIR into Assets

clean:
	rm -f $(OBJS) $(TARGETDIR)/$(EXEC)
	@echo "Cleaning up assets folder..."
	@rm -rf $(TARGETDIR)/Assets
#.Phony -> no files only executable
.PHONY: all clean assets
