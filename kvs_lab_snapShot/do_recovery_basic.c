#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 4500


int do_recovery_basic(kvs_t* kvs) { 

    FILE* Recovery_file = fopen("kvs.dat", "r");
    if (Recovery_file == NULL) {
        perror("파일 열기 오류");
        return 1; // 오류 코드 반환 
    }

    // 데이터 셋의 항목 수를 파일에서 읽어오기
    int itemN;
    fscanf(Recovery_file, "%d\n", &itemN);
    kvs->items = 0;
    // printf("초기 kvs 아이템수 : %d",itemN);


    // char line[MAX_LINE_LENGTH];
    // char* re_parser = NULL;
    char key[32];
    char content[MAX_LINE_LENGTH];
    while (fscanf(Recovery_file, "%s %[^\n]", key, content) == 2) {
        
        // 트윗 전체 출력
        // printf("%s %s\n", key, content);
        // printf("kvs items : %d\n" , kvs->items);
        set(kvs , key , content);
    }

    fclose(Recovery_file);
    return 0; // 아무 문제 없을 때 0 반환 
}