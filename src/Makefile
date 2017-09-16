CC		= g++

OUT		= piVR

INCPATH		= ../include
OBJPATH		= ../obj

LDFLAGS         += -lRTIMULib
CFLAGS          = -I$(INCPATH)

_DEPS		= test.h
DEPS		= $(patsubst %,$(INCPATH)/%,$(_DEPS))
_OBJ		= main.o test.o
OBJ		= $(patsubst %,$(OBJPATH)/%,$(_OBJ))

$(OBJPATH)/%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUT) : $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ -I$(OBJPATH)

clean:
	rm -f $(OBJPATH)/*

new:
	rm -f $(OBJPATH)/*
	rm -f $(OUT)
	make
