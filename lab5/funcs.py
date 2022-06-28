from class1 import*

def genListBin(m: int):
	number_list=input("Input binary numbers: ").split(' ')

	M = []
	for i in range(m):
		a = TIntNumber2(2, number_list[i])

		M.append(a) 
	return M

def genListHex(m: int):
	number_list=input("Input hex numbers: ").split(' ')

	M = []
	for i in range(m):
		a = TIntNumber16(16, number_list[i])

		M.append(a) 
	return M




def findSumBin(M, m):
	sum = TIntNumber2(2, "0")

	print("\nYour row: ")
	for i in range(m):
		print(M[i].number, end=" ")
		sum.add(M[i])

	print("\nYour decimal row: ")
	for i in range(m):
		M[i].changeSystem(10)
		print(M[i].dec, end = " ")

	sum.changeSystem(10)
	print("\nDecimal sum: " + sum.number)
	sum.changeSystem(2)
	print("Binary sum: " + sum.number)
	print("\n\n")

	return sum



def findSumHex(M, m):
	sum = TIntNumber16(16, "0")

	print("\nYour row: ")
	for i in range(m):
		print(M[i].number, end=" ")
		sum.add(M[i])

	print("\nYour decimal row: ")
	for i in range(m):
		M[i].changeSystem(10)
		print(M[i].dec, end = " ")

	sum.changeSystem(10)
	print("\nDecimal sum: " + sum.number)
	sum.changeSystem(16)
	print("Hex sum: " + sum.number)
	
	return sum