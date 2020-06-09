# Macros ========================================
#OS=MAC
OS=LINUX
#=========================
# compiler info
CC=g++
CFLAGS= -g -O2 -Wconversion -Wall -Wextra -Werror -ansi -pedantic -std=c++17
# 
LFLAGS=
VALGRIND=-q --leak-check=full --show-reachable=yes --tool=memcheck --trace-children=yes
#=========================
# files
CODE_IN=DeSerializable
EXTENSION=.cpp
#DRIVER=driver-int
DRIVER=ObjectSerilazation
# extra files
EXTRA1=DSObject
# in macro
# < $(IN)in-$*.txt
# $*
TO_CODE=
#TO_CODE= $*
#=========================
# exe name
EXE=gnu
#=========================
# directories
OUTDIR=gnu/
MASTER=_mOut/
TEST=_tOut/
IN=_in/
#=========================
# object to deal with

#NUM_OFF=1
#NUM_TESTS=10

#OBJS=$(OUTDIR)$(CODE_IN).o
OBJS=$(OUTDIR)$(DRIVER).o $(OUTDIR)$(CODE_IN).o $(OUTDIR)$(EXTRA1).o
# 

DUMP1=
DUMP2=
DUMP3=
DUMP4=
DUMP5=
DUMP6=
DUMP7=
DUMP8=
DUMP9=
DUMP10=
DUMP11=
DUMP12=
DUMP13=
DUMP14=
DUMP15=
DUMP16=
DUMP17=
DUMP20=

#DUMP=dump$(NUM_OFF).txt 
DUMP1=dump1.txt 
#DUMP2=dump2.txt 
#DUMP3=dump3.txt
#DUMP4=dump4.txt 
#DUMP5=dump5.txt 
#DUMP6=dump6.txt 
#DUMP7=dump7.txt 
#DUMP8=dump8.txt 
#DUMP9=dump9.txt 
#DUMP10=dump0.txt 
#DUMP11=dump11.txt 
#DUMP12=dump12.txt 
#DUMP13=dump13.txt 
#DUMP14=dump14.txt 
#DUMP15=dump15.txt 
#DUMP16=dump16.txt 
#DUMP17=dump17.txt 
#DUMP20=dump20.txt 

DUMP = $(DUMP1) $(DUMP2) $(DUMP3) $(DUMP4) $(DUMP5) $(DUMP6) $(DUMP7) $(DUMP8) $(DUMP9) $(DUMP10) $(DUMP11) $(DUMP12) $(DUMP13) $(DUMP14) $(DUMP15) $(DUMP16) $(DUMP17) $(DUMP20)

DIFF1=
DIFF2=
DIFF3=
DIFF4=
DIFF5=
DIFF6=
DIFF7=
DIFF8=
DIFF9=
DIFF10=
DIFF11=
DIFF12=
DIFF13=
DIFF14=
DIFF15=
DIFF16=
DIFF17=
DIFF20=

#DIFF=$(TEST)out-$(NUM_OFF).diff
DIFF1=$(TEST)out-1.diff
#DIFF2=$(TEST)out-2.diff
#DIFF3=$(TEST)out-3.diff 
#DIFF4=$(TEST)out-4.diff
#DIFF5=$(TEST)out-5.diff
#DIFF6=$(TEST)out-6.diff
#DIFF7=$(TEST)out-7.diff
#DIFF8=$(TEST)out-8.diff
#DIFF9=$(TEST)out-9.diff
#DIFF10=$(TEST)out-10.diff
#DIFF11=$(TEST)out-11.diff
#DIFF12=$(TEST)out-12.diff
#DIFF13=$(TEST)out-13.diff
#DIFF14=$(TEST)out-14.diff
#DIFF15=$(TEST)out-15.diff
#DIFF16=$(TEST)out-16.diff
#DIFF17=$(TEST)out-17.diff
#DIFF20=$(TEST)out-20.diff 

DIFF = $(DIFF1) $(DIFF2) $(DIFF3) $(DIFF4) $(DIFF5) $(DIFF6) $(DIFF7) $(DIFF8) $(DIFF9) $(DIFF10) $(DIFF11) $(DIFF12) $(DIFF13) $(DIFF14) $(DIFF15) $(DIFF16) $(DIFF17) $(DIFF20)

