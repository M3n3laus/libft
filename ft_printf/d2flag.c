#include "ft_printf.h"

void dhelper(t_package *package)
{
	if(package->sign.str)
	{
		if(!((package->mws)) || package->mws->str[0] == 32)
		{
			package->string = t_string_join(package->sign, *(package->string));
			mom(&(package->trash), T_CHAR, package->string);
		}
		else if (package->mws)
		{
			package->mws = t_string_join(package->sign, *(package->mws));
			mom(&(package->trash), T_CHAR, package->mws);
		}
	}
	if(package->mws)
	{
		package->string = (contains('-',
					package->flag.h_flag, NUM_H_FLAGS) != -1) ?
			t_string_join(*(package->string), *(package->mws)) :
			t_string_join(*(package->mws), *(package->string));
		mom(&(package->trash), T_CHAR, package->string);
	}
}
