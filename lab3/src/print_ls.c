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
	printf("%s", (S_IRUSR & st_mode) ? "r" : "-");
	printf("%s", (S_IWUSR & st_mode) ? "w" : "-");
	printf("%s", (S_IXUSR & st_mode) ? "x" : "-");

	// 用户组的三个属性
	printf("%s", (S_IRGRP & st_mode) ? "r" : "-");
	printf("%s", (S_IWGRP & st_mode) ? "w" : "-");
	printf("%s", (S_IXGRP & st_mode) ? "x" : "-");

	// 其他用户的三个属性
	printf("%s", (S_IROTH & st_mode) ? "r" : "-");
	printf("%s", (S_IWOTH & st_mode) ? "w" : "-");
	printf("%s", (S_IXOTH & st_mode) ? "x" : "-");

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
	struct passwd *user = NULL;
	user = getpwuid(st_uid);
	printf("%s", (*user).pw_name);
    printf(" ");
}

//打印文件所有者所在组
void print_gname(gid_t st_gid)
{
	struct group *group = NULL;
	group = getgrgid(st_gid);
	printf("%s", group->gr_name);
    printf(" ");
}

//打印文件最后修改时间
void print_time(time_t st_mtimes)
{
	//12个月份的英文缩写
	char *month[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm *mtime;
    mtime = localtime(&st_mtimes);
    //打印文件的日期 时间
    printf("%s %02d %02d:%02d:%02d", month[mtime->tm_mon], mtime->tm_mday, mtime->tm_hour, mtime->tm_min, mtime->tm_sec);
    printf(" ");
}