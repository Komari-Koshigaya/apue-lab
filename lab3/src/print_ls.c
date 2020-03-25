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
}


//打印文件权限
void print_perm(mode_t st_mode)
{
	// 用户的三个属性
	if(S_IRUSR & st_mode)		printf("r");
	else						printf("-");
	if(S_IWUSR & st_mode)		printf("w");
	else						printf("-");
	if(S_IXUSR & st_mode)		printf("x");
	else						printf("-");

	// 用户组的三个属性
	if(S_IRGRP & st_mode)		printf("r");
	else						printf("-");
	if(S_IWGRP & st_mode)		printf("w");
	else						printf("-");
	if(S_IXGRP & st_mode)		printf("x");
	else						printf("-");

	// 其他用户的三个属性
	if(S_IROTH & st_mode)		printf("r");
	else						printf("-");
	if(S_IWOTH & st_mode)		printf("w");
	else						printf("-");
	if(S_IXOTH & st_mode)		printf("x");
	else						printf("-");
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
// void print_time(time_t st_mtime)
// {
//     printf(" ");
// }