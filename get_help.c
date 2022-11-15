#include "shell.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
        unsigned int ustatus;
        int is_digit;
        int str_len;
        int big_number;

        if (datash->args[1] != NULL)
        {
                ustatus = _atoi(datash->args[1]);
                is_digit = _isdigit(datash->args[1]);
                str_len = _strlen(datash->args[1]);
                big_number = ustatus > (unsigned int)INT_MAX;
                if (!is_digit || str_len > 10 || big_number)
                {
                        get_error(datash, 2);
                        datash->status = 2;
                        return (1);
                }
                datash->status = (ustatus % 256);
        }
        return (0);
}
root@GreenWater:/mnt/c/Users/Ayomide GreenWater/Desktop/alx/simple_shell_test# cat get_help.c
#include "shell.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell *datash)
{

        if (datash->args[1] == 0)
                aux_help_general();
        else if (_strcmp(datash->args[1], "setenv") == 0)
                aux_help_setenv();
        else if (_strcmp(datash->args[1], "env") == 0)
                aux_help_env();
        else if (_strcmp(datash->args[1], "unsetenv") == 0)
                aux_help_unsetenv();
        else if (_strcmp(datash->args[1], "help") == 0)
                aux_help();
        else if (_strcmp(datash->args[1], "exit") == 0)
                aux_help_exit();
        else if (_strcmp(datash->args[1], "cd") == 0)
                aux_help_cd();
        else if (_strcmp(datash->args[1], "alias") == 0)
                aux_help_alias();
        else
                write(STDERR_FILENO, datash->args[0],
                      _strlen(datash->args[0]));

        datash->status = 0;
        return (1);
}
