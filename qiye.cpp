#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
 
//函数声明
void ShowMainMenu();
int  CheckNum(char*pcNotice);
int CheckAge(char*pcNotice);
struct Employee * Create();
void Add(struct Employee * pHead);
struct Employee * Search(struct Employee *pHead);
void Modify(struct Employee * pHead);
void Delete(struct Employee * pHead);
void ShowLine();
void ShowHead(int iType);
struct Employee*Read();
void Show(struct Employee * pHead);
 
struct Employee
{
	int iNumber;//工号
	char acName[999];//姓名
    int Age;
    char Sex[999];
	int fSalary;//薪资
	struct Employee *pNext;
};
 
int  CheckNum(char *pcNotice)
{
    int Num;
    do
    {
        printf(pcNotice);
        scanf("%d",&Num);
        getchar();
    }while(Num<0);
    return Num;
}
int CheckAge(char *pcNotice)
{
    int iAge;
    do
    {
        printf(pcNotice);
        scanf("%d",&iAge);
    }while(iAge<0);
    return iAge;
}
 
void ShowHead(int iType)
{
    printf("\t\t员工信息管理系统\n");
    if(iType==1)
    {
        printf("\t|工号\t|姓名\t|性别\t|年龄\t|薪资\t\n");
    }
    else if(iType==2)
    {
        printf("\t|工号\t|姓名\t|性别\t|年龄\t|薪资\t\n");
    }
}
 
void Show(struct Employee * pHead)
{
	struct Employee * pCur = pHead;
	int i=0;
	if(pHead==NULL)
	{
		printf("======没有员工记录======\n");
	}
	else
	{
		ShowHead(1);
		do{
		    printf("\t|%-6d |%-7s|%-7s|%-7d|%-d\t\n",pCur->iNumber,pCur->acName,pCur->Sex,pCur->Age,pCur->fSalary);
			ShowLine();
			pCur=pCur->pNext;
		}while(pCur!=NULL);
	}
 }
 
 struct Employee * Create()
{
	struct Employee * pHead = NULL, *pTail = NULL, *pTemp,*pCur;
	int iNum,iFlag;
	while(1)
	{
		while(1)
		{
			iNum = CheckNum("请输入员工工号（输入0退出):");
			if(iNum==0)
			{
				printf("添加结束！新表是：\n");
				Show(pHead);
				return pHead;
			 }
			 iFlag=0;
			 pCur = pHead;
			 while(pCur!= NULL)
			 {
			 	if(pCur->iNumber==iNum)
			 	{
			 		iFlag=1;
			 		break;
				 }
				 pCur = pCur-> pNext;
			 }
			 if(iFlag == 1)
			 {
			 	printf("工号重复，请再次输入:\n");
				continue;
			 }
			 else
			      break;
		}
		pTemp =(struct Employee *)malloc(sizeof(struct Employee));
		if(pTemp == NULL)
		{
		    printf("\n分配内存失败\n");
			return NULL;
		}
		pTemp->iNumber = iNum;
		printf("输入员工姓名:");
		gets(pTemp->acName);
		printf("请输入性别（男/女）：");
        gets(pTemp->Sex);
        printf("请输入薪水：");
        scanf("%d",&pTemp->fSalary);
        //getchar();
        //gets(pTemp->fSalary);
		pTemp->Age=CheckAge("请输入年龄：");
 
		pTemp->pNext =NULL;
 
		if(!pHead)
		{
			pHead = pTail = pTemp;
		}
		else
		{
			pTail->pNext = pTemp;
			pTail = pTemp;
		}
	}
}
 
