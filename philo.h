#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>


typedef struct s_time
{
    int eat;
    int sleep;
    int die;
    int die_eat;
    int philo;
    pthread_mutex_t *fork;
    pthread_mutex_t print;
    pthread_mutex_t n_eat_mutex;
    pthread_mutex_t lock;
} t_time ;

typedef struct s_philo
{
    int fork;
    pthread_t thread;
    int n_eat;
    t_time *data;
    int id;
    
} t_philo;



void    *ft_pid(void *philo);
void    ft_data_philo(int i, t_philo *philo, t_time *data);
void    ft_print(char *s);
void    ft_data(char **argv, t_time *data);
int     ft_philo(t_philo *g);
int     ft_check(int i);
int     ft_atoi(char *nptr);
int     ft_mutex_init(int num, t_time *data);
int     ft_init(t_philo *philo, t_time *data, int num);
#endif