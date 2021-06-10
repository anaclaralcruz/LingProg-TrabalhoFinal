CPP = g++
CPPFLAGS = -Wall

OBJS = main.o banco.o receita.o  


trabalho: $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS) -lsqlite3