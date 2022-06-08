from funcs import *

fileName1 = 'originalFile.txt' 
fileName2 = 'newFile.txt'

writeInFile(fileName1)
readOutFile(fileName1)

genFile(fileName1, fileName2)
readOutFile(fileName2)