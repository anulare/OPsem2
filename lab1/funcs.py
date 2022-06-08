def writeInFile(fileName: str): 
    answer = int(input("What do you want?\n\t(1)create a new file or\n\t(2)add to an existing file\n"))
    b = True

    while(b):
        if answer==1:
            inFile = open(fileName, 'w')
            b = False
        elif answer==2:
            inFile = open(fileName, 'a')
            b = False
        else:
            answer = int(input("Invalid response, please try again: "))
            
    print(">>> " + fileName + " to WRITE was opened successfully\n")
    s=input("--Now enter your strings. Press Ctrl+Q+ENTER to stop writing text\n")

    while( s.find(chr(17)) == -1 ):
        inFile.write(s+'\n')
        s=input()
    else:
        inFile.write(s[0:s.find(chr(17))]+'\n')
    inFile.close()
    print("\n<<< " + fileName + " to WRITE was closed successfully\n")



def readOutFile(fileName: str): 
    outFile = open(fileName, 'r')
    
    print(">>> " + fileName + " to READ was opened successfully\n")

    text = outFile.read()
    print(text)

    outFile.close()
    print("\n<<< " + fileName + " to READ was closed successfully" + "\n\n")



def genFile(oldFileName: str, newFileName: str):
    outFile = open(oldFileName, 'r')
    inFile = open(newFileName, 'w')

    text = outFile.read().split("\n")

    i=0
    while(i<len(text)):
        text[i] = str(i) + ", " + text[i] + ", " + str( len(text[i]) ) + '\n'
        inFile.write(text[i])
        i+=1
    else:
        print("\n\n" + newFileName + " was generated successfully\n")