#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int c;
	char lat[10];
	char lon[11];
	char date[10];
	char time[8];
	
	int i=0;
	char *str;
	FILE*fp,*fp1;
	fp=fopen("export.txt","r");
	fp1=fopen("export.csv","w");
	if(fp==NULL)
	{
		printf("打开文件错误！");
		return 0;
	}
	fseek(fp,0,SEEK_END);
	c=ftell(fp);
	fseek(fp,1,SEEK_SET);
	str=(char*)malloc(c);
	fread(str,1,c,fp);
	while(!((*(str+i)=='<')&&(*(str+i+1)=='/')&&(*(str+i+2)=='g')&&(*(str+i+3)=='p')&&(*(str+i+4)=='x')&&(*(str+i+5)=='>')))
	{
	
		if((*(str+i)=='l')&&(*(str+i+1)=='a')&&(*(str+i+2)=='t'))
		{
		strncpy(lat,str+i+5,9);
		lat[10]='\0';
		printf("%s ",lat);
		fprintf(fp1,"%s,",lat);
		strncpy(lon,str+i+4+17,10);
		lon[9]='\0';
		printf("%s ",lon);
		fprintf(fp1,"%s,",lon);
		strncpy(date,str+i+43,10);
		date[10]='\0';
		printf("%s ",date);
		fprintf(fp1,"%s,",date);
		strncpy(time,str+i+54,9);
		time[8]='\0';
		printf("%s ",time);
		fprintf(fp1,"%s\n",time);
		printf("\n");
		
	    }
		i++;
	}
		fclose(fp);
		fclose(fp1);
	    
	return 0;
}
