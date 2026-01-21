#include "../Headers/server.h"

void	ft_usiputnbrcount_base_fd(size_t n, char *base, char *fill)
{
	size_t	len;

	if (!base)
		return (-1);
	len = ft_strlen(base);
	if (n >= len)
	{
		ft_usiputnbrcount_base_fd(n / len, base, fill);
		ft_usiputnbrcount_base_fd(n % len, base, fill);
	}
	else
		ft_putcharcount_fd(base[n], fill);
	return ;
}
