#ifndef SIHA_READER
#define SIHA_READER

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int file_raw_read(int , char*, size_t);
char file_char_read(int );
int file_line_read(int , char* , size_t );
int file_format_read(int ,char* , ...);
int file_phrase_read(int, char*);
int buf_format_read(char* ,char* , ...);

#define FORMATERR -321
#define STDIN 0

#endif
