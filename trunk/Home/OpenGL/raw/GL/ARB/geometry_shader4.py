'''OpenGL extension ARB.geometry_shader4

Automatically generated by the get_gl_extensions script, do not edit!
'''
from OpenGL import platform, constants, constant, arrays
from OpenGL import extensions
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_ARB_geometry_shader4'
_DEPRECATED = False
GL_LINES_ADJACENCY_ARB = constant.Constant( 'GL_LINES_ADJACENCY_ARB', 0xA )
GL_LINE_STRIP_ADJACENCY_ARB = constant.Constant( 'GL_LINE_STRIP_ADJACENCY_ARB', 0xB )
GL_TRIANGLES_ADJACENCY_ARB = constant.Constant( 'GL_TRIANGLES_ADJACENCY_ARB', 0xC )
GL_TRIANGLE_STRIP_ADJACENCY_ARB = constant.Constant( 'GL_TRIANGLE_STRIP_ADJACENCY_ARB', 0xD )
GL_PROGRAM_POINT_SIZE_ARB = constant.Constant( 'GL_PROGRAM_POINT_SIZE_ARB', 0x8642 )
glget.addGLGetConstant( GL_PROGRAM_POINT_SIZE_ARB, (1,) )
GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB = constant.Constant( 'GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB', 0x8C29 )
glget.addGLGetConstant( GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB, (1,) )
GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB = constant.Constant( 'GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB', 0x8DA7 )
GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB = constant.Constant( 'GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB', 0x8DA8 )
GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB = constant.Constant( 'GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB', 0x8DA9 )
GL_GEOMETRY_SHADER_ARB = constant.Constant( 'GL_GEOMETRY_SHADER_ARB', 0x8DD9 )
GL_GEOMETRY_VERTICES_OUT_ARB = constant.Constant( 'GL_GEOMETRY_VERTICES_OUT_ARB', 0x8DDA )
GL_GEOMETRY_INPUT_TYPE_ARB = constant.Constant( 'GL_GEOMETRY_INPUT_TYPE_ARB', 0x8DDB )
GL_GEOMETRY_OUTPUT_TYPE_ARB = constant.Constant( 'GL_GEOMETRY_OUTPUT_TYPE_ARB', 0x8DDC )
GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB = constant.Constant( 'GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB', 0x8DDD )
glget.addGLGetConstant( GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB, (1,) )
GL_MAX_VERTEX_VARYING_COMPONENTS_ARB = constant.Constant( 'GL_MAX_VERTEX_VARYING_COMPONENTS_ARB', 0x8DDE )
glget.addGLGetConstant( GL_MAX_VERTEX_VARYING_COMPONENTS_ARB, (1,) )
GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB = constant.Constant( 'GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB', 0x8DDF )
glget.addGLGetConstant( GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB, (1,) )
GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB = constant.Constant( 'GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB', 0x8DE0 )
glget.addGLGetConstant( GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB, (1,) )
GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB = constant.Constant( 'GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB', 0x8DE1 )
glget.addGLGetConstant( GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB, (1,) )
glProgramParameteriARB = platform.createExtensionFunction( 
'glProgramParameteriARB',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLuint,constants.GLenum,constants.GLint,),
doc='glProgramParameteriARB(GLuint(program), GLenum(pname), GLint(value)) -> None',
argNames=('program','pname','value',),
deprecated=_DEPRECATED,
)

glFramebufferTextureARB = platform.createExtensionFunction( 
'glFramebufferTextureARB',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,constants.GLenum,constants.GLuint,constants.GLint,),
doc='glFramebufferTextureARB(GLenum(target), GLenum(attachment), GLuint(texture), GLint(level)) -> None',
argNames=('target','attachment','texture','level',),
deprecated=_DEPRECATED,
)

glFramebufferTextureLayerARB = platform.createExtensionFunction( 
'glFramebufferTextureLayerARB',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,constants.GLenum,constants.GLuint,constants.GLint,constants.GLint,),
doc='glFramebufferTextureLayerARB(GLenum(target), GLenum(attachment), GLuint(texture), GLint(level), GLint(layer)) -> None',
argNames=('target','attachment','texture','level','layer',),
deprecated=_DEPRECATED,
)

glFramebufferTextureFaceARB = platform.createExtensionFunction( 
'glFramebufferTextureFaceARB',dll=platform.GL,
extension=EXTENSION_NAME,
resultType=None, 
argTypes=(constants.GLenum,constants.GLenum,constants.GLuint,constants.GLint,constants.GLenum,),
doc='glFramebufferTextureFaceARB(GLenum(target), GLenum(attachment), GLuint(texture), GLint(level), GLenum(face)) -> None',
argNames=('target','attachment','texture','level','face',),
deprecated=_DEPRECATED,
)


def glInitGeometryShader4ARB():
    '''Return boolean indicating whether this extension is available'''
    return extensions.hasGLExtension( EXTENSION_NAME )