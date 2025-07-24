#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putptr(void *ptr);
int	ft_putstr(char *c);
int	ft_putchar(char c);
int	ft_putnbrunsigned(unsigned int n);
int	ft_putintdec(int n);
int	ft_puthex_upx(unsigned int n, int type);

#endif
