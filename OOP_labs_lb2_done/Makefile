all: maze

maze: MyCell.o CellStack.o MyMaze.o MyInterface.o PlayerControl.o main.o MyHuman.o MyPlayer.o MyObject.o MyDynamite.o MyBonus.o MyAim.o MyExit.o FileLog.o MyLog.o ConsolLog.o LogInterface.o GameInit.o GameFacade.o GameExecutor.o BAttack.o BDamage.o BLevel.o SuperEnemy.o Save.o Load.o SaveLoad.o
	g++ MyCell.o CellStack.o MyMaze.o MyInterface.o PlayerControl.o main.o MyHuman.o MyPlayer.o MyObject.o MyDynamite.o MyBonus.o MyAim.o MyExit.o FileLog.o MyLog.o ConsolLog.o LogInterface.o GameInit.o GameFacade.o GameExecutor.o BAttack.o BDamage.o BLevel.o SuperEnemy.o Save.o Load.o SaveLoad.o -o maze
	
main.o: main.cpp
	g++ -c main.cpp

MyCell.o: ./Maze/MyCell.cpp
	g++ -c ./Maze/MyCell.cpp
	
CellStack.o: ./Maze/CellStack.cpp
	g++ -c ./Maze/CellStack.cpp
	
MyMaze.o: ./Maze/MyMaze.cpp
	g++ -c ./Maze/MyMaze.cpp

MyInterface.o: ./Interface/MyInterface.cpp
	g++ -c ./Interface/MyInterface.cpp

PlayerControl.o: ./Humans/PlayerControl.cpp
	g++ -c ./Humans/PlayerControl.cpp

MyHuman.o:	./Humans/MyHuman.cpp
	g++ -c ./Humans/MyHuman.cpp
	
MyPlayer.o: ./Humans/MyPlayer.cpp
	g++ -c ./Humans/MyPlayer.cpp
	
SuperEnemy.o: ./Humans/SuperEnemy.cpp
	g++ -c ./Humans/SuperEnemy.cpp
	
MyObject.o: ./ActiveObjects/MyObject.cpp
	g++ -c ./ActiveObjects/MyObject.cpp
	
MyDynamite.o: ./ActiveObjects/MyDynamite.cpp
	g++ -c ./ActiveObjects/MyDynamite.cpp
	
MyBonus.o: ./ActiveObjects/MyBonus.cpp
	g++ -c ./ActiveObjects/MyBonus.cpp
	
MyAim.o: ./ActiveObjects/MyAim.cpp
	g++ -c ./ActiveObjects/MyAim.cpp	

MyExit.o: ./ActiveObjects/MyExit.cpp
	g++ -c ./ActiveObjects/MyExit.cpp
	
GameInit.o: ./GameControl/GameInit.cpp
	g++ -c ./GameControl/GameInit.cpp
	
GameFacade.o: ./GameControl/GameFacade.cpp
	g++ -c ./GameControl/GameFacade.cpp

GameExecutor.o: ./GameControl/GameExecutor.cpp
	g++ -c ./GameControl/GameExecutor.cpp

Save.o: ./SaveLoad/Save.cpp
	g++ -c ./SaveLoad/Save.cpp

Load.o: ./SaveLoad/Load.cpp
	g++ -c ./SaveLoad/Load.cpp

MyLog.o: ./Logs/MyLog.cpp
	g++ -c ./Logs/MyLog.cpp

FileLog.o: ./Logs/FileLog.cpp
	g++ -c ./Logs/FileLog.cpp

ConsolLog.o: ./Logs/ConsolLog.cpp
	g++ -c ./Logs/ConsolLog.cpp	

LogInterface.o: ./Logs/LogInterface.cpp
	g++ -c ./Logs/LogInterface.cpp	

BAttack.o: ./Humans/Behaviors/BAttack.cpp
	g++ -c ./Humans/Behaviors/BAttack.cpp

BDamage.o: ./Humans/Behaviors/BDamage.cpp
	g++ -c ./Humans/Behaviors/BDamage.cpp
	
BLevel.o: ./Humans/Behaviors/BLevel.cpp
	g++ -c ./Humans/Behaviors/BLevel.cpp

SaveLoad.o: ./SaveLoad/SaveLoad.cpp
	g++ -c ./SaveLoad/SaveLoad.cpp
		
clean:
	rm -rf *.o maze