MEM1=
MEM2=
MEM3= 
MEM4=
MEM5=
MEM6=
MEM7=
MEM8=
MEM9=
MEM10=
MEM11=
MEM12=
MEM13=
MEM14=
MEM15=
MEM16=
MEM17=
MEM20=

#MEMORY=$(TEST)memory-$(NUM_OFF).txt
MEM1=$(TEST)memory-1.txt
#MEM2=$(TEST)memory-2.txt
#MEM3=$(TEST)memory-3.txt 
#MEM4=$(TEST)memory-4.txt
#MEM5=$(TEST)memory-5.txt
#MEM6=$(TEST)memory-6.txt
#MEM7=$(TEST)memory-7.txt
#MEM8=$(TEST)memory-8.txt
#MEM9=$(TEST)memory-9.txt
#MEM10=$(TEST)memory-10.txt
#MEM11=$(TEST)memory-11.txt
#MEM12=$(TEST)memory-12.txt
#MEM13=$(TEST)memory-13.txt
#MEM14=$(TEST)memory-14.txt
#MEM15=$(TEST)memory-15.txt
#MEM16=$(TEST)memory-16.txt
#MEM17=$(TEST)memory-17.txt
#MEM20=$(TEST)memory-20.txt 

MEMORY = $(MEM1) $(MEM2) $(MEM3) $(MEM4) $(MEM5) $(MEM6) $(MEM7) $(MEM8) $(MEM9) $(MEM10) $(MEM11) $(MEM12) $(MEM13) $(MEM14) $(MEM15) $(MEM16) $(MEM17) $(MEM20)

STYLE=$(TEST)$(CODE_IN)$(EXTENSION).out
#$(TEST)$(CODE_IN).h.out
# $(TEST)$(DRIVER)$(EXTENSION).out
#$(TEST)$(EXTRA1)$(EXTENSION).out

#=========================
# what to run

S=
E=
D=
M=
P=
X=

# normal

#S=style
E=$(OUTDIR)$(EXE)
M=memory
D=diff
#P=Dumpit
#X=doxygen

ALL=$(S) $(E) $(M) $(D) $(P) $(X)
#ALL=$(S) $(E) $(M) $(P) $(D) $(X)


#=========================
# run preexisting code
ERASE=rm
PYTHON=~/Dropbox/Normal/programs/codeCheck.py


# TARGETS ==============================================================
# compiling

all : $(ALL) makefile
	$(info )
	$(info )
	$(info --------------------------------------------------------------------------------------------------)
	$(info ======================================= MAKEFILE SUCESSFUL ======================================= )
	$(info --------------------------------------------------------------------------------------------------)
	$(info )

$(OUTDIR)$(EXE) : $(OBJS) makefile
	$(info )
	$(info ------------------------------------------------------------------------------------------------)
	$(info ======================================= END OF COMPILING ======================================= )
	$(info ------------------------------------------------------------------------------------------------)
	$(info )
	$(info )
	$(info ==================== LINKING: $@ ==================== )
	$(CC) $(OBJS) -o $(OUTDIR)$(EXE) $(LFLAGS) 
	$(info )
#	$(info ---------------------------------------------------------------------------------------------- )
#	$(info ======================================= END OF LINKING ======================================= )
#	$(info ---------------------------------------------------------------------------------------------- )
	

$(OUTDIR)%.o : %$(EXTENSION) makefile
	$(info )
	$(info ==================== COMPILING: $@ ==================== )
	$(CC) $(CFLAGS) -c $*$(EXTENSION) -o $(OUTDIR)$*.o

#=======================================================================

clean :
	$(info --------------------------------------------------)
	$(info ==================== CLEANING ==================== )
	$(info --------------------------------------------------)
	$(ERASE) -r latex/ html/ $(OUTDIR)* $(TEST)*

