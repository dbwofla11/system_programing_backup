#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
    char* value = (char*)malloc(sizeof(char)*100);

    /* do program here */
    if (kvs == NULL || key == NULL){
        fprintf(stderr , "Invalid input\n");
        return NULL;
    }

	// 여기서 먼저 -1에 \n을 해줘서 다른 get string을 할 때 format이 맞게함
	// set으로 저장된 문자를 불러오면 문자가 불러오지긴 하는데 \n도 기본적으로 딸려와서 이렇게 설계함
    strcpy(value , "-1\n");
    node_t *curr = kvs->db;
    // DB를 순회를 한 번 하긴 해야함 
    while (curr != NULL) {

        // key를 찾으면 return value 
        if (strcmp(curr->key, key) == 0) {
            
            // strdup()은 문자열 s를 복사후 복사한 문자열 포인터 반환
            // 이때 복사할 공간을 확보하기 위해서 내부적으로 malloc이 호출함                     
            // char *value_copy = strdup(curr->value); < 근데 안씀 > 

            //이미 malloc한 곳에 카피함 
            strcpy(value , curr->value);
            if (value == NULL) {
                perror("벨류가 없음");
                return value;
            }
            break;
        }
        // 다음으로 넘어가기 
        curr = curr->next;
    }
    return value;
}