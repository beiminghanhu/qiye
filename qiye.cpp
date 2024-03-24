#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
 
//��������
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
	int iNumber;//����
	char acName[999];//����
    int Age;
    char Sex[999];
	int fSalary;//н��
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
    printf("\t\tԱ����Ϣ����ϵͳ\n");
    if(iType==1)
    {
        printf("\t|����\t|����\t|�Ա�\t|����\t|н��\t\n");
    }
    else if(iType==2)
    {
        printf("\t|����\t|����\t|�Ա�\t|����\t|н��\t\n");
    }
}
 
void Show(struct Employee * pHead)
{
	struct Employee * pCur = pHead;
	int i=0;
	if(pHead==NULL)
	{
		printf("======û��Ա����¼======\n");
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
			iNum = CheckNum("������Ա�����ţ�����0�˳�):");
			if(iNum==0)
			{
				printf("��ӽ������±��ǣ�\n");
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
			 	printf("�����ظ������ٴ�����:\n");
				continue;
			 }
			 else
			      break;
		}
		pTemp =(struct Employee *)malloc(sizeof(struct Employee));
		if(pTemp == NULL)
		{
		    printf("\n�����ڴ�ʧ��\n");
			return NULL;
		}
		pTemp->iNumber = iNum;
		printf("����Ա������:");
		gets(pTemp->acName);
		printf("�������Ա���/Ů����");
        gets(pTemp->Sex);
        printf("������нˮ��");
        scanf("%d",&pTemp->fSalary);
        //getchar();
        //gets(pTemp->fSalary);
		pTemp->Age=CheckAge("���������䣺");
 
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
		printf("\n=====û��Ա����¼��======\n");
		return NULL;
	 }
	 printf("\t1:����Ա������\n\t2:����Ա������\n");
 
	 printf("���������ѡ��:");
	 scanf("%d",&iItem);
	 getchar();
 
	switch(iItem)
	{
		case 1:
		       printf("������Ա�����ţ�");
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
					printf("Ա������δ�ҵ���\n");
				}
				break;
		case 2:
			printf("������Ա������");
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
			 	printf("Ա������δ�ҵ���\n");
			 }
			 break;
		default:
			printf("���빤�����ݴ���\n");
		}
		return pCur;
 }
 
 void Add(struct Employee * pHead)
{
	struct Employee * pCur,*pTail,*pTemp;
	int iNum,iFlag;
 
	if(pHead==NULL)
	{
		printf( "\n û��Ա�����ݣ����״δ�����\n");
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
			iNum=CheckNum("������Ա������:");
			if(iNum==0)
			{
				printf("�����ɣ��µı���:\n");
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
			 	printf("�����ظ������ٴ�����:\n");
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
		printf("����Ա������:");
		gets(pTemp->acName);
		printf("�������Ա���/Ů����");
        gets(pTemp->Sex);
        printf("������нˮ��");
        scanf("%d",&pTemp->fSalary);
        //getchar();
        //gets(pTemp->fSalary);
		pTemp->Age=CheckAge("���������䣺");
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
 		printf("\n\t�������µ�Ա������!f\t\n");
 		pTemp->iNumber =CheckNum("�����빤��");
		printf("����Ա������:");
		gets(pTemp->acName);
		printf("�������Ա���/Ů����");
        		gets(pTemp->Sex);
		pTemp->Age=CheckAge("���������䣺");
  		printf("������нˮ��");
        scanf("%d",&pTemp->fSalary);
		printf("�޸ĳɹ����¼�¼��:\n");
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
		printf("ɾ���ɹ���ʣ���Ա�������ǣ�\n");
		Show(pHead);
	 }
}
 
 
void ShowMainMenu()
{ int i;
    system("cls");
    printf("\n\t\t\tԱ����Ϣ����ϵͳ\n\n");
    for(i=0;i<80;i++)
    {
        printf("*");
    }
    printf("\n1.����Ա������\t\t\t\t\t\t5.����Ա������\t\t\n");
    printf("2.���Ա������\t\t\t\t\t\t6.ɾ��Ա������\t\t\n");
    printf("3.��ʾԱ������\t\t\t\t\t\t7.��ȡԱ������\t\t\n");
    printf("4.����Ա������\t\t\t\t\t\t8.����Ա������\t\t\n");
    printf("0.�˳�����\n");
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
 printf("�������ļ�����");
 gets(Empsystem);
 if((fp=fopen(Empsystem,"rb"))==NULL)
 {
     printf("\n�޷����ļ�\n");
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
        printf("���޴��ˣ�\n");
        return;
    }
    printf("�����ļ�����");
    gets(Empsystem);
    if((fp=fopen(Empsystem,"wb"))==NULL)
    {
        printf("\n�޷����ļ�\n");
        getchar();
        exit(1);
    }
    while(pCur)
    {
        fwrite(pCur,sizeof(struct Employee),1,fp);
        pCur=pCur->pNext;
        iCount++;
    }
    printf("\n======�������======\n");
    fclose(fp);
}
 
int main()
{
struct Employee*pHead=NULL;
int iItem;
while (1)
{ShowMainMenu();
printf("\n�����루1-8��:");
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
printf("�������˵�\n");
getch();
}
}
