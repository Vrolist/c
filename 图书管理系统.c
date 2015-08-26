#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
	char book_name[30];
	int bianhao;
	double price;
	char author[20];
	char state[20];
	char name[20];
	char sex[10];
	int xuehao;
	struct book *book_next;
};
struct club{
	char name[20];
	char sex[10];
	int xuehao;
	char borrow[30];
	struct club *club_next;
};
void Print_Book(struct book *head_book);/*浏览所有图书信息*/
void Print_Club(struct club *head_club);/*浏览所有会员信息*/
struct book *Create_New_Book();/*创建新的图书库，图书编号输入为0时结束*/
struct book *Search_Book_bianhao(int bianhao,struct book *head_book);
struct book *Search_Book_name(char *b_name,struct book *head_book);
struct book *Search_Book_price(double price_h,double price_l,struct book *head_book);
struct book *Insert_Book(struct book *head_book,struct book *stud_book);/*增加图书，逐个添加*/
struct book *Delete_Book(struct book *head_book,int bianhao);/*删除图书*/
struct club *Create_New_Club();
struct club *Search_Club_xuehao(int xuehao,struct club *head_club);
struct club *Search_Club_name(char *c_name,struct club *head_club);
struct club *Insert_Club(struct club *head_club,struct club *stud_club);
struct club *Delete_Club(struct club *head_club,int xuehao);
struct book *Lent_Book(int bianhao,int xuehao,struct book *head_book,struct club *head_club);
struct book *back(int bianhao,int xuehao,struct book *head_book,struct club *head_club);
int main()
{
	struct book *head_book,*p_book;
	char book_name[30],name[20],author[20],sex[10];
	int bianhao;
	double price,price_h,price_l;
	int size_book=sizeof(struct book);
	int m=1,n=1,f;
	char *b_name,*c_name;
	struct club *head_club,*p_club;
	int xuehao;
	int size_club=sizeof(struct club);
	
	int choice;
    printf("/n欢迎您第一次进入图书管理系统!/n/n");
	printf("----->[向导]----->[新建图书库]/n/n");
	printf("注意:当输入图书编号为0时,进入下一步./n/n");
	head_book=Create_New_Book();
	system("cls");
	printf("/n欢迎您第一次进入图书管理系统!/n/n");
	printf("----->[向导]----->[新建会员库]/n/n");
	printf("注意:当输入会员学号为0时,进入主菜单./n/n");
	head_club=Create_New_Club();
	system("cls");
	do{ 
		printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
		printf("/n");
		printf("/t/t/t[1]:借书办理/t");printf(" [6]:还书办理/n");
		printf("/n");
		printf("/t/t/t[2]:查询图书/t");printf(" [7]:查询会员/n");
		printf("/t/t/t[3]:添加图书/t");printf(" [8]:添加会员/n");
		printf("/t/t/t[4]:删除图书/t");printf(" [9]:删除会员/n");
		printf("/t/t/t[5]:遍历图书/t");printf("[10]:遍历会员/n/n");
		printf("/t/t/t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓/n/n");
		printf("/t/t/t0:退出/n/n");
		printf("请选择<0~10>:");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("输入所借图书编号:/n");
			scanf("%d",&bianhao);
			printf("输入借书人的学号:/n");
			scanf("%d",&xuehao);
			head_book=Lent_Book(bianhao,xuehao,head_book,head_club);
			system("cls");
			printf("/n借阅成功!/n/n");
			printf("相关信息如下:/n/n");
			head_book=Search_Book_bianhao(bianhao,head_book);
			break;
		case 2:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("1.按编号查询/n/n");
			printf("2.按名称查询/n/n");
			printf("3.按价格区间查询/n/n");
			printf("0.返回主菜单/n/n");
			printf("请选择:");
			scanf("%d",&f);
			if(f==1){
				printf("请输入查询图书编号:");
			    scanf("%d",&bianhao);
			    printf("相关信息如下:/n/n");
			    head_book=Search_Book_bianhao(bianhao,head_book);
			    break;
			}
			else if(f==2){
				b_name=book_name;
				getchar();
				printf("请输入查询图书名称:");
			    gets(b_name);
			    printf("相关信息如下:/n/n");
			    head_book=Search_Book_name(b_name,head_book);
			    break;
			}
			else if(f==3){
				printf("请输入最高价格:");
				scanf("%lf",&price_h);
				printf("请输入最低价格:");
				scanf("%lf",&price_l);
				printf("相关信息如下:/n/n");
				head_book=Search_Book_price(price_h,price_l,head_book);
				break;
			}
			else if(f==0){
				break;
			}
			break;
		case 6:
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("输入所还图书编号:/n");
			scanf("%d",&bianhao);
			printf("输入还书人的学号:/n");
			scanf("%d",&xuehao);
			head_book=back(bianhao,xuehao,head_book,head_club);
			system("cls");
			printf("/n归还成功!/n/n");
			printf("相关信息如下:/n/n");
			head_book=Search_Book_bianhao(bianhao,head_book);
			break;
		case 3:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("请输入图书名称:");
	        scanf("%s",book_name);
	        printf("请输入图书编号:");
	        scanf("%d",&bianhao);
	        printf("请输入单价:");
	        scanf("%lf",&price);
	        printf("请输入作者名字:");
	        scanf("%s",author);
	        printf("/n");
			struct book *ptr_b;
	        for(ptr_b=head_book;ptr_b;ptr_b=ptr_b->book_next)
			{
			if(ptr_b->bianhao==bianhao)
			{
				printf("此编号图书已存在/n");
				m=0;
				break;
			}
			}
			if(m){
            p_book=(struct book *)malloc(size_book);
			strcpy(p_book->book_name,book_name);
		    p_book->bianhao=bianhao;
		    p_book->price=price;
		    p_book->xuehao=0;
		    strcpy(p_book->author,author);
		    strcpy(p_book->state,"存在");
		    strcpy(p_book->sex,"待定");
		    strcpy(p_book->name,"待定");
			head_book=Insert_Book(head_book,p_book);
			printf("/n添加图书成功!/n/n");
			}
			break;
		case 4:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("输入删除图书编号:/n");
			scanf("%d",&bianhao);
			head_book=Delete_Book(head_book,bianhao);
			printf("/n删除图书成功!/n/n");
			break;
		case 5:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			Print_Book(head_book);
			break;
		case 7:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("1.按学号查询/n/n");
			printf("2.按姓名查询/n/n");
			printf("0.返回主菜单/n/n");
			printf("请选择:");
			scanf("%d",&f);
			if(f==1){
				printf("请输入查询会员学号:");
			    scanf("%d",&xuehao);
			    printf("相关信息如下:/n/n");
			    head_club=Search_Club_xuehao(xuehao,head_club);
			    break;
			}
			else if(f==2){
				c_name=name;
				getchar();
				printf("请输入查询会员姓名:");
			    gets(c_name);
			    printf("相关信息如下:/n/n");
			    head_club=Search_Club_name(c_name,head_club);
			    break;
			}
			else if(f==0){
				break;
			}
			break;
			printf("请输入查询会员学号:/n");
			scanf("%d",&xuehao);
			printf("相关信息如下:/n/n");
			
			break;
		case 8:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("请输入会员名字:");
	        scanf("%s",name);
	        printf("请输入会员性别:");
	        scanf("%s",sex);
	        printf("请输入会员学号:");
	        scanf("%d",&xuehao);
	        printf("/n");
			struct club *ptr_c;
		    for(ptr_c=head_club;ptr_c;ptr_c=ptr_c->club_next)
			{
			if(ptr_c->xuehao==xuehao)
			{
				printf("此学号会员已存在/n");
				n=0;
				break;
			}
			}
		if(n){
			p_club=(struct club *)malloc(sizeof(struct club));
		    strcpy(p_club->name,name);
		    strcpy(p_club->sex,sex);
		    p_club->xuehao=xuehao;
		    strcpy(p_club->borrow,"暂无");
			head_club=Insert_Club(head_club,p_club);
			printf("/n添加会员成功!/n/n");
		}
			break;
		case 9:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("输入要删除会员学号:/n");
			scanf("%d",&xuehao);
			head_club=Delete_Club(head_club,xuehao);
			printf("/n删除会员成功!/n/n");
			break;
		case 10:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			Print_Club(head_club);
			break;
		case 0:
			system("cls");
			printf("/n/t/t/t〓〓〓〓〓图书管理系统〓〓〓〓〓/n/n");
			printf("/n谢谢您的使用!/n/n");
			break;
		}
	}while(choice!=0);
	
	return 0;
}
struct book *Create_New_Book()
{
	struct book *head_book,*p_book;
	int bianhao;
	double price;
	char book_name[30],author[20];
	int size_book=sizeof(struct book);
	
