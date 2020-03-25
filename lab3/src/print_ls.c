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
	printf("%s", (S_IRUSR & st_mode) ? "r" : "-");
	printf("%s", (S_IWUSR & st_mode) ? "w" : "-");
	printf("%s", (S_IXUSR & st_mode) ? "x" : "-");

	// �û������������
	printf("%s", (S_IRGRP & st_mode) ? "r" : "-");
	printf("%s", (S_IWGRP & st_mode) ? "w" : "-");
	printf("%s", (S_IXGRP & st_mode) ? "x" : "-");

	// �����û�����������
	printf("%s", (S_IROTH & st_mode) ? "r" : "-");
	printf("%s", (S_IWOTH & st_mode) ? "w" : "-");
	printf("%s", (S_IXOTH & st_mode) ? "x" : "-");

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
	struct passwd *user = NULL;
	user = getpwuid(st_uid);
	printf("%s", (*user).pw_name);
    printf(" ");
}

//��ӡ�ļ�������������
void print_gname(gid_t st_gid)
{
	struct group *group = NULL;
	group = getgrgid(st_gid);
	printf("%s", group->gr_name);
    printf(" ");
}

//��ӡ�ļ�����޸�ʱ��
void print_time(time_t st_mtimes)
{
	//12���·ݵ�Ӣ����д
	char *month[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm *mtime;
    mtime = localtime(&st_mtimes);
    //��ӡ�ļ������� ʱ��
    printf("%s %02d %02d:%02d:%02d", month[mtime->tm_mon], mtime->tm_mday, mtime->tm_hour, mtime->tm_min, mtime->tm_sec);
    printf(" ");
}