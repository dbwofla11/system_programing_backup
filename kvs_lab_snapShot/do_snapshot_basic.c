#include "kvs.h"
#include <stdio.h>

int do_snapshot_basic(kvs_t* kvs) {
    // in-memory-dataset을 특정 위치 아래 kvs.dat 파일로 저장하는 함수 
    FILE* Snapshot_file = fopen("kvs.dat", "w");
    if (Snapshot_file == NULL) {
        perror("파일 열기 오류");
        return 1; // 오류 코드 반환 
    }

    // 연결 리스트를 순회하며 각 노드를 파일에 쓰기
    node_t* curr = kvs->db;
    while (curr != NULL) { // 노드 순회 

        // length는 확인용 ( key길이 , key , value길이 , value )
        fprintf(Snapshot_file, "%s %s\n", curr->key, curr->value);

        curr = curr->next;
    }
    fclose(Snapshot_file);

    return 0; // 아무 문제 없을 때 0 반환 
}
