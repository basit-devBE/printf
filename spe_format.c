#include "main.h"

/**
 * pro - prints string in rot13
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number bytes printed
 */
int pro(va_list pr, params_t *par)
{
    int loopIndex, rotationIndex;
    int bytesPrinted = 0;
    char rot13Table[] = "BCDEFGHIJKLMNOPQRSTUVWXYZA	bcdefghijklmnopqrstuvwxyza";
    char *p = va_arg(pr, char *);
    (void)par;

    loopIndex = 0;
    rotationIndex = 0;
    while (p[loopIndex])
    {
        if ((p[loopIndex] >= 'A' && p[loopIndex] <= 'Z')
            || (p[loopIndex] >= 'a' && p[loopIndex] <= 'z'))
        {
            rotationIndex = p[loopIndex] - 65;
            bytesPrinted += _putchar(rot13Table[rotationIndex]);
        }
        else
            bytesPrinted += _putchar(p[loopIndex]);
        loopIndex++;
    }
    return bytesPrinted;
}

/**
 * prr - prints string in reverse
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number bytes
 */
int prr(va_list pr, params_t *par)
{
    int stringLength, totalBytes = 0;
    char *currentChar = va_arg(pr, char *);
    (void)par;

    if (currentChar)
    {
        for (stringLength = 0; *currentChar; currentChar++)
            stringLength++;
        currentChar--;
        for (; stringLength > 0; stringLength--, currentChar--)
            totalBytes += _putchar(*currentChar);
    }
    return totalBytes;
}

/**
 * pft - prints range of char addresses
 * @exit: exit address
 * @start: start address
 * @stop: stop address
 * Return: number bytes
 */
int pft(char *start, char *stop, char *exit)
{
    int totalSum = 0;

    while (start <= stop)
    {
        if (start != exit)
            totalSum += _putchar(*start);
        start++;
    }
    return totalSum;
}

