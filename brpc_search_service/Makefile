CXX = g++
CFLAGS = -std=c++11 -O2 -Wall -g -DGFLAGS_NS=google

OBJS = code/service/*.hpp code/connpool/*.h code/connpool/*.cpp 

TARGET = code/service/*.pb.cc  -I/usr/local/include -pthread -lbrpc -lprotobuf -lhiredis -lmysqlclient -lgflags -L/usr/local/lib

S_TARGET = server

server: $(OBJS)
	mkdir -p bin
	protoc -I=protobuf/ --cpp_out=code/service/ protobuf/service.proto
	$(CXX) $(CFLAGS) $(OBJS) -o bin/$(S_TARGET) code/server.cpp $(TARGET)
	
clean:
	rm -rf bin/*
