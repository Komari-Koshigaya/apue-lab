#include <head.h>

void print_type(mode_t st_mode)  //打印文件类型
{
    if(S_ISREG(st_mode))//普通文件
    {
        printf("-");
    }
    else if(S_ISDIR(st_mode))//目录文件
    {
        printf("d");
    }
    else if(S_ISCHR(st_mode))//字符设备
    {
        printf("c");
    }
    else if(S_ISBLK(st_mode))//块设备
    {
        printf("b");
    }
    else if(S_ISFIFO(st_mode))//FIFO管道
    {
        printf("p");
    }
    else if(S_ISSOCK(st_mode))//套接字
    {
        printf("s");
    }       
    else if(S_ISLNK(st_mode))//符号连接
    {
        printf("l");
    }else{
        printf(";");
    }
}