
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 
#define UNUMBER 100

struct arg{
	float ave;
	int sum;
};
void show(int *,int );
void urand(int * ,int );
struct arg operater(int * ,int);
int compar(const void *,const void *);
void syssort(int *,int);
void mysort(int *,int);

