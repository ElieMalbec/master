1)
2)Mettre en commentaire les appels system
3)

/*f i c h i e r    m o n _ f i l s _ e s t _ f i n i . c*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void mon_fils_est_fini(int sig) 
{
	printf("mon  f i l s    e s t    t e r m i n é  . . .\ n " ) ;
}

int main( ) 
{
	pid_t    pid ;
	system (" c l e a r ");
	/ /    u n e   b e l l e    c o n s o l e  . . .
	if ((pid =   fork( ) ) == 0 ) 
	{
	/ /    Dans   l e    f i l s
	printf( "  f i l s    :    j e   me   m e t   e n   p a u s e  ,   mon   PID   e s t :   %d\n" ,    getpid( )) ;
	f o r  ( ; ; ) ;
	/ /    b o u c l e    i n f i n i e}
	/*l e    p è r e    s t o p p e   s o n    f i l s*/
	p r i n t f ( " p è r e  ,   mon   PID   :   %d \ n " , g e t p i d  ( ) ) ;
	s y s t e m ( " p s−lH " ) ;
	( v o i d )    s i g n a l ( SIGCHLD ,    m o n _ f i l s _ e s t _ f i n i ) ;
	p r i n t f ( " a p p u y e z   s u r   u n e   t o u c h e   p o u r   s t o p p e r    l e    f i l s  \ n " ) ;
	g e t c h a r ( ) ;
k i l l ( p i d  ,   SIGINT ) ;
	/ / l e    p è r e    i n t e r r o m p t    l e    f i l s    p i ds y s t e m ( " p s−lH " ) ;
	w a i t p i d ( p i d  ,   NULL ,    0 ) ;
	s y s t e m ( " p s−lH " ) ;
	r e t u r n   EXIT_SUCCESS ;
}
