#include <glut.h>
#include <math.h>

GLint Width = 512, Height = 512; //������ � ������ ������

int n = 0, ch = 0; //���������� �������� 
double r = 0.025; //r - ������ �������
double rsb = 0.01; //rsb - ������ ��������� ������
//���������� ��� ��������� ������, ���������� �� ����� "������" ����� ��������� ����������� � � ����������� �������� �� �������� �������� ������.
double Speed1 = 0, Speed2 = 0, Speed15 = 0, Speed05 = 0;
//���������� ��� ��������� ������, ���������� �� ������ "�������". ����� ��������� ����������� � � ����������� �������� �� �������� �������� ������
double Speedc = -0.4, Speedc1 = -0.4, Speedcx = 0.5, Speedcx1 = 0.5, Speedcl = -0.5, Speedcl1 = -0.5;

double Position1 = 0, Position05 = 0, Position15 = 0; // ������� ������


void Circle(double r1, int cnt, double kx, double ky) { //������� ������ ����. r1 - ������, � ������� kx � ky �� ����� �������� ������� ����� � ����� �����, cnt - �������� ���������� �����
	float y, x;
	float da = 3.14159 * 2.0 / cnt; //����� ���� �� cnt ������
	glBegin(GL_TRIANGLE_FAN); //������������ �������� ������ � ������ ��������� ����� ������
	glVertex2f(0 + kx, 0 + ky); //���������� ������ �����
	for (int i = 0; i <= cnt; i++) { //���� ������� ������ ����
		x = r1 * sin(da * i); //���������� ����� �� x
		y = r1 * cos(da * i); //���������� ����� �� y
		glVertex2f(x + kx, y + ky); //������� �������
	}
	glEnd();
}

void �ub�Right() { //������� ������ �����, ��� ������ ������, ������� ����� �����������, ����� �������
	glColor3f(1, 0, 1); //������-���������� ����
	//������ �����, ��������� �� ��������� ����������
	Circle(rsb, 30, 0.5, Speedc);
	Circle(rsb, 30, 0.5, Speedc1);
	Circle(rsb, 30, Speedcx, -0.4);
	Circle(rsb, 30, Speedcx1, -0.4);
	Circle(rsb, 30, Speedcx, Speedc);
	Circle(rsb, 30, Speedcx1, Speedc);
	Circle(rsb, 30, Speedcx, Speedc1);
	Circle(rsb, 30, Speedcx1, Speedc1);

}

void CubeCenter() {
	glColor3ub(255, 255, 255); // ����� ����
	// ������ �����, ��������� �� ��������� ���������� ��������� ������
	Circle(rsb, 30, 0, Speedc);
	Circle(rsb, 30, 0, Speedc1);
	Circle(rsb, 30, Speedcl1 + 0.5, -0.4);
	Circle(rsb, 30, Speedcl + 0.5, -0.4);
	Circle(rsb, 30, -Speedcx1 + 0.5, Speedc1);
	Circle(rsb, 30, -Speedcx + 0.5, Speedc1);
	Circle(rsb, 30, -Speedcx + 0.5, Speedc);
	Circle(rsb, 30, -Speedcx1 + 0.5, Speedc);
}


void CubeLeft() { //������� ������ ����� ��������� ���������� ����� ��� ������ �����, ������� ����� �����������, ����� ���
	glColor3ub(249, 101, 21); //��������	��������� ����
	//������ �����, ��������� �� ��������� ����������
	Circle(rsb, 30, -0.5, Speedc);
	Circle(rsb, 30, -0.5, Speedc1);
	Circle(rsb, 30, Speedcl1, -0.4);
	Circle(rsb, 30, Speedcl, -0.4);
	Circle(rsb, 30, -Speedcx1, Speedc1);
	Circle(rsb, 30, -Speedcx, Speedc1);
	Circle(rsb, 30, -Speedcx, Speedc);
	Circle(rsb, 30, -Speedcx1, Speedc);
}
void StarCenter() {
	glColor3ub(0, 128, 0);
	Circle(rsb, 30, 0, Position15);
	Circle(rsb, 30, 0, -Position05);
	Circle(rsb, 30, Position15, Position05);
	Circle(rsb, 30, -Position15, Position05);
	Circle(rsb, 30, -Position1, -Position1);
	Circle(rsb, 30, Position1, -Position1);
	Circle(rsb, 30, Position05, 0);
	Circle(rsb, 30, -Position05, 0);
	Circle(rsb, 30, Position05, Position05);
	Circle(rsb, 30, -Position05, Position05);
	// ��������� �������� � ������
	//glBegin(GL_LINE_LOOP); //��� ����� ���� �������� �� ����� ����� �������, ���� �� ����� ������
	//glVertex2f(0,Position15);//1
	//glVertex2f(Position05,Position05);//9
	//glVertex2f(Position15,Position05);//3
	//glVertex2f(Position05,0);//7
	//glVertex2f(Position1,-Position1);//5
	//glVertex2f(0,-Position05);//2
	//glVertex2f(-Position1,-Position1);//6
	//glVertex2f(-Position05,0);//8
	//glVertex2f(-Position15,Position05);//4
	//glVertex2f(-Position05,Position05);//10
	//glEnd();
}

