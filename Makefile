CC=gcc

INCLUDES=-I ./include
LDFLAGS=-lpthread
CFLAGS=-c -Wall $(INCLUDES)

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g -ggdb -DDEBUG 
else
	CFLAGS += -DNDEBUG
endif
	
BUILD_DIR = ./build
EXECUTABLE = $(BUILD_DIR)/sched_demo.bin 

SOURCES = core/main.c core/scheduler.c core/sched/rr.c lib/dlist.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean builddir

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): builddir $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

builddir:
	@mkdir -p $(BUILD_DIR)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

