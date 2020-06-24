#include <iostream>
#include <GL/freeglut.h>
#include <stdlib.h>

bool* keys = new bool[256];
float new_x = 0;
float new_y = 0;
bool but = true;

void Mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		but = true;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		but = false;
}

void Motion(int x, int y) {
	if (but) {
		system("CLS");
		std::cout << "mouseX: " << x << " | " << "mouseY: " << y << "\n";
	}
}

void keyDown(unsigned char key, int x, int y){
	keys[key] = true;
	std::cout << key;
}
void keyUp(unsigned char key, int x, int y){
	keys[key] = false;
	std::cout << " ";
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard");
	glutDisplayFunc(display);

	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glutMainLoop();

	return 0;
}