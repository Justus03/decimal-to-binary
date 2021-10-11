/* _______________
 *
 * Author: SIMPORE juste kevin
 * 
 * date: march 22nd 2021
 *
 * programme_purpose: convert a decimal number to binary...
 *
 * _______________
 *
 */

# include<stdio.h>
# include<stdlib.h>

# include"M_headers.h"


int main(int argc, char *argv[])
{
  int  choix=0;

  printf("convertisseur décimal-binaire:\n\n");
  printf("**MENUE**\n1-convertir un nombre décimal en binaire\n2-Apropos du programme\n");
  scanf("%d", &choix);
  choice(&choix);
  
  return 0;
}

	
