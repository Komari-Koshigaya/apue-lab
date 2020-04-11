#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


void * myls_with_cp(void *src_path);
void * mycp(void *filename);