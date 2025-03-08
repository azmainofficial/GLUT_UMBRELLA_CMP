#include <GL/glut.h>
#include <math.h>
#include <vector>

#define PI 3.14159265

struct CircleData {
    float radius, x, y, r, g, b;
};

struct RectangleData {
    float width, height, x, y, r, g, b;
};

// Vector to store circles
std::vector<CircleData> circles = {
    {0.65,  0.0,   0.2,  0.5, 1, 1},
    {0.40,  0.0,  -0.09, 1, 1, 1},
    {0.40, -0.5, -0.09,  1, 1, 1},
    {0.40,  0.5, -0.09,  1, 1, 1},
    {0.15, -0.12345, -0.37, 0, 0, 0},
    {0.10, -0.12345, -0.37, 1, 1, 1}
};

// Vector to store rectangles
std::vector<RectangleData> rectangles = {
    {0.05, 0.7,  0.0,  -0.04,  0, 0, 0},
    {0.3,  0.3, -0.175, -0.22, 1, 1, 1},
    {0.05, 0.06, 0.0,  0.88,   0, 0, 0}
};


void RenderText(float x, float y, const char* text, void* font = GLUT_BITMAP_HELVETICA_18) {
    glRasterPos2f(x, y);

    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void Rectangle(float width, float height, float x, float y, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);

    glVertex2f(x - width / 2, y - height / 2);
    glVertex2f(x + width / 2, y - height / 2);
    glVertex2f(x + width / 2, y + height / 2);
    glVertex2f(x - width / 2, y + height / 2);

    glEnd();
    glFlush();
}


void Circle(float radius, float x, float y, float red, float green, float blue){
    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);

    for(short int i = 0 ;i< 360;i++){
        double angle = 2* PI * i/360;
        double x_ = cos(angle) * radius;
        double y_ = sin(angle) * radius;
        glVertex2f(x+x_,y+y_);
    }
    glEnd();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    for (const auto& c : circles) {
        Circle(c.radius, c.x, c.y, c.r, c.g, c.b);
    }
    for (const auto& r : rectangles) {
        Rectangle(r.width, r.height, r.x, r.y, r.r, r.g, r.b);
    }


    RenderText(-0.37, 0.5, "Azmain 41220200226", GLUT_BITMAP_TIMES_ROMAN_24);

    glLoadIdentity();
    glutSwapBuffers();
}
void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(10,10);

    glutCreateWindow("GLUT Umbrella");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

}
