#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("invalid argument!\n");
        return -1;
    }

    pthread_t myls;
    int result = pthread_create(&myls,NULL,(void *)myls_with_cp,argv[1]);
    if( result != 0){
    	printf("thread creation failed\n");
		exit(1);
    }
    pthread_join(myls,NULL);
    perror(argv[0]);
    return 0;
}