void Reshape(GLint w, GLint h) //������� ���������� ��� ��������� �������� ���� 
{
	Width = w;
	Height = h;
	//������������� ������� ������� ����������� 
	glViewport(0, 0, w, h);
	//��������������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void FireworkLeft() { //������� ������ ����� �����
	Circle(r, 30, -0.5, -0.4); //��������� �����
}

void FireworkCenter() { //������� ������ ����������� �����
	Circle(r, 30, 0, 0); //��������� �����
	n++; //�������
	r = r + 0.00005; //���������� �������
}

void FireworkRight() { //������� ������ ������ �����
	Circle(r, 30, 0.5, -0.4); //��������� �����
	n++; //�������
}

void FireworkCenter2() { //������� ������ ����������� �����
	Circle(r, 30, 0, -0.4); //��������� �����
	n++; //�������
	r = r + 0.00005; //���������� �������
}

void background() { //������� ������ ������ ���
	glBegin(GL_TRIANGLE_STRIP); //������ ��������� ���������
	glColor3ub(0, 0, 0); //������ ����
	glVertex2i(10, 10); //������ �������
	glVertex2i(10, -10);
	glVertex2i(-10, 10);
	glVertex2i(-10, -10);
	glEnd();
}

void All(void){ //������� ��� ��������� �����
	glClearColor(0, 0, 0, 1); //������� ����� ������
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	background(); //�������� ������� ��� ��������� ������� ����
	glColor3ub(254, 221, 0); //������ ��������-������ ���� �������
	if (n < 3500) { //���� ������ 3500 
		glTranslatef(0, 0.0004, 0); //� ������� glTranslatef ������� �������� �������
		FireworkRight(); //�������� �������, ������� ������ ������ �����
		FireworkCenter(); //�������� �������, ������� ������ ����������� �����
		FireworkLeft(); //�������� �������, ������� ������ ����� �����
		FireworkCenter2();
		glFinish(); //���������� ���������	
	}
	if (n >= 3500) { //���� n ������  3500 
		if (ch < 20000) { //�������� �������, ������� ������ ��������� �����
			StarCenter();
			�ub�Right();
			CubeLeft();
			CubeCenter();
		}
		if (ch < 20000) {
			//�������� ���������� ��������� �����. �������� �������� ������.
			Speed1 += 0.0001;
			Speed2 += 0.0002;
			Speed15 += 0.00015;
			Speed05 += 0.00005;
			Speedc += 0.0001;
			Speedc1 -= 0.0001;
			Speedcx -= 0.0001;
			Speedcx1 += 0.0001;
			Speedcl += 0.0001;
			Speedcl1 -= 0.0001;
			Position1 += 0.0001;
			Position05 += 0.00005;
			Position15 += 0.00015;
			//����������� �������
			ch++;
		}
		glFinish();//���������� ���������
	}
}
int main(int argc, char* argv[])
{
	/* ������������� GLUT */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	/* �������� ���� */
	glutCreateWindow("Firework Star and 2 Cubs");
	/* ����������� ���������� ������� */
	glutReshapeFunc(Reshape);
	glutDisplayFunc(All);
	glutIdleFunc(All);
	/* ������ ��������� ��������� ������� */
	glutMainLoop();
}
