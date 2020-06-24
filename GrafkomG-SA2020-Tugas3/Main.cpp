#include <iostream>
#include <GL/freeglut.h>
#include <vector>

int i = 0;
bool but = true;
int mouse_x = 0;
int mouse_y = 0;
int pos;
std::vector <char> vec;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();

	glFlush();
}

void print() {
	system("cls");
	std::cout << "mouseX: " << mouse_x << " | " << "mouseY: " << mouse_y << std::endl;
	for (auto i : vec)
		std::cout << i << " ";
}

void Mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		but = true;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		but = false;
}

void Motion(int x, int y) {
	if (but) {
		mouse_x = x;
		mouse_y = y;
	}

	print();
}

void keyDown(unsigned char key, int x, int y) {
	auto cari = std::find(vec.begin(), vec.end(), key);
	if(cari == vec.end())	
		vec.push_back(key);
	
	print();
}

void keyUp(unsigned char key, int x, int y){
	auto cari = std::find(vec.begin(), vec.end(), key);
	if (cari != vec.end()) {
		pos = distance(vec.begin(), cari);
		vec.erase(vec.begin() + pos);
	}

	print();
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

	glutMainLoop();

	return 0;
}