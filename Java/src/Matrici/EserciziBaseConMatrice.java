package Matrici;
public class EserciziBaseConMatrice {
    public static void main(String[] args) throws Exception {
        int dimx = 5;
        int dimy = 5;
        int matrix[][] = new int[dimx][dimy];

        // riempio la matrice di solo i*j
        for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                matrix[i][j] = i*j;
            }
        }

        StampaMatrice(matrix, dimx, dimy);
        System.out.println();

        // matrice con tutti 0 tranne nella diagonale principale dovo ci sono 1
        for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                if (i == j) 
                    matrix[i][j] = 1;
                else 
                    matrix[i][j] = 0;
            }
        }

        StampaMatrice(matrix, dimx, dimy);
        System.out.println();

        // matrice con tutti 1 sotto la diagonale principale, sulla diagonale 2, sopra 3
        for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                if (i == j) 
                    matrix[i][j] = 2;
                else if (i < j) 
                    matrix[i][j] = 3;
                else 
                    matrix[i][j] = 1;
            }
        }

        StampaMatrice(matrix, dimx, dimy);
        System.out.println();
    }

    private static void StampaMatrice(int m[][], int dimx, int dimy) {
        for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                System.out.print(m[i][j]+" ");
            }
            System.out.println();
        }
    }

}
