CXX_FLAGS      := $(shell pkg-config --cflags protobuf) -xc++
LD_FLAGS       := $(shell pkg-config --libs protobuf)

PROTOS         := $(wildcard ./proto/*.proto)
PROTO_OBJS     := $(PROTOS:.proto=.pb.o)
PBGENS   := $(PROTOS:.proto=.pb.cc)
LIB := libMessage.so


all: create_out_dir $(LIB)

clean: 
	rm -rf cpp
	rm -rf .obj
	rm -f libMessage.so

create_out_dir:
	@mkdir -p cpp
	@mkdir -p .obj
	@mkdir -p .obj/proto

%.pb.cc: %.proto
	protoc --cpp_out=./cpp $<

%.pb.o : %.pb.cc
	$(CXX) $(CXX_FLAGS) -fPIC -c -I./cpp -o .obj/$@ cpp/$<

$(LIB): $(PROTO_OBJS)
	$(CXX) $(LD_FLAGS) -shared -pedantic -Wall -Wextra -o $@ $(wildcard ./.obj/proto/*.pb.o) -lprotobuf