#include "kvs.h"
#define MAX_LINE_LENGTH 200

int main()
{
	// kvs Open() ( DB 구조체 , 열기 )
	kvs_t* kvs = open();
	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// workload execution  
	// 0) file open
	FILE *answerFile;
	answerFile = fopen("answer.dat" , "w");

	FILE *query_lines;
	query_lines = fopen("query.dat" , "r");
	if (query_lines == NULL) {
		perror("파일 열기 실패");
		return -1;
    }
	// 한 줄을 저장할 버퍼 ( buffer of file )
    char *line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    if (line == NULL) {
        perror("메모리 할당 실패");
        fclose(query_lines);
        return 1;
    }
	// 파일에서 한 줄씩 읽어오고 저장하기 ( file -> )
    while (fgets(line, MAX_LINE_LENGTH, query_lines) != NULL) {
        // 한 줄 출력 ( 테스트용 )
        // printf("한 줄: %s", line);
		

		// "," 단위로 파싱(파싱파트)
		char *operation = strtok(line, ",");
		char *key = strtok(NULL, ","); // 다음 토큰 얻기
		char *content = strtok(NULL, ",");
		// printf("operation : %s ||| key : %s ||| content : %s" , operation , key , content);
		
		
		// 2) 	if set, insert (key, value) into kvs.
		// 		if get, seach the key in kvs and return the value. 
		//		Return -1 if the key is not found  
		if ( strcmp(operation , "set") == 0 ){

			if (key != NULL && content != NULL){

				int result = set(kvs , key , content);
				if ( result == 0 )
				{	// 반환 메시지 
					printf(" 값이 성공적으로 설정됨 \n");
				}
				else
				{
					printf(" 값 설정에 실패함 \n");
				}
			}
			else 
			{
				printf(" SET 명령어에는 키와 값이 필요함 \n");
			}
		}
		else if ( strcmp(operation , "get") == 0 ){

			if ( key != NULL ){
				
				char *result = get(kvs , key);
				if ( result != NULL )
				{	// 테스트용 메시지 + 파일 쓰기 
					fprintf(answerFile, "%s\n" , result);
					printf("결과: %s\n", result);
					
				}
				else 
				{
					printf(" 키를 찾을 수 없음 \n");
				}
			}
			else 
			{
				printf(" get 명령어에는 키가 필요함 \n");
			}
		} else {
			printf(" 지원하지 않는 작업입니다. \n");
		}		
    }

	
	free(line);
	fclose(query_lines);

	close(kvs);
	
	return 0;
}