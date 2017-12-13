#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	// // Uncomment for Part 2
	// // ********************
	 const int primatives = 4;

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.1f;
	// // ********************
};