	head_book=NULL;
	printf("请输入图书名称:");
	scanf("%s",book_name);
	printf("请输入图书编号:");
	scanf("%d",&bianhao);
	printf("请输入单价:");
	scanf("%lf",&price);
	printf("请输入作者名字:");
	scanf("%s",author);
	printf("/n");	
	while(bianhao!=0){
		p_book=(struct book *)malloc(size_book);
		strcpy(p_book->book_name,book_name);
		p_book->bianhao=bianhao;
		p_book->price=price;
		p_book->xuehao=0;
		strcpy(p_book->author,author);
		strcpy(p_book->state,"存在");
		strcpy(p_book->sex,"待定");
		strcpy(p_book->name,"待定");
		head_book=Insert_Book(head_book,p_book);	
		printf("请输入图书名称:");
		scanf("%s",book_name);
		printf("请输入图书编号:");
		scanf("%d",&bianhao);
		printf("请输入单价:");
		scanf("%lf",&price);
		printf("请输入作者名字:");
		scanf("%s",author);
		printf("/n");
	}
	
	return head_book;
}
struct book *Search_Book_bianhao(int bianhao,struct book *head_book)
{
	struct book *ptr_book;
	int flag=0;
	for(ptr_book=head_book;ptr_book;ptr_book=ptr_book->book_next)
	{
		if(ptr_book->bianhao==bianhao){
			printf("图书编号:%d/n",ptr_book->bianhao);
			printf("图书名称:%s/n",ptr_book->book_name);
			printf("图书单价:%.2lf/n",ptr_book->price);
			printf("图书作者:%s/n",ptr_book->author);
			printf("存在状态:%s/n",ptr_book->state);
			printf("借书人姓名:%s/n",ptr_book->name);
			printf("借书人性别:%s/n",ptr_book->sex);
			printf("学号:%d/n",ptr_book->xuehao);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("暂无此图书信息!/n/n");
	}
	return head_book;
}
struct book *Search_Book_name(char *b_name,struct book *head_book)
{
	struct book *ptr_book;
	int flag=0;
	for(ptr_book=head_book;ptr_book;ptr_book=ptr_book->book_next)
	{
		if(strcmp(ptr_book->book_name,b_name)==0){
			printf("图书编号:%d/n",ptr_book->bianhao);
			printf("图书名称:%s/n",ptr_book->book_name);
			printf("图书单价:%.2lf/n",ptr_book->price);
			printf("图书作者:%s/n",ptr_book->author);
			printf("存在状态:%s/n",ptr_book->state);
			printf("借书人姓名:%s/n",ptr_book->name);
			printf("借书人性别:%s/n",ptr_book->sex);
			printf("学号:%d/n",ptr_book->xuehao);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("暂无此图书信息!/n/n");
	}
	return head_book;
}
struct book *Search_Book_price(double price_h,double price_l,struct book *head_book)
{
	struct book *ptr_book;
	int flag=0;
	for(ptr_book=head_book;ptr_book;ptr_book=ptr_book->book_next)
	{
		if((ptr_book->price>=price_l)&&(ptr_book->price<=price_h)){
			printf("图书编号:%d/n",ptr_book->bianhao);
			printf("图书名称:%s/n",ptr_book->book_name);
			printf("图书单价:%.2lf/n",ptr_book->price);
			printf("图书作者:%s/n",ptr_book->author);
			printf("存在状态:%s/n",ptr_book->state);
			printf("借书人姓名:%s/n",ptr_book->name);
			printf("借书人性别:%s/n",ptr_book->sex);
			printf("学号:%d/n",ptr_book->xuehao);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("暂无此图书信息!/n/n");
	}
	return head_book;
}
struct book *Delete_Book(struct book *head_book,int bianhao)
{
	struct book *ptr1_book,*ptr2_book;
	
