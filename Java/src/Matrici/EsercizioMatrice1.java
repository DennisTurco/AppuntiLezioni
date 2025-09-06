package Matrici;
import java.util.Scanner;

public class EsercizioMatrice1 {
    public static void main(String[] args) {
        int dimx = 5, dimy = 5;

        // Scanner scan = new Scanner(System.in);
        // System.out.print("dimx = ");
        // dimx = scan.nextInt();
        // System.out.print("dimy = ");
        // dimy = scan.nextInt();
        // scan.close();
        
        int matrix1[][] = new int[dimx][dimy];
        int matrix2[][] = new int[dimx][dimy];
        int matrix3[][] = new int[dimx][dimy];

        int min = -100;
        int max = 100;
        
        for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                matrix1[i][j] = (int) (Math.random() * (max - min + 1)) + min;
                matrix2[i][j] = (int) (Math.random() * (max - min + 1)) + min;
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        StampaMatrice(matrix1, dimx, dimy);
        System.out.println();
        StampaMatrice(matrix2, dimx, dimy);
        System.out.println();
        StampaMatrice(matrix3, dimx, dimy);

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
