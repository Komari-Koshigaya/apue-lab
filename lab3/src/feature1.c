# include <head.h>


int myls(char *path, int hide_file)
{

    DIR *currentdir;
    currentdir = opendir(path);   //�򿪵�ǰĿ¼����path�����·������ ��../src ������Ҫ���⴦��
    
    if(path == NULL)   
    {
        printf("invalid path"); 
        return -1;
    }
   
    if(currentdir == NULL)
    {
        printf("open directory fail\n");
        return -1;
    }
    
    struct dirent *currentdp;
    struct stat curr_stat;
    
    printf("file in %s include:\n\n", path);
    chdir(path);	//�ѹ���·���л���pathĿ¼��ʡȥ�˺����ȡ�ļ���Ϣ�ǣ�ƴ��Ŀ¼���ļ����Ĳ���
    while( (currentdp = readdir(currentdir)) != NULL )  //ѭ����ȡĿ¼�µ��ļ�
    {

    	if(hide_file && strncmp(currentdp->d_name, ".", 1) == 0)//�ж��Ƿ�ʱ�����ļ���������δָ�� -a ���򲻴�ӡ�����ļ�
    	{
    		continue;
    	}
        //�ֲ���������malloc�����ڴ�,strlen����'\0'��������Ҫ+1  ����ʹ���� chmod(path)  ����ƴ���ļ���ȫ�ƵĴ������ʡȥ
        // curr_file = (char *) malloc(strlen("/") + strlen(path) + strlen(currentdp->d_name) + 1);
        // sprintf(curr_file, "%s/%s", path, currentdp->d_name); //����curr_fileΪ ��ǰ·��/��ǰ�ļ���

        if( stat(currentdp->d_name, &curr_stat) < 0)//��ȡ�ļ������ԣ����ж��Ƿ��ȡ�ɹ�
        {
            printf("get stat error\n");
            continue;
        }

        print_type(curr_stat.st_mode);//��ӡ�ļ�����
        print_perm(curr_stat.st_mode);//��ӡ�ļ�Ȩ��
        printf("%ld ", curr_stat.st_nlink);//��ӡ�ļ�������
        print_uname(curr_stat.st_uid);//��ӡ�ļ� ������
        print_gname(curr_stat.st_gid);//��ӡ�ļ�������������
        printf("%5ld ", curr_stat.st_size);//��ӡ�ļ���С �ֽڼ���  5����λ�Ҷ���
        print_time(curr_stat.st_mtime);//��ӡ�ļ�����޸�ʱ��
        printf("%s\n", currentdp->d_name); //��ӡ��ǰ�ļ���
     }   

    printf("\n");
    closedir(currentdir);
    return 0;
}