	while(head_book!=NULL && head_book->bianhao==bianhao){
		ptr2_book=head_book;
		head_book=head_book->book_next;
		free(ptr2_book);
	}
	if(head_book==NULL)
		return NULL;
	
	ptr1_book=head_book;
	ptr2_book=head_book->book_next;
	while(ptr2_book!=NULL){
		if(ptr2_book->bianhao==bianhao){
			ptr1_book->book_next=ptr2_book->book_next;
			free(ptr2_book);
		}
		else
			ptr1_book=ptr2_book;
		ptr2_book=ptr1_book->book_next;
	}
	
	return head_book;
}
struct club *Create_New_Club()
{
	struct club *head_club,*p_club;
	int xuehao;
	char name[20],sex[10];
	int size_club=sizeof(struct club);
	
	head_club=NULL;
	printf("请输入会员名字:");
	scanf("%s",name);
	printf("请输入会员性别:");
	scanf("%s",sex);
	printf("请输入会员学号:");
	scanf("%d",&xuehao);
	printf("/n");
	
	while(xuehao!=0){
		p_club=(struct club *)malloc(size_club);
		strcpy(p_club->name,name);
		strcpy(p_club->sex,sex);
		p_club->xuehao=xuehao;
		strcpy(p_club->borrow,"暂无");
		
		head_club=Insert_Club(head_club,p_club);
		
		printf("请输入会员名字:");
		scanf("%s",name);
		printf("请输入会员性别:");
		scanf("%s",sex);
		printf("请输入会员学号:");
		scanf("%d",&xuehao);
		printf("/n");
	}
	
