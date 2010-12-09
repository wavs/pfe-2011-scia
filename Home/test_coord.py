from CoordTransformer.CoordTransformer import *

t = CoordTransformer()
t.setInfo(640, 43, 900, 550)
x = 0
y = 43

(x, y) = t.newCoord(x, y)
print x, y