#include <head.h>

void print_type(mode_t st_mode)  //��ӡ�ļ�����
{
    if(S_ISREG(st_mode))//��ͨ�ļ�
    {
        printf("-");
    }
    else if(S_ISDIR(st_mode))//Ŀ¼�ļ�
    {
        printf("d");
    }
    else if(S_ISCHR(st_mode))//�ַ��豸
    {
        printf("c");
    }
    else if(S_ISBLK(st_mode))//���豸
    {
        printf("b");
    }
    else if(S_ISFIFO(st_mode))//FIFO�ܵ�
    {
        printf("p");
    }
    else if(S_ISSOCK(st_mode))//�׽���
    {
        printf("s");
    }       
    else if(S_ISLNK(st_mode))//��������
    {
        printf("l");
    }else{
        printf(";");
    }
}