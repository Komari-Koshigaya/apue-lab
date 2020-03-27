# include <head.h>


int myls(char *path, int hide_file)
{

    DIR *currentdir;
    currentdir = opendir(path);   //打开当前目录，若path是相对路径，如 ：../src 并不需要特殊处理
    
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
    struct stat curr_stat;
    
    printf("file in %s include:\n\n", path);
    chdir(path);	//把工作路径切换到path目录，省去了后面获取文件信息是，拼接目录和文件名的步骤
    while( (currentdp = readdir(currentdir)) != NULL )  //循环获取目录下的文件
    {

    	if(hide_file && strncmp(currentdp->d_name, ".", 1) == 0)//判断是否时隐藏文件，若是且未指定 -a ，则不打印隐藏文件
    	{
    		continue;
    	}
        //局部变量，用malloc申请内存,strlen不算'\0'，所以需要+1  由于使用了 chmod(path)  下面拼接文件名全称的代码可以省去
        // curr_file = (char *) malloc(strlen("/") + strlen(path) + strlen(currentdp->d_name) + 1);
        // sprintf(curr_file, "%s/%s", path, currentdp->d_name); //设置curr_file为 当前路径/当前文件名

        if( stat(currentdp->d_name, &curr_stat) < 0)//获取文件的属性，并判断是否获取成功
        {
            printf("get stat error\n");
            continue;
        }

        print_type(curr_stat.st_mode);//打印文件类型
        print_perm(curr_stat.st_mode);//打印文件权限
        printf("%ld ", curr_stat.st_nlink);//打印文件连接数
        print_uname(curr_stat.st_uid);//打印文件 所有者
        print_gname(curr_stat.st_gid);//打印文件所有者所在组
        printf("%5ld ", curr_stat.st_size);//打印文件大小 字节计算  5个空位右对齐
        print_time(curr_stat.st_mtime);//打印文件最后修改时间
        printf("%s\n", currentdp->d_name); //打印当前文件名
     }   

    printf("\n");
    closedir(currentdir);
    return 0;
}