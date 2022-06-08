from funcs import *

fileName1 = 'drugs.bin' 
fileName2 = 'drugsEdit.bin'

writeInFile(fileName1)
readOutFile(fileName1)

delMoreThan1Year(fileName1, fileName2)
readOutFile(fileName2)

warning(fileName2)