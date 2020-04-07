# include <head.h>


//打印当前工作目录的文件信息，并且复制非目录文件
int myls_with_cp(char *path)
{

    DIR *currentdir = opendir(path);   //打开当前目录，若path是相对路径，如 ：../src 并不需要特殊处理
    // DIR *temp = opendir(path);

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

	chdir(path);	//把工作路径切换到path目录，省去了后面获取文件信息是，拼接目录和文件名的步骤
    // printf("DIR: %s\n", get_current_dir_name() );

	print_directory(currentdir, 1);
	// print_directory(temp, 1);

    chdir("..");
    closedir(currentdir);
    // closedir(temp);
    return 0;
}

// DIR *currentdir 目录文件, int trav_subdi 是否遍历子目录，1代表遍历，0遍历
int print_directory(DIR *currentdir, int trav_subdir)
{
	struct dirent *currentdp;
    struct stat curr_stat;
    while( (currentdp = readdir(currentdir)) != NULL )  //循环获取目录下的文件
    {

    	if( strncmp(currentdp->d_name, ".", 1) == 0 )//判断是否时隐藏文件，若是且未指定 -a ，则不打印隐藏文件
    	{
    		continue;
    	}

        if( stat(currentdp->d_name, &curr_stat) < 0)//获取文件的属性，并判断是否获取成功
        {
            printf("get stat error\n");
            continue;
        }

		if( trav_subdir == 1 && S_ISDIR(curr_stat.st_mode) ){//若是目录文件，则遍历子目录文件
			printf("\033[40;32m%s \033[0m ", currentdp->d_name);
			// printf("\033[40;32m%s \033[0m\n\n", currentdp->d_name);
			//若是目录 则打印出来的目录名是绿色  40是背景颜色：黑色， 32是字体颜色：绿色
			myls_with_cp(currentdp->d_name);
			
			continue;
		}

        // print_type(curr_stat.st_mode);//打印文件类型
        // print_perm(curr_stat.st_mode);//打印文件权限
        // printf("%ld ", curr_stat.st_nlink);//打印文件连接数
        // print_uname(curr_stat.st_uid);//打印文件 所有者
        // print_gname(curr_stat.st_gid);//打印文件所有者所在组
        // printf("%5ld ", curr_stat.st_size);//打印文件大小 字节计算  5个空位右对齐
        // print_time(curr_stat.st_mtime);//打印文件最后修改时间
        printf("%s ", currentdp->d_name); //打印当前文件名

        process_mycp(currentdp->d_name);
     }
     // printf("\n");
}

//创建一个子进程，用于复制文件到指定目录
void process_mycp(char *filename)
{

    pid_t pid_child, pid_return;
    pid_child = fork();
    if( pid_child < 0)
    {
    	printf("Error occured on forking.\n");
    }
    else if ( pid_child == 0 )
    {
    	// int result = execlp("src/mycp", "mycp", filename, "/home/niejun/test", NULL);
    	int result = execlp("/home/niejun/aos/lab/lab4/src/mycp", "mycp", filename, "/home/niejun/test", NULL);
    	if ( -1 == result)
    	{
			printf("execlp mycp error!\n");
		}
    	exit(0);
    }
    do{
    	pid_return = waitpid(pid_child, NULL, WNOHANG);

    }while( pid_return == 0 );

    if(pid_return != pid_child)
    {
    	printf("some error occured when wait mycp exiting!\n");
    }
}