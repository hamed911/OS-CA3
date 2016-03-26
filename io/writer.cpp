#include "writer.h"

int file_raw_write(int fd, char* str){
	return write(fd,str,strlen(str));
}

int file_char_write(int fd, char c){
	char buffer[2];
	buffer[0] = c;
	buffer[1] = 0;
	return file_raw_write(fd,buffer);
}

void itoa(int num, char* buffer, int base){
	int i=0;
	if(num<0){
		buffer[i++] = '-';
		num *= -1;
	}
	int tmp_num=num;
	int dig_count=0;
	while(tmp_num){
		tmp_num/=base;
		++dig_count;
	}
	i+=dig_count;
	i--;
	while(num){
		buffer[i--] = num%base + '0';
		num/=base;
	}
	if(dig_count==0)
		buffer[++i] = '0';
	buffer[i+dig_count+1] = 0;
}

int file_int_write(int fd, int num, int base){
	char buffer[1024];
	itoa(num,buffer,base);
	return file_raw_write(fd,buffer);
}

int buf_format_write(char* buffer, char* format, ...){
	va_list args;
	int i;
	int j;
	int size = strlen(format);
	va_start(args,format);
	j=0;
	for(i=0;i<size;i++){
		if(format[i]!='%'){
			buffer[j++] = format[i];
			continue;
		}
		++i;
		if(format[i] == 'd'){
			int printing = va_arg(args,int);
			char ibuffer[1024];
			itoa(printing,ibuffer,10);
			int k;
			for(k=0;k<strlen(ibuffer);k++)
				buffer[j++] = ibuffer[k];
		}
		else if(format[i] == 's'){
			char* printing = va_arg(args,char*);
			int k;
			for(k=0;k<strlen(printing);k++)
				buffer[j++] = printing[k];
		}
		else if(format[i] == 'c'){
			char printing = va_arg(args,int);
			buffer[j++] = printing;
		}
		else{
			return FORMATERR;
		}
	}
	buffer[j]=0;
	va_end(args);
	return 0;
}

int file_format_write(int fd,char* format, ...){
	static map<int, sem_t*> lock;
	if(lock.find(fd)==lock.end()){
		sem_t* newLock = new sem_t;
		lock[fd] = newLock;
		sem_init(newLock,0,1);
	}
	sem_wait(lock[fd]);	
	va_list args;
	int i;
	int j;
	int size = strlen(format);
	char buffer[2048];
	va_start(args,format);
	j=0;
	for(i=0;i<size;i++){
		if(format[i]!='%'){
			buffer[j++] = format[i];
			continue;
		}
		++i;
		if(format[i] == 'd'){
			int printing = va_arg(args,int);
			char ibuffer[1024];
			itoa(printing,ibuffer,10);
			int k;
			for(k=0;k<strlen(ibuffer);k++)
				buffer[j++] = ibuffer[k];
		}
		else if(format[i] == 's'){
			char* printing = va_arg(args,char*);
			int k;
			for(k=0;k<strlen(printing);k++)
				buffer[j++] = printing[k];
		}
		else if(format[i] == 'c'){
			char printing = va_arg(args,int);
			buffer[j++] = printing;
		}
		else{
			return FORMATERR;
		}
	}
	buffer[j] = 0;
	va_end(args);
	int ret = file_raw_write(fd,buffer);
	sem_post(lock[fd]);
	return ret;
}
