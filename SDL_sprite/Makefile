CC=gcc
CFLAGS = -Wall -g $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image
OUTPUT_DIR = output

all: $(OUTPUT_DIR)/main clean run

$(OUTPUT_DIR)/main: main.o
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) main.o -o $(OUTPUT_DIR)/main $(LDFLAGS)

clean:
	rm ./*.o

run:
	./$(OUTPUT_DIR)/main