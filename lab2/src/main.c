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
    if( stat(argv[2], &st))   // ����������Ŀ���ļ����ļ��в����ڣ���ִ�и��Ƶ��ļ�
    {
        printf("copy to file��\n");
        cp_to_file(argv[1], argv[2]);
        return 0;
    }
    //stat(argv[2], &st);
    if( S_ISDIR(st.st_mode ))   //ִ�и��Ƶ�Ŀ¼
    {    
        cp_to_dir(argv[1], argv[2]);
    }
    perror(argv[0]);
}
