objet=objet
bin=bin

$(bin)/main: $(objet)/main.o $(objet)/swap.o
	mkdir -p $(bin)
	gcc -o $(bin)/main $(objet)/main.o $(objet)/swap.o
$(objet)/%.o: %.c
	mkdir -p $(objet)
	gcc -c $< -o $@