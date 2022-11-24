#include <stdio.h>
#include<string.h>

int main ()
{
  int i, j;//contadores de loop de for 
  int sessoes, pessoasPFilme[2], idade[100];//Questoes da sessao
  int crianca = 0, adolescentes = 0, adulto = 0, idoso = 0, mIdadeMasculino =0, mIdadeFeminino = 0;//contadores
  int qInteira = 0, qMeia = 0;//contadores ingrsso
  int quantidade;//quantidade de ingresso desejado 
  int masculino = 0, feminino = 0, opcao;//contadores , e opcao de ingrresso 

  float total, inteira[100], meia[100];//dinheiro

  char filme[2][100], caracteristica[100][20];//nome do filme e ,caracteristica(masculino ou feminino)

     do {
    printf ("Me forneca a quantidade de sessoes ? ");
    scanf ("%d", &sessoes);
    
    if (sessoes != 2)
        printf("Valor invalido, digite novamente!\n");
        
  } while (sessoes != 2);



        //inicio do loop de cada sessao
      for (i = 0; i < 2; i++)
	{
	  total = 0.00;
	  qInteira = 0.0;
	  qMeia = 0.0;
	  

	  printf ("\nMe forneca o nome do filme da sessao %d: ", i + 1);
	  fflush (stdin);
	  fgets (filme[i], 100, stdin);

	  printf("\nMe forneca o numero de pessoas que assistiram o filme %s: ",filme[i]);
	  scanf ("%d", &pessoasPFilme[i]);

	  while (pessoasPFilme[i] < 10)
	    {
	      printf("\nNumero de pessoas pra sessao e inferior ao recomendado que e 10\nMe forneca o numero de pessoas que assistiram o filme: ");
	      scanf ("%d", &pessoasPFilme[i]);
	    }


	  for (j = 0; j <= pessoasPFilme[i]; j++)
	    {
	      printf ("\n\nA pessoa %d e do sexo (M)asculino ou (F)eminino: ", j + 1);
	      fflush (stdin);
	      scanf ("%s", &caracteristica[j]);

	      if (strcmp(caracteristica[j], "Masculino") == 0)
			{
		  		masculino++;
			}else if (strcmp(caracteristica[j], "Feminino") == 0)
				{
		  	    	feminino++;
				}
	      	else{
				while (strcmp(caracteristica[j], "Feminino") != 0 && strcmp(caracteristica[j], "Masculino") != 0)
					{
						printf("\n\nSexo invalido ,fora das opcoes anteriormente informado\nMe informe se a pessoa %d e do sexo (M)asculino ou (F)eminino: ", j + 1);
						fflush (stdin);
						scanf ("%s", &caracteristica[j]);
						if (strcmp(caracteristica[j], "Masculino") == 0)
							{
								masculino++;
							}else if (strcmp(caracteristica[j], "Feminino") == 0)
								{
									feminino++;
								}
					}
			}


	      printf ("\n\nMe informe a idade da pessoa %d ", j + 1);
	      scanf ("%d", &idade[j]);

	      while (idade[j] > 100 || idade[j] < 3)
			{
		  		printf("\n\nIdade invalida para qualquer filme. por gentileza me informe a idade da pessoa %d: ", j + 1);
		 		 scanf ("%d", &idade[j]);
			}

	      	if (idade[j] > 18 && strcmp(caracteristica[j], "Masculino") == 0)
			{
		  		mIdadeMasculino++;
			}
	      	else if (idade[j] > 18 && strcmp(caracteristica[j], "Feminino") == 0)
				{
		  			mIdadeFeminino++;
				}

	      		if (idade[j] >= 3 && idade[j] <= 13)
				{
		 			 crianca++;
				}
				else if (idade[j] >= 14 && idade[j] <= 17)
				{
		  			adolescentes++;
				}
	      		else if (idade[j] >= 18 && idade[j] <= 64)
				{
		 			 adulto++;
				}
	     		 else if (idade[j] >= 65 && idade[j] <= 100)
				{
		 			 idoso++;
				}


	      printf("A pessoa %d desseja um ingresso\n(1)INTEIRA - R$50,00\n(2)MEIA - R$25,00\n",j + 1);
	      scanf ("%d", &opcao);

	      while (opcao > 2 || opcao < 1)
			{
				printf("Opcao da pessoa %d e invalida , por favor me informe qual ingresso a pessoa deseja\n(1)INTEIRA - R$50,00\n(2)MEIA - R$25,00\n",j + 1);
				scanf ("%d", &opcao);
			}

	      printf ("Quantos ingressoa a pessoa %d deseja ? ", j + 1);
	      scanf ("%d", &quantidade);



	      switch (opcao)
			{
				case 1:
				inteira[j] = 50.0 * quantidade;
				printf ("Valo a pagar: R$%.2f", inteira[j]);
				total = total + inteira[j];
				qInteira=quantidade;
				break;

				case 2:
				meia[j] = 25.0 * quantidade;
				printf ("Valo a pagar: R$%.2f", meia[j]);
				total = total + meia[j];
				qMeia=quantidade;
				break;

			}


	    }



	 	printf("O Filme %sconta com a participacao de homens %d e mulheres %dzn",filme[i], masculino, feminino);
	  	printf ("\tFaixa Etaria\tClassificacao\tQuantidade");
	  	printf("\tde 3 atC) 13 anos\tCriancas\t%d\n\tde 14 atC) 17 anos\tAdolescentes\t%d\n\tde 18 atC) 64 anos\tAdultos\t%d\n\tde 65 atC) 100 anos\tIdosos\t%d\n\n",crianca, adolescentes, adulto, idoso);
	  	printf("Quantidade de Homens maiores de 18:%d\nQuantidade de Mulheres maiores de 18 anos:%d",mIdadeMasculino, mIdadeFeminino);
	  
		if (qMeia > qInteira)
			{
			printf("Houveram mais vendas de ingressos de MEIA do que de INTEIRA e o valor arrecadado e :%f",total);
			}
		else if (qInteira > qMeia)
			{
			printf("Houveram mais vendas de ingressos de INTEIRA do que de MEIA e o valor arrecadado e :%f",total);
			}


	}
    
  
    

}

