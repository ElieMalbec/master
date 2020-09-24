#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int nbr_unsigned;

	if (nb < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * nb);
		ft_putchar('-');
	}
	else
		nbr_unsigned = (unsigned int)nb;
	if (nbr_unsigned >= 10)
	{
		ft_putnbr(nbr_unsigned / 10);
		ft_putnbr(nbr_unsigned % 10);
	}
	else
		ft_putchar(nbr_unsigned + '0');
}

void    ft_foreach(int *tab, int length, void (*f)(int)){
    for (int i = 0; i < length; i++){
        f(tab[i]);
    }
}

int main(void){
    int tmp[] = {1, 15, 12, 87, 35};
    ft_foreach(tmp, 5, &ft_putnbr);
    return 0;
}