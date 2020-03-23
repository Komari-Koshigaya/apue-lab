#include <head.h>

//打印文件类型
void print_type(mode_t st_mode)  
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
    printf(" ");
}


//打印文件权限
void print_perm(mode_t st_mode)
{
    printf(" ");
}

//打印文件连接数
void print_link(nlink_t st_nlink)
{
    printf(" ");
}

//打印文件 所有者
void print_uname(uid_t st_uid)
{
    printf(" ");
}

//打印文件所有者所在组
void print_gname(gid_t st_gid)
{
    printf(" ");
}

//打印文件最后修改时间
void print_time(time_t st_mtime)
{
    printf(" ");
}