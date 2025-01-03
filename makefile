CC = g++
CCFLAGS = -g -w 
CCLIBS = -lncurses
mygame: main.o Gui.o Game.o Player.o Bullet.o Tank.o Bomb.o Medicalpack.o Mine.o Supertank.o Lasertank.o Obstacle.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Player.o Bullet.o Tank.o Bomb.o Medicalpack.o Mine.o Supertank.o Lasertank.o Obstacle.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C

Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C

Tank.o: Tank.h Tank.C
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.C

Bomb.o: Bomb.h Bomb.C
	$(CC) $(CCFLAGS) -c -o Bomb.o Bomb.C

Medicalpack.o: Medicalpack.h Medicalpack.C
	$(CC) $(CCFLAGS) -c -o Medicalpack.o Medicalpack.C

Mine.o: Mine.h Mine.C
	$(CC) $(CCFLAGS) -c -o Mine.o Mine.C

Supertank.o: Supertank.h Supertank.C
	$(CC) $(CCFLAGS) -c -o Supertank.o Supertank.C

Lasertank.o: Lasertank.h Lasertank.C
	$(CC) $(CCFLAGS) -c -o Lasertank.o Lasertank.C

Obstacle.o: Obstacle.h Obstacle.C
	$(CC) $(CCFLAGS) -c -o Obstacle.o Obstacle.C

clean:
	rm -rf mygame *.o
