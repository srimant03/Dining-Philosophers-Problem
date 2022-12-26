run: f b p pb

f:	fork.c
	gcc fork.c -o f -lpthread

b:	bowl.c
	gcc bowl.c -o b -lpthread

p: 	phil.c
	gcc phil.c -o p -lpthread

pb: 	philBowl.c
	gcc philBowl.c -o pb -lpthread

clean:
	rm -f f b p pb