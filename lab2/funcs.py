import pickle
from datetime import datetime

def writeInFile(fileName: str): 
    answer = int(input("What do you want?\n\t(1)create a new file or\n\t(2)add to an existing file\n"))
    b = True

    while(b):
        if answer==1:
            inFile = open(fileName, 'wb')
            ampulList=[]
            b = False
        elif answer==2:
            with open(fileName, 'rb') as outFile:
                ampulList = pickle.load(outFile)
            outFile.close()

            inFile = open(fileName, 'wb')
            b = False
        else:
            answer = int(input("Invalid response, please try again: "))
            
    print(">>> " + fileName + " to WRITE was opened successfully\n\n")
    print("--Input ampuls parameters:")

    res = ""
    while( res.lower()!="no" ):
        if res == "yes" or res == "":
            name = input("Name: ")

            date = input("Date of production: ")
            day = int(date[0:2])
            month = int(date[3:5])
            year = int(date[6:10])

            time = input("How long can be used after opening(HH:MM): ")
            
            shelfTime = float(input("ShelfTime: "))

            
            ampula = {  'name'   : name,

                'date' : date,
                'day'     : day,
                'month' : month,
                'year'   : year,

                'time' : time,

                'shelfTime' : shelfTime}
            
            ampulList.append(ampula)

            
            res = input("\nDo you want to add another ampula(yes or no)? -")
            print("")
        else:
            res = input("\nInvalid response, try again please -")
            print("")


    pickle.dump(ampulList, inFile)

    inFile.close()
    print("<<< " + fileName + " to WRITE was closed successfully\n\n\n")


################################

def readOutFile(fileName: str): 
    with open(fileName, 'rb') as outFile:
        ampulList = pickle.load(outFile)

    print(">>> " + fileName + " to READ was opened successfully\n")
      
    i=0
    while(i<len(ampulList)):
        print("Name: " + ampulList[i]['name'])
        print("Date of production(DD.MM.YYYY): " + ampulList[i]['date'])
        print("How long can be used after opening(HH:MM): " + ampulList[i]['time'])
        print("ShelfTime: " + str(ampulList[i]['shelfTime']))
        print('')
        i+=1

    outFile.close()
    print("<<< " + fileName + " to READ was closed successfully\n\n")


#####

def delMoreThan1Year(fileName1: str, fileName2: str):
    with open(fileName1, 'rb') as outFile:
        ampulList = pickle.load(outFile)

    inFile = open(fileName2, 'wb')
    ampulList2=[]

    i=0
    while(i<len(ampulList)):
        if(ampulList[i]['shelfTime']<=1):
            ampulList2.append(ampulList[i])
            i+=1
        else:
            i+=1
    
    pickle.dump(ampulList2, inFile)

    outFile.close()
    inFile.close()

    print("----------------------------------------------")
    print("--ALL AMPULS WITH SHELFTIME > 1 WERE DELETED--")
    print("----------------------------------------------\n")   

#############

def warning(fileName: str):
    months = [31,28,31,30,31,30,31,31,30,31,30,31]

    with open(fileName, 'rb') as outFile:
        ampulList = pickle.load(outFile)

    i=0
    while(i<len(ampulList)):

        prodDay = ampulList[i]['day']
        prodMonth = ampulList[i]['month']
        prodYear = ampulList[i]['year']

        k=0
        while(k<prodMonth - 1):
            prodDay+=months[k]
            k+=1

        TIME0 = datetime.now()

        thisDay=TIME0.day
        thisMonth=TIME0.month
        thisYear=TIME0.year

        l=0
        while(l<thisMonth - 1):
            thisDay+=months[l]
            l+=1

        shelfDays = round(ampulList[i]['shelfTime'] * 365)
        daysPassed = -prodDay + (thisYear - prodYear) * 365 + thisDay + 1

        timeLeft = shelfDays - daysPassed

        if(timeLeft<=0):
            print("!!!" + ampulList[i]['name'] + " is expired!!!")
        elif(timeLeft<=10):
            print("!!!" + ampulList[i]['name'] + " is expiring in " + str(timeLeft + 1) + " days !!!")

        i+=1