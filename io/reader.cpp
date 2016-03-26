#include "reader.h"

int file_raw_read(int fd, char* buffer, size_t n){
	return read(fd, buffer, n);
}

char file_char_read(int fd){
	int count;
	char c;
	count = read(fd,&c,1);
	if(count<=0)
		return count;
	return c;
}

int file_phrase_read(int fd, char* buffer){
	char c;
	while((c=file_char_read(fd))>0 && c==' ');
	if(c=='\n'){
		buffer[0]=0;
		return 0;
	}
	else if(c<=0){
		buffer[0]=0;
		return c;
	}
	*buffer++ = c;
	int count=1;
	while((c=file_char_read(fd))>0 && c!='\n' && c!=' '){
		*buffer++ = c;
		++count;
	}
	*buffer = 0;
	return count;
}

int file_line_read(int fd, char* buffer, size_t maxn){
	char* tmp;
	char c;
	int count=0;
	for(tmp=buffer;maxn>0;++buffer,--maxn,++tmp){
		c = file_char_read(fd);
		if(c<=0 || c=='\n')
			break;
		*tmp = c;
		count++;
	}
	*tmp = 0;
	//if(c<=0)
	//	return c;
	return count;
}

int file_format_read(int fd,char* format, ...){
	va_list args;
	va_start(args,format);
	char line[2048];
	int lsize;
	if((lsize=file_line_read(fd,line,2047))<=0)
		return lsize;
	int i;
	int j=0;
	int count=0;
	for(i=0;i<strlen(format);i++){
		if(format[i]==line[j]){
			++j;
			continue;
		}
		if(format[i]!='%')
			return count;
		i++;
		if(format[i] == 'd'){
			int *readed = va_arg(args,int*);
			*readed = atoi(line+j);
			while('0'<=line[j] && line[j]<='9')
				++j;
			++count;
		}
		else if(format[i] == 's'){
			char* readed = va_arg(args,char*);
			int off=0;
			while(line[j]!=' ' && line[j]!=0){
				readed[off] = line[j];
				++off;
				++j;
			}
			readed[off] = 0;
			++count;
		}
		else if(format[i] == 'c'){
			char *readed = va_arg(args,char*);
			*readed = line[j];
			++j;
			++count;
		}
		else{
			return FORMATERR;
		}
	}
	va_end(args);
	return count;
}

int buf_format_read(char* line,char* format, ...){
	va_list args;
	va_start(args,format);
	int lsize;
	if((lsize=strlen(line))==-1)
		return -1;
	else if(lsize==0)
		return 0;
	int i;
	int j=0;
	int count=0;
	for(i=0;i<strlen(format);i++){
		if(format[i]==line[j]){
			++j;
			continue;
		}
		if(format[i]!='%')
			return count;
		i++;
		if(format[i] == 'd'){
			int *readed = va_arg(args,int*);
			*readed = atoi(line+j);
			while('0'<=line[j] && line[j]<='9')
				++j;
			++count;
		}
		else if(format[i] == 's'){
			char* readed = va_arg(args,char*);
			int off=0;
			while(line[j]!=' ' && line[j]!=0){
				readed[off] = line[j];
				++off;
				++j;
			}
			readed[off] = 0;
			++count;
		}
		else if(format[i] == 'c'){
			char *readed = va_arg(args,char*);
			*readed = line[j];
			++j;
			++count;
		}
		else{
			return FORMATERR;
		}
	}
	va_end(args);
	return count;
}
