#include <head.h>

extern errorno;
pthread_mutex_t mutex[5] = PTHREAD_MUTEX_INITIALIZER;//5只筷子，互斥使用
int main(int argc,char *argv[])
{
    pthread_t phil[5];//哲学家进程
    int i;

    for(i = 0; i < 5; i++)
    {
    	int result = pthread_create(&phil[i],NULL,(void *)dining_thread, i);
	    if( result != 0){
	    	printf("thread creation failed\n");
			exit(1);
	    }
    }
    for(i = 0; i < 5; i++)
    {
    	 pthread_join(phil[i],NULL);
    }
   
    perror(argv[0]);
    return 0;
}

void *dining_thread(void *num)
{
	int philno = num;//哲学家编号
	printf("%d号哲学家开始思考\n", philno);
	sleep(1);//在Linux下,sleep()里面的单位是秒，而不是毫秒
	while(1){
		printf("%d号尝试拿起筷子\n", philno);
		pthread_mutex_lock(&mutex[philno]);//拿起左筷子
		//判断是否能拿起右筷子，若无法拿起，先释放左筷子，过后再试
		int result = pthread_mutex_trylock(&mutex[(philno+1)%5]);
		if( result != 0) //若拿起右筷子失败，则释放左筷子
		{
			pthread_mutex_unlock(&mutex[philno]);
			printf("%d号尝试拿起筷子失败，差一只，思考人生1s\n", philno);
			sleep(5);
			continue;
		}

		printf("%d号哲学家开始进餐\n", philno);
		sleep(5);
		printf("%d号进餐完毕，放下筷子\n", philno);
		pthread_mutex_unlock(&mutex[(philno+1)%5]);
		pthread_mutex_unlock(&mutex[philno]);
		break;
	}
}