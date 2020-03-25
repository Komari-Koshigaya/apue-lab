# include <head.h>


int myls(char *path)
{

    DIR *currentdir;
    currentdir = opendir(path);   //打开当前目录
    
    if(path == NULL)   
    {
        printf("invalid path"); 
        return -1;
    }
   
    if(currentdir == NULL)
    {
        printf("open directory fail\n");
        return -1;
    }
    
  
    struct dirent *currentdp;
    char *curr_file;    //当前文件名，包括路径，如 /home/niejun/test.txt
    struct stat curr_stat;
    
    printf("file in %s include:\n", path);
    while( (currentdp = readdir(currentdir)) != NULL )  //循环获取目录下的文件
    {
        
        curr_file = (char *) malloc(strlen("/123") + strlen(path) + strlen(currentdp->d_name));
        sprintf(curr_file, "%s/%s", path, currentdp->d_name); //设置curr_file为 当前路径/当前文件名
        //printf("%s\n", curr_file);
        
        if( stat(curr_file, &curr_stat) < 0)//获取文件的属性，并判断是否获取成功
        {
            printf("get stat error\n");
            continue;
        }
        free(curr_file);curr_file = NULL;

        print_type(curr_stat.st_mode);//打印文件类型
        print_perm(curr_stat.st_mode);//打印文件权限
        printf("%ld ", curr_stat.st_nlink);//打印文件连接数
        print_uname(curr_stat.st_uid);//打印文件 所有者
        print_gname(curr_stat.st_gid);//打印文件所有者所在组
        printf("%5ld ", curr_stat.st_size);//打印文件大小 字节计算  5个空位右对齐
        print_time(curr_stat.st_mtime);//打印文件最后修改时间
        printf("%s\n", currentdp->d_name); //打印当前文件名
     }   

    
    closedir(currentdir);
    return 0;
}