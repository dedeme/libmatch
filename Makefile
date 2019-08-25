LIB=match

CFLAGS = -Wall -rdynamic
OBJECTS = $(subst src/dmc,obj,$(patsubst %.c,%.o,$(wildcard src/dmc/*.c)))

lib/lib$(LIB).a : $(OBJECTS)
	if [ ! -e lib ];then mkdir lib;fi
	ar rcs lib/lib$(LIB).a $(OBJECTS)

obj/%.o : src/dmc/%.c include/dmc/%.h
	if [ ! -e obj ];then mkdir obj;fi
	gcc $(CFLAGS) -c $< -o $@ -Iinclude \
	-Ilib/libdmc/include
