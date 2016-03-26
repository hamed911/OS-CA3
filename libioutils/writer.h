#ifndef SIHA_WRITER
#define SIHA_WRITER

#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <semaphore.h>
#include <map>
using namespace std;

int file_raw_write(int, char*);
int file_char_write(int, char);
int file_int_write(int, int, int);
int file_format_write(int fd,char* format, ...);
int buf_format_write(char* buffer, char* format, ...);


#define FORMATERR -321
#define STDOUT 1
#define STDERR 2

#endif
