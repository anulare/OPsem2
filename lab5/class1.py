from abc import abstractmethod


class TIntNumber:
	def __init__(self, system, number):
		self.system = system
		self.number = number
		self.dec = 0

	@abstractmethod
	def changeSystem(self, sys):
		pass

	def compare(self, c):
		

		if (self.dec == c.dec):
			print(self.number + " == " + c.number)

		elif (self.dec > c.dec):
			print(self.number + " > " + c.number)

		elif (self.dec < c.dec):
			print(self.number + " < " + c.number)



class TIntNumber2(TIntNumber):
	def changeSystem(self, sys):
		if (self.system == 2 and sys == 10):
			self.dec = 0

			for i in range(len(self.number)):
				if (self.number[len(self.number) - i - 1] == '1'):
					self.dec += 2**i

			self.number = str(self.dec)
			self.system = 10

		elif (self.system == 10 and sys == 2):
			self.number = ''

			whole = self.dec
			rest = 0

			while(whole):
				rest = whole % 2
				whole //= 2

				self.number = str(rest) + self.number

			self.system = 2

	def add(self, addition):
		self.changeSystem(10)
		addition.changeSystem(10)

		self.dec = self.dec + addition.dec

		self.changeSystem(2)


class TIntNumber16(TIntNumber):
	def changeSystem(self, sys):
		HEX = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']

		if (self.system == 16 and sys == 10):
			self.dec = 0

			for i in range(len(self.number)):
				for j in range(16):
					if (self.number[len(self.number) - i - 1] == HEX[j]):
						self.dec += j * (16**i)
						break

			self.number = str(self.dec)
			self.system = 10

		elif (self.system == 10 and sys == 16):
			self.number = ''

			whole = self.dec
			rest = 0

			while(whole):
				rest = whole % 16
				whole //= 16

				self.number = HEX[rest] + self.number

			self.system = 16

		elif (self.system == 16 and sys == 2):
			BIN = ["0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"]

			self.dec = 0
			binary = ''

			for i in range(len(self.number)):
				for j in range(16):
					if (self.number[len(self.number) - i - 1] == HEX[j]):
						binary = BIN[j] + binary
						self.dec += j * (16**i)
						break

			while (binary[0] == '0' and len(binary) > 1):
				binary = binary[1:]

			self.number = binary
			self.system = 2
	
	def add(self, addition):
		self.changeSystem(10)
		addition.changeSystem(10)

		self.dec = self.dec + addition.dec

		self.changeSystem(16)