#include "formatted_string.h"

static int	get_digit_len(int nbr)
{
	if (nbr == 0)
		return (1);
	return ((nbr > 9 || nbr < -9) + get_digit_len(nbr / 10));
}
char	*get_longstr(long nbr)
{
	long	rem;
	size_t	index;
	char	*nbstr;

	return (NULL);
}

char	*get_intstr(int nbr)
{
	int		rem;
	size_t	index;
	char	*nbstr;

	index = get_digit_len(nbr);
	nbstr = malloc((index + 1 + (nbr < 0)) * sizeof(char));
	if (!nbstr)
		return (NULL);
	index += (nbr < 0);
	nbstr[index] = '\0';
	if (nbr < 0)
		*nbstr = '-';
	while (1)
	{
		index--;
		rem = nbr % 10;
		if (rem < 0)
			rem = -rem;
		nbstr[index] = rem + '0';
		if (&nbstr[index] == nbstr || index == 1 && *nbstr == '-')
			break ;
		nbr /= 10;
	}
	return (nbstr);
}

int main(void)
{
	char *num = get_intstr(-10000);
	printf("%s\n", num);
	free(num);
}
