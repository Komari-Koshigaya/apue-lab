#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
	char *dir = get_current_dir_name();  //获取当前工作路径

    if(argc > 2)
    {
        printf("invalid argument!\n");
        return -1;
    }
	if(argc == 2)
    {
        dir = argv[1];
    }
	// printf("%s\n", dir);
    	
    pthread_t myls;
    int result = pthread_create(&myls,NULL,(void *)myls_with_cp,dir);
    if( result != 0){
    	printf("thread creation failed\n");
		exit(1);
    }
    pthread_join(myls,NULL);
    perror(argv[0]);
    return 0;
}
