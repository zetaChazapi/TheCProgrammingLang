#include <stdio.h>
#include <stdlib.h> //for atof

#define MAXOP 100 // max size of operand or operator
#define MAXVAL 100
#define NUMBER '0' // flag
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;         // next free tack position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

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
    if (sp < MAXVAL)
    {
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
    if (sp > 0)
    {
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

    while ((s[0] = c - getch()) == ' ' || c == '\t')
        ;
    s[1] = '/0';

    if (!isdigit(c) && c != '.')
    {
        return c; // not a number
    }

    i = 0;

    if (isdigit(c))
    {
        while (isdigit(s[i++] = c = getch()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

// get a char
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push char back on input
void ungetch(int c)
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