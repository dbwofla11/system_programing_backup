#include "kvs.h"

int set(kvs_t* kvs, const char* key, const char* value)
{
	
	if (kvs == NULL || key == NULL || value == NULL) {
        fprintf(stderr, "Invalid Input\n"); // 오류가 나면 파일에 적어짐
        return -1;
    }
	printf("set 호출 \n");


	/* do program here */
	// current 값의 key만 확인하고 업데이트 하는거 ( key가 2번 같은거 )
	node_t *curr = kvs->db;
	while ( curr != NULL ){
		if ( strcmp(curr->key , key) == 0 ){ // 이미 kvs에 key가 존재할때 

			// 원래 value를 free시키고 
			free(curr->value);

			// 다시 value를 넣어줌 ( 업데이트 )
			curr->value = strdup(value); 
			if ( curr->value == NULL ){ 
				perror("메모리가 활당을 잘못함");
				return -1;
			}
			return 0;
		} 
		curr = curr->next;
	}

	// malloc을 할때 반환형을 맞춰야함 반환이 포인터면 예도 포인터 
	node_t *Set_node = (node_t *)malloc(sizeof(node_t));  
	if ( Set_node == NULL ){
		perror("메모리가 활당을 잘못함");
		return -1;
	}

	// key값 노드에 카피 
	strncpy(Set_node->key , key , sizeof(Set_node->key));
	Set_node->value = strdup(value); // (문자열)복사 + 복사된 문자열을 가리키는 포인터를 반환함 
	if ( Set_node->value == NULL ){
		perror("메모리가 활당을 잘못함");
		free(Set_node);
		return -1;
	}

	// set_node->next 값을 kvs->db로 맞춰줌 
	Set_node->next = kvs->db;

	// DB안의 노드 + item set을 따로 새로 만듬 
	kvs->db = Set_node;
	kvs->items++;

	return 0;
}
