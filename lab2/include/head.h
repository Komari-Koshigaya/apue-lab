#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFMAXLEN  1024    //read和write函数的buffer最大程度

void cp_to_dir(char *srcfile, char *destpath); //复制文件到目录
void cp_to_file(char *srcfile, char *destpath);  //cp src/file.txt des/des.txt