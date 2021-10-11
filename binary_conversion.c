// made by SIMPORE Juste kevin

# include<stdio.h>
# include<stdlib.h>

# include"M_headers.h"


int division_entiere(int *P_divdt, int divdt, int *divsr, int *tableau, int *i1)
{
  int R,i;
  static int i0=0;
  
  if(divdt<*divsr)
    {
      tableau[i0]=divdt;
      *i1=0;
      i0++;
    }
  else
    {
      *i1=1;
      i=0;
      do
	{
	  R=divdt-*divsr;
	  divdt=R;
	  i++;
	}while(R>=*divsr);
      
      tableau[i0]=R;
      *P_divdt=i;
      i0++;
      
    }
  
  return i0;
}

void afficheur_tableau(int *tableau, int taille, int num_case, char mode)
{
  int i;
  
  while(mode != 'h' && mode != 't')
    {
      printf("Veillez spécifiez le mode svp ('h' ou 't')\n");
      scanf("%c", &mode);
    }
  
  if(mode=='h')
    {
      printf("la conversion en binaire du nombre entré est(le complément à 2 est utilisé pour les valeurs négatives):\n");
      for(i=num_case-1; i>=0; i--)
	{
	  printf("%d", tableau[i]);
	}
      printf("\n");
    }
  
  else if(mode=='t')
    {
      printf("la conversion du nombre decimal dans la base que vous avez choisie correspond à:\n");
      for(i=num_case-1; i<=taille; i++)
	{
	  printf("%d",tableau[i]);
	}
    }
  else
    {
      printf("###Eurreur###\n");
      
    }
}

void choice(int *a)
{
  int nbr_divdt, nbr_divsr=2, case_ref, i, signe=0;
  int tableau[1001]={0};

  switch(*a)
    {
    case 1:
      printf("Veillez saisir le nombre decimal à convertir:\n");
      scanf("%d", &nbr_divdt);
      
      if(nbr_divdt<0)
	{
	  signe=1;
	  nbr_divdt=-nbr_divdt;
	}
      
      do
	{
	  case_ref=division_entiere(&nbr_divdt, nbr_divdt, &nbr_divsr, tableau, &i);
	}while(i!=0);
      if(signe)
	complement_2(tableau, case_ref);
      
      afficheur_tableau(tableau, 1001, case_ref, 'h');
      
      break;
    case 2:
      printf("Ceci est un programme destiné à faire la conversion\n d'un nombre decimal vers sa base 2 correspondante.\n\n Autheur: SIMPORE Juste kevin\n Nationnalité: Burkinabè\n Profession: Etudiant à l'Institut Supérieur du Genie Electrique Bf\n Adresse mail: simporekevin07@gmail.com\n");
      break;
    default:
      do
	{
	  printf("choisissez entre 1 et 2 svp\n");
	  scanf("%d", a);
	}while(*a!=1 && *a!=2);
      choice(a);
      
      break;
    }
}

void complement_2(int *tableau, int case_ref)
{
  int i=0, verf;

  for(i=0,verf=0; verf!=1 && i<=case_ref-1; i++)
    {
      if(tableau[i]==1)
	verf=1;
      else
	verf=0;
    }
  if(verf==1)
    {
      do
	{
	  if(tableau[i]==1)
	    tableau[i]=0;
	  else
	    tableau[i]=1;

	  i++;
	}while(i<=case_ref-1);
    }
}
