from funcs import*

m = int(input("Input m: "))
M = genListBin(m)

n = int(input("\nInput n: "))
N = genListHex(n)


binSum = findSumBin(M,m)
hexSum = findSumHex(N,n)

hexSum.changeSystem(2)

print("Hex sum in binary form: " + hexSum.number)
print("\n\n")

binSum.compare(hexSum)