	return head_club;
}
struct club *Search_Club_xuehao(int xuehao,struct club *head_club)
{
	struct club *ptr_club;
	int flag=0;
	for(ptr_club=head_club;ptr_club;ptr_club=ptr_club->club_next)
	{
		if(ptr_club->xuehao==xuehao){
			printf("会员姓名:%s/n",ptr_club->name);
			printf("会员性别:%s/n",ptr_club->sex);
			printf("会员学号:%d/n",ptr_club->xuehao);
			printf("所借图书:%s/n",ptr_club->borrow);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("此用户不存在!/n/n");
	}
	return head_club;
}
struct club *Search_Club_name(char *c_name,struct club *head_club)
{
	struct club *ptr_club;
	int flag=0;
	for(ptr_club=head_club;ptr_club;ptr_club=ptr_club->club_next)
	{
		if(strcmp(ptr_club->name,c_name)==0){
			printf("会员姓名:%s/n",ptr_club->name);
			printf("会员性别:%s/n",ptr_club->sex);
			printf("会员学号:%d/n",ptr_club->xuehao);
			printf("所借图书:%s/n",ptr_club->borrow);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("此用户不存在!/n/n");
	}
	return head_club;
}
struct book *Lent_Book(int bianhao,int xuehao,struct book *head_book,struct club *head_club)
{
	struct book *ptr_book;
	struct club *ptr_club;
	int flag=0;
	
	for(ptr_book=head_book;ptr_book;ptr_book=ptr_book->book_next)
		for(ptr_club=head_club;ptr_club;ptr_club=ptr_club->club_next)
		{
			if((ptr_book->bianhao==bianhao)&&(ptr_club->xuehao==xuehao))
			{
				strcpy(ptr_book->name,ptr_club->name);   /*字符串的复制，把右边的内容复制到左边*/
				strcpy(ptr_book->sex,ptr_club->sex);
				ptr_book->xuehao=ptr_club->xuehao;
				strcpy(ptr_book->state,"暂无");
				strcpy(ptr_club->borrow,ptr_book->book_name);
				flag++;
			}
			if(flag==0){
				printf("暂无此图书或您还未注册为会员!/n/n");
			}
		}
		
		return head_book;
}
struct book *back(int bianhao,int xuehao,struct book *head_book,struct club *head_club)
{
	struct book *ptr_book;
	struct club *ptr_club;
	int flag=0;
	
