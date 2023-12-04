#include "kvs.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 4500


void read_line_until_newline(int file_descriptor, char* buffer, int max_length) {
    ssize_t total_read = 0;

    while (total_read < max_length - 1) {
        ssize_t bytes_read = read(file_descriptor, buffer + total_read, 1);
        printf(bytes_read);

        if (bytes_read <= 0 || buffer[total_read] == '\n') {
            break;  // 파일의 끝에 도달하거나 줄바꿈 문자를 만남
        }
        total_read += bytes_read;
    }

    buffer[total_read] = '\0';  // 널 문자 추가
}


int do_recovery_costom(kvs_t* kvs){

    // 특정 위치 아래에 있는 kvs.dat 파일로부터 in-memory-kvs를 복원하는 함수 
    int Recovery_file = open("kvs.dat", O_RDONLY);
    if (Recovery_file == -1) {
        perror("파일 열기 오류");
        return 1;
    }

    char key[32];
    char content[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    while (1) {
        // 파일에서 줄바꿈 문자를 만날 때까지 읽어옴
        read_line_until_newline(Recovery_file, buffer, 1);

        // 읽은 데이터 처리
        printf(buffer);

        // 파일의 끝에 도달하면 종료
        if (buffer[0] == '\0') {
            break;
        }


        // printf("%s %s\n", key, content);
        // printf("kvs items : %d\n" , kvs->items);
        // set 함수 호출ax 
        // set(kvs, key, content);
    }

    close(Recovery_file);
    return 0;
}