#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFMAXLEN  1024    //read��write������buffer���̶�

void cp_to_dir(char *srcfile, char *destpath); //�����ļ���Ŀ¼
void cp_to_file(char *srcfile, char *destpath);  //cp src/file.txt des/des.txt