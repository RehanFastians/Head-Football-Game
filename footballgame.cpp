#include "footballgame.h"
#include "raylib.h"
#include "ball.h"
#include "background.h"
#include "player.h"
#include "goalie.h"
#include <iostream>
#include <string>
using namespace std;

void FootballGame ::resetPositons()
{
    // Reset player and goalie positions
    ((Player *)entities[0])->setPosition({float(SCREEN_WIDTH / 2.0 - 100), float(SCREEN_HEIGHT / 2.0)});
    ((Player *)entities[1])->setPosition({float(SCREEN_WIDTH / 2.0 + 100), float(SCREEN_HEIGHT / 2.0)});
    ((Player *)entities[1])->setDirection({-1.0, 0.0}); // default direction is left
    ((Player *)entities[0])->setDirection({1.0, 0.0});  // default direction is right
    ((Goalie *)entities[2])->setDirection({0.0, 1.0});
    ((Goalie *)entities[3])->setDirection({0.0, -1.0}); // default direction is left
    ((Ball *)entities[4])->setDirection({0.0, 0.0});
    ((Ball *)entities[4])->setSpeed(0);
    ((Goalie *)entities[2])->setPosition({80, float(SCREEN_HEIGHT / 2.0)});
    ((Goalie *)entities[3])->setPosition({float(SCREEN_WIDTH - 100), float(SCREEN_HEIGHT / 2.0)});
    ((Ball *)entities[4])->updatePosition({float(SCREEN_WIDTH / 2.0 - 7), float(SCREEN_HEIGHT / 2.0 - 7)});
}

void FootballGame::simulatePausedScreen()
{
    // Pause the game and show a paused screen
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN);
        DrawText("Game Paused", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150, 50, BLACK);
        DrawText("Press Esc to continue", SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2 + 20, 50, BLACK);
        EndDrawing();
        // if (IsKeyDown(KEY_TAB))
        //     break;
    }
}

void FootballGame::pauseForGoal(int limit)
{
    // Pause the game for a goal celebration
    int delay = 0;
    while (delay < limit * 60) // Display "Goal!" for limit seconds
    {
        BeginDrawing();
        ClearBackground(WHITE);
        background.loadBackground(SCREEN_WIDTH, SCREEN_HEIGHT);
        for (int i = 0; i < 5; i++)
        {
            entities[i]->draw();
        }
        // Draw Score
        DrawText(TextFormat("%d - %d", score[0], score[1]), SCREEN_WIDTH / 2.0 - 50, 10, 45, WHITE);
        // Draw Time
        DrawText(TextFormat("Time: %d", timeElapsed / 60), SCREEN_WIDTH / 2.0 - 30, SCREEN_HEIGHT - 35, 30, WHITE);
        EndDrawing();
        delay++;
    }
}

void FootballGame::isGoaled()
{
    // Check if the ball is in the goal area of either team
    if (((Ball *)entities[4])->getPosition().x <= horizontalLimit && ((Ball *)entities[4])->getPosition().y >= ((Goalie *)entities[2])->getMinHeight() && ((Ball *)entities[4])->getPosition().y <= ((Goalie *)entities[2])->getMaxHeight())
    {
        score[1]++;
        PlaySound(goalSound); // Play goal sound
        pauseForGoal(3.5);    // Pause for goal celebration
        resetPositons();
    }
    else if (((Ball *)entities[4])->getPosition().x >= SCREEN_WIDTH - horizontalLimit - ((Ball *)entities[4])->getSpriteImage().width && ((Ball *)entities[4])->getPosition().y >= ((Goalie *)entities[3])->getMinHeight() && ((Ball *)entities[4])->getPosition().y <= ((Goalie *)entities[3])->getMaxHeight())
    {
        score[0]++;
        PlaySound(goalSound); // Play goal sound
        pauseForGoal(3.5);    // Pause for goal celebration
        resetPositons();
    }
}

void FootballGame ::showOpeningScreen()
{

    Image temp = LoadImage("images/opening.png");
    ImageResize(&temp, SCREEN_WIDTH, SCREEN_HEIGHT);

    // enter any key to start the game
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(LoadTextureFromImage(temp), 0, 0, WHITE); // Load and draw the background image
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ESCAPE))
            break;
    }
}

void FootballGame ::showClosingScreen()
{

    int delay = 0;
    while (delay < 300) // Display "Game Over" for 5 second
    {
        BeginDrawing();
        DrawText("Game Over", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150, 50, BLACK);
        DrawText(TextFormat("Final Score: %d - %d", score[0], score[1]), SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 20, 50, BLACK);
        delay++;
        EndDrawing();
    }
}

void FootballGame::simulateGame()
{
    PlaySound(backgroundMusic);            // Play background music
    SetSoundVolume(backgroundMusic, 0.5f); // Set volume to 50%
    showOpeningScreen();                   // Show opening screen before starting the game
    SetSoundVolume(backgroundMusic, 0.1f); // Set volume to 10%
    // Initialize player and goalie positions
    ((Player *)entities[0])->setPosition({float(SCREEN_WIDTH / 2.0 - 100), float(SCREEN_HEIGHT / 2.0)});
    ((Player *)entities[1])->setPosition({float(SCREEN_WIDTH / 2.0 + 100), float(SCREEN_HEIGHT / 2.0)});
    ((Goalie *)entities[2])->setPosition({80, float(SCREEN_HEIGHT / 2.0)});
    ((Goalie *)entities[3])->setPosition({float(SCREEN_WIDTH - 100), float(SCREEN_HEIGHT / 2.0)});
    ((Ball *)entities[4])->updatePosition({float(SCREEN_WIDTH / 2.0 - 7), float(SCREEN_HEIGHT / 2.0 - 7)});

    while (WindowShouldClose() == false)
    {
        if (IsKeyDown(KEY_TAB))
        {
            simulatePausedScreen(); // Pause the game if TAB key is pressed
        }
        BeginDrawing();
        ClearBackground(WHITE);
        background.loadBackground(SCREEN_WIDTH, SCREEN_HEIGHT);
        entities[0]->update(horizontalLimit, verticalLimit);                                                         // Update player 1
        entities[1]->update(horizontalLimit, verticalLimit);                                                         // Update player 2
        ((Ball *)entities[4])->update((Player *)entities[0], (Player *)entities[1], horizontalLimit, verticalLimit); // Update ball position based on player positions
        ((Goalie *)entities[2])->update((Ball *)entities[4], horizontalLimit, verticalLimit);                        // Update goalie 1 position based on ball position
        ((Goalie *)entities[3])->update((Ball *)entities[4], horizontalLimit, verticalLimit);                        // Update goalie 2 position based on ball position
        isGoaled();                                                                                                  // Check if a goal has been scored
        // Draw Entities
        for (int i = 0; i < 5; i++)
        {
            entities[i]->draw();
        }
        // Draw Score
        DrawText(TextFormat("%d - %d", score[0], score[1]), SCREEN_WIDTH / 2.0 - 50, 10, 45, WHITE);
        // Draw Time
        DrawText(TextFormat("Time: %d", timeElapsed / 60), SCREEN_WIDTH / 2.0 - 30, SCREEN_HEIGHT - 35, 30, WHITE);
        timeElapsed++;
        if (timeElapsed >= timeLimit * 60) // Assuming 60 FPS, convert time limit to frames
        {
            EndDrawing();
            break;
        }
        EndDrawing();
    }
    showClosingScreen(); // Show closing screen after the game ends
}