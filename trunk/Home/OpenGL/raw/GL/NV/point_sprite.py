'''OpenGL extension NV.point_sprite

Automatically generated by the get_gl_extensions script, do not edit!
'''
from OpenGL import platform, constants, constant, arrays
from OpenGL import extensions
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_NV_point_sprite'
_DEPRECATED = False
GL_POINT_SPRITE_NV = constant.Constant( 'GL_POINT_SPRITE_NV', 0x8861 )
glget.addGLGetConstant( GL_POINT_SPRITE_NV, (1,) )
GL_COORD_REPLACE_NV = constant.Constant( 'GL_COORD_REPLACE_NV', 0x8862 )
GL_POINT_SPRITE_R_MODE_NV = constant.Constant( 'GL_POINT_SPRITE_R_MODE_NV', 0x8863 )
glget.addGLGetConstant( GL_POINT_SPRITE_R_MODE_NV, (1,) )
glPointParameteriNV = platform.createExtensionFunction( 
'glPointParameteriNV',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,constants.GLint,),
doc='glPointParameteriNV(GLenum(pname), GLint(param)) -> None',
argNames=('pname','param',),
deprecated=_DEPRECATED,
)

glPointParameterivNV = platform.createExtensionFunction( 
'glPointParameterivNV',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,arrays.GLintArray,),
doc='glPointParameterivNV(GLenum(pname), GLintArray(params)) -> None',
argNames=('pname','params',),
deprecated=_DEPRECATED,
)


def glInitPointSpriteNV():
    '''Return boolean indicating whether this extension is available'''
    return extensions.hasGLExtension( EXTENSION_NAME )
