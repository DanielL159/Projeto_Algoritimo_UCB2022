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
	  total = 0.00;//Zera o valor total arecado pra que se tenha apenas o valor por sessao 
	  qInteira = 0.0;//Zera o Inteira total arecado pra que se tenha apenas o quantidade por sessao 
	  qMeia = 0.0;//Zera o quantida de Meias compradas  arecado pra que se tenha apenas o quantida por sessao 
	  
		//Recebe o nome do filme .
	  printf ("\nMe forneca o nome do filme da sessao %d: ", i + 1);
	  fflush (stdin);
	  fgets (filme[i], 100, stdin);

	//Quantidade de Pessoas Que assistiram aquela sessao em especifico .
	  printf("\nMe forneca o numero de pessoas que assistiram o filme %s: ",filme[i]);
	  scanf ("%d", &pessoasPFilme[i]);

		//Enquanto o numero de pessoas for inferior a 10 ele entrara em loop ate que seja digitado um valor maior que 10
	  while (pessoasPFilme[i] < 10)
	    {
	      printf("\nNumero de pessoas pra sessao e inferior ao recomendado que e 10\nMe forneca o numero de pessoas que assistiram o filme: ");
	      scanf ("%d", &pessoasPFilme[i]);
	    }

	//Usamos a variavel da quantidade de pessoas como delimitador de loop pois so queremos receber e verifica as informacoes das pessoa que estao na sessao
	  for (j = 0; j <= pessoasPFilme[i]; j++)
	    {
			//Recebe o sexo da pessoa como string
	      printf ("\n\nA pessoa %d e do sexo (M)asculino ou (F)eminino: ", j + 1);
	      fflush (stdin);//Limpa o Lixo de Memoria.
	      scanf ("%s", &caracteristica[j]);//Preferimos essa funcao pq a fgets adiciona um \0 no final da string , o que na hora de comparar da erro 

	      if (strcmp(caracteristica[j], "Masculino") == 0)//Verifica se sexo da pessoa e Masculino ,se for adiciona um ao contador masculino
			{
		  		masculino++;
			}else if (strcmp(caracteristica[j], "Feminino") == 0)//Verifica se sexo da pessoa e Feminino ,se for adiciona um ao contador feminino
				{
		  	    	feminino++;
				}
	      	else{
				while (strcmp(caracteristica[j], "Feminino") != 0 && strcmp(caracteristica[j], "Masculino") != 0)//Enquanto sexo da pessoa nao for Feminino ou Masculino
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


	      printf ("\n\nMe informe a idade da pessoa %d ", j + 1);//Recebe idade da pessoa em questao ;
	      scanf ("%d", &idade[j]);

	      while (idade[j] > 100 || idade[j] < 3)//Enquanto idade da pessoa for maior que 100 ou menor que 3 entra de loop 
			{
		  		printf("\n\nIdade invalida para qualquer filme. por gentileza me informe a idade da pessoa %d: ", j + 1);
		 		 scanf ("%d", &idade[j]);
			}

	      	if (idade[j] > 18 && strcmp(caracteristica[j], "Masculino") == 0)//Se o sexo da pessoa for masculino e ela for maior aque 18 entra adiciona 1 a contador de maior de idade masculino.
			{
		  		mIdadeMasculino++;
			}
	      	else if (idade[j] > 18 && strcmp(caracteristica[j], "Feminino") == 0)//Se o sexo da pessoa for feminino e ela for maior aque 18 entra adiciona 1 a contador de maior de idade feminino.
				{
		  			mIdadeFeminino++;
				}

	      		if (idade[j] >= 3 && idade[j] <= 13)//quando idade for maior ou igual a tres e menor ou igual a 13 adiciona 1 ao contador crianca
				{
		 			 crianca++;
				}
				else if (idade[j] >= 14 && idade[j] <= 17)//quando idade for maior ou igual a 14 e menor ou igual a 17 adiciona 1 ao contador adolescente
				{
		  			adolescentes++;
				}
	      		else if (idade[j] >= 18 && idade[j] <= 64)//quando idade for maior ou igual a 18 e menor ou igual a 64 adiciona 1 ao contador adulto
				{
		 			 adulto++;
				}
	     		 else if (idade[j] >= 65 && idade[j] <= 100)//quando idade for maior ou igual a 65 e menor ou igual a 100 adiciona 1 ao contador velho
				{
		 			 idoso++;
				}

			//Recebe qual dos tipos de ingresso a pessoa deseja 
	      printf("A pessoa %d desseja um ingresso\n(1)INTEIRA - R$50,00\n(2)MEIA - R$25,00\n",j + 1);
	      scanf ("%d", &opcao);

	      while (opcao > 2 || opcao < 1)//enquanto a opcoa de ingresso for maior que 2 ou menor que 1 entra ira perguntar o ingresso
			{
				printf("Opcao da pessoa %d e invalida , por favor me informe qual ingresso a pessoa deseja\n(1)INTEIRA - R$50,00\n(2)MEIA - R$25,00\n",j + 1);
				scanf ("%d", &opcao);
			}

	      printf ("Quantos ingressoa a pessoa %d deseja ? ", j + 1);//Pergunta quantos do tipo de ingresso anteriormente selecionado a pessoa deseja 
	      scanf ("%d", &quantidade);



	      switch (opcao)//Switch pra selecionar opcao de calculo de valor de ingresso selecionado
			{
				case 1://Caso de Inteira 
				inteira[j] = 50.0 * quantidade;//valor da inteira x quantos a pessoa quer 
				printf ("Valo a pagar: R$%.2f", inteira[j]);//imprime valor da inteira 
				total = total + inteira[j];//Valor arrecadadi e igual ao valor ja armazenado na total mais a da inteira e caso tenha da meia
				qInteira=quantidade;//contador para saber quantas inteira foram vendiadas
				break;

				case 2://caso de meia 
				meia[j] = 25.0 * quantidade;//valor da miea x quantos a pessoa quer 
				printf ("Valo a pagar: R$%.2f", meia[j]);//imprime valor da meia
				total = total + meia[j];//Valor arrecadadi e igual ao valor ja armazenado na total mais a da meia e caso tenha da inteira
				qMeia=quantidade; //contador para saber quantas meias foram vendiadas
				break;

			}


	    }

		//imprime todas as informacoes da sessao em questao 

	 	printf("O Filme %sconta com a participacao de homens %d e mulheres %dzn",filme[i], masculino, feminino);
	  	printf ("\tFaixa Etaria\tClassificacao\tQuantidade");
	  	printf("\tde 3 atC) 13 anos\tCriancas\t%d\n\tde 14 atC) 17 anos\tAdolescentes\t%d\n\tde 18 atC) 64 anos\tAdultos\t%d\n\tde 65 atC) 100 anos\tIdosos\t%d\n\n",crianca, adolescentes, adulto, idoso);
	  	printf("Quantidade de Homens maiores de 18:%d\nQuantidade de Mulheres maiores de 18 anos:%d",mIdadeMasculino, mIdadeFeminino);
	  //caso a quantidade me venda de ingressod de meia seja maior que a da interia aparecera uma mensagem caso ao contrio apresentarea outro texto .
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