doxygen : Doxyfile makefile
	$(info )
	$(info ------------------------------------------------- )
	$(info ==================== DOXYGEN ==================== )
	$(info ------------------------------------------------- )
	doxygen --version
	( cat Doxyfile ; echo "EXTRACT_ALL=YES" ) | doxygen -
	( cat Doxyfile ; echo "EXTRACT_ALL=NO" ) | doxygen -

#=======================================================================
# testing
# changes per project

$(TEST)out-%.txt : $(OUTDIR)$(EXE) makefile
	$(info )
	$(info ==================== RUNNING: $(OUTDIR)$(EXE), $@ ==================== )
	./$(OUTDIR)$(EXE) $(TO_CODE)
#	./$(OUTDIR)$(EXE) $(TO_CODE) > $(TEST)out-$(NUM_OFF).txt
	./$(OUTDIR)$(EXE) $(TO_CODE) > $(TEST)out-$*.txt

$(TEST)memory-%.txt : $(OUTDIR)$(EXE) makefile
	$(info )
	$(info ==================== VALGRIND: $(TEST)memory-$*.txt,  ==================== )
#	valgrind $(VALGRIND) ./$(OUTDIR)$(EXE) $(TO_CODE)
	valgrind $(VALGRIND) ./$(OUTDIR)$(EXE) $(TO_CODE) > $(TEST)memory-$*.txt

memory : $(MEMORY)
	$(info )
	$(info ----------------------------------------------------------------------------------------------- )
	$(info ======================================= END OF VALGRIND ======================================= )
	$(info ----------------------------------------------------------------------------------------------- )
	$(info )

#=======================================================================
# Diffs
# changes per project

$(TEST)out-%.diff : $(TEST)out-%.txt makefile
	$(info )
	$(info =========== DIFFING =========== )
#	cat $(TEST)out-$*.txt
#	cat $(MASTER)out-$*.txt
	cp $(TEST)out-$*.txt $(TEST)out$*.txt
	diff $(TEST)out-$*.txt $(MASTER)out-$*.txt
	cp $(TEST)out-$*.txt $(TEST)out-$*.diff

diff : $(DIFF) makefile
	$(info )
	cp $(TEST)out-$(NUM_OFF).diff $(TEST)out.diff
	$(info )
	$(info --------------------------------------------------------)
	$(info ==================== END OF DIFFING ==================== )
	$(info --------------------------------------------------------)
	$(info )


#===================================================
# test output files

dump%.txt : $(TEST)out-%.txt makefile
	$(info )
	$(info =========== DUMPIT: $@ ===========)
	dumpit $< > $(TEST)$@
	dumpit $(MASTER)$(<F) > $(MASTER)$@
	diff $(TEST)$@ $(MASTER)$@

Dumpit : $(DUMP) makefile
	$(info )
	$(info -------------------------------------------------------)
	$(info ==================== END OF DUMPIT ==================== )
	$(info -------------------------------------------------------)
	$(info )

#=======================================================================
# style

$(TEST)%.out : % $(PYTHON) makefile
	$(info )
	$(info ==================== CHECKING: $@  ====================)
	python $(PYTHON) --input $* --output $@
	diff $@ $(MASTER)$(<F).out
#	tablen $*


style: $(STYLE) makefile
	$(info )
	$(info -------------------------------------------------------------------------------------------------------)
	$(info ======================================= END OF STYLE CHECKING ========================================= )
	$(info -------------------------------------------------------------------------------------------------------)
	$(info )

#=======================================================================
typescript : makefile
	date
	uptime
	echo Adrian Kacmarcik
	pwd
	whoami
	uname -a
	cat /proc/cpuinfo
	cat /proc/meminfo
	gcc -g -O -Wall -Wextra -std=c11 -pedantic -pthread main-thread.c matrix-thread.c -o matrix-threads
	clang -g -O -Wall -Wextra -std=c11 -pedantic -pthread main-thread.c matrix-thread.c -o matrix-threads
	./matrix-threads _in/in-3.txt | tee output.txt
	diff --strip-trailing-cr _mOut/out-3.txt output.txt
	valgrind -q --leak-check=full --show-reachable=yes --trace-children=yes --tool=memcheck ./matrix-threads _in/in-3.txt
	doxygen
#	cd latex; make; cd ..; ls -al latex/
