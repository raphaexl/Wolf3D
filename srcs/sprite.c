/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onahiz <onahiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:37:59 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/26 21:09:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_sprite	*ft_create_sprites(t_vect2d pos, int texture)
{
	t_sprite	*new;

	if ((new = (t_sprite *)malloc(sizeof(*new))))
	{
		new->x = pos.x;
		new->y = pos.y;
		new->remove = 0;
		new->texture = texture;
		new->next = NULL;
	}
	return (new);
}

void		ft_push_back_sprites(t_sprite **s, t_sprite *new)
{
	t_sprite *p;

	if (!s || !new)
		return ;
	else if (!*s)
		*s = new;
	else
	{
		p = *s;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

t_sprite	*ft_sprites(t_sprite *s, int indice)
{
	while (s && (--indice >= 0))
		s = s->next;
	return (s);
}

void		ft_clear_sprites(t_sprite **s)
{
	t_sprite	*p;
	t_sprite	*q;

	if (!s || !*s)
		return ;
	p = *s;
	while (p && p->remove)
	{
		(*s) = (*s)->next;
		free(p);
		p = *s;
	}
	while (p)
	{
		while (p && !p->remove)
		{
			q = p;
			p = p->next;
		}
		if (!p)
			return ;
		q->next = p->next;
		free(p);
		p = q->next;
	}
}

int			ft_length_sprites(t_sprite *s)
{
	if (!s)
		return (0);
	return (1 + ft_length_sprites(s->next));
}
