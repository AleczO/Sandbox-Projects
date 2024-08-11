# Ulam Spiarl in Raylib - Tutorial

![Ulam Spiral](Resources/ulam-spiral.png)


First we need to initialize our Raylib window. We can use the basic window template from [examples site](https://www.raylib.com/examples.html). To keep the main function clean and easy-to-read i will set flags and initialize window in external function.

```c++
void Initialize(void){
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               
}
```