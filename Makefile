exe = MC-Fluent


cc = g++

cflags = -Wall -O2 -I/usr/include/libxml2

clibs = -lxml2

$(exe):main.cpp SortOut.o ReadFR.o rewritepower.o ModifyMate.o filestat.o RMSE.o
	$(cc) $(cflags) -o $(exe) main.cpp SortOut.o ReadFR.o rewritepower.o ModifyMate.o filestat.o RMSE.o $(clibs)

SortOut.o: SortOut.cpp SortOut.h
	$(cc) $(cflags) -c SortOut.cpp SortOut.h $(clibs)

ReadFR.o: ReadFR.cpp ReadFR.h SortOut.o
	$(cc) $(cflags) -c ReadFR.cpp ReadFR.h SortOut.o $(clibs)

rewritepower.o: rewritepower.cpp rewritepower.h ReadFR.o SortOut.o
	$(cc) $(cflags) -c rewritepower.cpp $(clibs)

ModifyMate.o: ModifyMate.cpp ModifyMate.h ReadTRou.o ReadGEO.o
	$(cc) $(cflags) -c ModifyMate.cpp $(clibs)

ReadTRou.o:ReadTRou.cpp ReadTRou.h
	$(cc) $(cflags) -c ReadTRou.cpp $(clibs)

ReadGEO.o:ReadGEO.cpp ReadGEO.h
	$(cc) $(cflags) -c ReadGEO.cpp $(clibs)

filestat.o: filestat.cpp filestat.h
	$(cc) $(cflags) -c filestat.cpp filestat.h $(clibs)

RMSE.o: RMSE.cpp RMSE.h
	$(cc) $(cflags) -c RMSE.cpp RMSE.h $(clibs)


.PHONY: clean

clean:
	 rm -fr *~ *.o $(exe)