struct Employee * Search(struct Employee *pHead)
 {
 	struct Employee *pCur =pHead;
 	int iNum=0,iItem=0;
	char acName[10];
	if(pHead==NULL)
	{
		printf("\n=====没有员工记录！======\n");
		return NULL;
	 }
	 printf("\t1:输入员工工号\n\t2:输入员工姓名\n");
 
	 printf("请输入你的选项:");
	 scanf("%d",&iItem);
	 getchar();
 
	switch(iItem)
	{
		case 1:
		       printf("请输入员工工号：");
			   scanf("%d",&iNum);
			   while(pCur!=NULL)
			   {
			   	if(iNum ==pCur->iNumber)
			   	{
			   	    ShowHead(1);
			   	  printf("\t|%-6d |%-7s|%-7s|%-7d|%-d\t\n",pCur->iNumber,pCur->acName,pCur->Sex,pCur->Age,pCur->fSalary);
			   	    ShowLine();
					return pCur;
				   }
				    pCur=pCur->pNext;
				}
				if(pCur==NULL)
				{
					printf("员工数据未找到！\n");
				}
				break;
		case 2:
			printf("请输入员工姓名");
			gets(acName);
			while(pCur!=NULL);
			{
				if(strcmp(acName,pCur->acName)==0)
				{
					ShowHead(1);
					printf("\t|%-6d |%-7s|%-7s|%-7d|%-d\t\n",pCur->iNumber,pCur->acName,pCur->Sex,pCur->Age,pCur->fSalary);
					ShowLine();
					return pCur;
				}
				pCur=pCur->pNext;
			 }
			 if(pCur==NULL)
			 {
			 	printf("员工数据未找到！\n");
			 }
			 break;
		default:
			printf("输入工号数据错误！\n");
		}
		return pCur;
 }
 
 void Add(struct Employee * pHead)
{
	struct Employee * pCur,*pTail,*pTemp;
	int iNum,iFlag;
 
	if(pHead==NULL)
	{
		printf( "\n 没有员工数据，请首次创建！\n");
		return;
	}
	pCur = pHead;
	while(pCur->pNext!=NULL)
	    pCur = pCur->pNext;
	pTail =pCur;
 
	while(1)
	{
		while(1)
		{
			iNum=CheckNum("请输入员工工号:");
			if(iNum==0)
			{
				printf("添加完成，新的表是:\n");
				Show(pHead);
				return;
			}
			iFlag=0;
			 pCur = pHead;
			 while(pCur!= NULL)
			 {
			 	if(pCur->iNumber==iNum)
			 	{
			 		iFlag=1;
			 		break;
				 }
				 pCur = pCur-> pNext;
			 }
			 if(iFlag == 1)
			 {
			 	printf("工号重复，请再次输入:\n");
				continue;
			 }
			 else
			      break;
		}
		pTemp =(struct Employee *)malloc(sizeof(struct Employee));
		if(pTemp == NULL)
		{
			return;
		}
		pTemp->iNumber = iNum;
		printf("输入员工姓名:");
		gets(pTemp->acName);
		printf("请输入性别（男/女）：");
        gets(pTemp->Sex);
        printf("请输入薪水：");
        scanf("%d",&pTemp->fSalary);
        //getchar();
        //gets(pTemp->fSalary);
		pTemp->Age=CheckAge("请输入年龄：");
		pTemp->pNext=NULL;
		if(!pHead)
		{
			pHead = pTail = pTemp;
		}
		else
		{
			pTail->pNext = pTemp;
			pTail = pTemp;
		}
	}
}
 
