#include "uhead.h"

int compar(const void *a,const void *b){
	int *aa=(int *) a,*bb = (int *)b;
	if(* aa > *bb) return 1;
	if(* aa == *bb) return 0;
	if(* aa < *bb) return -1;
}

void syssort(int *base,int m){
	int fd,out[m];
	struct timeval tv1,tv2;
	struct timezone tz;
	gettimeofday(&tv1,&tz);
	qsort(base,m,sizeof(int),compar);
	gettimeofday(&tv2,&tz);
	printf("tv2_usec-tv1_usec: %d\n",tv2.tv_usec-tv1.tv_usec);
	/*for(i=0;i<m;i++){
		printf("%d",base[i]);
		printf("\n");
	}*/
	fd = open("sort1.txt", O_CREAT | O_TRUNC | O_RDWR, 0600);
	int size  = write(fd,base,m);
	close(fd);
	fd=open("sort1.txt",O_RDONLY, 0600);
	lseek(fd, 0, SEEK_SET);//Before to read the file,you should call the function to make the fd point to begin of files
	size = read(fd, out,m+1);
	printf("size = %d\nread from file:\n %d\n",size,out);
	close(fd);
}

void mysort(int *a,int m){
	int i,j,k;
	int fd,out[m];
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
	/*fd = open("sort2.txt", O_CREAT | O_TRUNC | O_RDWR, 0600);
	int size  = write(fd,a,m);
	close(fd);
	fd=open("sort2.txt",O_RDONLY,0600);
	lseek(fd, 0, SEEK_SET);//Before to read the file,you should call the function to make the fd point to begin of files
	size = read(fd, out,m+1);
	printf("size = %d\nread from file:\n %d\n",size,out);
	close(fd);*/
	
}
