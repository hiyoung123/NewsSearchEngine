CXX = g++
CFLAGS = -std=c++11 -O2 -Wall -g -DGFLAGS_NS=google

OBJS = code/service/*.hpp code/cppjieba/*.hpp code/cppjieba/limonp/*.hpp code/nlohmann/*.hpp

TARGET = code/service/base_service.pb.cc -I/usr/local/include -pthread -lbrpc -lprotobuf -lbrpc -lgflags -L/usr/local/lib

S_TARGET = server

server: $(OBJS)
	mkdir -p bin
	protoc -I=protobuf/ --cpp_out=code/service/ protobuf/base_service.proto
	$(CXX) $(CFLAGS) $(OBJS) -o bin/$(S_TARGET) code/server.cpp $(TARGET)
	
clean:
	rm -rf bin/*
