/**
 * Copyright by Radua
 * 数独的2.0版本
 * 实现了对非法数据的检查
 * 和循环运算
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <windows.h>
 /* 定义数独元素 */
 const int BXO[9]={1,2,3,4,5,6,7,8,9};
 /* 定义全局数独*/
  int shudu[9][9];
 /**
  *测试变量的定义
  *
  */
 void pts()
 {
     printf("%d",BXO[1]);
     shudu[1][1]=9;
     printf("%d",shudu[1][1]);
 }
 /**
  * 测试数独全局变量的外函数引用
  *
  */
 void pts2()
 {
     printf("%d",shudu[1][1]);
 }
 /**
  * 初始化数独
  */
 void Init()
 {
     for (int i=1;i<=9;i++)
     {
         for (int j=1;j<=9;j++)
         {
             shudu[i][j]=0;
         }
     }
 }
 /**
  * 判断横行数字是否重复
  *
  */
   int PDSHline(int hline,int n)
 {
     for (int i=1;i<n;i++)
     {
         if (shudu[hline][i]==shudu[hline][n])
            return 1;
     }
     return 0;
 }

  /**
  * 判断竖行数字是否重复
  *
  */
   int PDSVline(int vline,int n)
 {
     for (int i=1;i<n;i++)
     {
         if (shudu[i][vline]==shudu[n][vline])
            return 1;
     }
     return 0;
 }
 /**
  * 检查死解
  *
  */
 int CDSlution(int hline,int vline)
 {
     int CheckNums[9],calc=vline-1,pd=-1,calc1=calc;
     for (int i=1;i<vline;i++)
     {
         CheckNums[i]=shudu[hline][i];
     }
     for (int i=1;i<hline;i++)
     {
         for (int j=1;j<=calc1;j++)
         {
//             if (CheckNums[j]!=shudu[i][vline])
//                {
//                 calc++;
//                 CheckNums[calc]=shudu[i][vline];
//                }
            if (CheckNums[j]==shudu[i][vline]) pd = 1;
         }
          if (pd == -1)
          {
              calc++;
              CheckNums[calc]= shudu[i][vline];
          }else{
              pd=-1;
          }
     }
     if (calc==9) return 1;
     else return 0;
 }
 /**
  * 单行数字的生成
  *
  */
 int  SCShudu(int hline,int vline)
 {

     int u;
     u=rand()%9+1;
     if (CDSlution(hline,vline)==1) return 3;
     shudu[hline][vline]=u;
     if (PDSHline(hline,vline)==1)SCShudu(hline,vline);
     if (PDSVline(vline,hline)==1)SCShudu(hline,vline);
     return 1;
 }
 /**
  * 输出生成的数独
  *
  */
   int INPshudu()
 {
     FILE * result;
     result = fopen("result.txt","a+");

     for (int i=1;i<=9;i++)
     {
         for (int j=1;j<=9;j++)
         {
             printf("   %d",shudu[i][j]);
             fprintf(result,"   %d",shudu[i][j]);
         }
         printf("\n");
         fprintf(result,"\n");
     }
     fprintf(result,"\n");
     fclose(result);
     printf("\n");
     return 0;
 }

 /**
  * 这里采用的是随机生成数独
  * 第一行的方法
  *
  */
 int RadShudu()
 {
     int t=0;
     for (int j=1;j<=9;j++){
        for (int i=1;i<=9;i++)
     {
         if (SCShudu(j,i)==3) {
                t=RadShudu();
                if (t==1)return 1;
         }
         SCShudu(j,i);
     }
     }
     INPshudu();
     return 1;
 }
 /**
  * 创建数独
  *
  */
 void Creat()
 {
     Init();
     srand(time(0));
     printf("\t\t数独生成程序2.0");
     printf("\n\t\t\tBY RADUA\n");
     printf("\n\n\t\t请输入需要的数独个数:");
     int h;
     scanf("%d",&h);
     for (int i=0;i<h;i++)
     {
              RadShudu();
     }
     printf("结果保存在result.txt文件中");


 }

 void Panel()
 {
     MessageBox(NULL,"Hello World!","C图形程序",MB_OK);
     Creat();
 }
