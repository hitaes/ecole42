#ifndef ITER_H
# define ITER_H

# include <string>

template< typename T >
void iter(T *array, size_t len, void (*func)(T &))
{
    if (array == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

#endif