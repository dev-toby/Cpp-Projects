#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Height and width of the boundary
const int width = 80;
const int height = 20;

// co-ordinate of snake head (x-axis, y-axis)
int x,y;


// Food co-ordinate
int fruitCordX, fruitCordY;


// Variable to store the score of a player
int playerScore;


// Array to store the co-ordinate of the snakes tail
int snakeTailX[100], snakeTailY[100];


// Variable to store the length of the snakes tail
int snakeTailLength;


// Variable for storing the snakes moving direction
enum snakeDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};


// snakeDirection variable
snakeDirection sDir;


// Boolean variable for checking game is over or not
bool isGameOver;


void GameInIt()
{
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

void GameRender(string playerName)
{
    system("cls"); // Clear the console
    //  Creating top walls with "-"
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < height; i++){
        for (int j = 0; j <= width; j++){
        // Creating side walls "|"
            if (j == 0 || j == width)
                cout << "|";
        // Creating the snakes head with "O"
            if (i == y && j == x)
                cout << "O";
        // Creating the snakes food with "#"
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#";
        // Creating the snakes body with "O"
            else {
                bool prTail = false;
                for (int k = 0; k < snakeTailLength; k++) {
                    if (snakeTailX[k] ==  j && snakeTailY[k] == i) {
                        cout << "O";
                        prTail = true;
                    }
                }
                if (!prTail)
                    cout << " ";
            }
        }
        cout << endl;
    }
    // Creating bottom walls with "-"
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;
    // Display player score
    cout << playerName << "'s Score: " << playerScore << endl;
}

void UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 1; 1< snakeTailLength; i ++){
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (sDir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    // Check for snake collision with the wall (|)
    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;
    // Check for the collision with the Tail (O)
    for (int i = 0; i < snakeTailLength; i++){
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }
    // Check for snake collision with the fruit (#)
    if (x == fruitCordX && y == fruitCordY){
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLength++;
    }  
}
int testDifficulty()
{
    int dfc, choice;
    cout << "\n SET DIFFICULTY \n 1: Easy \n 2: Meduim \n 3: Hard" "\n NOTE; if not choosen, the difficulty will be automatically set to medium." "\n Choose the difficulty level: ";
    cin >> choice;
    switch (choice) {
    case '1':
        dfc = 50;
        break;
    case '2':
        dfc = 100;
        break;
    case '3':
        dfc = 150;
        break;
    default:
        dfc = 100;
    }
    return dfc;
}

void UserInput (){
    // This is to check if the key is pressed or not
    if (_kbhit()) {
        switch (_getch()){
        case 'a':
            sDir = LEFT;
            break;
        case 'd':
            sDir = RIGHT;
            break;
        case 'w':
            sDir = UP;
            break;
        case 's':
            sDir = DOWN;
            break;
        case 'x':
            isGameOver = true;
            break;
        }
    }
}

int main (){
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int dfc = testDifficulty();

    GameInIt();
    while(!isGameOver) {
        GameRender(playerName);
        UserInput();
        UpdateGame();
        Sleep(dfc);
    }
    return 0;
}