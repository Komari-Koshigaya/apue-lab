#include <head.h>

//��ӡ�ļ�����
void print_type(mode_t st_mode)  
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


//��ӡ�ļ�Ȩ��
void print_perm(mode_t st_mode)
{
	// �û�����������
	if(S_IRUSR & st_mode)		printf("r");
	else						printf("-");
	if(S_IWUSR & st_mode)		printf("w");
	else						printf("-");
	if(S_IXUSR & st_mode)		printf("x");
	else						printf("-");

	// �û������������
	if(S_IRGRP & st_mode)		printf("r");
	else						printf("-");
	if(S_IWGRP & st_mode)		printf("w");
	else						printf("-");
	if(S_IXGRP & st_mode)		printf("x");
	else						printf("-");

	// �����û�����������
	if(S_IROTH & st_mode)		printf("r");
	else						printf("-");
	if(S_IWOTH & st_mode)		printf("w");
	else						printf("-");
	if(S_IXOTH & st_mode)		printf("x");
	else						printf("-");
	printf(" ");
}

//��ӡ�ļ�������
void print_link(nlink_t st_nlink)
{
    printf(" ");
}

//��ӡ�ļ� ������
void print_uname(uid_t st_uid)
{
    printf(" ");
}

//��ӡ�ļ�������������
void print_gname(gid_t st_gid)
{
    printf(" ");
}

//��ӡ�ļ�����޸�ʱ��
// void print_time(time_t st_mtime)
// {
//     printf(" ");
// }