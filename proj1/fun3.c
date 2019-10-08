#include "uhead.h"

int compar(const void *a,const void *b){
	int *aa=(int *) a,*bb = (int *)b;
	if(* aa > *bb) return 1;
	if(* aa == *bb) return 0;
	if(* aa < *bb) return -1;
}

void syssort(int *base,int m){
	int i;
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	qsort(base,m,sizeof(int),compar);
	gettimeofday(&tv2,&tz);
	printf("tv2_usec-tv1_usec: %d\n",tv2.tv_usec-tv1.tv_usec);
	for(i=0;i<m;i++){
		printf("%d",base[i]);
		printf("\n");
	}
	
}

void mysort(int *a,int m){
	int i,j,k;
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	for(j=0;j<m;j++){
		for(k=0;k<m-j;k++){
			if(a[k]>a[k+1]){
				int temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;		
			}
		}
	}
	gettimeofday(&tv2,&tz);
	printf("tv2_usec-tv1_usec: %d\n",tv2.tv_usec-tv1.tv_usec);
	for(i=0;i<m;i++){
		printf("%d",a[i]);
		printf("\n");
	}
	
	
}
