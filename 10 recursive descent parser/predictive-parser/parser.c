#include <stdio.h>
#include <string.h>

FILE *fptr1,*fptr2,*fptr3;
char str[20],s,t[20];
int p=0;
void main()
{
	fptr1 = fopen("grammer.txt","r");
	int ch;
	ch = fscanf(fptr1,"%s",str);
	//printf("%s",str);
	fptr2 = fopen("grammer1.txt","w");
	while(ch!=EOF)
	{
		s = str[0];
		//printf("\n%c",s);
		fprintf(fptr2,"%c -> ",s);
		int k = 3;
		if(str[k]==s)
		{
			while(str[k]!='/')
			{
				k++;
			}
			for(int i=k+1;i<strlen(str);i++)
			{
				fprintf(fptr2,"%c",str[i]);
			}
			fprintf(fptr2,"%c`\n",s);
			fprintf(fptr2,"%c` -> ",s);
			for(int i=4;str[i]!='/';i++)
			{
				fprintf(fptr2,"%c",str[i]);
			}
			fprintf(fptr2,"%c`\n",s);
			fprintf(fptr2,"%c` -> #",s);
		}
		else
		{
			for(int i=3;i<strlen(str);i++)
			{
				//printf("%c\n",str[i]);
				if(str[i]=='/')
				{
					fprintf(fptr2,"\n%c -> ",s);
				//printf("\n%c->",s);
				}
				else
				{
					fprintf(fptr2,"%c",str[i]);
				//printf("%c",str[i]);
				}
			}
		}
		fprintf(fptr2,"\n");	
		ch = fscanf(fptr1,"%s",str);
	}
	fclose(fptr1);
	fclose(fptr2);
	fptr1 = fopen("grammer1.txt","r");
	ch = fscanf(fptr1,"%s",str);
	while(ch!=EOF)
	{
		fscanf(fptr1,"%s",str);
		fscanf(fptr1,"%s",str);
		for(int i=0;i<strlen(str);i++)
		{
			if(p==0)
			{
				if((str[i]>='A'&&str[i]<='Z')||str[i]=='`')
				{
					continue;
				}
				else
				{
					t[p++]=str[i];
				}
			}
			else
			{
				int m=0;
				if((str[i]>='A'&&str[i]<='Z')||str[i]=='`')
				{
					continue;
				}
				else
				{
					for(int i=0;i<p;i++)
					{
						if(t[i]==str[i])
						{
							m=1;
						}
					}
					if(m==0)
					{t[p++]=str[i];}
				}
			}
		}
		ch = fscanf(fptr1,"%s",str);
	}
	fclose(fptr1);
	for(int i=0;i<p;i++)
	{
		printf("%c\t",t[i]);
	}
	fptr1=fopen("grammer1.txt","r");
	fptr2=fopen("table.txt","w");
	
}