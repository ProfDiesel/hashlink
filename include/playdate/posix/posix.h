#pragma once

#include <hl.h>

#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <locale.h>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define HL_UTF8PATH

typedef struct stat pstat;

void *sys_alloc_align( int size, int align );
void sys_free_align( void *ptr, int size );
char *sys_platform_name(void);
char *sys_get_user_lang(void);
vbyte *sys_exe_path(void);
double sys_process_memory(void);