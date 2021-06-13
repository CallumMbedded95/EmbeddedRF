CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
BIN = arm-none-eabi-objcopy
STL = st-flash
CFLAGS = -mthumb -mcpu=cortex-m3
DEPS = gpio_definitions.h
OBJ = gpio_definitions.o main.o

all: app.bin

crt.o: crt.s
	$(AS) -o crt.o crt.s

gpio_definitions.o: gpio_definitions.c
	$(CC) $(CFLAGS) -c -o gpio_definitions.o gpio_definitions.c

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

app.elf: memory_map.ld crt.o main.o gpio_definitions.o
	$(LD) -T memory_map.ld -o app.elf crt.o gpio_definitions.o main.o 

app.bin: app.elf
	$(BIN) -O binary app.elf app.bin

clean:
	rm -f *.o *.elf *.bin

flash: app.bin
	$(STL) write app.bin 0x8000000

erase:
	$(STL) erase
