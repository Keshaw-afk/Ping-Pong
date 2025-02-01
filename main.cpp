#include <iostream>
#include <raylib.h>



int main(){
    InitWindow(800, 450, "Ping Pong");
    SetTargetFPS(60); // Set the target FPS to 60
    while (!WindowShouldClose())
    {
        static int speed_left_rectangle_y = 4;
        static int speed_right_rectangle_y = 4;
        BeginDrawing();
        ClearBackground(RAYWHITE);   
        static int left_rectangle_init_x = 10;
        static int left_rectangle_init_y = 10;

        static int right_rectangle_init_x = 765;
        static int right_rectangle_init_y = 340;

        static int left_rectangle_coordinate_x = left_rectangle_init_x;
        static int left_rectangle_coordinate_y = left_rectangle_init_y;

        static int right_rectangle_coordinate_x = right_rectangle_init_x;
        static int right_rectangle_coordinate_y = right_rectangle_init_y;


        DrawRectangle(left_rectangle_init_x, left_rectangle_coordinate_y, 20, 100, RED);
        DrawRectangle(right_rectangle_init_x, right_rectangle_coordinate_y, 20, 100, RED);


        if (IsKeyDown(KEY_DOWN)){
            left_rectangle_coordinate_y += speed_left_rectangle_y;
        }
        else if (IsKeyDown(KEY_UP)){
            left_rectangle_coordinate_y -= speed_left_rectangle_y;
        }
        
        right_rectangle_coordinate_y += speed_right_rectangle_y;

        if (left_rectangle_coordinate_y <= 0 || left_rectangle_coordinate_y >= 350)
        {
            speed_left_rectangle_y = -speed_left_rectangle_y;
        }
        if (right_rectangle_coordinate_y <= 0 || right_rectangle_coordinate_y >= 350)
        {
            speed_right_rectangle_y = -speed_right_rectangle_y;
        }

        static int circle_coordinate_x = 400;
        static int circle_coordinate_y = 225;
        static int speed_circle_x = 4;
        static int speed_circle_y = 4;

        DrawCircle(circle_coordinate_x, circle_coordinate_y, 12, BLACK);

        circle_coordinate_x += speed_circle_x;
        circle_coordinate_y += speed_circle_y;

        if (circle_coordinate_x >= 800 || circle_coordinate_x <= 0)
        {
            speed_circle_x = -speed_circle_x;
        }
        if (circle_coordinate_y >= 450 || circle_coordinate_y <= 0)
        {
            speed_circle_y = -speed_circle_y;
        }

        if (circle_coordinate_x <= left_rectangle_init_x + 20 && circle_coordinate_y >= left_rectangle_coordinate_y && circle_coordinate_y <= left_rectangle_coordinate_y + 100)
        {
            speed_circle_x = -speed_circle_x;
        }
        if (circle_coordinate_x >= right_rectangle_init_x - 20 && circle_coordinate_y >= right_rectangle_coordinate_y && circle_coordinate_y <= right_rectangle_coordinate_y + 100)
        {
            speed_circle_x = -speed_circle_x;
        }
        

        EndDrawing();
    }
    CloseWindow(); // Close the window and unload resources
    return 0;
}
