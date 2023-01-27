import java.lang.Math;
import java.util.Scanner;

public class MineSweeper {

    private final String[] chars = {"  ", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16"};

    private String[][] gameBoardUserView = new String[17][17];

    private String[][] gameBoardHidden = new String[17][17];

    public static void main(String[] args) {
        MineSweeper M = new MineSweeper();
        M.playGame();
    }

    public void playGame() {
        generateUserViewGameBoard();
        generateHiddenGameBoard();
        displayHiddenGameBoard();
        System.out.println("");

        boolean game = true;
        while (game) {
            displayUserViewGameBoard();
            game = playerMove();
        }
    }

    public void generateUserViewGameBoard() {
        for (int i = 0; i <= 16; i++) {
            for (int j = 0; j <= 16; j++) {
                if (i == 0) {
                    gameBoardUserView[i][j] = chars[j];
                }
                else if (j == 0) {
                    gameBoardUserView[i][j] = chars[i];
                }
                else {
                    gameBoardUserView[i][j] = "--";
                }
            }
        }
    }
    public void generateHiddenGameBoard() {
        for (int i = 0; i <= 16; i++) {
            for (int j = 0; j <= 16; j++) {
                if (i == 0) {
                    gameBoardHidden[i][j] = chars[j];
                }
                else if (j == 0) {
                    gameBoardHidden[i][j] = chars[i];
                }
                else {
                    gameBoardHidden[i][j] = "--";
                }
            }
        }

        int bomb_num = 0;
        while (bomb_num < 40) {
            int x = (int) ((Math.random() * (17 - 1)) + 1);
            int y = (int) ((Math.random() * (17 - 1)) + 1);

            if (gameBoardHidden[x][y].equals("--")) {
                gameBoardHidden[x][y] = "XX";
                bomb_num++;
            }
        }

        for (int i = 1; i <= 16; i++) {
            for (int j = 1; j <= 16; j++) {
                int adjacentbombs = 0;
                if (!gameBoardHidden[i][j].equals("XX")) {
                    if (i > 1) {
                        if (gameBoardHidden[i-1][j].equals("XX")) adjacentbombs += 1;
                    }
                    if (j > 1) {
                        if (gameBoardHidden[i][j-1].equals("XX")) adjacentbombs += 1;
                    }
                    if (i < 16) {
                        if (gameBoardHidden[i+1][j].equals("XX")) adjacentbombs += 1;
                    }
                    if (j < 16) {
                        if (gameBoardHidden[i][j+1].equals("XX")) adjacentbombs += 1;
                    }
                    if (i > 1 && j > 1) {
                        if (gameBoardHidden[i-1][j-1].equals("XX")) adjacentbombs += 1;
                    }
                    if (i < 16 && j < 16) {
                        if (gameBoardHidden[i+1][j+1].equals("XX")) adjacentbombs += 1;
                    }
                    if (i > 1 && j < 16) {
                        if (gameBoardHidden[i-1][j+1].equals("XX")) adjacentbombs += 1;
                    }
                    if (i < 16 && j > 1) {
                        if (gameBoardHidden[i+1][j-1].equals("XX")) adjacentbombs += 1;
                    }
                    gameBoardHidden[i][j] = String.valueOf("0" + adjacentbombs);
                }
            }
        }
    }

    public void displayUserViewGameBoard() {
        for (int i = 0; i <= 16; i++) { // row
            for (int j = 0; j <= 16; j++) { // column
                System.out.print(gameBoardUserView[i][j] + " ");
            }
            System.out.println(); // change line on console as row comes to end in the matrix.
        }
    }

    public void displayHiddenGameBoard() {
        for (int i = 0; i <= 16; i++) { // row
            for (int j = 0; j <= 16; j++) { // column
                System.out.print(gameBoardHidden[i][j] + " ");
            }
            System.out.println(); // change line on console as row comes to end in the matrix.
        }
    }

    public boolean playerMove() {
        Scanner scnr = new Scanner(System.in);
        System.out.print("\nEnter Row Number: ");
        int x = scnr.nextInt();
        System.out.print("Enter Column Number: ");
        int y = scnr.nextInt();
        System.out.println("");

        if (x < 1 || x > 16 || y < 1 || y > 16) {
            System.out.println("Invalid input");
            System.out.println("");
            return true;
        }
        else if (!gameBoardUserView[x][y].equals("--")) {
            System.out.println("This cell has already been revealed");
            System.out.println("");
            return true;
        }
        if (gameBoardHidden[x][y].equals("XX")) {
            System.out.println("You hit a mine! L siehbi");
            System.out.println("");
            return false;
        }
        else if (checkAdjacentCells(x, y)) {
            showCells(x, y);
        }
        else {
            updateGameBoard(x, y);
        }
        return true;
    }

    public boolean checkAdjacentCells(int i, int j) {
        if (i > 1) {
            if (gameBoardHidden[i - 1][j].equals("XX")) return false;
        }
        if (j > 1) {
            if (gameBoardHidden[i][j - 1].equals("XX")) return false;
        }
        if (i < 16) {
            if (gameBoardHidden[i + 1][j].equals("XX")) return false;
        }
        if (j < 16) {
            if (gameBoardHidden[i][j + 1].equals("XX")) return false;
        }
        if (i > 1 && j > 1) {
            if (gameBoardHidden[i - 1][j - 1].equals("XX")) return false;
        }
        if (i < 16 && j < 16) {
            if (gameBoardHidden[i + 1][j + 1].equals("XX")) return false;
        }
        if (i > 1 && j < 16) {
            if (gameBoardHidden[i - 1][j + 1].equals("XX")) return false;
        }
        if (i < 16 && j > 1) {
            if (gameBoardHidden[i + 1][j - 1].equals("XX")) return false;
        }
        return true;
    }

    public void showCells(int i, int j) {
        gameBoardUserView[i][j] = gameBoardHidden[i][j];

        if (i > 1) {
            gameBoardUserView[i-1][j] = gameBoardHidden[i-1][j];
        }
        if (j > 1) {
            gameBoardUserView[i][j-1] = gameBoardHidden[i][j-1];
        }
        if (i < 16) {
            gameBoardUserView[i+1][j] = gameBoardHidden[i+1][j];
        }
        if (j < 16) {
            gameBoardUserView[i][j+1] = gameBoardHidden[i][j+1];
        }
        if (i > 1 && j > 1) {
            gameBoardUserView[i-1][j-1] = gameBoardHidden[i-1][j-1];
        }
        if (i < 16 && j < 16) {
            gameBoardUserView[i+1][j+1] = gameBoardHidden[i+1][j+1];
        }
        if (i > 1 && j < 16) {
            gameBoardUserView[i-1][j+1] = gameBoardHidden[i-1][j+1];
        }
        if (i < 16 && j > 1) {
            gameBoardUserView[i+1][j-1] = gameBoardHidden[i+1][j-1];
        }
    }

    public void updateGameBoard(int x, int y) {
        gameBoardUserView[x][y] = gameBoardHidden[x][y];
    }
}