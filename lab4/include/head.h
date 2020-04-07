#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


int myls_with_cp(char *path);   //打印当前工作目录的文件信息，并且复制非目录文件

void print_type(mode_t st_mode);  //打印文件类型

void print_perm(mode_t st_mode);//打印文件权限

void print_link(nlink_t st_nlink);//打印文件连接数

void print_uname(uid_t st_uid);//打印文件 所有者

void print_gname(gid_t st_gid);//打印文件所有者所在组

void print_time(time_t st_mtimes);//打印文件最后修改时间

// DIR *currentdir 目录文件, int trav_subdi 是否遍历子目录，1代表遍历，0遍历
int print_directory(DIR *currentdir, int trav_subdir);

//创建一个子进程，用于复制文件到指定目录
void process_mycp(char *filename);