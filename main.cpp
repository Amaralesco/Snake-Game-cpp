#include<iostream>
using namespace std;
bool gameOver;
int score;

//variable for map dimensions
const int width = 20;
const int height = 20;

//Variables for Snake position
int playerX;
int playerY;

int fruitX;
int fruitY;

//We need enumeration so player is not required to keep pressing the direction key
enum eDirection {STOP =0, LEFT, RIGHT,UP,DOWN};
eDirection dir;


void Setup(){
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

    system("cls"); // clear the screen
    for (int i = 0; i < width+1; i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++){
        for (int j = 0; j< width; j++){
            if (j==0){
                cout << "#";
            }
            else{
                cout << " ";
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

}

void Input(){

}

void Logic(){


}

int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        //Sleep(10);
    }

    return 0;   
}