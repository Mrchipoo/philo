#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

pthread_mutex_t lock;


typedef struct s_time
{
    int eat;
    int sleep;
    int die;
    int die_eat;
    int fork;
    int philo;
} t_time ;

typedef struct s_philo
{
    bool fork;
    int n_eat;
    t_time data;
    int id;
} t_philo;


pthread_mutex_t lock =  PTHREAD_MUTEX_INITIALIZER;
#endif