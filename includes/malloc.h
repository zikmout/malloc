#ifndef MALLOC_H
# define MALLOC_H
# define PAGE_SIZE getpagesize()
# define TMAX_SIZE 4040 // 1024 - 32 - 24
//# define TMAX_SIZE 992 // 1024 - 32
# define TNB 2048
# define TZMAX_SIZE (size_t)4 * TNB
//# define TZMAX_SIZE (size_t)((TMAX_SIZE + 32) * TNB) // 1024 * 2048 = 2 097 152 (= 2Mb)

# define SMAX_SIZE 131040 // 131072 - 32 - 24
# define SNB 128
# define SZMAX_SIZE (size_t)((SMAX_SIZE + 32) * SNB) // 131072 * 128 = 16 777 215 (= 16Mb)

//# define align4(x) (((((x)-1)>>2)<<2)+4) // 32bit architecture
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>
#include "../libft/libft.h"
//typedef char *(*psf)(struct s_params *, char *, char *, size_t);
//word = 8 bytes (64bit architecture)
typedef struct s_head t_head;
struct s_head
{
	void	*addr;  // 8 bytes
	int		empty;  // 4 bytes (aligned with 8 bytes)
	size_t	size;	// 8 bytes
	t_head	*next;	// 8 bytes
};

typedef struct s_zone t_zone;
struct s_zone
{
	t_head	*entry; // 8 bytes
	size_t	zleft;  // 8 bytes
	t_zone	*next;	// 8 bytes
};


typedef struct s_env t_env;
struct s_env
{
	t_zone *tiny;
	t_zone *small;
	t_head *large;
};

t_env g_e;

void	init_ts(t_zone **zone, size_t zone_size);
void	*malloc(size_t size);
void	print_zone(t_zone *begin);
void	*new_zone_alloc(t_zone **zcur, size_t size);
void	*malloc_large(size_t size);
void	print_large(t_head *begin);
t_head	*list_find_end(t_head *begin);
void	new_alloc_end(t_zone **zcur, t_head **hcur, size_t size);
//void        init_ptab(psf **tab);
t_head	*parse_large(t_head *begin, void *ptr);
t_head	*parse_ts(t_zone *begin, void *ptr);
void	free(void *ptr);
void	*realloc_large(void *ptr, size_t size);

void	*locate(t_zone *begin, t_zone **head, void *ptr);
#endif
