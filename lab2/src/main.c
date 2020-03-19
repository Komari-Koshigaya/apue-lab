#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    if( argc != 3)
    {
        printf("invalid argument!");
        return;
    }
    
    //获取源文件的文件名
    char *p;
    if(NULL == rindex(argv[1],'/'))//如果源文件不包含目录间隔符"/"
    {
        p = (char *) malloc(strlen("/") + strlen(argv[1]));
        sprintf(p, "%s%s", "/", argv[1]);
    }
    else{
        p = rindex(argv[1],'/');
    }
    //printf("%s\n",p);
    
    //设置目标文件名
    char *destpath = (char *) malloc(strlen(p) + strlen(argv[2]));
    sprintf(destpath, "%s%s", argv[2], p);
    printf("destpath is %s\n", destpath);
    
    

    struct stat st;
    stat(argv[2], &st);
    
    //执行复制到目录
    if( S_ISDIR(st.st_mode))
    {
        //printf("执行复制到目录");
        
        int inf = open(argv[1],O_RDONLY, 0);
        int outf = open(destpath, O_WRONLY|O_CREAT|O_TRUNC, 0600);
        char buf[1024];
        int i;
        do{//复制文件
            i = read(inf, buf, 4096);
            //printf("%s",buf);//打印buf获取到的内容
            write(outf, buf, i);
        }while(i);
        perror(argv[0]);
        close(outf);
        close(inf);
    }
    
}
