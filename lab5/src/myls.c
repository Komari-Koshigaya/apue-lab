# include <head.h>

//打印当前工作目录的文件信息，并且复制非目录文件
void * myls_with_cp(void *src_path)
{
    char *path = (char *)src_path;
    DIR *currentdir = opendir(path);

    if(path == NULL)   
    {
        printf("invalid path"); 
        return;
    }
   
    if(currentdir == NULL)
    {
        printf("open directory fail\n");
        return;
    }

	chdir(path);
	print_directory(currentdir, 0);

    chdir("..");
    closedir(currentdir);
}

// DIR *currentdir 目录文件, int trav_subdi 是否遍历子目录，1代表遍历，0遍历
int print_directory(DIR *currentdir, int trav_subdir)
{
	struct dirent *currentdp;
    struct stat curr_stat;
    while( (currentdp = readdir(currentdir)) != NULL )  //循环获取目录下的文件
    {

    	if( strncmp(currentdp->d_name, ".", 1) == 0 )
    	{
    		continue;
    	}

        if( stat(currentdp->d_name, &curr_stat) < 0)//获取文件的属性，并判断是否获取成功
        {
            printf("get stat error\n");
            continue;
        }
        if( S_ISDIR(curr_stat.st_mode) ){
            printf("\033[40;32m%s \033[0m ", currentdp->d_name); //打印当前绿色目录名
            continue;
        }
        printf("%s ", currentdp->d_name); //打印当前文件名
		

        thread_mycp(currentdp->d_name);//若非目录文件，则复制该文件
     }
     printf("\n");
}


//创建一个子线程程，用于复制文件到指定目录
void thread_mycp(char *filename)
{
    pthread_t thread_mycp;
    int result = pthread_create(&thread_mycp,NULL,(void *)mycp,filename);
    if( result != 0){
        printf("thread creation failed\n");
        exit(1);
    }
    // pthread_join(thread_mycp,NULL); //此方法使得 cp操作串行进行，改用 在main中 使用pthread_exit(0);

}