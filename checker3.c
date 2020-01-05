#include "holberton.h"
/**
 * cascii - check if is a char
 * @d: char
 * Return: 1 if fails else 0 ok
 */
int cascii(int d)
{
	if (d < 0 || d > 127)
	{
		return (0);
	}
	return (1);
}
