#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char *s;
	int len=0;
	if((fp=fopen("e:\\test\\xiadade.txt","r"))==0)
	{
		printf("文件不能打开！");
		return(-1);
	}
	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	s=(char *)malloc(len);
	printf("length=%d\n",len);
	fclose(fp);
	return 0;
}
