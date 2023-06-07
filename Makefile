ALL=mo53
CXX=g++
CXXFLAGS=-std=c++14

mo53: main.o data_list.o data_table.o manager.o list_storage.o text_loader.o bin_loader.o
	$(CXX) $(CXXFLAGS) -o mo53 main.o data_list.o data_table.o manager.o list_storage.o text_loader.o bin_loader.o

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
	rm -f mo53
