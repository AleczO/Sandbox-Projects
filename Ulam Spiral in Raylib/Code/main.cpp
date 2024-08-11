#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
#define screenWidth 900
#define screenHeight 900



void Initialize(void){
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Ulam Spiral");
    SetTargetFPS(60);
}


class Spiral{
private:
    Vector2 Position = {screenHeight / 2, screenWidth / 2};
    
    int vertical = 1;
    int horizontal = 1;

    const int delta = 5;
    const int PointSize = 2;

    vector<Vector2> Positions;


    bool IsPrime(int number){
        if(number == 1)
            return 0;

        for(int i = 2; i * i <= number; ++i)
            if(number % i == 0)
                return 0;
        
        return 1;
    }

public:
    void GenerateSpiral(int iterationCount){
        for(int i = 0; i < iterationCount; ++i){

            for(int j = 0; j < vertical; ++j){
                Positions.push_back(Position);
                Position.x += delta;
            }
            vertical++;

            for(int j = 0; j < horizontal; ++j){
                Positions.push_back(Position);
                Position.y -= delta;
            }
            horizontal++;

            for(int j = 0; j < vertical; ++j){
                Positions.push_back(Position);
                Position.x -= delta;
            }
            vertical++;

            for(int j = 0; j < horizontal; ++j){
                Positions.push_back(Position);
                Position.y += delta;
            }
            horizontal++;
    
        }
    }
    
    void DrawSpiral(void){
        for(int i = 1; i < Positions.size(); ++i){
            if(IsPrime(i)) 
                DrawCircle(Positions[i].x, Positions[i].y, PointSize, BLACK);
        }
    }
};


int main(void)
{
    Initialize();

    Spiral S;
    S.GenerateSpiral(90);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        S.DrawSpiral();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
