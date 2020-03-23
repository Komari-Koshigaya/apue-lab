# include <head.h>


int myls(char *path)
{

    DIR *currentdir;
    currentdir = opendir(path);   //�򿪵�ǰĿ¼
    
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
    char *curr_file;    //��ǰ�ļ���������·������ /home/niejun/test.txt
    struct stat curr_stat;
    printf("file in %s include:\n", path);
    while( (currentdp = readdir(currentdir)) != NULL )  //ѭ����ȡĿ¼�µ��ļ�
    {
        
        curr_file = (char *) malloc(strlen("/") + strlen(path) + strlen(currentdp->d_name));
        sprintf(curr_file, "%s/%s", path, currentdp->d_name); //����curr_fileΪ ��ǰ·��/��ǰ�ļ���
        //stat(curr_file, &curr_stat);//��ȡ�ļ�������
        //printf("%s\n", curr_file);
        
        if( stat(curr_file, &curr_stat) < 0)
        {
            printf("get stat error\n");
            continue;
        }
        print_type(curr_stat.st_mode);//��ӡ�ļ�����
        print_perm(curr_stat.st_mode);//��ӡ�ļ�Ȩ��
        print_link(curr_stat.st_nlink);//��ӡ�ļ�������
        print_uname(curr_stat.st_uid);//��ӡ�ļ� ������
        print_gname(curr_stat.st_gid);//��ӡ�ļ�������������
        //print_size(curr_stat.st_size);//��ӡ�ļ���С
        print_time(curr_stat.st_mtime);//��ӡ�ļ�����޸�ʱ��
        
        
        printf("%s\n", currentdp->d_name); //��ӡ��ǰ�ļ���
     }   

    
    closedir(currentdir);
    return 0;
}