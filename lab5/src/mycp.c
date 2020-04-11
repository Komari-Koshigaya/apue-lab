#include <head.h>

extern errorno;
void * mycp(void *filename)
{
    //获取源文件的文件名
    char * srcfile = (char *)filename;
    const char *destpath = "/home/niejun/test";
    char *p;
    if(NULL == rindex(srcfile,'/'))//如果源文件不包含目录间隔符"/"
    {
        p = (char *) malloc(strlen("/") + strlen(srcfile));
        sprintf(p, "%s%s", "/", srcfile);
    }
    else{
        p = rindex(srcfile,'/');
    }
    
    if(access(destpath,0)==-1)//access函数查看待复制的目录是否存在
	{
	    if (mkdir(destpath,0777))//如果不存在就用mkdir函数来创建
		{
		   printf("creat dir failed!!!");
		}
	} 

    //设置目标文件名
    char *destfile = (char *) malloc(strlen(p) + strlen(destpath));
    sprintf(destfile, "%s%s", destpath, p);
    // printf("srcfile : %s, destfile: %s\n\n", srcfile,destfile);
    
    int inf = open(srcfile,O_RDONLY, 0);
    int outf = open(destfile, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    char buf[1024]={0};
    int i;
    do{//复制文件
        i = read(inf, buf, 1024);
        //printf("%s",buf);//打印buf获取到的内容
        write(outf, buf, i);
    }while(i>0);//read出错返回-1，读取结束返回0，为了避免出错时的死循环
    
    close(outf);
    close(inf);
}
