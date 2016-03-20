COMPILER      = gcc
OPTIONS       = -ansi -pedantic-errors -Wall -Wall -Werror -Wextra -o
LINKER_OPT    = -L/usr/lib -lstdc++ -lprotobuf -lmysqlclient

all: localTest

localTest: server client

server: server.cpp MysqlOpt.cpp protobuf/protobufUtils.pb.cc
	$(COMPILER) $(OPTIONS) server server.cpp MysqlOpt.cpp protobuf/protobufUtils.pb.cc $(LINKER_OPT)

client: client.cpp protobuf/protobufUtils.pb.cc
	$(COMPILER) $(OPTIONS) client client.cpp protobuf/protobufUtils.pb.cc $(LINKER_OPT)


#
# The End !
#
