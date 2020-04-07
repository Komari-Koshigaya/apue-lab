#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    char buf[1024] = "";
	char *target = get_current_dir_name();  //获取当前工作路径
    //若命令行没有参数，则打印当前目录的文件信息
    if(argc != 2 && argc != 1)
    {
    	printf("invalid argument!\n");
    	return;
    }
    if(argc == 2)
    {
        target = argv[1]; 
    }

	myls_with_cp(target);
    perror(argv[0]);
    return 0;
}
