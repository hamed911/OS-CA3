#include "opener.h"
#define true 1

extern int errno;
char* append(int n, char *merged,... ){
	va_list args;
	va_start(args,merged);
	int i;
	*merged = 0;
	for(i=0;i<n;i++){
		char* first = va_arg(args,char*);
		strcat(merged,first);
	}
	va_end(args);
	return merged;	
}

int get_file_descriptor(const char* dir,const char* file){
	mkdir(dir,S_IRWXU);
	char merged[256];
	memset(merged,0,sizeof(merged));	
	char* directory = append(3,merged,dir,"/",file);
	
	int temp = open(directory,O_RDWR);
	if(temp==-1){
		if(errno == EACCES)
			return PERMISION_DEN;
		else
			return FILE_NF;
	}
	return temp;
}