	for(ptr_book=head_book;ptr_book;ptr_book=ptr_book->book_next)
		for(ptr_club=head_club;ptr_club;ptr_club=ptr_club->club_next)
		{
			if((ptr_book->bianhao==bianhao) && (ptr_club->xuehao==xuehao))
			{
				strcpy(ptr_book->name,"暂无");
				strcpy(ptr_book->sex,"待定");
				ptr_book->xuehao=0;
				strcpy(ptr_book->state,"暂无");
				strcpy(ptr_club->borrow,"暂无");
				flag++;
			}
			if(flag==0){
				printf("输入有误，请重试/n/n");
			}
		}
		
		return head_book;
}
struct book *Insert_Book(struct book *head_book,struct book *stud_book)
{
	struct book *ptr_b,*ptr1_b,*ptr2_b;
	ptr2_b=head_book;
	ptr_b=stud_book;
	if(head_book==NULL){
		head_book=ptr_b;
		head_book->book_next=NULL;
	}
	else{
		while((ptr_b->bianhao > ptr2_b->bianhao) && (ptr2_b->book_next!=NULL)){
			ptr1_b=ptr2_b;
			ptr2_b=ptr2_b->book_next;
		}
		if(ptr_b->bianhao <= ptr2_b->bianhao){
			if(head_book==ptr2_b) head_book=ptr_b;
			else ptr1_b->book_next=ptr_b;
			ptr_b->book_next=ptr2_b;
		}
		else{
			ptr2_b->book_next=ptr_b;
			ptr_b->book_next=NULL;
		}
	}
	return head_book;
}
struct club *Insert_Club(struct club *head_club,struct club *stud_club)
{
	struct club *ptr_c,*ptr1_c,*ptr2_c;
	ptr2_c=head_club;
	ptr_c=stud_club;
	if(head_club==NULL){
		head_club=ptr_c;
		head_club->club_next=NULL;
	}
	else{
		while((ptr_c->xuehao > ptr2_c->xuehao) && (ptr2_c->club_next!=NULL)){
			ptr1_c=ptr2_c;
			ptr2_c=ptr2_c->club_next;
		}
		if(ptr_c->xuehao <= ptr2_c->xuehao){
			if(head_club==ptr2_c) head_club=ptr_c;
			else ptr1_c->club_next=ptr_c;
			ptr_c->club_next=ptr2_c;
		}
		else{
			ptr2_c->club_next=ptr_c;
			ptr_c->club_next=NULL;
		}
	}
	return head_club;
}
void Print_Club(struct club *head_club)
{
	struct club *ptr_c;
	if(head_club==NULL){
		printf("/n无记录/n/n");
		return;
	}
	printf("/n会员姓名/t会员性别/t会员学号/n/n");
	for(ptr_c=head_club;ptr_c;ptr_c=ptr_c->club_next)
		printf("%s/t/t%s/t/t%d/n",ptr_c->name,ptr_c->sex,ptr_c->xuehao);
}
struct club *Delete_Club(struct club *head_club,int xuehao)
{
	struct club *ptr1_club,*ptr2_club;
	
	while(head_club!=NULL && head_club->xuehao==xuehao){
		ptr2_club=head_club;
		head_club=head_club->club_next;
		free(ptr2_club);
	}
	if(head_club==NULL)
		return NULL;
	
	ptr1_club=head_club;
	ptr2_club=head_club->club_next;
	while(ptr2_club!=NULL){
		if(ptr2_club->xuehao==xuehao){
			ptr1_club->club_next=ptr2_club->club_next;
			free(ptr2_club);
		}
		else
			ptr1_club=ptr2_club;
		ptr2_club=ptr1_club->club_next;
	}
	
	return head_club;
}
void Print_Book(struct book *head_book)
{
	struct book *ptr_b;
	if(head_book==NULL){
		printf("/n无记录/n/n");
		return;
	}
	printf("/n图书编号/t图书名称/t图书单价/t图书作者/n/n");
	for(ptr_b=head_book;ptr_b;ptr_b=ptr_b->book_next)
		printf("%d/t/t%s/t/t%.2lf/t/t%s/n/n",ptr_b->bianhao,ptr_b->book_name,ptr_b->price,ptr_b->author);
}