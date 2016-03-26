#ifndef SIHA_OPENER
#define SIHA_OPENER

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

char* append (int, char*,...);
int get_file_descriptor(const char* ,const char*);

#define FOLDER_NF -26
#define FILE_NF -30
#define PERMISION_DEN -6

#endif
