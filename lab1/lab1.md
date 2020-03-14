# 实验内容
##### 内容一： 在Linux下通过C语言程序设计链表应用程序

1. 定义单向链表的数据结构
2. 创建链表
3. 插入节点
4. 遍历节点等

##### 内容二： Linux下通过GNU工具链编译、调试、运行该程序



# 编译
项目改用cmake组织
进入项目根目录,本实验是进入 lab1 目录
 先后执行

~~~shell
mkdir build # 在项目根目录新建 build 文件夹
cd build    # 在build目录编译，使得所有中间文件在build下
cmake ..    # cmake 编译父目录
make   
./../bin/student # 生成的程序在 ../bin下,文件名是 student
~~~
程序便开始运行了



# 实验运行情况：

1. 先创建个不带头的单向空链表
2. 而后选择插入值
3. 再将链表遍历打印

![QQ截图20200311155128](运行截图.png)



# 源代码如下

~~~c
#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    long stu_id;     //学号
    char name[20];   //姓名
    
    struct student *next; //指针域
}student, *List;

struct student *create_list()
{
    struct student *head;
    head = NULL;
    return head;
}
void print_list(List head)
{
	List rear = head;
	if(rear == NULL){
		printf("This list is NULL!\n");
		return;
	}
	printf("该生学号为： %ld ， 姓名为： %s \n", rear->stu_id,rear->name);
	while(rear->next != NULL){
		rear = rear->next;
		printf("该生学号为： %ld ， 姓名为： %s \n", rear->stu_id,rear->name);
	}
	return;
}
List insert_list(List head)
{
	List temp, rear = head;
	temp = (List)malloc(sizeof(student));

	printf("请输入学号：\n");
	scanf("%ld",&temp->stu_id);
	printf("请输入姓名：\n");
	scanf("%s",&temp->name);

	if(head == NULL)
	{
		head = temp;
		head->next = NULL;
	}else
	{
		while(rear->next != NULL){
			rear = rear->next;
		}
		rear->next = temp;
		rear = temp;
		rear->next=NULL;
	}
	print_list(head);
	return head;
}



int main()
{
	List head;
	while(1){
		printf("————————————\t %40s \t————————————\n","please choose one operation");
	    printf("————————————\t %40s \t————————————\n","1.create a new single link list");
	    printf("————————————\t %40s \t————————————\n","2.insert value into single link list");
	    printf("————————————\t %40s \t————————————\n","3.print single link list");
	    printf("————————————\t %40s \t————————————\n","0.exit program");

	    char oper = getchar();
	    
	    switch(oper)
	    {
	    	case '0': 
	        		printf("你选择的是退出程序!byebye!\n");
	        		exit(0);
	        case '1': 
	        		printf("你选择的是创建链表!\n");
	        		head = create_list();
	        		break;
	        case '2': 
	        		printf("你选择的是插入节点!\n");
	        		head = insert_list(head);
	        		break;
	        case '3': 
	        		printf("你选择的是打印链表!\n");
	        		print_list(head);
	        		break;
	        		
	        default: 
	        		printf("invalid operation number!byebye!\n");
	                break;
	                  
	    }
	    printf("\n\n");getchar();
	}
    
}

~~~

