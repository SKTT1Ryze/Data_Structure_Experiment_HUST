#Makefile for Graph
TARGET=Graph.out
OBJECT=Graph.o 
SOURCE=Graph.cpp 
#make
$(TARGET):$(OBJECT)
	#gcc $^ -o $@
	g++ $^ -o $@
$(OBJECT):$(SOURCE)
	#gcc -c Graph.cpp -o Graph.o
	g++ -c Graph.cpp -o Graph.o
#clean
.PHONY:clean
	rm -rf $(OBJECT) $(TARGET)

