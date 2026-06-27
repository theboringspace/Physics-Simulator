#include "raylib.h"
#include "World.h"

int main()
{
	InitWindow(1980, 1080, "Physics Simulator");
	SetTargetFPS(120);

	/*
	 * VARIABLE INITIALIZATIONS
	 */
	World world;
	Body ball(Vector2D(400, 100), 20.0);
	world.AddBody(ball);

	double dt;

	/*
	 * TEXTURE INITIALIZATIONS
	 */


	while (!WindowShouldClose())
	{
		/*
		 * UPDATE VARIABLES
		 */
		dt = GetFrameTime();
		for (auto& body : world.GetBodies())
		{
			body.ApplyForce(Vector2D(0, 9.81 * body.GetMass()));
		}
		world.Update(dt);

		/*
		 * DRAWING ON SCREEN
		 */
		BeginDrawing();
			ClearBackground(RAYWHITE);

			for (auto& body : world.GetBodies())
			{
				DrawCircle(body.GetPosition().GetX(), body.GetPosition().GetY(), 30, DARKGRAY);
			}


		EndDrawing();
	}

	CloseWindow();

	return 0;
}