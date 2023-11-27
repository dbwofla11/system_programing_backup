SRCS = static_main.c
SRCSD = dynamic_main.c

LIBSRCS = open.c close.c set.c get.c do_snapshot.c do_recovery.c 
TARG_STATIC = kvs_static
TARG_DYNAMIC = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

DY_OPTS = -fPIC -shared 

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)

LARS_STATIC = libkvs.a
LARS_DYNAMIC = libkvs.so

all: static dynamic


static: $(TARG_STATIC) # static 할때 쓰는거 

$(TARG_STATIC): $(OBJS) $(LARS_STATIC) # 실행만들기 -> ( 메인 + 라이브러리 )
	$(CC) -o $(TARG_STATIC) $(OBJS) $(LIBS)

$(LARS_STATIC): $(LOBJS) # 장착할 라이브러리 
	ar rs $(LARS_STATIC) $(LOBJS)

# 오브젝트 파일로 만든다음 합치기  
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ 

dynamic: $(TARG_DYNAMIC) # dynamic 할때 쓰는거 

# 다이나믹 
$(TARG_DYNAMIC): $(LARS_DYNAMIC) 
	$(CC) -o $(TARG_DYNAMIC) $(SRCSD) -ldl

$(LARS_DYNAMIC): 
	$(CC) $(DY_OPTS) -o $(LARS_DYNAMIC) $(LIBSRCS)



clean:
	rm -rf $(TARG_STATIC) $(LARS_STATIC) $(TARG_DYNAMIC) $(LARS_DYNAMIC) $(OBJS) $(LOBJS)