#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    if( argc != 3)
    {
        printf("invalid argument!");
        return;
    }

    struct stat st;
    stat(argv[2], &st);
    
    //执行复制到目录
    if( S_ISDIR(st.st_mode))
    {
        //printf("执行复制到目录");
        cp_to_dir(argv[1], argv[2]);
    }
    else{
        //printf("执行复制到文件");
        cp_to_file(argv[1], argv[2]);
    }
    perror(argv[0]);
}
