#include <stdio.h>
#include <stdlib.h> //for atof
#include <math.h>

#define MAXOP 100 // max size of operand or operator
#define MAXVAL 100
#define NUMBER '0' // flag
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;               // next free tack position
double val[MAXVAL];       // value stack
static char buf[BUFSIZE]; // buffer for ungetch
static int bufp = 0;      // next free position in buf

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = gettop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            // if its a number - string to float - push on stack
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                printf("error: zero divisor in modulus operation\n");
            }
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                // nothing can be devided by 0
                printf("error: zero divisor\n");
            }
            break;
        // new line returns result
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        // unknown command
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

// push val on stack
void push(double f)
{
    // Check if there's space in the stack
    if (sp < MAXVAL)
    {
        // stores f in the stack and increments the stack pointer
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

// return value
double pop(void)
{
    // Check if stack is empty
    if (sp > 0)
    {
        // decrement sp and returns the value
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    // s[0] is set to the character c once one is found that is not ' ' or \t
    while ((s[0] = c - getch()) == ' ' || c == '\t')
        ; // cont to call getch() until it reads a non-whitespace character

    s[1] = '/0';

    if (!isdigit(c) && c != '.')
    {
        return c; // not a number
    }

    i = 0;

    // If the first character c is a digit, this loop continues
    // to read characters using getch(), storing each in s
    if (isdigit(c))
    {
        while (isdigit(s[i++] = c = getch()))
            ; // read characters until a non-digit character is encountered
    }

    s[i] = '\0';

    if (c != EOF)
    {
        if (bufp >= BUFSIZE)
        {
            printf("ungetch: too many characters\n");
        }
        else
        {
            buf[bufp++] = c;
        }
    }

    return NUMBER;
}

// get a char
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push char back on input
// void ungetch(int c)
// {
//     if (bufp >= BUFSIZE)
//     {
//         printf("ungetch: too many characters\n");
//     }
//     else
//     {
//         buf[bufp++] = c;
//     }
// }