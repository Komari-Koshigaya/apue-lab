# include <head.h>


void cp_to_file(char *srcfile, char *destfile)
{
    printf("srcfile : %s, destfile: %s\n\n", srcfile,destfile);
    int inf = open(srcfile,O_RDONLY, 0);
    int outf = open(destfile, O_CREAT|O_WRONLY|O_EXCL, 0600);
    char buf[BUFMAXLEN];
    int i;
    
    do{//复制文件
        i = read(inf, buf, BUFMAXLEN);
        //printf("%s",buf);//打印buf获取到的内容
        write(outf, buf, i);
    }while(i>0);//read出错返回-1，读取结束返回0，为了避免出错时的死循环
    
    //perror("feature1.c/cp_to_file()");//打印cp_to_dir() 函数调用时的错误信息
    close(outf);
    close(inf);
}
