#include <head.h>

extern errorno;
void cp_to_dir(char *srcfile, char *destpath)
{
    //��ȡԴ�ļ����ļ���
    char *p;
    if(NULL == rindex(srcfile,'/'))//���Դ�ļ�������Ŀ¼�����"/"
    {
        p = (char *) malloc(strlen("/") + strlen(srcfile));
        sprintf(p, "%s%s", "/", srcfile);
    }
    else{
        p = rindex(srcfile,'/');
    }
    
    //����Ŀ���ļ���
    char *destfile = (char *) malloc(strlen(p) + strlen(destpath));
    sprintf(destfile, "%s%s", destpath, p);
    printf("srcfile : %s, destfile: %s\n\n", srcfile,destfile);
    
    int inf = open(srcfile,O_RDONLY, 0);
    int outf = open(destfile, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    char buf[BUFMAXLEN]={0};
    int i;
    do{//�����ļ�
        i = read(inf, buf, BUFMAXLEN);
        //printf("%s",buf);//��ӡbuf��ȡ��������
        write(outf, buf, i);
    }while(i>0);//read������-1����ȡ��������0��Ϊ�˱������ʱ����ѭ��
    
    perror("feature2.c/cp_todir()");//��ӡcp_to_dir() ��������ʱ�Ĵ�����Ϣ
    close(outf);
    close(inf);
}
