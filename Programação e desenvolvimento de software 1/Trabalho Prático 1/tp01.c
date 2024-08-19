#include <stdio.h>
 
// for para a quantidade de jogos
int main() {
    int quantidade_jogos;
    scanf("%d", &quantidade_jogos);

    for (int jogo = 0; jogo < quantidade_jogos; jogo++) {
        int tamanho_tabuleiro;
        scanf("%d", &tamanho_tabuleiro);

// declarando tabuleiro e o tamanho digitado pelo usuário
        char tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
        char revelados[tamanho_tabuleiro][tamanho_tabuleiro];

//for para preencher o tabuleiro digitado pelo usuário e criar um tabuleiro que contará o progresso, o qual é feito de 1 (não foi descoberto), 2 (casa descoberta) e b (bomba)
        for (int linha = 0; linha < tamanho_tabuleiro; linha++) {
            for (int coluna = 0; coluna < tamanho_tabuleiro; coluna++) {
                scanf(" %c", &tabuleiro[linha][coluna]);
                if (tabuleiro[linha][coluna] == 'b') {
                    revelados[linha][coluna] = 'b';
                } else {
                    if(tabuleiro[linha][coluna] == 'x')
                    revelados[linha][coluna] = '1';
                }
            }
        }

// jogadas que irá fazer mais o for delas
        int jogadas;
        scanf("%d", &jogadas);
        int perdeu = 0;

// for para não exceder o limite de jogadas mais as coordenadas digitadas, preferi deixar x,y porque é mais intuitivo e simples de entender 
        for (int limite = 0; limite < jogadas; limite++) {
            int x, y;
            scanf("%d %d", &x, &y);

// caso seja bomba, irá sair do for e vai dar a mensagem perdeu
            if (tabuleiro[x][y] == 'b') {
                perdeu = 1;
            } else {
                if (revelados[x][y] == '1') {

// caso a coordenada x,y selecionada ainda nao tenha sido descoberta, irá checar se está dentro do tabuleiro e caso sim, irá revelar ela. Caso ja tenha sido descoberta nada acontece
                 if (x < tamanho_tabuleiro && y < tamanho_tabuleiro ) {
                   revelados[x][y] = '2';

// aqui chega a parte mais complicada do código, nessa parte para cada coordenada adjacente, irá revelá-las caso nao sejam bombas, e caso sejam bomba, não irá ativar as diagonais
                    if (x - 1 >= 0 && tabuleiro[x-1][y] != 'b' && revelados[x-1][y] !='2') {
                           revelados[x-1][y] = '2';
                           if (y - 1 >= 0 && revelados[x-1][y-1] != 'b' && tabuleiro[x][y-1] != 'b')
                            revelados[x-1][y-1] = '2';

                    }

                    if ( y + 1 < tamanho_tabuleiro && tabuleiro[x][y+1] != 'b' && revelados[x][y+1] !='2') {
                           revelados[x][y+1] = '2';
                           if (y + 1 >= 0 && revelados[x-1][y+1] != 'b' && tabuleiro[x-1][y] != 'b')
                            revelados[x-1][y+1] = '2';

                    }

                    if ( x+1 < tamanho_tabuleiro && tabuleiro[x+1][y] != 'b' && revelados[x+1][y] !='2') {
                           revelados[x+1][y] = '2';
                           if (y+1 < tamanho_tabuleiro && revelados[x+1][y+1] != 'b' && tabuleiro[x][y+1] != 'b')
                            revelados[x+1][y+1] = '2';

                    }

                    if (y - 1 >= 0 && tabuleiro[x][y-1] != 'b' && revelados[x][y-1] !='2') {
                           revelados[x][y-1] = '2';
                           if (y - 1 >= 0 && revelados[x+1][y-1] != 'b' && tabuleiro[x+1][y] != 'b')
                            revelados[x+1][y-1] = '2';

                    }

                 }
                }

            }

        }

        if (perdeu) {
            printf("PERDEU\n");
        } else {
            int ganhou = 1;
            for (int linha = 0; linha < tamanho_tabuleiro; linha++) {
                for (int coluna = 0; coluna < tamanho_tabuleiro; coluna++) {
                    if (revelados[linha][coluna] == '1'){
                        ganhou = 0;
                        // aqui irá checar se o tabuleiro que contém as casas reveladas tem alguma casa que ainda não foi descoberta, caso sim, a saída será faltou terminar, caso não, o usuário ganhou
                    }
                }
                if (!ganhou) break;
            }
            if (ganhou) {
                printf("GANHOU\n");
            } else {
                printf("FALTOU TERMINAR\n");
            }
        }
    }

    return 0;
}
