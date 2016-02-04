#include<iostream>
#include<cstdlib>
#include <GL\freeglut.h>
using namespace std;

float posX = 0.0f;
float posY = 0.0f;
float move_unit = 0.1f;


float r = 0.0f;
float g = 0.0f;
float b = 0.0f;

void Display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glPushMatrix();
	glTranslatef(posX, posY, 0.0f);
	glBegin(GL_POLYGON);

	glColor3f(r, g, b);
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.1f);

	glEnd();
	glPopMatrix();
	glFlush();
}

void KeysFun(unsigned char key, int xpos, int ypos) {

	switch (key) {

	case '\x1B':
		cout << "Escape key is press Now Exit" << endl;
		exit(EXIT_SUCCESS);
		break;

	case 'r':
		cout << "R Key press" << endl;
		r = 1.0f;
		g = 0.0f;
		b = 0.0f;
		break;



	case 'g':
		cout << "G Key press" << endl;
		r = 0.0f;
		g = 1.0f;
		b = 0.0f;
		break;

	case 'b':
		cout << "B Key press" << endl;
		r = 0.0f;
		g = 0.0f;
		b = 1.0f;
		break;


}

	glutPostRedisplay();
}
void SpecialKeys(int key,  int xpos, int ypos) {

	switch (key) {

		
	case GLUT_KEY_UP:

		if (posY<1.0) {
			cout << "Up key is press" << endl;
			posY += move_unit;


			cout << "Up Y Axis : " << posY << endl;
		}
		break;
		
	case GLUT_KEY_DOWN:
		if (posY > -1.0) {

			cout << "Down key is press" << endl;

			posY -= move_unit;

			cout << "Down Y Axis : " << posY << endl;
		}
		break;

	case GLUT_KEY_RIGHT:
		if (posX < 1.0) {
			cout << "Right key is press" << endl;
			posX += move_unit;
			cout << "Right X Axis : " << posX << endl;
		}
		break;

	case GLUT_KEY_LEFT:
		if (posX > -1.0) {
			cout << "Left key is press" << endl;
			posX -= move_unit;
			cout << "Left Y Axis : " << posX << endl;
		}
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void init(void) {


	glClearColor(239.0f / 255, 239.0f / 255, 187.0f / 255, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

int main(int argc, char**argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Color Movement");
	init();
	glutDisplayFunc(&Display);
	glutKeyboardFunc(&KeysFun);
	glutSpecialFunc(&SpecialKeys);
	glutMainLoop();

	return EXIT_SUCCESS;


}