SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)  
LDFLAGS=-L$(LIBDIR)
EXEC=asispell
DOCDIR=doc


all : clean dossier $(BINDIR)/$(EXEC) tests

tests : $(TESTDIR)/testsCorrecteurOrthographique $(TESTDIR)/testsDictionnaire $(TESTDIR)/testsMot

doc :
	doxygen

dossier :
	mkdir  $(BINDIR) $(LIBDIR) $(TESTDIR)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libmot.a $(LIBDIR)/libdictionnaire.a $(LIBDIR)/libcorrecteurOrthographique.a
	$(CC)  -o $@ $^ -lmot -ldictionnaire -lcorrecteurOrthographique $(LDFLAGS)

$(LIBDIR)/libmot.a : $(SRCDIR)/mot.o
	$(AR) -r $@ $^
	
$(LIBDIR)/libdictionnaire.a : $(SRCDIR)/dictionnaire.o
	$(AR) -r $@ $^
	
$(LIBDIR)/libcorrecteurOrthographique.a : $(SRCDIR)/correcteurOrthographique.o
	$(AR) -r $@ $^
	
$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS)
	
	
$(TESTDIR)/testsCorrecteurOrthographique : $(SRCDIR)/testsCorrecteurOrthographique.o $(LIBDIR)/libmot.a $(LIBDIR)/libdictionnaire.a $(LIBDIR)/libcorrecteurOrthographique.a
	$(CC) -o $@ $^ -lmot -ldictionnaire -lcorrecteurOrthographique $(LDFLAGS) -lcunit -L${HOME}/local/lib
	
$(TESTDIR)/testsDictionnaire : $(SRCDIR)/testsDictionnaire.o $(LIBDIR)/libmot.a $(LIBDIR)/libdictionnaire.a $(LIBDIR)/libcorrecteurOrthographique.a
	$(CC) -o $@ $^ -lcorrecteurOrthographique -ldictionnaire -lmot $(LDFLAGS) -lcunit -L${HOME}/local/lib
	
$(TESTDIR)/testsMot : $(SRCDIR)/testsMot.o $(LIBDIR)/libmot.a $(LIBDIR)/libdictionnaire.a $(LIBDIR)/libcorrecteurOrthographique.a
	$(CC) -o $@ $^ -lcorrecteurOrthographique -ldictionnaire -lmot $(LDFLAGS) -lcunit -L${HOME}/local/lib
	

clean :
	rm -rf $(BINDIR)
	rm -rf $(LIBDIR)
	rm -f $(SRCDIR)/*.o
	rm -rf $(TESTDIR)
	rm -rf $(DOCDIR)
