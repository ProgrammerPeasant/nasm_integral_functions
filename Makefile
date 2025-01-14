CC = x86_64-linux-gnu-gcc
AS = nasm
GDB = gdb

CFLAGS = \
	-m32 \
	-Wfatal-errors \
	-no-pie \
	-g \
	-Isrc

ASFLAGS = \
	-f elf32 \
	-DUNIX \
	-g

LDFLAGS = \
	-m32 \
	-no-pie \
	-z noexecstack \
	-g

SOURCES = \
	main.c \
	src/integral.c \
	src/functions.asm

HEADERS = \
	src/integral.h

# Corrected MAIN_OBJ variable
MAIN_OBJ = $(SOURCES:%.c=build/%.o)
MAIN_OBJ := $(MAIN_OBJ:%.asm=build/%.o)
MAIN_OBJ := $(MAIN_OBJ:build/src/%=build/%)

EXECUTABLE = ./integral

TEST_SOURCES = \
	test/main.c \
	test/test_functions.asm \
	src/integral.c

TEST_HEADERS = \
	src/integral.h

TEST_MAIN_OBJ := $(TEST_MAIN_OBJ:%.asm=test/build/%.o)
TEST_MAIN_OBJ := $(filter-out test/build/src/integral.o,$(TEST_MAIN_OBJ)) test/build/integral.o
TEST_MAIN_OBJ += test/build/src/functions.o test/build/test/test_functions.o

TEST_EXE = test/build/test.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJ)
	$(CC) $(LDFLAGS) $(MAIN_OBJ) -o $@

test/build/integral.o: src/integral.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.asm
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@

test: $(TEST_EXE)

$(TEST_EXE): $(TEST_MAIN_OBJ)
	$(CC) $(LDFLAGS) $(TEST_MAIN_OBJ) -o $@

test/build/%.o: %.c $(TEST_HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

test/build/%.o: %.asm
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf build
	rm -rf test/build