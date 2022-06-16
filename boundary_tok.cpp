#include "stdio.h"
#include "string.h"
int main()
{
    FILE *fp;
    char *p;
    char contain[4096];
    fp = fopen("D:\\Programs\\vscode\\contain.txt", "r");

    fread(contain, 4095, 1, fp);
    if (strstr(p = strstr(contain, "Content-Type: application/octet-stream"), "------WebKitFormBoundary") != NULL)
    {
        strtok(p,"Content-Type: application/octet-stream");
        p=strtok(NULL,"");
        printf("%s",p);
    }
        

    fclose(fp);
    return 0;
}
