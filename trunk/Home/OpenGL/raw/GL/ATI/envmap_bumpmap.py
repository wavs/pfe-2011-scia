'''OpenGL extension ATI.envmap_bumpmap

Automatically generated by the get_gl_extensions script, do not edit!
'''
from OpenGL import platform, constants, constant, arrays
from OpenGL import extensions
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_ATI_envmap_bumpmap'
_DEPRECATED = False
GL_BUMP_ROT_MATRIX_ATI = constant.Constant( 'GL_BUMP_ROT_MATRIX_ATI', 0x8775 )
GL_BUMP_ROT_MATRIX_SIZE_ATI = constant.Constant( 'GL_BUMP_ROT_MATRIX_SIZE_ATI', 0x8776 )
GL_BUMP_NUM_TEX_UNITS_ATI = constant.Constant( 'GL_BUMP_NUM_TEX_UNITS_ATI', 0x8777 )
GL_BUMP_TEX_UNITS_ATI = constant.Constant( 'GL_BUMP_TEX_UNITS_ATI', 0x8778 )
GL_DUDV_ATI = constant.Constant( 'GL_DUDV_ATI', 0x8779 )
GL_DU8DV8_ATI = constant.Constant( 'GL_DU8DV8_ATI', 0x877A )
GL_BUMP_ENVMAP_ATI = constant.Constant( 'GL_BUMP_ENVMAP_ATI', 0x877B )
GL_BUMP_TARGET_ATI = constant.Constant( 'GL_BUMP_TARGET_ATI', 0x877C )
glTexBumpParameterivATI = platform.createExtensionFunction( 
'glTexBumpParameterivATI',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,arrays.GLintArray,),
doc='glTexBumpParameterivATI(GLenum(pname), GLintArray(param)) -> None',
argNames=('pname','param',),
deprecated=_DEPRECATED,
)

glTexBumpParameterfvATI = platform.createExtensionFunction( 
'glTexBumpParameterfvATI',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,arrays.GLfloatArray,),
doc='glTexBumpParameterfvATI(GLenum(pname), GLfloatArray(param)) -> None',
argNames=('pname','param',),
deprecated=_DEPRECATED,
)

glGetTexBumpParameterivATI = platform.createExtensionFunction( 
'glGetTexBumpParameterivATI',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,arrays.GLintArray,),
doc='glGetTexBumpParameterivATI(GLenum(pname), GLintArray(param)) -> None',
argNames=('pname','param',),
deprecated=_DEPRECATED,
)

glGetTexBumpParameterfvATI = platform.createExtensionFunction( 
'glGetTexBumpParameterfvATI',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,arrays.GLfloatArray,),
doc='glGetTexBumpParameterfvATI(GLenum(pname), GLfloatArray(param)) -> None',
argNames=('pname','param',),
deprecated=_DEPRECATED,
)


def glInitEnvmapBumpmapATI():
    '''Return boolean indicating whether this extension is available'''
    return extensions.hasGLExtension( EXTENSION_NAME )
