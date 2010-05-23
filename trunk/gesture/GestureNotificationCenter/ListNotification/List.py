class List:
	def __init__(self):
		self.fifo = []

	def addElt(self, elt):
		self.fifo.append(elt)

	def popElt(self):
		if (len(self.fifo) > 0):
			return self.fifo.pop(0)

	def isEmpty(self):
		return len(self.fifo) == 0

	def getElt(self):
		if (len(self.fifo) > 0):
			return self.fifo[0]
		