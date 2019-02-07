#include "includes/push_swap.h"

void	remove_a(int *sa, int *sb, int *ss, int *ra, int *rb, int *rr, int *rra, int *rrb, int *rrr, int *pa, int *pb)
{
	(*sa) = -1;
	(*ra) = -1;
	(*rra) = -1;
}

void	remove_b(int *sa, int *sb, int *ss, int *ra, int *rb, int *rr, int *rra, int *rrb, int *rrr, int *pa, int *pb)
{
	(*sb) = -1;
	(*rb) = -1;
	(*rrb) = -1;
}

void	remove_all(int *sa, int *sb, int *ss, int *ra, int *rb, int *rr, int *rra, int *rrb, int *rrr, int *pa, int *pb)
{
	(*rr) = -1;
	(*rrr) = -1;
}

int main(void)
{
	size_t	i;
	size_t	d;
	char *line;
	char *line2;
	
	i = 0;
	d = 0;
	line = NULL;
	line2 = NULL;
	sa = -1;
	sb = -1;
	ss = -1;
	ra = -1;
	rb = -1;
	rr = -1;
	rra = -1;
	rrb = -1;
	rrr = -1;
	pa = -1;
	pb = -1;
	while (get_next_line(0, &line))
	{
		if (line2 != NULL)
		{
			if (!ft_strcmp(line, "sa") && sa == 0)
			{
				inu++;
				remove_a(&sa, &sb, &ss, &ra, &rb, &rr, &rra, &rrb, &rrr, &pa, &pb);
				sa = -1;
			}
			else if (!ft_strcmp(line, "sb") && sb == 0)
			{
				inu++;
				sb = -1;
			}
			else if (!ft_strcmp(line, "pa"
		}
		else
		{
			
		}
		line2 = line;

	}
	ft_printf("nb = %d  doublon = %d \n", inu);
	return (0);
}
