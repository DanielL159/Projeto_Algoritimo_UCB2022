
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
    int i,j,a,b;
    int masculino=0,feminino=0;
    char filme [2][50],caracteristica[50];

    printf("Me forneca a quantidade de sessoes ? ");
    scanf("%d",&sessoes);

    if (sessoes == 2){
        for ( i = 0; i < 2; i++)
        {
            printf("Me forneca o nome do filme da sessao %d: ",i+1);
            fflush(stdin);
            fgets(filme[i],50,stdin);

            printf("\nMe forneca o numero de pessoas que assistiram o filme: ",filme[i]);
            scanf("%d",&pessoasPFilme[i]);

            while (pessoasPFilme[i] < 10  )
            {
                printf("\nNumero de pessoas pra sessao e inferior ao recomendado que e 10\nMe fornecaMe forneca o numero de pessoas que assistiram o filme: ");
                scanf("%d",&pessoasPFilme[i]);
            }


            for ( j = 0; j <= pessoasPFilme; j++)
            {
               /* printf("\n\nA pessoa %d e do sexo (M)asculino ou (F)eminino: ",j+1);
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
                 
                 




            }
            
            
            
        }  
    }else {
        printf("Numero de sessoes invalida");
    }
    

}