CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
BIN = arm-none-eabi-objcopy
STL = st-flash
CFLAGS = -fno-exceptions -mthumb -mcpu=cortex-m3
#DEPS = gpio_definitions.h
OBJ = main.o #RCCRegisterControl.o Timer.o UART.o

all: app.bin

crt.o: crt.s
	$(AS) -o crt.o crt.s

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

app.elf: memory_map.ld crt.o $(OBJ)
	$(LD) -T memory_map.ld -o app.elf crt.o $(OBJ)

app.bin: app.elf
	$(BIN) -O binary app.elf app.bin

clean:
	rm -f *.o *.elf *.bin

flash: app.bin
	$(STL) write app.bin 0x8000000

erase:
	$(STL) erase
