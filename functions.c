#include "main.h"


int _errputs(char *str)
{
        int i;
        if (!(str))
                return (0);
        for (i = 0; str[i]; i++)
                write(2, &str[i], 1);
        return (i);
}
void print_error(char **av, char *err)
{
        _errputs(_getenv("_"));
        _errputs(": 1: ");
        _errputs(av[0]);
        _errputs(": ");
        _errputs(err);
}
