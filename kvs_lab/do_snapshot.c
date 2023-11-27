#include "kvs.h"


int do_snapshot(kvs_t* kvs){

    // in-memory-dataset 을 특정 위치 아래 kvs.dat파일로 저장하는 함수 
    FILE* Snapshot_file = fopen("kvs.dat" , "w");
    if ( Snapshot_file == NULL){
        perror("파일 열기 오류");
        return 1; // 오류 코드 반환 
    }

    // 데이터 셋의 항목 수를 파일에 쓰기 
    fwrite( &(kvs->items) , sizeof(int) , 1 , Snapshot_file);

    // 연결 리스트를 순회하며 각 노드를 파일에 쓰기
    node_t* curr = kvs->db;
    while ( curr != NULL ){
        // 1개의 노드 

        // 키와 값의 길이, 그리고 키와 값 자체를 파일에 쓰기 
        int key_length = strlen(curr->key) + 1;
        int value_length = strlen(curr->value) + 1;

        // length는 확인용 
        fwrite( &key_length , sizeof(int) , 1 , Snapshot_file);
        fwrite( curr->key, sizeof(char) , key_length , Snapshot_file);

        fwrite( &value_length , sizeof(int) , 1 , Snapshot_file );
        fwrite( curr->value, sizeof(char), value_length, Snapshot_file );

        curr = curr->next;
    }
    fclose(Snapshot_file);
    
    return 0; // 아무문제 없을 때 0반환 
}