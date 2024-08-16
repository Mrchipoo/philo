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
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t time_to_die;
    int max_meals;
    int dead;
    int philo;
    size_t time;
    pthread_mutex_t *fork;
    pthread_mutex_t print;
    pthread_mutex_t lock;
    pthread_mutex_t meals;
    pthread_mutex_t dead_lock;
    pthread_mutex_t monitor;
    pthread_mutex_t checker;
} t_time;

typedef struct s_philo
{
    pthread_t thread;
    t_time *data;
    int id;
    int dead_check;
    int nb_of_meals;
    size_t last_meal;
    pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;



void    *ft_routine(void *arg);
void    ft_usleep(size_t time);
void    ft_monitor(t_philo *philo, t_time *data);
void    ft_data_philo(int i, t_philo *philo, t_time *data);
void    ft_print(t_philo *philo, char *s, int i, size_t time_to);
void    ft_data(int argc, char **argv, t_time *data);
void     ft_check(int i, t_philo *data);
int     ft_philo(t_philo *g);
int     ft_atoi(char *str);
int     checker(char **argv,int argc);
int     ft_mutex_init(int num, t_time *data);
int     ft_init(t_philo *philo, t_time *data, int num);
int     ft_max(int i, int j);
int     ft_min(int i, int j);
int     ft_mutex_join(t_time data, t_philo *philo);
size_t	get_current_time(void);
#endif