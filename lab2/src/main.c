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
    if( stat(argv[2], &st))   // 该条件代表目标文件或文件夹不存在，则执行复制到文件
    {
        printf("copy to file！\n");
        cp_to_file(argv[1], argv[2]);
        return 0;
    }
    //stat(argv[2], &st);
    if( S_ISDIR(st.st_mode ))   //执行复制到目录
    {    
        cp_to_dir(argv[1], argv[2]);
    }
    perror(argv[0]);
}
