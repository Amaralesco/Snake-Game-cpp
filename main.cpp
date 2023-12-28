#include<iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
int score;

//variable for map dimensions
const int width = 20;
const int height = 20;

//Variables for Snake position
int playerX;
int playerY;

//Variables for Fruit position
int fruitX;
int fruitY;

// Tail
int tailX[100],tailY[100];
int nTail;

//We need enumeration so player is not required to keep pressing the direction key
enum eDirection {STOP =0, LEFT, RIGHT,UP,DOWN};
eDirection dir;


void Setup(){

    system("cls");

    gameOver = false;
    dir = STOP;
    score = 0;

    //center the player on the map
    playerX = width / 2;
    playerY = height / 2;

    fruitX = rand() % width; 
    fruitY = rand() % height;


}

void Draw(){

    //system("cls"); // clear the screen
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    
    for (int i = 0; i < width+1; i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++){
        for (int j = 0; j< width; j++){
            if (j==0){
                cout << "#";
            }
            
            if( i == playerY & j == playerX) {
                cout <<"O";
            }
            else if ( i == fruitY && j == fruitX){
                cout << "F";
            }
            else{
                bool print = false;

                for (int k = 0; k<nTail; k++){
                    if (tailX[k] == j && tailY[k]== i){
                        print = true;
                        cout << "o";
                    }
                    
                }
                if(!print){
                    cout << " ";
                }
            }

            

            if (j == width -1 ){
                cout << "#";
            }
        }
        cout << endl;
        /* if (i==0){
                cout << "#";
        } */

    }


    for (int i = 0; i < width+1; i++){
        cout << "#";
    }
    cout << endl;

    cout << "Score:" << score << endl;

}

void Input(){
    //if keyboard hit true
    if(_kbhit ()){
        switch (_getch()){
            case 'a':
                dir = LEFT;
                break;

            case 'd':
                dir = RIGHT;
                break;

            case 'w':
                dir = UP;
                break;

            case 's':
                dir = DOWN;
                break;

            case 'x':
                gameOver = true;
                break;
        }
    }

}

void Logic(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = playerX;
    tailY[0] = playerY;
    for(int i = 1;i < nTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        playerX--; 
        break;
    
    case RIGHT:
        playerX++;
        break;

    case UP:
        playerY--;
        break;

    case DOWN:
        playerY++;
        break;
    
    default:
        break;
    }
    if(playerX > width || playerX <0 || playerY > height || playerY < 0){
        gameOver = true;
    }
    for (int i = 0; i < nTail; i++){
        if (tailX[i] == playerX && tailY[i]==playerY){
            gameOver = true;
        }
    }

    if ( playerX == fruitX && playerY == fruitY){
        score += 10;
        nTail++;
        //Spawn new fruit
        fruitX = rand() % width; 
        fruitY = rand() % height;   
    }

}

int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        //sleep(10);
        Sleep(50);
    }

    return 0;   
}