CC = clang
LDFLAGS = -shared
CFLAGS = -fPIC -Wall -Wextra -O2 -g

NUBO_LIB = build/libnubo.so

SRCS = $(shell echo src/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${NUBO_LIB}

$(NUBO_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^
	rm -f ${OBJS} $(SRCS:.c=.d)

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	rm -f ${NUBO_LIB} ${OBJS} $(SRCS:.c=.d)
