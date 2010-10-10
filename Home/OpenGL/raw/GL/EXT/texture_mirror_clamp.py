'''OpenGL extension EXT.texture_mirror_clamp

Automatically generated by the get_gl_extensions script, do not edit!
'''
from OpenGL import platform, constants, constant, arrays
from OpenGL import extensions
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_EXT_texture_mirror_clamp'
_DEPRECATED = False
GL_MIRROR_CLAMP_EXT = constant.Constant( 'GL_MIRROR_CLAMP_EXT', 0x8742 )
GL_MIRROR_CLAMP_TO_EDGE_EXT = constant.Constant( 'GL_MIRROR_CLAMP_TO_EDGE_EXT', 0x8743 )
GL_MIRROR_CLAMP_TO_BORDER_EXT = constant.Constant( 'GL_MIRROR_CLAMP_TO_BORDER_EXT', 0x8912 )


def glInitTextureMirrorClampEXT():
    '''Return boolean indicating whether this extension is available'''
    return extensions.hasGLExtension( EXTENSION_NAME )
