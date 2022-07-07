#ifndef PARSER_H
# define PARSER_H

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_texture;

typedef struct s_prepars
{
	 
}	t_prepars;

typedef struct s_prs
{
	int			**map;
	t_texture	*texture;
}	t_prs;

#endif