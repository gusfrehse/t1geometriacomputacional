CFLAGS += -Wall -Wextra -Wpedantic -pedantic-errors -O2 -Wno-format -g -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wl,-z,now -Wl,-z,relro

OBJS = poligono.o util.o

poligono : $(OBJS)

poligono.o : poligono.c util.h
util.o : util.c util.h

