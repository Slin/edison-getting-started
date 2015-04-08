CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=submodules/block_oled/Firmware/pong/spi/spi_port_edison.cpp submodules/block_oled/Firmware/pong/spi/spi_device_edison.cpp I_<3_3D.cpp submodules/block_oled/Firmware/pong/oled/Edison_OLED.cpp submodules/block_oled/Firmware/pong/gpio/gpio_edison.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=I_<3_3D

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)