import sys
sys.path[:0] = ['../']
import Board as b
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import pygame

class GfCenter (object):

	instance = None
	widgetList = []
	
	def __new__(self):
		if self.instance is None:
			self.instance = object.__new__(self)
		return self.instance

	def drawMeSquare(self, x, y, w, h, color):
		b.drawBox(x, y, w, h, color, False)

	def drawMeTexturedSquare(self, x, y, w, h, color, texture):
		b.drawTexturedBox(x, y, w, h, color, texture)

	def registerToLoadTexture(self, widget):
		self.widgetList.append(widget)

	def loadTextureForWidgetRegistered(self):
		for w in self.widgetList:
			w.idImage = self.getTextureFromImage(w.link)

	def getTextureFromImage(self, link):
		print link
		textureSurface = pygame.image.load(link)
		textureData = pygame.image.tostring(textureSurface, "RGBA", 1)
		width = 256
		height = 256
		#  
		texture = glGenTextures(1)
		glBindTexture(GL_TEXTURE_2D, texture)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData)
		return texture
		