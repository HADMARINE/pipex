/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:50:08 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 15:07:44 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n);
int		c_exec(va_list *valist);
int		s_exec(va_list *valist);
int		p_exec(va_list *valist);
int		d_exec(va_list *valist);
int		u_exec(va_list *valist);
int		x_exec(va_list *valist);
int		xmaj_exec(va_list *valist);
int		percent_exec(va_list *valist);
int		counter(const char *str);

int	(*getfunc(const char ch))(va_list *valist)
{
	if (ch == '\0')
		return (NULL);
	if (ch == 'c')
		return (&c_exec);
	if (ch == 's')
		return (&s_exec);
	if (ch == 'p')
		return (&p_exec);
	if (ch == 'd')
		return (&d_exec);
	if (ch == 'i')
		return (&d_exec);
	if (ch == 'u')
		return (&u_exec);
	if (ch == 'x')
		return (&x_exec);
	if (ch == 'X')
		return (&xmaj_exec);
	if (ch == '%')
		return (&percent_exec);
	else
		return (NULL);
}

static void
	parser_varinit(short *paflag, unsigned int *len, char **sp, const char *str)
{
	*paflag = 0;
	*len = 0;
	*sp = (char *)str;
}

static void
	parser_paflag_exec(unsigned int *len, char tmpch,
		va_list *valist, short paflag)
{
	if (paflag == 0)
		*len += getfunc(tmpch)(valist);
	else
		*len += getfunc(tmpch)(valist);
}

int	parser(const char *str, va_list *valist)
{
	char			*sp;
	char			tmpch;
	short			paflag;
	unsigned int	len;

	parser_varinit(&paflag, &len, &sp, str);
	while (*sp)
	{
		if (*sp == '%' && *(sp + 1))
		{
			tmpch = *ft_strchr("cspdiuxX%", *(sp + 1));
			if (tmpch != '\0')
			{
				sp += 2;
				parser_paflag_exec(&len, tmpch, valist, paflag);
			}
		}
		else
		{
			ft_putchar_fd(*sp++, 1);
			len++;
		}
	}
	return (len);
}
