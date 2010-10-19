## Class : CoordTransformer<br/>
## This object transform coordonate from opencv to coordonnate widgets can utilized
##
class CoordTransformer:
	
	
	## Funtion init<br/>
	## Arguments :<br/>
	##			  - ex1 : x value of test point 1
	##		      - ey1 : y value of test point 1
	##			  - ex2 : x value of test point 2
	##		      - ey2 : y value of test point 2<br/>
	## Return : the object itself
	##
	def __init__(self, ex1 = 0, ey1 = 0, ex2 = 100, ey2 = 100):
		self.refx1 = 50
		self.refy1 = 50
		self.refx2 = 150
		self.refx2 = 150
		self.ex1 = ex1
		self.ey1 = ex2
		self.ex2 = ex2
		self.ey2 = ey2
	
	## Funtion setExy1<br/>
	## Arguments :<br/>
	##			  - ex1 : x value of test point 1
	##		      - ey1 : y value of test point 1
	##			  
	## Return : no
	##
	def setExy1(self, ex1, ey1):
		self.ex1 = ex1
		self.ey1 = ey1

	## Funtion setExy2<br/>
	## Arguments :<br/>
	##			  - ex2 : x value of test point 2
	##		      - ey2 : y value of test point 2
	##			  
	## Return : no
	##
	def setExy1(self, ex2, ey2):
		self.ex2 = ex2
		self.ey2 = ey2