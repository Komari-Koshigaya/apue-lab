#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    char *curr_wd = get_current_dir_name();  //获取当前工作路径
    char buf[1024] = "";
    int hide_file = 1; //默认不显示隐藏文件
    if(argc == 1)
    {
    	getcwd(buf, sizeof(buf));  //若命令行没有参数，则打印当前目录的文件信息
    	myls(buf, hide_file);
    }
    else{
        //循环参数，查看是否有 -a，有则显示隐藏文件
        int i;
        for(i = 1; i < argc; i++)
        {
            if( strcmp("-a", argv[i]) == 0)
            {
                hide_file = 0;
                break;
            }
        }

        //若只有两个参数，且第二个参数是 -a，则打印当前目录的文件信息，含隐藏文件
        if(strcmp("-a", argv[1]) == 0 && argc == 2)
        {
            myls(curr_wd, hide_file);
        }

        // 若有多个参数，则循环打印多个目录下的文件信息
        for (i = 1; i < argc; ++i)
        {
            if(strcmp("-a", argv[i]) == 0)      continue;
            chdir(curr_wd); //多次打印不同目录下的文件信息时，为防止出现相对目录错误，每次打印前切换到当前进程最开始执行时的目录
            myls(argv[i], hide_file);
        }
    }

    perror(argv[0]);
    return 0;
}
