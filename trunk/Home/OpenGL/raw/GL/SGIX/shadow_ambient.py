'''OpenGL extension SGIX.shadow_ambient

Automatically generated by the get_gl_extensions script, do not edit!
'''
from OpenGL import platform, constants, constant, arrays
from OpenGL import extensions
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_SGIX_shadow_ambient'
_DEPRECATED = False
GL_SHADOW_AMBIENT_SGIX = constant.Constant( 'GL_SHADOW_AMBIENT_SGIX', 0x80BF )


def glInitShadowAmbientSGIX():
    '''Return boolean indicating whether this extension is available'''
    return extensions.hasGLExtension( EXTENSION_NAME )