#include "raylib.h"
#include "IForceGenerator.h"
#include "GravityForce.h"
#include "DragForce.h"
#include "World.h"

int main()
{
	InitWindow(1980, 1200, "Physics Simulator");
	SetTargetFPS(120);

	/*
	 * CONSTANTS INITIALIZATIONS
	 */
	const double PIXELS_PER_METER = 100;
	const double EARTH_GRAVITY = PIXELS_PER_METER * 9.81;

	/*
	 * VARIABLE INITIALIZATIONS
	 */
	World world;
	Body square(Vector2D(400, 100), 5.0);
	world.AddBody(square);

	GravityForce earth_gravity(EARTH_GRAVITY);
	DragForce air_drag(0.1);
	world.AddForceGenerator(&earth_gravity);
	world.AddForceGenerator(&air_drag);

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
		
		world.Update(dt);

		/*
		 * DRAWING ON SCREEN
		 */
		BeginDrawing();
			ClearBackground(RAYWHITE);

			for (auto& body : world.GetBodies())
			{
				DrawRectangle(body.GetPosition().GetX(), body.GetPosition().GetY(), 50, 50, DARKGRAY);
			}


		EndDrawing();
	}

	CloseWindow();

	return 0;
}