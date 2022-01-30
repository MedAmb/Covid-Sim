CC = g++
CFLAGS = -Wextra -Wall -g


THIS_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
SRC_DIR  := $(THIS_DIR)src
INC_DIR  := $(THIS_DIR)inc

OBj_FILES = location.o mobility_model.o person.o ppmodel.o rwpmodel.o simulator.o ui.o


rebuild: clean all

all: $(OBj_FILES)
	@echo "Building Simulator"
	$(CC) -o Simulator.out $< $(CFLAGS) -I$(INC_DIR)

location.o : $(SRC_DIR)/location.cpp
		@echo "Compiling location.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

mobility_model.o : $(SRC_DIR)/mobility_model.cpp
		@echo "Compiling mobility_model.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

person.o : $(SRC_DIR)/person.cpp
		@echo "Compiling person.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

ppmodel.o : $(SRC_DIR)/ppmodel.cpp
		@echo "Compiling ppmodel.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

rwpmodel.o : $(SRC_DIR)/rwpmodel.cpp
		@echo "Compiling rwpmodel.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

simulator.o : $(SRC_DIR)/simulator.cpp
		@echo "Compiling simulator.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

ui.o : $(SRC_DIR)/ui.cpp
		@echo "Compiling ui.cpp"
		$(CC) -c $< -o $@ $(CFLAGS) -I$(INC_DIR)

clean:
	@echo "deleting intermediate files"
	rm *.o
 