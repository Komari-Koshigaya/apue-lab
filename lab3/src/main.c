#include <head.h>

extern errorno;
int main(int argc,char *argv[])
{
    char *curr_wd = get_current_dir_name();
    myls(curr_wd);
    
    perror(argv[0]);
    return 0;
}
