#include <mysql/mysql.h>
#include <string>
#include <stdio.h>
#include "protobuf/protobufUtils.pb.h"

using namespace std;

MYSQL mysql;
char *msg = new char[1025];

void connectMysql()
{
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "st6rangie", "note", 3306, NULL, 0);
}



void closeConnect()
{
	mysql_close(&mysql);
}