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

void signup(const string username, const string password, const string nickname)
{
	MYSQL_RES *result = NULL;
	string sql = "select * from User where username='" + username + "';";
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int rowcnt = mysql_num_rows(result);

	protobufUtils::PGRequest PGRt;

	if (rowcnt == 0) {
		sql = "insert into User values('"
		      + username + "','"
		      + password + "','"
		      + nickname + "', 0);";
		if (mysql_query(&mysql, sql.c_str()) == 0) {
			PGRt.set_code("666");
			PGRt.set_errorinfo("succed");
		} else {
			PGRt.set_code("300");
			PGRt.set_errorinfo("Username or password invalid!");
		}
	} else {
		PGRt.set_code("301");
		PGRt.set_errorinfo("Username has been used!");
	}
	PGRt.SerializeToArray(msg, 1024);
}

void login(const string username, const string password)
{
	protobufUtils::PGRequest PGRt;

	printf("%s\n", username.c_str());
	printf("%s\n", password.c_str());

	MYSQL_RES *result = NULL;
	string sql = "select * from User where username = '"
	             + username + "';";
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	int rowcnt = mysql_num_rows(result);
	if (rowcnt == 0)
	{
		PGRt.set_code("302");
		PGRt.set_errorinfo("No such a username!");
	} else {
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);

		if (strcmp(row[1], password.c_str()) == 0) {
			PGRt.set_code("666");
			PGRt.set_errorinfo("succed");
		} else {
			PGRt.set_code("303");
			PGRt.set_errorinfo("password error");
		}
	}

	PGRt.SerializeToArray(msg, 1024);
}

void postScore(const string username, const string score)
{
	protobufUtils::PGRequest PGRt;

	printf("%s\n", username.c_str());
	printf("%s\n", score.c_str());


	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.SerializeToArray(msg, 1024);
}

void postPicture(const string username, const string picture)
{
	protobufUtils::PGRequest PGRt;

	printf("%s\n", username.c_str());
	printf("%s\n", picture.c_str());


	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.SerializeToArray(msg, 1024);
}

void getRank()
{
	protobufUtils::PGRequest PGRt;


	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.SerializeToArray(msg, 1024);
}

void getPicList()
{
	protobufUtils::PGRequest PGRt;


	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.SerializeToArray(msg, 1024);
}

void getExactPic(const string pictureID)
{
	printf("%s\n", pictureID.c_str());
	protobufUtils::PGRequest PGRt;

	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.SerializeToArray(msg, 1024);
}

void closeConnect()
{
	mysql_close(&mysql);
}