#include <stdio.h>

int main(void)
{
	char s[10]="peach";
	char p[10]="";
	char *ss = s;
	char *pp= p;
	for (int i =0; i < 10;i++)
	{
		*pp++ = *ss++;
	}
	printf("%s and  %s && %p-%p %p-%p", s, p, &pp,&p,&s, &ss);
	return 0;
}
