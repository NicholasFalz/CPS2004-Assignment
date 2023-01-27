import java.lang.Math;
import java.util.Scanner;

public class MineSweeper {

    private int[][] gameboardVisible = new int[10][10];
    private int[][] gameboardHidden = new int[10][10];
    public static void main(String[] args) {

        String[][] gameboard = generateGameBoard();

        gameboard = generateBombLocations(gameboard);





        for (int i = 0; i <= 16; i++) { // row
            for (int j = 0; j <= 16; j++) { // column
                System.out.print(gameboard[i][j] + " ");
            }
            System.out.println(); // change line on console as row comes to end in the matrix.
        }
    }

    static String[][] generateGameBoard() {
        String[][] gameboard = new String[17][17];

        String[] chars = {"  ", "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15"};
        for (int i = 0; i <= 16; i++) {
            for (int j = 0; j <= 16; j++) {
                if (i == 0) {
                    gameboard[i][j] = chars[j];
                } else if (j == 0) {
                    gameboard[i][j] = chars[i];
                } else {
                    gameboard[i][j] = "--";
                }
            }
        }
        return gameboard;
    }

    static String[][] generateBombLocations(String[][] gameboard) {
        int bomb_num = 0;
        while (bomb_num < 40) {
            int x = (int) ((Math.random() * (17 - 1)) + 1);
            int y = (int) ((Math.random() * (17 - 1)) + 1);

            System.out.println(x);
            System.out.println(y);

            if (gameboard[x][y].equals("--")) {
                gameboard[x][y] = "XX";
                bomb_num++;
            }
        }
        return gameboard;
    }

    static boolean playerMove() {
        Scanner scnr = new Scanner(System.in);
        System.out.print("\nEnter Row Number: ");
        int x = scnr.nextInt();
        System.out.print("Enter Column Number: ");
        int y = scnr.nextInt();

        if (x < 0 || x > 15 || y < 0 || y > 15) {
            System.out.print("\nIncorrect Input");
            return true;
        }
  //      if (gameboard[x][y].equals())
        return true;
    }
}