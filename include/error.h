#ifndef _ERROR_H_
#define _ERROR_H_

#include <errno.h>

void		set_error(int errnum, char const *msg, char const *arg);
void		print_error(char *proc_name);

#endif