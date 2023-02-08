import java.lang.Math;
import java.util.Scanner;

public class MineSweeper {

    private final String[] chars = {"--", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16"}; // chars to indicate the row and column of the gameboard

    private final String[][] gameBoardUserView = new String[17][17]; // gameboard which will be shown to the user (will start filled with blank cells and uncovered according to player choices)

    private final String[][] gameBoardHidden = new String[17][17]; // gameboard which will be hidden from the user (shows all mine positions and number of mines adjacent to each cell)

    public static void main(String[] args) {
        MineSweeper Game = new MineSweeper();
        Game.playGame();
    }

    public void playGame() {
        generateUserViewGameBoard();
        generateHiddenGameBoard();

        System.out.println("==================================================");
        System.out.println("|              Goofy Ahh Minesweeper             |");
        System.out.println("==================================================\n");

        boolean playing = true;
        while (playing) {
            displayUserViewGameBoard();
            playing = playerMove();
            if (checkWin()) {
                System.out.println("Yoy have secured the W. Congratulations!\n");
                displayHiddenGameBoard();
                playing = false;
            }
        }
    }

    public void generateUserViewGameBoard() { // generates the gameboard which the user will see (filled with uncovered cells)
        for (int i = 0; i <= 16; i++) {
            for (int j = 0; j <= 16; j++) {
                if (i == 0) {
                    gameBoardUserView[i][j] = chars[j];
                } else if (j == 0) {
                    gameBoardUserView[i][j] = chars[i];
                } else {
                    gameBoardUserView[i][j] = "--";
                }
            }
        }
    }

    public void generateHiddenGameBoard() { // generates the gameboard which will be hidden from the user (contains mine positions and adjacent mine numbers)
        for (int i = 0; i <= 16; i++) {
            for (int j = 0; j <= 16; j++) {
                if (i == 0) {
                    gameBoardHidden[i][j] = chars[j];
                } else if (j == 0) {
                    gameBoardHidden[i][j] = chars[i];
                } else {
                    gameBoardHidden[i][j] = "--";
                }
            }
        }

        int bomb_num = 0;
        while (bomb_num < 40) { // generates 40 random bomb positions in the hidden gameboard
            int x = (int) ((Math.random() * (17 - 1)) + 1); // randomly generate x position of bomb
            int y = (int) ((Math.random() * (17 - 1)) + 1); // randomly generate y position of bomb

            if (gameBoardHidden[x][y].equals("--")) { // if chosen position does not have a bomb in that place already
                gameBoardHidden[x][y] = "XX";
                bomb_num++;
            }
        }

        for (int i = 1; i <= 16; i++) {
            for (int j = 1; j <= 16; j++) {
                int adjacentbombs = 0;
                if (!gameBoardHidden[i][j].equals("XX")) { // the following if statements will check each cell's adjacent cells to determine the number of mines adjacent to each cell
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
                    gameBoardHidden[i][j] = "0" + adjacentbombs;
                }
            }
        }
    }

    public void displayUserViewGameBoard() { // method which displays the gameboard which the user will play on
        for (int i = 0; i <= 16; i++) { // row
            for (int j = 0; j <= 16; j++) { // column
                System.out.print(gameBoardUserView[i][j] + " ");
            }
            System.out.println(""); // change line on console
        }
    }

    public void displayHiddenGameBoard() { // method which displays the gameboard containing mine locations and adjacent mine numbers
        for (int i = 0; i <= 16; i++) { // row
            for (int j = 0; j <= 16; j++) { // column
                System.out.print(gameBoardHidden[i][j] + " ");
            }
            System.out.println(""); // change line on console
        }
    }

    public boolean playerMove() { // method which prompts the user to choose a cell to reveal by entering its row and colum number
        Scanner scnr = new Scanner(System.in);
        System.out.print("\nEnter Row Number: ");
        int x = scnr.nextInt();
        System.out.print("Enter Column Number: ");
        int y = scnr.nextInt();
        System.out.println("");

        if (x < 1 || x > 16 || y < 1 || y > 16) { // providing an invalid integer/s
            System.out.println("Invalid input\n");
            return true;
        } else if (!gameBoardUserView[x][y].equals("--")) { // selecting a cell which has already been revealed
            System.out.println("This cell has already been revealed\n");
            return true;
        }
        if (gameBoardHidden[x][y].equals("XX")) { // reveals a mine
            System.out.println("You hit a mine! F\n");
            displayHiddenGameBoard(); // when player loses, the mine positions are displayed, similar to the actual minesweeper
            return false;
        } else if (checkAdjacentCells(x, y)) {
            showCells(x, y); // if none of the selected cell's adjacent cells are bombs, reveal the selected cell along with its 8 adjacent cells
        } else {
            updateGameBoard(x, y);
        }
        return true;
    }

    public boolean checkAdjacentCells(int i, int j) { // method which checks if the chosen cell's adjacent cells are not bombs
        if (i > 1) {
            if (gameBoardHidden[i-1][j].equals("XX")) return false; // if any one of them is a bomb, return false
        }
        if (j > 1) {
            if (gameBoardHidden[i][j-1].equals("XX")) return false;
        }
        if (i < 16) {
            if (gameBoardHidden[i+1][j].equals("XX")) return false;
        }
        if (j < 16) {
            if (gameBoardHidden[i][j+1].equals("XX")) return false;
        }
        if (i > 1 && j > 1) {
            if (gameBoardHidden[i-1][j-1].equals("XX")) return false;
        }
        if (i < 16 && j < 16) {
            if (gameBoardHidden[i+1][j+1].equals("XX")) return false;
        }
        if (i > 1 && j < 16) {
            if (gameBoardHidden[i-1][j+1].equals("XX")) return false;
        }
        if (i < 16 && j > 1) {
            if (gameBoardHidden[i+1][j-1].equals("XX")) return false;
        }
        return true; // if none of them are bombs, return true
    }

    public void showCells(int i, int j) { // method which reveals the selected cell and its adjacent cells
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

    public void updateGameBoard(int x, int y) {  // method which updates the user-visible gameboard with the corresponding value in the hidden gameboard
        gameBoardUserView[x][y] = gameBoardHidden[x][y];
    }

    public boolean checkWin() { // method which checks if the player has won
        for (int i = 0; i <= 16; i++) { // row
            for (int j = 0; j <= 16; j++) { // column
                if (gameBoardUserView[i][j].equals("--") && !gameBoardHidden[i][j].equals("XX")) return false; // if all unrevealed cells are mines, player has won
            }
        }
        return true;
    }
}