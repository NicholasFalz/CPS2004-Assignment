import java.lang.Math;

public class Main {
    public static void main(String[] args) {

        String[][] gameboard = generateGameBoard();

        for(int i = 0; i < 40; i++) {
            int x = (int) ((Math.random() * (17 - 1)) + 1);
            int y = (int) ((Math.random() * (17 - 1)) + 1);

            System.out.println(x);
            System.out.println(y);

            gameboard[x][y] = "XX";
        }

        for (int i = 0; i <= 16; i++) { //this equals to the row in our matrix.
            for (int j = 0; j <= 16; j++) { //this equals to the column in each row.
                System.out.print(gameboard[i][j] + " ");
            }
            System.out.println(); //change line on console as row comes to end in the matrix.
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
}