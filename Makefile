#
# Makefile.c++
#
# Instructions:
#
# 1. Edit Makefile using vi or emacs:
#    a. rename target, if desired
#    b. add list of source files at SRCS = ...
# 2. % touch Makefile.dep
# 3. % make depend
# 4. % make
#

TARGET = borne
CC = gcc
CFLAGS = -Wall -O -g 

#Version materielle
INCLDIRS =
LIBDIRS = 

#dependance librairie libsmartcard_borne (voir git)
LIBS64 = -lsmartcard_borne_x64 -lpcsclite

#ajouter vos fichier source ici
SRCS = BaseClients.c borne.c Boutons.c GenerateurSave.c LecteurCarte.c Prise.c Timer.c Voyants.c

#Version prototype
#INCLDIRS = 
#SRCS = console_pompiste.c service.c distributeur.c lecteur_carte.c pompes.c stdafx.c imprimante.c liste_client.c pupitre.c mem_sh.c lcarte.c


OBJS = ${SRCS:.c=.o} 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLDIRS) -o $@ $(OBJS) $(LIBS64)

$(OBJS):
	$(CC) $(CFLAGS) $(INCLDIRS) -c $*.c

depend:
	$(CC) -MM $(SRCS) $(INCLDIRS) > Makefile.dep

clean:
	rm -f $(OBJS) core

veryclean: clean
	rm -f $(TARGET) a.out *.*~

include Makefile.dep

