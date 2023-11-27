#include "kvs.h"

int close(kvs_t* kvs)
{
	if (kvs == NULL){
		fprintf(stderr , "error: kvs not pointer\n");
		return -1;
	}

	node_t *curr = kvs->db;
	while ( curr != NULL ){
		// 활당해제 
		node_t *next_node = curr->next;
		free(curr->value);
		free(curr);
		curr = next_node;
	}

	free(kvs);
	

	return 0;
}
