#include <stdio.h>
#include <stdlib.h> //biblioteca para limpar terminal

//função para imprimir espaço no terminal
void espaco(int qnt) {
    if (qnt == 0)return;
    printf(" ");
    espaco(qnt - 1);
}

//função para imprimir um texto mais o espaço
void linhaComEspaco(size_t n, const char* texto){
    espaco(n);
    printf("%s\n", texto);
}

//função para imprimir o L do cavalo quando vai para a esquerda, tendo a opção de ir para cima ou baixo
void esquerdaLado(size_t i, size_t mov, size_t dife){
    if (dife == 1)
    {
        if(i > mov) return;

        linhaComEspaco(i, "cima");
        linhaComEspaco(i, "Esquerda Esquerda");

        esquerdaLado(i + 1, mov, dife);
    } else{
        if (i == 0) return;
        
        linhaComEspaco(i, "Esquerda Esquerda");
        linhaComEspaco(i, "Baixo");

        esquerdaLado(i - 1, mov, dife);
    }
    
}
//função para imprimir o L do cavalo quando vai para a direita, tendo a opção de ir para cima ou baixo
void Direitalado(size_t i, size_t m, size_t dife){
    if (dife == 1)
    {
        if(i > m) return;

        linhaComEspaco(i, "Direita Direita");
        linhaComEspaco(i, "          baixo");

        Direitalado(i + 1, m, dife);
    }else
    {
        if(i == 0) return;

        linhaComEspaco(i, "           cima");
        linhaComEspaco(i, "Direita Direita");

        Direitalado(i - 1, m, dife);
    }
}
//Para imprimir cima no terminal 
void imprimirCima (size_t n, int vezes){
    if (vezes == 0) return;
    espaco(n);
    printf("cima\n");
    imprimirCima(n, vezes - 1);
}
//para imprimir baixo no terminal
void imprimirBaixo(size_t n, int vezes){
    if(vezes == 0) return;
    espaco(n);
    printf("baixo\n");
    imprimirBaixo(n, vezes - 1);
}
//Movimento L do cavalo, para a direita indo para cima ou para baixo
void direita(size_t i, size_t m, size_t direcao){
    if (direcao == 1)
    {
        if(i == 0) return;
        espaco(i);
        printf("direita\n");
        imprimirCima(i , 2);
        direita(i - 1, m, direcao);
    } else if (direcao == 2)
    {
        if (i > m) return;
        imprimirBaixo(i, 2);
        espaco(i);
        printf("direita\n");
        direita(i + 1, m, direcao);
    }
}
//Movimento L do cavalo, para a esquerda indo para cima ou para baixo
void esquerda (size_t n, size_t m, size_t direcao){
    if (direcao == 1)
    {
        if(n > m) return;
        espaco(n);
        printf("esquerda\n");
        imprimirCima(n, 2);
        esquerda(n + 1, m, direcao);
    } else if (direcao == 2)
    {
        if (n == 0)return;
        imprimirBaixo(n, 2);
        espaco(n);
        printf("esquerda\n");
        esquerda(n - 1, m, direcao);
    }
}
//Escolha do movimento da torre
void movimentoTorre (int mov, int direcao){
    if(mov <= 0) return;
    switch (direcao)
    {
    case 1:
        if (mov > 0)
        {
            printf("cima\n");
        }
        break;
    case 2:
        if (mov > 0)
        {
            printf("baixo\n");
        }
        break;
    case 3:
        if (mov > 0)
        {
            printf("direita ");
        }
        break;
    case 4:
        if (mov > 0)
        {
            printf("esquerda ");
        }
        break;
    default:
        break;
    }
    movimentoTorre(mov - 1, direcao);
}
//Escolha do movimento da bispo
void movimentoBispo (int n, int mov, int direcao){
    switch (direcao)
    {
    case 1:
        if (n > mov) return;
        
        espaco(n);
        printf("direita baixo\n");

        movimentoBispo(n + 1, mov, direcao);
        break;
    case 2:
        if (mov == 0)return;
        
        espaco(mov);
        printf("direita cima\n");

        movimentoBispo(n, mov - 1, direcao);

        break;
    case 3:
        if (n > mov)return;

        espaco(n);
        printf("esquerda cima\n");

        movimentoBispo(n + 1, mov, direcao);
        break;
    case 4:
        if (mov == 0) return;
        
        espaco(mov);
        printf("esquerda baixo\n");

        movimentoBispo(n, mov - 1, direcao);
        break;
    }
}
//Escolha do movimento da cavalo
void movimentoCavalo (int mov, int direcao, int dife){
    switch (direcao)
    {
    case 1:
        if (dife == 1) {
            direita(mov, 0, direcao);
        } else {
            esquerda(1, mov, direcao);
        }
        break;
    case 2:
        if (dife == 1) {
            direita(1, mov, direcao);
        } else {
            esquerda(mov, 0, direcao);
        }
        break;
    case 3:
        if (dife == 1) {
           Direitalado(1, mov, dife);
        } else {
            Direitalado(mov, 1, dife);
        }
        break;
    case 4:
        if (dife == 1) {
           esquerdaLado(1, mov, dife);
        } else {
            esquerdaLado(mov, 0, dife);
        }
    default:
        break;
    }
}
//variáveis do programa
struct xadrez
{
    int cavalo, rainha, torre, bispo;
};
// área da interação com o usuário
void main(){
    struct xadrez pec[3];
    int escolha;
    printf("Escolha qual a peça: \n1- Torre \n2-Bispo \n3-Rainha \n4-Cavalo \n");
    scanf("%d", &escolha);
    system("cls");//limpar terminal

    switch (escolha)
    {
    case 1:
        printf("Qual a direção que a torre deve fazer: \n1-Cima \n2-Baixo \n3-Direita \n4-Esquerda \n");
        scanf("%d", &pec[0].torre);
        printf("Qual a quantidade de movimentos: ");
        scanf("%d", &pec[1].torre);
        system("cls");//limpar terminal
        movimentoTorre(pec[1].torre, pec[0].torre);
        break;
    case 2:
        printf("Qual a direção que o bispo deve fazer: \n1-Direita e Baixo \n2-Direita e Cima \n3-Esquerda e Cima \n4-Esquerda e Baixo \n");
        scanf("%d", &pec[0].bispo);
        printf("qual a quantidade de movimentos: ");
        scanf("%d", &pec[1].bispo);
        system("cls");//limpar terminal
        movimentoBispo(1, pec[1].bispo, pec[0].bispo);
        break;
    case 3: 
        printf("Qual a direção que a rainha deve fazer: \n1-Cima \n2-Baixo \n3-Direita \n4-Esquerda \n5-Direita e baixo \n6-Direita e Cima \n7-Esquerda e cima \n8-Esquerda e baixo \n");
        scanf("%d", &pec[0].rainha);
        printf("Qual a quantidade de movimentos: ");
        scanf("%d", &pec[1].rainha);
        system("cls");//limpar terminal
        if (pec[0].rainha < 5)
        {
            movimentoTorre(pec[1].rainha, pec[0].rainha);
        } else
        {
            pec[2].rainha = pec[0].rainha - 4;

            movimentoBispo(1, pec[1].rainha, pec[2].rainha);
        }
        break;
    case 4:
        printf("Qual a diração que o cavalo deve fazer: \n1-Cima \n2-Baixo \n3-Direita \n4-Esquerda \n");
        scanf("%d", &pec[0].cavalo);
        printf("Qual a quantidade de movimentos: ");
        scanf("%d", &pec[1].cavalo);
        system("cls");//limpar terminal
        printf("Qual a direção do L: \n");
        printf((pec[0].cavalo < 3)? "1-Direita \n2-esquerda\n" : "1- Cima \n2-Baixo\n");
        scanf("%d",&pec[2].cavalo);
        system("cls");//limpar terminal
        movimentoCavalo(pec[1].cavalo, pec[0].cavalo, pec[2].cavalo);
        
    default:
        printf("Opção inválida\n");
        break;
    }

    return 0;
}
