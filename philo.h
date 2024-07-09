#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_time
{
    int time_to_eat;
    int time_to_sleep;
    int time_to_die;
    int max_meals;
    int philo;
    pthread_mutex_t *fork;
    pthread_mutex_t print;
    pthread_mutex_t n_eat_mutex;
    pthread_mutex_t lock;
} t_time;

typedef struct s_philo
{
    pthread_t thread;
    int n_eat;
    t_time *data;
    int id;
    int dead;
    pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
    
} t_philo;



void    *ft_routine(void *arg);
void    ft_data_philo(int i, t_philo *philo, t_time *data);
void    ft_print(char *s);
void    ft_data(char **argv, t_time *data);
int     ft_philo(t_philo *g);
void     ft_check(int i, t_philo *data);
int     ft_atoi(char *nptr);
int     ft_mutex_init(int num, t_time *data);
int     ft_init(t_philo *philo, t_time *data, int num);
int     ft_max(int i, int j);
int     ft_min(int i, int j);
#endif