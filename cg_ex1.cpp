#include <GL/glut.h>

#define LARGURA 500
#define ALTURA 500

void Desenha_triangulo(){
	//cor do desenho
	glColor3f(1.0f, 1.0f, 1.0f);

	//desenha o triangulo com a cor definida acima
	glBegin(GL_TRIANGLES);
		glVertex2i(0, 250);
		glVertex2i(250, 500);
		glVertex2i(500, 250);
	glEnd();
}

void Desenha_poligono(){
	//cor1
	glColor3f(1.0f, 1.0f, 1.0f);

	//desenha o poligono
	glBegin(GL_QUADS);
		glVertex2i(0,250);
		glVertex2i(250,500);
		glVertex2i(500,250);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2i(250,0);
	glEnd();
}

void Desenha_linha(){
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_LINE_STRIP);
		glVertex2i(150,250);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2i(400,400);
		glVertex2i(250,0);
	glEnd();
}

void Desenha_Quadrado(){
	glColor3f(0.0f, 0.0f, 0.0f);

	//desenha o poligono
	glBegin(GL_QUADS);
		glVertex2i(300,500);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2i(500,500);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(500,300);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(300,300);
	glEnd();
}

void Desenha(void){
	
	glViewport(0,250,250,250);
	//cor de fundo da viewport1 - red
	glScissor(0,250,250,250);
	glEnable(GL_SCISSOR_TEST);
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	Desenha_triangulo();

	glViewport(250,250,250,250);
	//cor de fundo da viewport2 - red
	glScissor(250,250,250,250);
	glEnable(GL_SCISSOR_TEST);
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	Desenha_poligono();

	glViewport(0,0,250,250);
	//cor de fundo da viewport3 - green
    glScissor(0,0,250,250);
	glEnable(GL_SCISSOR_TEST);
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Desenha_linha();

	glViewport(250,0,250,250);
	//cor de fundo da viewport4 - white
    glScissor(250,0,250,250);
	glEnable(GL_SCISSOR_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Desenha_Quadrado();

	//executa comando opengl
	glFlush();
}

//rendering
void Inicializa (void)
{
    /* Modo de projecao ortogonal */
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Primeira janela criada");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}

