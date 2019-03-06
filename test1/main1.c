#include <stdio.h>
#include <stdlib.h>

typedef struct s_data t_data;

struct s_data
{
  unsigned int a : 1;
  unsigned int b : 1;
  unsigned int c : 1;  
};

t_data *convert_bin(char a, char b);
unsigned char carry;
void add(t_data *data);

int main()
{
  t_data *data;

  data = convert_bin(5, 10);
  add(data);
  free(data);
}

t_data *convert_bin(char a, char b)
{
  char cpt;
  t_data *data;

  data = (t_data *)malloc(8 * sizeof(t_data));
  cpt = -1;
  while(++cpt < 8)
    {
      data[cpt].a |= a >> cpt;
      data[cpt].b |= b >> cpt;
      printf("a = %d, b = %d\n", data[cpt].a, data[cpt].b);
    }
  return (data);
}

void add(t_data *data)
{
  char cpt;

  carry = 0;
  cpt = -1;
  while(++cpt < 8)
    {
      if (data[cpt].a | data[cpt].b) //l'un des deux
	{
	  if (data[cpt].a & data[cpt].b)// les deux
	    {
	      if (carry)// les 3
		{
		  carry = 1;
		  data[cpt].c = 1;
		}
	      else//les 2
		{
		  carry = 1;
		  data[cpt].c = 0;
		}
	    }
	  else//l'un des deux
	    {
	      if (carry)//les 2
		{
		  carry = 1;
		  data[cpt].c = 0;
		}
	      else//l'un des deux
		  {
		  data[cpt].c = 1;
		}
	    }
	}
      else//aucun des deux
	{
	  if (carry)//le carry
	    {
	      carry = 0;
	      data[cpt].c = 1;
	    }
	  else//aucun
	    {
	      data[cpt].c = 0;
	    }
	}
      printf("%d", data[cpt].c);
    }
  printf("\n");
}
