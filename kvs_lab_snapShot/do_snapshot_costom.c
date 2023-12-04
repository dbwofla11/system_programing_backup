#include "kvs.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int do_snapshot_costom(kvs_t* kvs) {
    
    // in-memory-dataset을 특정 위치 아래 kvs.dat 파일로 저장하는 함수 
    int Snapshot_file = open("kvs.dat", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (Snapshot_file == -1) {
        perror("파일 열기 오류");
        return 1; // 오류 코드 반환 
    }

    // 연결 리스트를 순회하며 각 노드를 파일에 쓰기
    node_t* curr = kvs->db;
    while (curr != NULL) {
        // 1개의 노드 

        // 키의 길이를 파일에 쓰기
        int key_length = 0;
        while (curr->key[key_length] != '\0') {
            key_length++;
        }

        int value_length = 0;
        while (curr->value[value_length] != '\0') {
            value_length++;
        }

        
        write(Snapshot_file, curr->key, key_length); // 키를 파일에 쓰기
        write(Snapshot_file, " ", 1);
        write(Snapshot_file, curr->value, value_length); // 값을 파일에 쓰기
        
        // 개행 문자를 파일에 쓰기
        write(Snapshot_file, "\n", 1);

        curr = curr->next;
    }
    close(Snapshot_file);

    return 0; // 아무 문제 없을 때 0 반환 
}
