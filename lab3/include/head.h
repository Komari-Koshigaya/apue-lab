#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int myls(char *path);   //��ӡ��ǰ����Ŀ¼���ļ���Ϣ

void print_type(mode_t st_mode);  //��ӡ�ļ�����

void print_perm(mode_t st_mode);//��ӡ�ļ�Ȩ��

void print_link(nlink_t st_nlink);//��ӡ�ļ�������

void print_uname(uid_t st_uid);//��ӡ�ļ� ������

void print_gname(gid_t st_gid);//��ӡ�ļ�������������

void print_time(time_t st_mtime);//��ӡ�ļ�����޸�ʱ��
