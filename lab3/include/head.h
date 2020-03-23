#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int myls(char *path);   //打印当前工作目录的文件信息

void print_type(mode_t st_mode);  //打印文件类型

void print_perm(mode_t st_mode);//打印文件权限

void print_link(nlink_t st_nlink);//打印文件连接数

void print_uname(uid_t st_uid);//打印文件 所有者

void print_gname(gid_t st_gid);//打印文件所有者所在组

void print_time(time_t st_mtime);//打印文件最后修改时间
