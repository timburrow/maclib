#include <stdio.h>

#define CODE    0
#define COMMENT 1
#define STRING  2
#define STRING2 3

main()
{
  int c, c2;
  int state = CODE;

  while ((c = getchar()) != EOF)
  {
    if (state == CODE)
    {
      switch (c)
      {
        case '`':
          putchar(c);
          state = STRING2;
          break;
        case '\'':
          putchar(c);
          state = STRING;
          break;
        case '/':
          c = getchar();
          if (c == '/')
          {
            c2 = getchar();
            while ((c2 != EOF) && (c2 != '\n'))
            {
              c2 = getchar();
            }
            putchar(c2);
          }
          else if (c == '*')
          {
            state = COMMENT;
            c2 = getchar();
            while (state == COMMENT)
            {
              if (c2 == '*')
              {
                c2 = getchar();
                if (c2 == '/')
                {
                  state = CODE;
                }
              }
              else if (c != EOF)
              {
                c2 = getchar();
              }
            }
          }
          else
          {
            putchar((int) '/');
            putchar(c);
          }
          break;
        case '"':
          c = getchar();
          while ((c != '"') && (c != '\n') && (c != EOF))
          {
            c = getchar();
          }
          if (c != '"')
          {
            putchar(c);
          }
          break;
        default:
          putchar(c);
          break;
      }
    }
    else if (state == STRING)
    {
      switch (c)
      {
        case '\\':
          putchar(c);
          c = getchar();
          putchar(c);
          break;
        case '\'':
          putchar(c);
          state = CODE;
          break;
        default:
          putchar(c);
          break;
      }
    }
    else if (state == STRING2)
    {
      switch (c)
      {
        case '\\':
          putchar(c);
          c = getchar();
          putchar(c);
          break;
        case '`':
          putchar(c);
          state = CODE;
          break;
        default:
          putchar(c);
          break;
      }
    }
  }
  return(0);
}

