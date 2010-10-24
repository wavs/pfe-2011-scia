'''OpenGL extension EXT.color_subtable

Automatically generated by the get_gl_extensions script, do not edit!
'''
from OpenGL import platform, constants, constant, arrays
from OpenGL import extensions
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_EXT_color_subtable'
_DEPRECATED = False

glColorSubTableEXT = platform.createExtensionFunction( 
'glColorSubTableEXT',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,constants.GLsizei,constants.GLsizei,constants.GLenum,constants.GLenum,ctypes.c_void_p,),
doc='glColorSubTableEXT(GLenum(target), GLsizei(start), GLsizei(count), GLenum(format), GLenum(type), c_void_p(data)) -> None',
argNames=('target','start','count','format','type','data',),
deprecated=_DEPRECATED,
)

glCopyColorSubTableEXT = platform.createExtensionFunction( 
'glCopyColorSubTableEXT',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,constants.GLsizei,constants.GLint,constants.GLint,constants.GLsizei,),
doc='glCopyColorSubTableEXT(GLenum(target), GLsizei(start), GLint(x), GLint(y), GLsizei(width)) -> None',
argNames=('target','start','x','y','width',),
deprecated=_DEPRECATED,
)


def glInitColorSubtableEXT():
    '''Return boolean indicating whether this extension is available'''
    return extensions.hasGLExtension( EXTENSION_NAME )