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
    
    //ִ�и��Ƶ�Ŀ¼
    if( S_ISDIR(st.st_mode))
    {
        //printf("ִ�и��Ƶ�Ŀ¼");
        cp_to_dir(argv[1], argv[2]);
    }
    else{
        //printf("ִ�и��Ƶ��ļ�");
        cp_to_file(argv[1], argv[2]);
    }
    perror(argv[0]);
}
