#ifndef _ERROR_H_
#define _ERROR_H_

#include <errno.h>

extern char g_err[64];
void		set_error(int errnum, char const *msg, char const *arg);
void		print_error(char *proc_name);

#endif