#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    if( argc != 3)
    {
        printf("invalid argument!");
        return;
    }
    
    //��ȡԴ�ļ����ļ���
    char *p;
    if(NULL == rindex(argv[1],'/'))//���Դ�ļ�������Ŀ¼�����"/"
    {
        p = (char *) malloc(strlen("/") + strlen(argv[1]));
        sprintf(p, "%s%s", "/", argv[1]);
    }
    else{
        p = rindex(argv[1],'/');
    }
    //printf("%s\n",p);
    
    //����Ŀ���ļ���
    char *destpath = (char *) malloc(strlen(p) + strlen(argv[2]));
    sprintf(destpath, "%s%s", argv[2], p);
    printf("destpath is %s\n", destpath);
    
    

    struct stat st;
    stat(argv[2], &st);
    
    //ִ�и��Ƶ�Ŀ¼
    if( S_ISDIR(st.st_mode))
    {
        //printf("ִ�и��Ƶ�Ŀ¼");
        
        int inf = open(argv[1],O_RDONLY, 0);
        int outf = open(destpath, O_WRONLY|O_CREAT|O_TRUNC, 0600);
        char buf[1024];
        int i;
        do{//�����ļ�
            i = read(inf, buf, 4096);
            //printf("%s",buf);//��ӡbuf��ȡ��������
            write(outf, buf, i);
        }while(i);
        perror(argv[0]);
        close(outf);
        close(inf);
    }
    
}
