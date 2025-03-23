#include <posix/posix.h>

#include <stdlib.h>

void *sys_alloc_align( int size, int align ) {
	void *unaligned_ptr = NULL;
	const int offset = align - 1 + sizeof(void *);
	if (!(unaligned_ptr = (void *)malloc(size + offset))) {
		hl_fatal("assert");
		return NULL;
	}
	void **aligned_ptr = (void **)(((size_t)(unaligned_ptr) + offset) & ~(align - 1));
	aligned_ptr[-1] = unaligned_ptr;
	return aligned_ptr;
}

void sys_free_align( void *ptr, int size ) {
	if(!ptr)
		return;
	free(((void**)ptr)[-1]);
}

char *sys_platform_name(void) { return "playdate"; }

char *sys_get_user_lang(void) { return "en_US.UTF-8"; }

vbyte *sys_exe_path(void) { return NULL; }

double sys_process_memory(void) { return 0; }
