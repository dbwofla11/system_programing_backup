#include "kvs.h"


// open을 하게 될때 DB의 한 row의 크기를 활당한다 보면 됨 
kvs_t* open_kvs()
{
	clock_t start , end;
	// kvs 객체를 만들어서 가져다 줌 
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));
	
	start = clock();
	// do_recovery_basic(kvs);
	do_recovery_costom(kvs);
	end = clock();

	// if( kvs )
	// 	kvs->items = 0;
	
	// 확인용 
	printf("KVS 아이템 수 : %d\n", kvs->items);
	printf("do_recovery_Costom : %lf sec\n" , (double)( end - start )/CLOCKS_PER_SEC);

	return kvs;
}
