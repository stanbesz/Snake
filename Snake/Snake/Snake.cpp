

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
bool gameOver = true;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum directions{ stop=0, left,right,up,down};
directions dir;
void Setup() {
    gameOver = false;
    dir = stop;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width+1;
    fruitY = rand() % height+1;
    score = 0;
}
void Draw() {
    system("cls");
    
    for (int i = 0; i < width; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                std::cout << '#';
            }
            else if (j == x && i == y) {
                std::cout << "0";
            }
            else if (j == fruitX && i == fruitY) {
                std::cout << "*";
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < width; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}
void Input() {
    if (_kbhit()) {
        switch (_getch())
        {
        case 'a':
            dir = left;
            break;
        case 'w':
            dir = up;
            break;
        case 'd':
            dir = right;
            break;
        case 's':
            dir = down;
            break;
        case 'q':
            dir = stop;
            break;
        case 'x':
            std::cout << "Game Over! Final Score: " << score << std::endl;
            gameOver = true;
            break;
        }
    }
}
void Logic() {
    switch (dir)
    {
    case stop:

        break;
    case left:
        Sleep(20);
        x--;
        break;
    case right:
        Sleep(20);
        x++;
        break;
    case up:
        Sleep(50);
        y--;
        break;
    case down:
        Sleep(50);
        y++;
        break;
    default:
        break;
    }
    if (x == fruitX && y == fruitY) {
        score = score + 10;
        fruitX = rand() % height;
        fruitY = rand() % width;
    }
    if (x == width|| x == 0 || y == 0 || y == height) {
        gameOver = true;
        std::cout << "Game Over! Final Score: " << score << std::endl;
    }
}
int main()
{
    Setup();
    while (!gameOver) {
        Sleep(10);
        
        Draw();
        Logic();
        Input();
    }
}
