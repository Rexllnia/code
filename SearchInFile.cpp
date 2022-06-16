#include "stdio.h"
#include "string.h"
#include "malloc.h"
int SearchInFile(char *input_str,int n,char *path)
{
    FILE *fp;
    int i=0;
    char *str=(char*)malloc(n);
    fp = fopen(path, "r");
    while (strcmp(input_str,str)!=0)
    {
         fgets(str,n,fp);
         fseek(fp,i++,SEEK_SET);
    }
    fclose(fp);
    return i;

}
int DeleteInFile()
{
    FILE *fp;
    FILE *temp_fp;
    char ch;
    char *path="D:\\Programs\\vscode\\hello.html";
    int i=0;
    int pos=SearchInFile("<!--myHFSdir.-->",strlen("<!--myHFSdir.-->")+1,"D:\\Programs\\vscode\\hello.html");
    int pos2=SearchInFile("<!--/myHFSdir.-->",strlen("<!--/myHFSdir.-->")+1,"D:\\Programs\\vscode\\hello.html");
    fp = fopen(path, "r");
    temp_fp= fopen("temp1.txt","w+");
    for(i=0;i<pos;i++)
    {
       fputc(fgetc(fp),temp_fp);
    }
    fseek(fp,pos2-2,SEEK_SET);
    while(ch=fgetc(fp))
    {
       if(feof(fp))
            break;
        fputc(ch,temp_fp);
    }

    
    
    fclose(fp);
    
    fclose(temp_fp);
    remove("D:\\Programs\\vscode\\hello.html");
    rename("temp1.txt","D:\\Programs\\vscode\\hello.html");

}
int main()
{
    // FILE *fp;
    // char ch;
    // char single_ins[30] = "";
    // int i = 0;
    // int flag = 0;
    //  char str[17];
    //     char boundary_First[]="<!--myHFSdir.-->";
    // char boundary_End[]="<!--/myHFSdir.-->";
    // fp = fopen("D:\\Programs\\vscode\\hello.html", "r");
    // while (strcmp(boundary_First,str)!=0)
    // {
    //     fgets(str,17,fp);
    //     fseek(fp,i++,SEEK_SET);
    // }

    // printf("%d",i);
    DeleteInFile();
    //  printf("%d",SearchInFile("<!--myHFSdir.-->",17,"D:\\Programs\\vscode\\hello.html"));
    // for(i=0;i<strlen(boundary_First);i++)
    // {
    //     ch = fgetc(fp);
    //     if(ch!=boundary_First[i])
    //     break;
    // }

   
    return 0;
}
