# https://makefiletutorial.com/#the-all-target
# https://github.com/Gilad-Gur/c-lab-20465/blob/master/MAMAN22/makefile
# https://github.com/AvivNaaman/OpenU-C-Project/blob/d2b20532fdec80aa59a8080845b9f584c4ff3594/Makefile
# https://www.youtube.com/watch?v=DtGrdB8wQ_8
## https://github.com/gwu-cs-os/evening_os_hour/blob/master/f19/10.2-makefiles/02_simple_makefile/Makefile
## https://github.com/gwu-cs-os/evening_os_hour/blob/master/f19/10.2-makefiles/03_featureful_makefile/Makefile

CC=gcc#			# GCC Compiler
#						# Flags:
INCDIR=./#		# The path to the directory which includes the source files
OPT=-O0#			# Optimize mode
CFLAGS=-ansi -Wall -pedantic -g -I$(INCDIR) $(OPT)

# Binary output: the prog folder name
BNRY= permut
#${PWD##*/}

# The sub-path to the folder for the refresh script.  
RFESHDIR=../

# -----------

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# SRCS=assembler.c pre_assembler.c
# OBJS=assembler.o pre_assembler.o

all: $(BNRY)

$(BNRY): $(OBJS)
	$(CC) $^ -o $@

# regular expression where % is a wildcard
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

# -----------

run:
	make
	$(INCDIR)$(BNRY)
	make refresh
refresh:
	mv $(RFESHDIR)refresh.log $(RFESHDIR)refresh.archive.log
	$(RFESHDIR)refresh.sh $(INCDIR) $(BNRY) > $(RFESHDIR)refresh.log 2>&1
	sed -i '1d' $(RFESHDIR)refresh.log
	cat $(RFESHDIR)refresh.archive.log >> $(RFESHDIR)refresh.log
	rm $(RFESHDIR)refresh.archive.log

clean:
	rm -rf $(OBJS)
delete:
	rm -rf $(BNRY)
	make clean