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
void Print_Book(struct book *head_book);/*�������ͼ����Ϣ*/
void Print_Club(struct club *head_club);/*������л�Ա��Ϣ*/
struct book *Create_New_Book();/*�����µ�ͼ��⣬ͼ��������Ϊ0ʱ����*/
struct book *Search_Book_bianhao(int bianhao,struct book *head_book);
struct book *Search_Book_name(char *b_name,struct book *head_book);
struct book *Search_Book_price(double price_h,double price_l,struct book *head_book);
struct book *Insert_Book(struct book *head_book,struct book *stud_book);/*����ͼ�飬������*/
struct book *Delete_Book(struct book *head_book,int bianhao);/*ɾ��ͼ��*/
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
    printf("/n��ӭ����һ�ν���ͼ�����ϵͳ!/n/n");
	printf("----->[��]----->[�½�ͼ���]/n/n");
	printf("ע��:������ͼ����Ϊ0ʱ,������һ��./n/n");
	head_book=Create_New_Book();
	system("cls");
	printf("/n��ӭ����һ�ν���ͼ�����ϵͳ!/n/n");
	printf("----->[��]----->[�½���Ա��]/n/n");
	printf("ע��:�������Աѧ��Ϊ0ʱ,�������˵�./n/n");
	head_club=Create_New_Club();
	system("cls");
	do{ 
		printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
		printf("/n");
		printf("/t/t/t[1]:�������/t");printf(" [6]:�������/n");
		printf("/n");
		printf("/t/t/t[2]:��ѯͼ��/t");printf(" [7]:��ѯ��Ա/n");
		printf("/t/t/t[3]:���ͼ��/t");printf(" [8]:��ӻ�Ա/n");
		printf("/t/t/t[4]:ɾ��ͼ��/t");printf(" [9]:ɾ����Ա/n");
		printf("/t/t/t[5]:����ͼ��/t");printf("[10]:������Ա/n/n");
		printf("/t/t/t��������������������������������/n/n");
		printf("/t/t/t0:�˳�/n/n");
		printf("��ѡ��<0~10>:");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("��������ͼ����:/n");
			scanf("%d",&bianhao);
			printf("��������˵�ѧ��:/n");
			scanf("%d",&xuehao);
			head_book=Lent_Book(bianhao,xuehao,head_book,head_club);
			system("cls");
			printf("/n���ĳɹ�!/n/n");
			printf("�����Ϣ����:/n/n");
			head_book=Search_Book_bianhao(bianhao,head_book);
			break;
		case 2:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("1.����Ų�ѯ/n/n");
			printf("2.�����Ʋ�ѯ/n/n");
			printf("3.���۸������ѯ/n/n");
			printf("0.�������˵�/n/n");
			printf("��ѡ��:");
			scanf("%d",&f);
			if(f==1){
				printf("�������ѯͼ����:");
			    scanf("%d",&bianhao);
			    printf("�����Ϣ����:/n/n");
			    head_book=Search_Book_bianhao(bianhao,head_book);
			    break;
			}
			else if(f==2){
				b_name=book_name;
				getchar();
				printf("�������ѯͼ������:");
			    gets(b_name);
			    printf("�����Ϣ����:/n/n");
			    head_book=Search_Book_name(b_name,head_book);
			    break;
			}
			else if(f==3){
				printf("��������߼۸�:");
				scanf("%lf",&price_h);
				printf("��������ͼ۸�:");
				scanf("%lf",&price_l);
				printf("�����Ϣ����:/n/n");
				head_book=Search_Book_price(price_h,price_l,head_book);
				break;
			}
			else if(f==0){
				break;
			}
			break;
		case 6:
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("��������ͼ����:/n");
			scanf("%d",&bianhao);
			printf("���뻹���˵�ѧ��:/n");
			scanf("%d",&xuehao);
			head_book=back(bianhao,xuehao,head_book,head_club);
			system("cls");
			printf("/n�黹�ɹ�!/n/n");
			printf("�����Ϣ����:/n/n");
			head_book=Search_Book_bianhao(bianhao,head_book);
			break;
		case 3:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("������ͼ������:");
	        scanf("%s",book_name);
	        printf("������ͼ����:");
	        scanf("%d",&bianhao);
	        printf("�����뵥��:");
	        scanf("%lf",&price);
	        printf("��������������:");
	        scanf("%s",author);
	        printf("/n");
			struct book *ptr_b;
	        for(ptr_b=head_book;ptr_b;ptr_b=ptr_b->book_next)
			{
			if(ptr_b->bianhao==bianhao)
			{
				printf("�˱��ͼ���Ѵ���/n");
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
		    strcpy(p_book->state,"����");
		    strcpy(p_book->sex,"����");
		    strcpy(p_book->name,"����");
			head_book=Insert_Book(head_book,p_book);
			printf("/n���ͼ��ɹ�!/n/n");
			}
			break;
		case 4:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("����ɾ��ͼ����:/n");
			scanf("%d",&bianhao);
			head_book=Delete_Book(head_book,bianhao);
			printf("/nɾ��ͼ��ɹ�!/n/n");
			break;
		case 5:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			Print_Book(head_book);
			break;
		case 7:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("1.��ѧ�Ų�ѯ/n/n");
			printf("2.��������ѯ/n/n");
			printf("0.�������˵�/n/n");
			printf("��ѡ��:");
			scanf("%d",&f);
			if(f==1){
				printf("�������ѯ��Աѧ��:");
			    scanf("%d",&xuehao);
			    printf("�����Ϣ����:/n/n");
			    head_club=Search_Club_xuehao(xuehao,head_club);
			    break;
			}
			else if(f==2){
				c_name=name;
				getchar();
				printf("�������ѯ��Ա����:");
			    gets(c_name);
			    printf("�����Ϣ����:/n/n");
			    head_club=Search_Club_name(c_name,head_club);
			    break;
			}
			else if(f==0){
				break;
			}
			break;
			printf("�������ѯ��Աѧ��:/n");
			scanf("%d",&xuehao);
			printf("�����Ϣ����:/n/n");
			
			break;
		case 8:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("�������Ա����:");
	        scanf("%s",name);
	        printf("�������Ա�Ա�:");
	        scanf("%s",sex);
	        printf("�������Աѧ��:");
	        scanf("%d",&xuehao);
	        printf("/n");
			struct club *ptr_c;
		    for(ptr_c=head_club;ptr_c;ptr_c=ptr_c->club_next)
			{
			if(ptr_c->xuehao==xuehao)
			{
				printf("��ѧ�Ż�Ա�Ѵ���/n");
				n=0;
				break;
			}
			}
		if(n){
			p_club=(struct club *)malloc(sizeof(struct club));
		    strcpy(p_club->name,name);
		    strcpy(p_club->sex,sex);
		    p_club->xuehao=xuehao;
		    strcpy(p_club->borrow,"����");
			head_club=Insert_Club(head_club,p_club);
			printf("/n��ӻ�Ա�ɹ�!/n/n");
		}
			break;
		case 9:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("����Ҫɾ����Աѧ��:/n");
			scanf("%d",&xuehao);
			head_club=Delete_Club(head_club,xuehao);
			printf("/nɾ����Ա�ɹ�!/n/n");
			break;
		case 10:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			Print_Club(head_club);
			break;
		case 0:
			system("cls");
			printf("/n/t/t/t����������ͼ�����ϵͳ����������/n/n");
			printf("/nлл����ʹ��!/n/n");
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
	printf("������ͼ������:");
	scanf("%s",book_name);
	printf("������ͼ����:");
	scanf("%d",&bianhao);
	printf("�����뵥��:");
	scanf("%lf",&price);
	printf("��������������:");
	scanf("%s",author);
	printf("/n");	
	while(bianhao!=0){
		p_book=(struct book *)malloc(size_book);
		strcpy(p_book->book_name,book_name);
		p_book->bianhao=bianhao;
		p_book->price=price;
		p_book->xuehao=0;
		strcpy(p_book->author,author);
		strcpy(p_book->state,"����");
		strcpy(p_book->sex,"����");
		strcpy(p_book->name,"����");
		head_book=Insert_Book(head_book,p_book);	
		printf("������ͼ������:");
		scanf("%s",book_name);
		printf("������ͼ����:");
		scanf("%d",&bianhao);
		printf("�����뵥��:");
		scanf("%lf",&price);
		printf("��������������:");
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
			printf("ͼ����:%d/n",ptr_book->bianhao);
			printf("ͼ������:%s/n",ptr_book->book_name);
			printf("ͼ�鵥��:%.2lf/n",ptr_book->price);
			printf("ͼ������:%s/n",ptr_book->author);
			printf("����״̬:%s/n",ptr_book->state);
			printf("����������:%s/n",ptr_book->name);
			printf("�������Ա�:%s/n",ptr_book->sex);
			printf("ѧ��:%d/n",ptr_book->xuehao);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("���޴�ͼ����Ϣ!/n/n");
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
			printf("ͼ����:%d/n",ptr_book->bianhao);
			printf("ͼ������:%s/n",ptr_book->book_name);
			printf("ͼ�鵥��:%.2lf/n",ptr_book->price);
			printf("ͼ������:%s/n",ptr_book->author);
			printf("����״̬:%s/n",ptr_book->state);
			printf("����������:%s/n",ptr_book->name);
			printf("�������Ա�:%s/n",ptr_book->sex);
			printf("ѧ��:%d/n",ptr_book->xuehao);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("���޴�ͼ����Ϣ!/n/n");
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
			printf("ͼ����:%d/n",ptr_book->bianhao);
			printf("ͼ������:%s/n",ptr_book->book_name);
			printf("ͼ�鵥��:%.2lf/n",ptr_book->price);
			printf("ͼ������:%s/n",ptr_book->author);
			printf("����״̬:%s/n",ptr_book->state);
			printf("����������:%s/n",ptr_book->name);
			printf("�������Ա�:%s/n",ptr_book->sex);
			printf("ѧ��:%d/n",ptr_book->xuehao);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("���޴�ͼ����Ϣ!/n/n");
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
	printf("�������Ա����:");
	scanf("%s",name);
	printf("�������Ա�Ա�:");
	scanf("%s",sex);
	printf("�������Աѧ��:");
	scanf("%d",&xuehao);
	printf("/n");
	
	while(xuehao!=0){
		p_club=(struct club *)malloc(size_club);
		strcpy(p_club->name,name);
		strcpy(p_club->sex,sex);
		p_club->xuehao=xuehao;
		strcpy(p_club->borrow,"����");
		
		head_club=Insert_Club(head_club,p_club);
		
		printf("�������Ա����:");
		scanf("%s",name);
		printf("�������Ա�Ա�:");
		scanf("%s",sex);
		printf("�������Աѧ��:");
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
			printf("��Ա����:%s/n",ptr_club->name);
			printf("��Ա�Ա�:%s/n",ptr_club->sex);
			printf("��Աѧ��:%d/n",ptr_club->xuehao);
			printf("����ͼ��:%s/n",ptr_club->borrow);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("���û�������!/n/n");
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
			printf("��Ա����:%s/n",ptr_club->name);
			printf("��Ա�Ա�:%s/n",ptr_club->sex);
			printf("��Աѧ��:%d/n",ptr_club->xuehao);
			printf("����ͼ��:%s/n",ptr_club->borrow);
			printf("/n");
			flag++;
		}
		}
	if(flag==0){
			printf("���û�������!/n/n");
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
				strcpy(ptr_book->name,ptr_club->name);   /*�ַ����ĸ��ƣ����ұߵ����ݸ��Ƶ����*/
				strcpy(ptr_book->sex,ptr_club->sex);
				ptr_book->xuehao=ptr_club->xuehao;
				strcpy(ptr_book->state,"����");
				strcpy(ptr_club->borrow,ptr_book->book_name);
				flag++;
			}
			if(flag==0){
				printf("���޴�ͼ�������δע��Ϊ��Ա!/n/n");
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
				strcpy(ptr_book->name,"����");
				strcpy(ptr_book->sex,"����");
				ptr_book->xuehao=0;
				strcpy(ptr_book->state,"����");
				strcpy(ptr_club->borrow,"����");
				flag++;
			}
			if(flag==0){
				printf("��������������/n/n");
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
		printf("/n�޼�¼/n/n");
		return;
	}
	printf("/n��Ա����/t��Ա�Ա�/t��Աѧ��/n/n");
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
		printf("/n�޼�¼/n/n");
		return;
	}
	printf("/nͼ����/tͼ������/tͼ�鵥��/tͼ������/n/n");
	for(ptr_b=head_book;ptr_b;ptr_b=ptr_b->book_next)
		printf("%d/t/t%s/t/t%.2lf/t/t%s/n/n",ptr_b->bianhao,ptr_b->book_name,ptr_b->price,ptr_b->author);
}