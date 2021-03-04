#include <stdarg.h>
#include <unistd.h>

static int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

static int		ft_count(long long n, int base_len)
{
	int i = 1;
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

static void		ft_putnbr(long long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_putnbr(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int		ft_printf(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	va_start(ap, format);
	int res = 0, width = 0, len = 0, base_len = 0, neg = 0, flag_prec = 0, prec = 0, zeros = 0, spaces = 0;
	long num = 0;
	char *s, *base;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format <= '9' && *format >= '0')
			{
				width = width * 10 + *format - '0';
				format++;
			}
			if (*format == '.')
			{
				format++;
				flag_prec = 1;
				while (*format <= '9' && *format >= '0')
				{
					prec = prec * 10 + *format - '0';
					format++;
				}
			}
			if (*format == 's')
			{
				s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				len = ft_strlen(s);
			}
			if (*format == 'd')
			{
				num = va_arg(ap, int);
				base_len = 10;
				base = "0123456789";
				if (num < 0)
				{
					neg = 1;
					num *= -1;
				}
				len = ft_count(num, base_len) + neg;
			}
			if (*format == 'x')
			{
				num = va_arg(ap, unsigned);
				base_len = 16;
				base = "0123456789abcdef";
				len = ft_count(num, base_len);
			}
			if (flag_prec == 1 && prec > len && *format != 's')
				zeros = prec - len + neg;
			else if (flag_prec == 1 && prec < len && *format == 's')
				len = prec;
			else if (flag_prec == 1 && prec == 0 && (num == 0 || *format == 's'))
				len = 0;
			spaces = width - len - zeros;
			while (spaces-- > 0)
				res += write(1, " ", 1);
			if (neg)
				res += write(1, "-", 1);
			while (zeros-- > 0)
				ft_putnbr(num, base_len, base);
			res += len;
		}
		else
			res += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return res;
}

int		main(void)
{
	ft_printf("Hey this my printf in 10min %d", 123);
	return 0;
}
