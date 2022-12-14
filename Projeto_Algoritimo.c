
/*(Valor: 4,0 pontos) Um cinema de Brasília está interessado em descobrir o perfil das pessoas
que frequentam suas sessões de filmes e, para isso, necessita analisar as informacões
prestadas. Devem ser solicitados a quantidade de sessões que serão realizadas e, para cada
sessão, o nome do filme, a quantidade de pessoas que assistiram o filme, assim como, o sexo, a
idade e se foi pago inteira ou meia entrada. Para isso, algumas validacões devem ser realizadas:
1. Solicite a quantidade de sessões, aceitando exatamente 2 (duas) sessões. (0,4 ponto)
2. Solicite a quantidade de pessoas que assistiram ao filme, não aceitando valor inferior
a 10 (dez). (0,4 ponto)
3. Para cada pessoa que assistiu ao filme deverá ser solicitado e validado o sexo (M -
masculino, F - Feminino) e a idade (de 3 a 100 anos) (0,4 ponto).
4. Apresentar ao usuário apenas as opcões Inteira e Meia (0,4 ponto), e somar o valor
arrecadado na sessão, considerando que a inteira custa R$50,00 e a meia R$25,00 (0,4
ponto).
Após a leitura dos dados do filme, deverá ser apresentado:
5. o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de
pessoas do sexo masculino que assistiram ao filme (0,4 ponto).
6. a quantidade de pessoas, seguindo a classificacão por idade indicada abaixo. (0,4 ponto).
Idade Classificacão
de 3 até 13 anos Criancas
de 14 até 17 anos Adolescentes
de 18 até 64 anos Adultos
de 65 até 100 anos Idosos
7. Depois da leitura dos dados de cada sessão, deverá ser mostrada a quantidade de
pessoas maiores de idade (idade maior ou igual a 18 anos) do sexo masculino e a
quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes. (0,4
ponto).
8. Informar o valor total arrecadado em cada sessão e informar se houve mais pagamento
de inteira que de meia entrada. (0,4 ponto).
9. Dentro do contexto da atividade, pense em uma nova funcionalidade e implemente. (0,4
ponto)*/

#include <stdio.h>
#include<string.h>

int main (){
    int sessoes,pessoasPFilme[2],idade[100];
    int crianca=0,adolescentes=0,adulto=0,idoso=0,mIdadeMasculino=0,mIdadeFeminino=0;
    int qInteira=0,qMeia=0;
    int quantidade;
    int i,j;
    int masculino=0,feminino=0,opcao;

    float total=0.00,inteira[100] ,meia[100];

    char filme [2][100],caracteristica[100][50];

    printf("Me forneca a quantidade de sessoes ? ");
    scanf("%d",&sessoes);
    while (sessoes != 2 )
    {
        printf("\n\nNumero de sessoes maior ou menos que o permitido\nMe forneca a quantidade de sessoes ? ");
        scanf("%d",&sessoes);
    }
    

    if (sessoes == 2){
        for ( i = 0; i < 2; i++)
        {
            printf("\nMe forneca o nome do filme da sessao %d: ",i+1);
            fflush(stdin);
            fgets(filme[i],100,stdin);

            printf("\nMe forneca o numero de pessoas que assistiram o filme: ",filme[i]);
            scanf("%d",&pessoasPFilme[i]);

            while (pessoasPFilme[i] < 10  )
            {
                printf("\nNumero de pessoas pra sessao e inferior ao recomendado que e 10\nMe fornecaMe forneca o numero de pessoas que assistiram o filme: ");
                scanf("%d",&pessoasPFilme[i]);
            }


            for ( j = 0; j <= pessoasPFilme; j++)
            {
                /*printf("\n\nA pessoa %d e do sexo (M)asculino ou (F)eminino: ",j+1);
                fflush(stdin);
                scanf("%c",&caracteristica);

                a=strcmp(caracteristica,'M');
                b=strcmp(caracteristica,'F');

                if (a==0)
                {
                    masculino++;

                }else if(b == 0){

                    feminino++;

                }else {

                    while (a != 0 && b != 0)
                    {
                       printf("\n\nSexo invalido ,fora das opcoes anteriormente informado\nMe informe se a pessoa %d e do sexo (M)asculino ou (F)eminino: ");
                       fflush(stdin);
                       scanf("%c",&caracteristica);
                    }  

                }*/

                
                printf("\n\nMe informe a idade da pessoa %d ",j+1);
                scanf("%d",&idade[j]);
        
                while (idade[j] >100 || idade[j] <3)
                {
                  printf("\n\nIdade invalida para qualquer filme. por gentileza me informe a idade da pessoa %d: ",j+1);
                  scanf("%d",&idade[j]);
                }

                    if (idade >18 && caracteristica[j] =='M' ){
                        mIdadeMasculino++;
                    }else if (idade >18 && caracteristica[j] =='F'){
                        mIdadeFeminino++;
                    }

                   if (idade[j] >=3 && idade[j]<=13)
                    {
                     crianca++;
                    }else if (idade[j] >=14 && idade[j] <= 17)
                    {
                        adolescentes++;
                    }else if (idade[j] >=18 && idade[j] <= 64 ){
                        adulto++;
                    }else if (idade[j] >= 65 && idade[j]<= 100 ){
                        idoso++;
                    }
            

                printf("A pessoa %d desseja um ingresso\n(1)INTEIRA - R$50,00\n(2)MEIA - R$25,00\n",j+1);
                scanf("%d",&opcao);
                while (opcao >2 || opcao <1)
                {
                    printf("Opcao da pessoa %d e invalida , por favor me informe qual ingresso a pessoa deseja\n(1)INTEIRA - R$50,00\n(2)MEIA - R$25,00\n",j+1);
                    scanf("%d",&opcao);
                }

                printf("Quantos ingressoa a pessoa %d deseja ? ",j+1);
                scanf("%d",&quantidade);

                switch (opcao)
                {
                    case 1:
                        inteira[j] = 50.0 * quantidade;
                        printf("Valo a pagar: R$%.2f",inteira[j]);
                        total = total + inteira[j];
                        qInteira++;
                    break;

                    case 2:
                        meia[j] = 25.0 * quantidade;
                        printf("Valo a pagar: R$%.2f",meia[j]);
                        total = total + meia[j];
                        qMeia++;
                    break;
                
                }
                 
               
            }
         
            
  
            printf("O Filme %sconta com a participacao de homens %d e mulheres %dzn",filme[i],masculino,feminino);
            printf("\tFaixa Etaria\tClassificacao\tQuantidade");
            printf("\tde 3 até 13 anos\tCriancas\t%d\n\tde 14 até 17 anos\tAdolescentes\t%d\n\tde 18 até 64 anos\tAdultos\t%d\n\tde 65 até 100 anos\tIdosos\t%d\n\n",crianca,adolescentes,adulto,idoso);
            printf("Quantidade de Homens maiores de 18:%d\nQuantidade de Mulheres maiores de 18 anos:%d",mIdadeMasculino,mIdadeFeminino);
            if (qMeia>qInteira)
            {
                printf("Houveram mais vendas de ingressos de meia do que de inteira e o valor arrecadado e :%f",total);
            }else if (qInteira>qMeia){
                printf("Houveram mais vendas de ingressos de Inteira do que de Meia e o valor arrecadado e :%f",total);
            }
            
            
        }  
    }else{
        printf("Numero de sessoes invalida");
    }
    

}