#include "kvs.h"
#define MAX_LINE_LENGTH 4500

// 테스트용 kvs출력 
void print_kvs(kvs_t* kvs) {
    node_t *curr = kvs->db;

	printf("kvs 출력 테스트");
    while (curr != NULL) { 
        printf("Key: %s, Value: %s\n", curr->key, curr->value);
        curr = curr->next;
    }
}

int main()
{
	// kvs Open() ( DB 구조체 , 열기 )
	kvs_t* kvs = open_kvs();
	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// FILE* queryFile = fopen("./tt", "r");
	// if (!queryFile) {
	// 	printf("Failed to open 'query.dat'");
	// 	return -1;
	// }

	// FILE* answerFile = fopen("./answer.dat", "w");
	// if (!answerFile) {
	// 	printf("Failed to open 'answer.dat'");
	// 	return -1;
	// }

	// char Line[MAX_LINE_LENGTH]; 
	// char* result = NULL;
	// char operation[4];
	// char key[32];
	// char* parser = NULL;
	// char content[MAX_LINE_LENGTH];
	// // 파일에서 한 줄씩 읽어오고 저장하기 ( file -> )
    // while ( !feof(queryFile) ) {

	// 	// file에서 가져옴 
	// 	fscanf(queryFile, "%s\n", Line);
		
	// 	// "," 단위로 파싱(파싱파트)
	// 	parser = strtok(Line, ",");
	// 	strcpy(operation, parser);
	// 	parser = strtok(NULL, ",");
	// 	strcpy(key, parser);
	// 	parser = strtok(NULL, ",");
	// 	strcpy(content, parser);


	// 	if ( strcmp(operation , "set") == 0 ){
	// 		set(kvs , key , content);
	// 	}
	// 	else if ( strcmp(operation , "get") == 0 ){
	// 		result = get(kvs , key);
	// 		fprintf(answerFile, "%s\n" , result);
	// 		printf("get\n");		
    // 		free(result);
	// 		result = NULL;
	// 	}
	// }
	// // do_snapshot_basic(kvs);
	// do_snapshot_costom(kvs);

	// fclose(answerFile);
	// fclose(queryFile);
	// 테스트용 kvs 출력함수 호출 
	print_kvs(kvs);



	close_kvs(kvs);
	
	return 0;
	
}