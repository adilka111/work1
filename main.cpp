#include <iostream>

using namespace std;

int main()
#include <stdlib.h>
#include <string.h>


void add(void)
{
        FILE    *File;
        char myfile[50];
        short   Iter=0;
        short   Temp=0;
        short   CoordX=0;
        short CoordY=0;
        short   SumObj=0; //������������ �������� ��� ���������� � �����
        short NPoint=0; // ���������� ����� � ������� �������
// ��������� ���� �� ������, ����� ��������� ��� �� ������� � ���������� ��������� ��������
        rprintf("������� ��� �����\n");
        gets(myfile);
        if((File=fopen(myfile,"rb"))!=NULL)
        {
            while(!feof(File))
            {
                fread(&Temp,sizeof(short),1,File);
                if(Temp=='\n')  SumObj++;
            }
            SumObj--;
            fclose(File);
        }

        if(SumObj==0)
        {
            File=fopen(myfile,"wb");
        }
        else
        {
            File=fopen(myfile,"ab");
        }

        SumObj++;
        fwrite(&SumObj,sizeof(short),1,File);

    rprintf("������� ���������� ����� � ������� �������:");
    scanf("%d",&NPoint);
        fwrite(&NPoint,sizeof(short),1,File);

        for(Iter=0;Iter<NPoint;++Iter)
        {
            rprintf("������� X ��������� �������:");
            scanf("%d",&CoordX);
            rprintf("������� Y ���������� �������:");
            scanf("%d",&CoordY);
            fwrite(&CoordX,sizeof(short),1,File);
            fwrite(&CoordY,sizeof(short),1,File);
        }
        Temp='\n';
        fwrite(&Temp,sizeof(short),1,File);

        fclose(File);
    getchar();
}

void view(void)
{
    FILE    *File;
    short   NPoint=0;//���������� ����� � ������� �������
    char myfile[50];
    short   NObj=0;// � �������
    short   SumObj=0;// ���������� �������� ��� ��������� � ����
    short   Iter=0;
    short   Temp=0;
// ��������� ���� �� ������, ����� ��������� ��� ������� � ���������� ��������� ��������
        rprintf("������� ��� �����\n");
        gets(myfile);
    if((File=fopen(myfile,"rb"))!=NULL)
    {
        while(!feof(File))
        {
            fread(&Temp,sizeof(short),1,File);
            if(Temp=='\n')  SumObj++;
        }

        SumObj--;

        fclose(File);
    }
    else
    {
        rprintf("���� � ��������� ����������� !");
        return;
    }

    do
    {
        rprintf("������� ����� �������:");
        scanf("%d", &NObj);
    }   while(NObj<1 || NObj>SumObj);

    File=fopen(myfile,"rb");
    while(!feof(File))
    {
        fread(&Temp,sizeof(short),1,File);
        if(Temp==NObj)
        {
            fread(&NPoint,sizeof(short),1,File);
            for(Iter=0;Iter<NPoint;++Iter)
            {
                fread(&Temp,sizeof(short),1,File);
                rprintf("���������� X: %2d, ",Temp);
                //CoordObj1[0][Iter]=Temp;
                fread(&Temp,sizeof(short),1,File);
                rprintf("���������� Y: %2d\n, ",Temp);
                //CoordObg1[1]=Temp;
            }
        }
        do
        {
            fread(&Temp,sizeof(short),1,File);
        } while(Temp !='\n');
    }
    fclose(File);
}
int menu_select(void)
{
    char str[2],pos;

    printf("\n");
    rprintf("1. �������� ������ � ���������.\t");
    rprintf("2. ������� ������� �������.\t");
    rprintf("3. �����");

    do
    {
        rprintf("\n ������� ����� ������� ������:");
        gets(str);
        pos=atoi(str);
    } while(pos<0 || pos>3);
    return pos;
}

void main(void)
{
    char select;
    system("cls");
    for(;;)
    {
        select=menu_select();
        switch(select)
        {
        case 1: add(); break;
        case 2: view(); break;
        case 3: exit(0); break;
        default: break;
        }
    }
}
