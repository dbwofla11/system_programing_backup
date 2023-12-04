SRCS = static_main.c
# SRCSD = dynamic_main.c

LIBSRCS = open.c close.c set.c get.c do_snapshot_basic.c do_snapshot_costom.c do_recovery_basic.c do_recovery_costom.c 
TARG_STATIC = kvs_static

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

DY_OPTS = -fPIC -shared 

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)

LARS_STATIC = libkvs.a

all: static 

static: $(TARG_STATIC) # static 할때 쓰는거 

$(TARG_STATIC): $(OBJS) $(LARS_STATIC) # 실행만들기 -> ( 메인 + 라이브러리 )
	$(CC) -pg -o $(TARG_STATIC) $(OBJS) $(LIBS)

$(LARS_STATIC): $(LOBJS) # 장착할 라이브러리 
	ar rs $(LARS_STATIC) $(LOBJS)

# 오브젝트 파일로 만든다음 합치기  
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ 

clean:
	rm -rf $(TARG_STATIC) $(LARS_STATIC) $(TARG_DYNAMIC) $(LARS_DYNAMIC) $(OBJS) $(LOBJS)