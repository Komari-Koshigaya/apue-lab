#include <head.h>

extern errorno;
void cp_to_dir(char *srcfile, char *destpath)
{
    //获取源文件的文件名
    char *p;
    if(NULL == rindex(srcfile,'/'))//如果源文件不包含目录间隔符"/"
    {
        p = (char *) malloc(strlen("/") + strlen(srcfile));
        sprintf(p, "%s%s", "/", srcfile);
    }
    else{
        p = rindex(srcfile,'/');
    }
    
    //设置目标文件名
    char *destfile = (char *) malloc(strlen(p) + strlen(destpath));
    sprintf(destfile, "%s%s", destpath, p);
    printf("srcfile : %s, destfile: %s\n\n", srcfile,destfile);
    
    int inf = open(srcfile,O_RDONLY, 0);
    int outf = open(destfile, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    char buf[BUFMAXLEN]={0};
    int i;
    do{//复制文件
        i = read(inf, buf, BUFMAXLEN);
        //printf("%s",buf);//打印buf获取到的内容
        write(outf, buf, i);
    }while(i>0);//read出错返回-1，读取结束返回0，为了避免出错时的死循环
    
    perror("feature2.c/cp_todir()");//打印cp_to_dir() 函数调用时的错误信息
    close(outf);
    close(inf);
}
