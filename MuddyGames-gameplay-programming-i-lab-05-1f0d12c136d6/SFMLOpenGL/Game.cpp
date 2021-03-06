#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
	primatives;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(150.0, window.getSize().x /
		window.getSize().y, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			glTranslatef(0.01f, 0.0f, 0.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			glTranslatef(-0.01f, 0.0f, 0.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			glTranslatef(0.0f, 0.01f, 0.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			glTranslatef(0.0f, -0.01f, 0.0f);
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			glRotatef(-rotationAngle, 0.0f, 0.0f, 1.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			glScalef(1.0001f, 1.0001f, 1.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(0.9999f, 0.9999f, 1.0f);
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl; 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glBegin(GL_TRIANGLES); { 
		glVertex3f(0.0, 2.0, -5.0); 
		glVertex3f(-2.0, -2.0, -5.0); 
		glVertex3f(2.0, -2.0, -5.0); 
	} 
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); {
		glVertex3f(4.0, 2.0, -5.0);
		glVertex3f(2, -2.0, -5.0);
		glVertex3f(6.0, -2.0, -5.0);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN); {
		glVertex3f(12.0, 2.0, -5.0);
		glVertex3f(10, -2.0, -5.0);
		glVertex3f(14.0, -2.0, -5.0);
	}
	glEnd();

	glBegin(GL_POINTS); {
		glVertex3f(10.0, -3.0, -5.0);
	}

	glEnd(); 

	glBegin(GL_LINES); {
		glVertex3f(5.0, -11.0, -5.0);
		glVertex3f(15.0, -11.0, -5.0);
	}

	glEnd();

	glBegin(GL_LINE_STRIP); {
		glVertex3f(5.0, -15.0, -5.0);
		glVertex3f(15.0, -15.0, -5.0);
	}

	glEnd();

	glBegin(GL_LINE_LOOP); {
		glVertex3f(5.0, -5.0, -5.0);
		glVertex3f(15.0, -5.0, -5.0);
		glVertex3f(15.0, -10.0,-5.0);
	}

	glEnd();

	glBegin(GL_QUADS); {
		glVertex3f(-5.0, 20.0, -5.0);
		glVertex3f(-15.0, 20.0, -5.0);
		glVertex3f(-15.0, 10.0, -5.0);
		glVertex3f(-5.0, 10.0, -5.0);
	}

	glEnd();

	glBegin(GL_QUAD_STRIP); {
		glVertex3f(-15.0, 5.0, -5.0);
		glVertex3f(-15.0, -5.0, -5.0);
		glVertex3f(-5.0, 5.0, -5.0);
		glVertex3f(-5.0, -5.0, -5.0);
	}

	glEnd();

	glBegin(GL_POLYGON); {

		glVertex3f(-15.0, -10.0, -5.0);
		glVertex3f(-15.0, -20.0, -5.0);
		glVertex3f(-5.0, -20.0, -5.0);
		glVertex3f(-5.0, -10.0, -5.0);
		glVertex3f(-10.0, -5.0, -5.0);
	}

	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

