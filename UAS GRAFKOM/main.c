#include <GL/glut.h>

float angle = 0.0f;  
float ballX = 0.0f;  
float ballY = 0.0f;  
float bowlX = 0.0f;  
float bowlY = 0.0f; 

void drawBasketball() {
    glColor3f(1.0f, 0.549f, 0.0f);  
    glPushMatrix();
    glTranslatef(ballX, ballY, 0.0f);  
    glutWireSphere(0.5, 20, 20);  
    glPopMatrix();
}

void drawBowl() {
    glColor3f(1.0f, 1.0f, 1.0f);  
    glPushMatrix();
    glTranslatef(bowlX, bowlY, 0.0f);  
    glRotatef(angle, 0.0, 0.0, 1.0);  
    glutWireCone(1.0, 2.0, 20, 20);  
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    glRotatef(angle, 0.0, 1.0, 0.0);  
    drawBasketball();
    glPopMatrix();

    glPushMatrix();
    drawBowl();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            ballX -= 0.1f;  
            break;
        case 'd':
            ballX += 0.1f;  
            break;
        case 'w':
            ballY += 0.1f;  
            break;
        case 's':
            ballY -= 0.1f;  
            break;
        
    }
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            bowlY += 0.1f;  
            break;
        case GLUT_KEY_DOWN:
            bowlY -= 0.1f;  
            break;
        case GLUT_KEY_LEFT:
            bowlX -= 0.1f;  
            break;
        case GLUT_KEY_RIGHT:
            bowlX += 0.1f;  
            break;
    }
}

void update(int value) {
    angle += 1.0f;  
    if (angle > 360.0f) {
        angle -= 360.0f;
    }

    glutPostRedisplay();  
    glutTimerFunc(16, update, 0);  
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Objek 3D - Bola Basket & Mangkok");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutIdleFunc(display);
    glutTimerFunc(0, update, 0);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
