#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    char *curr_wd = get_current_dir_name();  //获取当前工作路径
    char buf[1024] = "";
    if(argc == 1)
    {
    	getcwd(buf, sizeof(buf));  //若命令行没有参数，则打印当前目录的文件信息
    	myls(buf);
    }
    else
    {// 若有参数则打印指定目录下的文件信息
    	myls(argv[1]);  //若传的参数是相对路径，如 ：../src 并不需要特殊处理
    	int i = 2;
		while(i < argc)
		{// 若有多个参数，则循环打印多个目录下的文件信息
			chdir(curr_wd); //多次打印不同目录下的文件信息时，为防止出现相对目录错误，每次打印前切换到当前进程最开始执行时的目录
			myls(argv[i]);
			i++;
		}
    }
    
    perror(argv[0]);
    return 0;
}
