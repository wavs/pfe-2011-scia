from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from WidgetCenter.WidgetCenter import *

ESCAPE = '\033'

def drawBox(x, y, width, height, color, titleBar):
	if width == 0:
		width = 1
	if height == 0:
		height = 1
	
	(r, g, b) = color
	#if (color == "white"):
	#	glColor3f(1.0, 1.0, 1.0)
	#else:
	#	glColor3f(0.8, 0.8, 0.8)
	glColor3f(r, g, b)
	glBegin(GL_QUADS)
	glVertex3f(x - (width/2.0), y - (height/2.0), 0.0)	# Top Left
	glVertex3f(x + (width/2.0), y - (height/2.0), 0.0)	# Top Right
	glVertex3f(x + (width/2.0), y + (height/2.0), 0.0)	# Bottom Right
	glVertex3f(x - (width/2.0), y + (height/2.0), 0.0)	# Bottom Left
	glEnd()
	
	if (titleBar):
		glColor3f(0.5, 0.0, 0.0)
	
		glBegin(GL_QUADS)
		glVertex3f(x - (width/2.0), y - (height/2.0), 0.0)	# Top Left
		glVertex3f(x + (width/2.0), y - (height/2.0), 0.0)	# Top Right
		glVertex3f(x + (width/2.0), y - (height/2.0) + 20, 0.0)	# Bottom Right
		glVertex3f(x - (width/2.0), y - (height/2.0) + 20, 0.0)	# Bottom Left
		glEnd()

class Board():
	def __init__(self, height, width, title):
		self.height = height
		self.width = width
		self.title = title
		self.window = 0
		self.count = 0
	
	def InitBoard(self):
		
		def keyPressed(*args):
			if args[0] == ESCAPE:
				glutDestroyWindow(self.window)
				sys.exit()
		
		def drawGLScene():
			self.count += 1
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
			w_center = WidgetCenter()
			l = w_center.getWidgetList()
			C = gluNewQuadric();
			w_center.displayOnGF()
			# for widget in l:
			# 	#glTranslatef(x, y, 0)
			# 	drawBox(widget.x, widget.y, widget.w, widget.h, widget.color, True)
			#drawCircle(C, 50, 50, 15, "bleu")
			#drawCircle(C, 150, 150, 15, "bleu")
			#drawBox(0, 0, 900, 550, "white", False)
			glLoadIdentity()
			glutSwapBuffers()
			gluDeleteQuadric(C)

		def drawCircle(C, x, y, r, color):
			#glPushMatrix()
			glTranslatef(x, y, 0)
			gluDisk(C, r - 3.0, r, 50, 1);
			#glPopMatrix()

		 
		def ReshapeGLScene(width, height):
			if height == 0:
				height = 1

			glViewport(0, 0, width, height)
			glMatrixMode(GL_PROJECTION)
			glLoadIdentity()
			glOrtho(0, 800, 600, 0, 0, 1)
			glDisable(GL_DEPTH_TEST)
			glMatrixMode(GL_MODELVIEW)
		 	glLoadIdentity()
			glTranslatef(0.375, 0.375, 0)
		
		def idleFun():
			self.count += 1
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
			w_center = WidgetCenter()
			l = w_center.getWidgetList()
			for widget in l:
				(x, y) = widget.getxy()
				(w, h) = widget.getwh()
				color = widget.getColor()
				#glTranslatef(x, y, 0)
				drawBox(x, y, w, h, color, True)
			glLoadIdentity()
			glutSwapBuffers()
			glFlush()
			glutPostRedisplay()
		
		glutInit(())
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH)
		glutInitWindowSize(self.height, self.width)
		glutInitWindowPosition(0, 0)
		self.window = glutCreateWindow(self.title)
		glutDisplayFunc(drawGLScene)
		glutIdleFunc(drawGLScene)
		glutReshapeFunc(ReshapeGLScene)
		glutKeyboardFunc(keyPressed)
		self.InitGL()
		glutMainLoop()
		
	def mainLoop(self):
		glutMainLoop()
	
	def InitGL(self):
		glClearColor(1.0, 1.0, 1.0, 1.0)
		glMatrixMode(GL_PROJECTION)
		glLoadIdentity()
		glOrtho(0, 800, 600, 0, 0, 1)
		glDisable(GL_DEPTH_TEST)
		glMatrixMode(GL_MODELVIEW)
	 	glLoadIdentity()
		glTranslatef(0.375, 0.375, 0)

