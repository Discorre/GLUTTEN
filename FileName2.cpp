#include <glut.h>
#include <math.h>

GLint Width = 512, Height = 512; //Ширина и высота экрана

int n = 0, ch = 0; //Переменные счетчики 
double r = 0.025; //r - радиус салютов
double rsb = 0.01; //rsb - радиус маленьких кругов
//Переменные для рисования кругов, отвечающих за салют "звезда" Равны начальным координатам и в последующем отвечают за скорость движения кругов.
double Speed1 = 0, Speed2 = 0, Speed15 = 0, Speed05 = 0;
//Переменные для рисования кругов, отвечающих за салюты "квадрат". Равны начальным координатам и в последующем отвечают за скорость движения кругов
double Speedc = -0.4, Speedc1 = -0.4, Speedcx = 0.5, Speedcx1 = 0.5, Speedcl = -0.5, Speedcl1 = -0.5;

double Position1 = 0, Position05 = 0, Position15 = 0; // Позиции звезды


void Circle(double r1, int cnt, double kx, double ky) { //Функция рисует круг. r1 - радиус, с помощью kx и ky мы можем задавать вершину круга в любой точке, cnt - точность прорисовки круга
	float y, x;
	float da = 3.14159 * 2.0 / cnt; //Делим круг на cnt частей
	glBegin(GL_TRIANGLE_FAN); //Треугольники задаются первой и каждой следующей парой вершин
	glVertex2f(0 + kx, 0 + ky); //Координаты центра круга
	for (int i = 0; i <= cnt; i++) { //Цикл который рисует круг
		x = r1 * sin(da * i); //Координата точки по x
		y = r1 * cos(da * i); //Координата точки по y
		glVertex2f(x + kx, y + ky); //Создаем вершину
	}
	glEnd();
}

void СubеRight() { //Функция рисует круги, для салюта справа, которые будут разлетаться, рисуя квадрат
	glColor3f(1, 0, 1); //Светло-фиолетовый цвет
	//Рисуем круги, указываем их начальные координаты
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
	glColor3ub(255, 255, 255); // Белый цвет
	// Рисуем круги, указываем их начальные координаты смещенные вправо
	Circle(rsb, 30, 0, Speedc);
	Circle(rsb, 30, 0, Speedc1);
	Circle(rsb, 30, Speedcl1 + 0.5, -0.4);
	Circle(rsb, 30, Speedcl + 0.5, -0.4);
	Circle(rsb, 30, -Speedcx1 + 0.5, Speedc1);
	Circle(rsb, 30, -Speedcx + 0.5, Speedc1);
	Circle(rsb, 30, -Speedcx + 0.5, Speedc);
	Circle(rsb, 30, -Speedcx1 + 0.5, Speedc);
}


void CubeLeft() { //Функция рисует круги тигрового оранжевого цвета для салюта слева, которые будут разлетаться, рисуя куб
	glColor3ub(249, 101, 21); //Тигровый	оранжевый цвет
	//Рисуем круги, указываем их начальные координаты
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
	// Рисование квадрата в центре
	//glBegin(GL_LINE_LOOP); //Эта часть кода отвечает за линии между звездой, если не видно звезды
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

void Reshape(GLint w, GLint h) //Функция вызывается при изменении размеров окна 
{
	Width = w;
	Height = h;
	//Устанавливаем размеры области отображения 
	glViewport(0, 0, w, h);
	//Ортографическая проекция
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void FireworkLeft() { //Функция рисует левый салют
	Circle(r, 30, -0.5, -0.4); //Рисование круга
}

void FireworkCenter() { //Функция рисует центральный салют
	Circle(r, 30, 0, 0); //Рисование круга
	n++; //Счетчик
	r = r + 0.00005; //Увеличение радиуса
}

void FireworkRight() { //Функция рисует правый салют
	Circle(r, 30, 0.5, -0.4); //Рисование круга
	n++; //Счетчик
}

void FireworkCenter2() { //Функция рисует центральный салют
	Circle(r, 30, 0, -0.4); //Рисование круга
	n++; //Счетчик
	r = r + 0.00005; //Увеличение радиуса
}

void background() { //Функция рисует задний фон
	glBegin(GL_TRIANGLE_STRIP); //Начало рисования примитива
	glColor3ub(0, 0, 0); //Черный цвет
	glVertex2i(10, 10); //Рисуем вершины
	glVertex2i(10, -10);
	glVertex2i(-10, 10);
	glVertex2i(-10, -10);
	glEnd();
}

void All(void){ //Функция для рисования всего
	glClearColor(0, 0, 0, 1); //Очистка цвета экрана
	glClear(GL_COLOR_BUFFER_BIT); //Очищает буфер цвета
	background(); //Вызываем функцию для рисования заднего фона
	glColor3ub(254, 221, 0); //Задаем бананово-желтый цвет салютам
	if (n < 3500) { //Пока меньше 3500 
		glTranslatef(0, 0.0004, 0); //С помощью glTranslatef создаем движение салютов
		FireworkRight(); //Вызываем функцию, которая рисует правый салют
		FireworkCenter(); //Вызываем функцию, которая рисует центральный салют
		FireworkLeft(); //Вызываем функцию, которая рисует левый салют
		FireworkCenter2();
		glFinish(); //Завершение рисования	
	}
	if (n >= 3500) { //Если n больше  3500 
		if (ch < 20000) { //Вызываем функции, которые рисуют маленькие круги
			StarCenter();
			СubеRight();
			CubeLeft();
			CubeCenter();
		}
		if (ch < 20000) {
			//Изменяем координаты маленьких шаров. Скорость движения кругов.
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
			//Увеличиваем счетчик
			ch++;
		}
		glFinish();//Завершение рисования
	}
}
int main(int argc, char* argv[])
{
	/* Инициализация GLUT */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	/* Открытие окна */
	glutCreateWindow("Firework Star and 2 Cubs");
	/* Регистрация вызываемых функций */
	glutReshapeFunc(Reshape);
	glutDisplayFunc(All);
	glutIdleFunc(All);
	/* Запуск механизма обработки событий */
	glutMainLoop();
}
