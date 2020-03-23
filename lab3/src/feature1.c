# include <head.h>


int myls(char *path)
{

    DIR *currentdir;
    currentdir = opendir(path);   //打开当前目录
    struct lstat *curr_lstat;
    
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
    printf("file in directory include:\n");
    while( (currentdp = readdir(currentdir)) != NULL )  //循环获取目录下的文件
    { 
        /*8lstat(currentdp->dname, curr_lstat);//获取文件的属性
        if( curr_lstat == NULL)
        {
            printf("get lstat error\n");
            continue;
        }*/
        
        printf("\n");
        printf("%s\n", currentdp->d_name);
     }   

    
    closedir(currentdir);
    return 0;
}