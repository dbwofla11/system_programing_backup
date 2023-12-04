#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	char key[32];
	char* value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	int items; // number of data 
};
typedef struct kvs kvs_t; 


kvs_t* open_kvs();
int close_kvs(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 


int do_snapshot_basic(kvs_t* kvs);
int do_snapshot_costom(kvs_t* kvs);

int do_recovery_basic(kvs_t* kvs);
int do_recovery_costom(kvs_t* kvs);