CXXFLAGS:=-std=c++14 -g -Wall 

lambda: main.cpp lambda.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ 

test: lambda 
	./lambda 

clean:
	rm -f *.o lambda 