void Modify(struct Employee * pHead)
 {  struct Employee * pCur=pHead;
 	struct Employee * pTemp=NULL;
 
 	pTemp = Search(pHead);
 	if(pTemp !=NULL)
 	{
 		printf("\n\t请输入新的员工数据!f\t\n");
 		pTemp->iNumber =CheckNum("请输入工号");
		printf("输入员工姓名:");
		gets(pTemp->acName);
		printf("请输入性别（男/女）：");
        		gets(pTemp->Sex);
		pTemp->Age=CheckAge("请输入年龄：");
  		printf("请输入薪水：");
        scanf("%d",&pTemp->fSalary);
		printf("修改成功！新纪录是:\n");
		ShowHead(1);
		printf("\t|%-6d |%-7s|%-7s|%-7d|%-d\t\n",pCur->iNumber,pCur->acName,pCur->Sex,pCur->Age,pCur->fSalary);
		ShowLine();
	 }
 }
 
 void Delete(struct Employee * pHead)
{
	struct Employee * pTemp=NULL,*pPre = pHead,*pCur = pHead;
	pTemp = Search(pHead);
	if(pTemp!=NULL)
	{
		if(pHead==pTemp)
		{
			pHead =pHead->pNext;
		}
		else
		{
			while(pCur!=pTemp)
			{
				pPre = pCur;
				pCur = pCur->pNext;
			}
			pPre->pNext = pCur->pNext;
		}
		free(pTemp);
		printf("删除成功！剩余的员工数据是：\n");
		Show(pHead);
	 }
}
 
 
void ShowMainMenu()
{ int i;
    system("cls");
    printf("\n\t\t\t员工信息管理系统\n\n");
    for(i=0;i<80;i++)
    {
        printf("*");
    }
    printf("\n1.输入员工数据\t\t\t\t\t\t5.更改员工数据\t\t\n");
    printf("2.添加员工数据\t\t\t\t\t\t6.删除员工数据\t\t\n");
    printf("3.显示员工数据\t\t\t\t\t\t7.读取员工数据\t\t\n");
    printf("4.查找员工数据\t\t\t\t\t\t8.保存员工数据\t\t\n");
    printf("0.退出程序\n");
    for(i=0;i<80;i++)
    {
        printf("*");
    }
}
 
void ShowLine()
{
	int i;
	for(i=0;i<80;i++)
	{
		printf("-");
	}
	printf("\n");
}
 
struct Employee*Read()
{
 FILE*fp;
 struct Employee*pHead=NULL,*pTemp=NULL,*pCur=NULL;
 char Empsystem[20];
 printf("请输入文件名：");
 gets(Empsystem);
 if((fp=fopen(Empsystem,"rb"))==NULL)
 {
     printf("\n无法打开文件\n");
     return NULL;
 }
 pTemp=(struct Employee*)malloc(sizeof(struct Employee));
 while(fread(pTemp,sizeof(struct Employee),1,fp))
  {
     if(!pHead)
     {
         pHead=pCur=pTemp;
     }
     else
     {
         pCur->pNext=pTemp;
         pCur=pTemp;
     }
     pTemp=(struct Employee*)malloc(sizeof(struct Employee));
   }
   fclose(fp);
   Show(pHead);
   return pHead;
}
 
void Save(struct Employee*pHead)
{
    FILE*fp;
    struct Employee*pCur=pHead;
    int iCount=0;
    char Empsystem[20];
    if(pHead==NULL)
    {
        printf("查无此人！\n");
        return;
    }
    printf("输入文件名：");
    gets(Empsystem);
    if((fp=fopen(Empsystem,"wb"))==NULL)
    {
        printf("\n无法打开文件\n");
        getchar();
        exit(1);
    }
    while(pCur)
    {
        fwrite(pCur,sizeof(struct Employee),1,fp);
        pCur=pCur->pNext;
        iCount++;
    }
    printf("\n======保存完成======\n");
    fclose(fp);
}
 
int main()
{
struct Employee*pHead=NULL;
int iItem;
while (1)
{ShowMainMenu();
printf("\n请输入（1-8）:");
scanf("%d",&iItem);
getchar();
while(iItem>10||iItem<0)
{
scanf("%d",&iItem);
getchar();
}
switch (iItem)
{
case 1:pHead=Create(); break;
case 2:Add(pHead);break;
case 3:Show(pHead);break;
case 4:Search(pHead);break;
case 5:Modify(pHead);break;
case 6:Delete(pHead);break;
case 7:pHead = Read();break;
case 8:Save(pHead);break;
case 0:exit(0);
}
printf("返回主菜单\n");
getch();
}
}
