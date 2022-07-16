#include "../../header_files/parser.h"

void	ft_free_serch_helper(t_prs **prs)
{
	ft_strerr("[ERROR] Invalid .cub file\n");
	ft_prs_exit(*prs, 0);
}

void	ft_free_allocated_err(t_prs *prs, int key)
{
	ft_strerr("[ERROR] Allocated memory\n");
	ft_prs_exit(prs, key);
}