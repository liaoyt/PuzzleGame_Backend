#include <mysql/mysql.h>
#include <string>
#include <stdio.h>
#include "protobuf/protobufUtils.pb.h"

using namespace std;

MYSQL mysql;
char *msg = new char[1024];

void connectMysql()
{
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "puzzlegame", "puzzlegame", "PuzzleGame", 3306, NULL, 0);
}

void signup()
{

}

void login()
{

}

void postScore()
{

}

void postPicture()
{

}

void getRank()
{

}

void getPicList()
{

}

void getExactPic()
{

}

void closeConnect()
{
	mysql_close(&mysql);
}