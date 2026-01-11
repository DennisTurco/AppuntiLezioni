#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//  X - -
//  O O -
//  X - -

int main () {
    char board[3][3];

    // pre-popolamento
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }

    bool game_over = false;
    bool turno_giocatore1 = true;
    int n_tiro = 0;

    while (game_over == false) {
        // stampa della board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        if (turno_giocatore1 == true) {
            printf("Turno del giocatore X");
        }
        else {
            printf("Turno del giocatore O");
        }

        // posizione su dove mettere la X o la O
        int pos_x, pos_y;
        printf("\nInserisci posizione (i, j): ");
        scanf("%d", &pos_x);
        scanf("%d", &pos_y);

        if (turno_giocatore1 == true) {
            board[pos_x][pos_y] = 'X';
        } else {
            board[pos_x][pos_y] = 'O';
        }

        // cambio di turno
        if (turno_giocatore1 == true) {
            turno_giocatore1 = false;
        } else {
            turno_giocatore1 = true;
        }

        n_tiro++;

        // capire se la partita e' finita
        // orizzontali e verticali
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || 
                (board[0][i] == 'X' && board[1][i] == 'X'  && board[2][i] == 'X')) {
                printf("\nGiocatore X vince");
                game_over = true;
            }
            if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') || 
                (board[0][i] == 'O' && board[1][i] == 'O'  && board[2][i] == 'O')) {
                printf("\nGiocatore O vince");
                game_over = true;
            }
        }
        // diagonali
        if ((board[0][0] == 'X'  && board[1][1] == 'X'  && board[2][2] == 'X') ||
            (board[0][2] == 'X'  && board[1][1] == 'X'  && board[2][0] == 'X')) {
            printf("\nGiocatore X vince");
            game_over = true;
        }
        if ((board[0][0] == 'O'  && board[1][1] == 'O'  && board[2][2] == 'O') ||
            (board[0][2] == 'O'  && board[1][1] == 'O'  && board[2][0] == 'O')) {
            printf("\nGiocatore O vince");
            game_over = true;
        }
        if (n_tiro == 9) game_over = true;
    }

}