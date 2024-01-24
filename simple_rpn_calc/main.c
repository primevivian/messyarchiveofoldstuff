/*
  RPN Calculator Test by viniciusbrit
  03-12-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 128

typedef struct 
{
    int top;
    double stack[MAX_SIZE];
} Stack;

void init_stack(Stack *st) 
{
    st->top = -1;
}

int is_empty(Stack *st) 
{
    return st->top == -1;
}

int is_full(Stack *st) 
{
    return st->top == MAX_SIZE - 1;
}

void push(Stack *st, double num) 
{
    if (is_full(st)) 
    {
        printf("Stack overflow.\n");
        exit(1);
    }
    st->top++;
    st->stack[st->top] = num;
}

double pop(Stack *st) 
{
    double item;
    if (is_empty(st)) 
    {
        printf("Stack underflow.\n");
        exit(1);
    }
    item = st->stack[st->top];
    st->top--;
    return item;
}

void pop_all(Stack *st)
{
    while (!is_empty(st))
    {
        pop(st);
    }
}

void swap(Stack *st)
{
    int temp;
    if (st->top < 1)
    {
        printf("Stack is too small to swap.\n");
        return;
    }
    temp = st->stack[st->top];
    st->stack[st->top] = st->stack[st->top - 1];
    st->stack[st->top - 1] = temp;
}

void print_stack(Stack *st)
{
    int i;
    if(is_empty(st))
    {
        printf("[Stack is empty.]\n");
    }
    else
    {
        for (i = 0; i <= st->top; i++)
        {
            printf("%d: %.8f\n", st->top - i + 1, st->stack[i]);
        }
    }
}

int main()
{
    Stack st;
    char ch;
    double n1, n2;
    int i;

    /* Initialize stack*/
    init_stack(&st);

    printf("[RPN Calculator]\n");
    printf("How to use:\n  -Input numbers individually, then input operation.\n");
    printf("Supported Operations:\n  -[+] > Addition.\n  -[-] > Subtraction.\n  -[*] > Multiplication.\n  -[/] > Division.\n  -[^] > Power.\n  -[r] > Square Root.\n");
    printf("Stack Operations:\n  -[c] > Clears Stack.\n  -[d] > Deletes First Number On Stack.\n  -[s] > Swaps First 2 Numbers On The Stack.\n  -[q] > Quits Program.\n");
    print_stack(&st);

    while ((ch = getchar()) != 'q') /* Q for Quit*/
    {
        if (isdigit(ch) || ch == '.') 
        {
            ungetc(ch, stdin);
            scanf("%lf", &n1);
            push(&st, n1);
            print_stack(&st);
        }
        else 
        {
            switch (ch)
            {
                case 'c': /* C for Clear*/
                    pop_all(&st);
                    print_stack(&st);
                    break;
                case 's': /* S for Swap*/
                    swap(&st);
                    print_stack(&st);
                    break;
                case 'd': /* D for Delete*/
                    pop(&st);
                    print_stack(&st);
                    break;
                case '+':
                    n2 = pop(&st);
                    n1 = pop(&st);
                    push(&st, (n1) + (n2));
                    print_stack(&st);
                    break;
                case '-':
                    n2 = pop(&st);
                    n1 = pop(&st);
                    push(&st, (n1) - (n2));
                    print_stack(&st);
                    break;
                case '*':
                    n2 = pop(&st);
                    n1 = pop(&st);
                    push(&st, (n1) * (n2));
                    print_stack(&st);
                    break;
                case '/':
                    n2 = pop(&st);
                    n1 = pop(&st);
                    push(&st, (n1) / (n2));
                    print_stack(&st);
                    break;
                case '^':
                    n2 = pop(&st);
                    n1 = pop(&st);
                    push(&st, pow(n1, n2));
                    print_stack(&st);
                    break;
                case 'r': /* R for square Root */
                    n1 = pop(&st);
                    push(&st, sqrt(n1));
                    print_stack(&st);
                    break;
            }
        }
    }
}
