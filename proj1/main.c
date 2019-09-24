#include "uhead.h"
int main(){
	int a[UNUMBER],ca[UNUMBER],i;
	struct arg t;
	urand(a,UNUMBER);
	//show(a,UNUMBER);
	t=operater(a,UNUMBER);
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	for(i=0;i<UNUMBER;i++){
		ca[i]=a[i];	
	}
	syssort(a,UNUMBER);
	mysort(ca,UNUMBER);
	return 0;
}
