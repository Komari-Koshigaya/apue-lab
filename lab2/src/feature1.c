# include <head.h>


void cp_to_file(char *srcfile, char *destfile)
{
    printf("srcfile : %s, destfile: %s\n\n", srcfile,destfile);
    int inf = open(srcfile,O_RDONLY, 0);
    int outf = open(destfile, O_CREAT|O_WRONLY|O_EXCL, 0600);
    char buf[BUFMAXLEN];
    int i;
    
    do{//�����ļ�
        i = read(inf, buf, BUFMAXLEN);
        //printf("%s",buf);//��ӡbuf��ȡ��������
        write(outf, buf, i);
    }while(i>0);//read������-1����ȡ��������0��Ϊ�˱������ʱ����ѭ��
    
    //perror("feature1.c/cp_to_file()");//��ӡcp_to_dir() ��������ʱ�Ĵ�����Ϣ
    close(outf);
    close(inf);
}
