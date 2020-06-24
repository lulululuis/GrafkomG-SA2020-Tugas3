#include <iostream>
#include <GL/freeglut.h>

bool* keys = new bool[256];

void keyDown(unsigned char key, int x, int y){
	keys[key] = true;
	std::cout << key;
}
void keyUp(unsigned char key, int x, int y){
	keys[key] = false;
	std::cout << " ";
}

void Mouse(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		std::cout << "mouseX: " << x << " | " << "mouseY: " << y << "\n";

	//if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)

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

	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutMouseFunc(Mouse);

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glutMainLoop();

	return 0;
}