#include "kvs.h"


// open을 하게 될때 DB의 한 row의 크기를 활당한다 보면 됨 
kvs_t* open_kvs()
{
	// kvs 객체를 만들어서 가져다 줌 
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));
	// do_recovery_basic(kvs);
	do_recovery_costom(kvs);
	
	// if( kvs )
	// 	kvs->items = 0;
	
	// 확인용 
	printf("아이템 수 : %d\n", kvs->items);

	return kvs;
}
