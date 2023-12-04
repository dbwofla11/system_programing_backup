#include "kvs.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 4400

int do_recovery_costom(kvs_t* kvs){

    // 특정 위치 아래에 있는 kvs.dat 파일로부터 in-memory-kvs를 복원하는 함수 
    int Recovery_file = open("kvs.dat", O_RDONLY);
    if (Recovery_file == -1) {
        perror("파일 열기 오류");
        return 1;
    }

    char key[32];
    char content[MAX_LINE_LENGTH];
    char current_char;


    // 파일 읽기
    while (1) {
        char current_char;
        int bytes_read = read(Recovery_file, &current_char, 1);

        // 파일의 끝에 도달하면 종료
        if (bytes_read == 0) {
            break;
        }

        // 개행 문자를 만날 때까지 key 읽기
        int key_index = 0;
        while (current_char != ' ' && current_char != '\n') {
            key[key_index++] = current_char;
            
            bytes_read = read(Recovery_file, &current_char, 1);

        }
        key[key_index] = '\0'; // 문자열 마지막에 널 문자 추가

        // 개행 문자를 만날 때까지 content 읽기
        int content_index = 0;
        while (current_char != '\n') {
            content[content_index++] = current_char;
            
            bytes_read = read(Recovery_file, &current_char, 1);

        }
        content[content_index] = '\0'; // 문자열 마지막에 널 문자 추가

        set(kvs, key, content);
    }
    



    close(Recovery_file);
    return 0;
}




