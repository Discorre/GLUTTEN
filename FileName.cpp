//#include <glut.h>
//#include <math.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//#define WINDOW_WIDTH 800
//#define WINDOW_HEIGHT 600
//#define NUM_CIRCLES 30
//#define EXPLOSION_HEIGHT WINDOW_HEIGHT / 2
//
//typedef struct {
//    float x;
//    float y;
//    float radius;
//} Circle;
//
//Circle circles[NUM_CIRCLES];
//
//void drawCircle(float x, float y, float radius) {
//    int numSegments = 100;
//    glBegin(GL_TRIANGLE_FAN);
//    for (int i = 0; i < numSegments; i++) {
//        float theta = 2.0f * 3.1415926f * i / numSegments;
//        float dx = radius * cosf(theta);
//        float dy = radius * sinf(theta);
//        glVertex2f(x + dx, y + dy);
//    }
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    for (int i = 0; i < NUM_CIRCLES; i++) {
//        Circle* circle = &circles[i];
//        drawCircle(circle->x, circle->y, circle->radius);
//    }
//
//    glutSwapBuffers();
//}
//
//void update(int value) {
//    for (int i = 0; i < NUM_CIRCLES; i++) {
//        Circle* circle = &circles[i];
//        circle->y += 2.0;  // Move the circles upwards
//
//        // Check if the circle has reached the explosion height, then explode
//        if (circle->y > EXPLOSION_HEIGHT) {
//            circle->radius *= 1.1;  // Increase the radius for explosion effect
//        }
//    }
//
//    glutPostRedisplay();
//    glutTimerFunc(16, update, 0);  // 60 frames per second
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//    glutCreateWindow("Fireworks");
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//
//    // Initialize circles with random positions and initial radius
//    for (int i = 0; i < NUM_CIRCLES; i++) {
//        circles[i].x = rand() % WINDOW_WIDTH;
//        circles[i].y = 0;
//        circles[i].radius = 5.0;
//    }
//
//    glutDisplayFunc(display);
//    glutTimerFunc(25, update, 0);  // Start the update loop
//
//    glutMainLoop();
//    return 0;
//}
