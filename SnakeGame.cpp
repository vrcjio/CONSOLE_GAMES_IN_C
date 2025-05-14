#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <vector>

using namespace std;

class SnakeGame
{
private:
    int posX, posY;
    int maxX, maxY;
    string direction;
    char input;
    bool exit;
    int fruitX, fruitY;
    int score;
    bool eatFood;
    vector<pair<int, int>> tail;
    int length;

    int getRandomeNumber(int min, int max)
    {
        return min + rand() % (max - min);
    }

    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

public:
    SnakeGame()
    {

        this->maxX = 60;
        this->maxY = 30;
        this->posX = maxX / 2;
        this->posY = maxY / 2;
        srand(time(0));
        this->direction = "right";
        this->input = ' ';
        this->exit = false;
        this->fruitX = this->fruitY = 0;
        this->score = 0;
        this->eatFood = true;
        this->length = 0;
    }

    void display()
    {
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "+---------------------------------------+" << endl;
        SetConsoleTextAttribute(hconsole, 10);
        cout << "+  SCORE:" << this->score << "                              +" << endl;
        SetConsoleTextAttribute(hconsole, 7);
        cout << "+---------------------------------------+" << endl;
    }

    void fruitCreate()
    {
        if (this->eatFood)
        {
            this->fruitX = getRandomeNumber(2, maxX - 1);
            this->fruitY = getRandomeNumber(2, maxY - 1);
            if (fruitX == posX && fruitY == posY)
            {
                return fruitCreate();
            }
            this->eatFood = false;
        }
    }

    void drawBoundaries()
    {
        // 1-15 colors options
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int y = 1; y <= this->maxY; y++)
        {
            for (int x = 1; x <= this->maxX; x++)
            {
                if (x == this->posX && y == this->posY)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "@"; // Snake head
                }
                else if (x == this->fruitX && y == this->fruitY)
                {
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << "*"; // Fruit
                }
                else if (x == 1 || y == 1 || x == this->maxX || y == this->maxY)
                {
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "#"; // Border
                }
                else
                {
                    bool printed = false;
                    for (auto t : this->tail)
                    {
                        if (t.first == x && t.second == y)
                        {
                            SetConsoleTextAttribute(hConsole, 10);
                            cout << "O"; // Tail part
                            printed = true;
                            break;
                        }
                    }

                    if (!printed)
                        cout << " ";
                }
            }
            cout << endl;
        }
    }

    void snakeMove()
    {
        // Up Arrow: 72
        // Down Arrow: 80
        // Left Arrow: 75
        // Right Arrow: 77

        if (_kbhit())
        {
            this->input = _getch();

            if ((this->input == 's' || this->input == 'S' || this->input == 80) && direction != "up")
            {
                direction = "down";
            }
            else if ((this->input == 'w' || this->input == 'W' || this->input == 72) && direction != "down")
            {
                direction = "up";
            }
            else if ((this->input == 'a' || this->input == 'A' || this->input == 75) && direction != "right")
            {
                direction = "left";
            }
            else if ((this->input == 'd' || this->input == 'D' || this->input == 77) && direction != "left")
            {
                direction = "right";
            }
            else if (this->input == 'q')
            {
                exit = true;
            }
        }

        pair<int, int> currentHead = {this->posX, this->posY};
        if (this->direction == "left")
        {
            this->posX--;
        }
        else if (this->direction == "right")
        {
            this->posX++;
        }
        else if (this->direction == "up")
        {
            this->posY--;
        }
        else if (this->direction == "down")
        {
            this->posY++;
        }

        this->tail.insert(this->tail.begin(), currentHead);
        if (this->tail.size() > length)
        {
            this->tail.pop_back();
        }
        // check if fruit was eaten during movement
        if (this->posX == this->fruitX && this->posY == this->fruitY)
        {
            score++;
            length++;
            eatFood = true;
        }
    }

    void gameOver()
    {
        if (this->posX <= 1 || this->posX >= this->maxX || this->posY <= 1 || this->posY >= this->maxY)
        {
            cout<<"Tota Score is: "<<this->score<<endl;
            cout << "Game Over (Wall)" << endl;
            getchar();
            this->exit = true;
        }
        for (auto t : this->tail)
        {
            if (t.first == this->posX && t.second == this->posY)
            {
                cout<<"Tota Score is: "<<this->score<<endl;
                cout << "Game Over (Self Collision)" << endl;
                getchar();
                this->exit = true;
            }
        }
    }

    void startGame()
    {
        while (!this->exit)
        {
            gotoxy(0, 0); // Yeh clear ki jagah cursor ko upar le jata hai
            display();
            fruitCreate();
            drawBoundaries();
            snakeMove();
            gameOver();
            Sleep(10); // optional: control speed
        }
    }

    void hideCursor()
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = 100;     // Set cursor size (optional)
        cursorInfo.bVisible = false; // Hide the cursor
        SetConsoleCursorInfo(out, &cursorInfo);
    }
};

int main()
{
    SnakeGame snake;
    snake.hideCursor();
    snake.startGame();
    return 0;
}
