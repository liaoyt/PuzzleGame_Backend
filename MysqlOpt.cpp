#include <mysql/mysql.h>
#include <string>
#include <stdio.h>
#include <fstream>
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

	PGRt.CheckInitialized();
	PGRt.SerializeToArray(msg, 1024);
}

void login(const string username, const string password)
{
	protobufUtils::PGRequest PGRt;

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
			PGRt.set_score(row[3]);
		} else {
			PGRt.set_code("303");
			PGRt.set_errorinfo("password error");
		}
	}

	PGRt.CheckInitialized();
	PGRt.SerializeToArray(msg, 1024);
}

void postScore(const string username, const string score)
{
	protobufUtils::PGRequest PGRt;

	string sql = "update User set score = " + score + " where username = '" + username + "';";
	// MYSQL_RES *result = NULL;
	if (mysql_query(&mysql, sql.c_str()) == 0) {
		PGRt.set_code("666");
		PGRt.set_errorinfo("succed");
	} else {
		PGRt.set_code("304");
		PGRt.set_errorinfo("Score Update error!");
	}

	PGRt.CheckInitialized();
	PGRt.SerializeToArray(msg, 1024);
}

void postPicture(const string username, const string pictureDate)
{
	protobufUtils::PGRequest PGRt;

	printf("%s\n", username.c_str());
	printf("%s\n", pictureDate.c_str());

	string sql = "insert into Pic(username, pictureDate) values('"
	             + username + "', '" + pictureDate + "');";

	if (mysql_query(&mysql, sql.c_str()) == 0) {
		PGRt.set_code("666");
		PGRt.set_errorinfo("succed");
	} else {
		PGRt.set_code("305");
		PGRt.set_errorinfo("Post picture error!");
	}

	PGRt.CheckInitialized();
	PGRt.SerializeToArray(msg, 1024);
}

void getRank(const string score)
{
	protobufUtils::PGRequest PGRt;

	printf("%s\n", score.c_str());

	string sql = "select nickname, score from User order by score desc limit 15;";
	MYSQL_RES *result = NULL;
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	MYSQL_ROW row = NULL;
	int rowcnt = mysql_num_rows(result);
	printf("%d\n", rowcnt);

	protobufUtils::PGRequest_RankInfo * rankinfo = PGRt.mutable_rankinfo();

	while (rowcnt --) {
		row = mysql_fetch_row(result);
		printf("%s\t%s\n", row[0], row[1]);
		rankinfo->add_topuser(row[0]);
		rankinfo->add_topscore(row[1]);
	}

	sql = "select count(*) from User where score >= " + score;
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	row = mysql_fetch_row(result);
	printf("%s\n", row[0]);
	rankinfo->set_myrank(row[0]);

	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.SerializeToArray(msg, 1024);
}

void getPicList()
{
	protobufUtils::PGRequest PGRt;

	string sql = "select * from Pic order by data desc limit 8";
	MYSQL_RES *result = NULL;
	mysql_query(&mysql, sql.c_str());
	result = mysql_store_result(&mysql);
	MYSQL_ROW row = NULL;
	int rowcnt = mysql_num_rows(result);
	printf("%d\n", rowcnt);

	while (rowcnt --) {
		row = mysql_fetch_row(result);
		printf("%s\t%s\n", row[1], row[2]);
		PGRt.add_pictures(string(row[1]) + string(row[2]));
	}

	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.CheckInitialized();
	PGRt.SerializeToArray(msg, 1024);
}

void getExactPic(const string pictureName)
{
	printf("%s\n", pictureName.c_str());
	protobufUtils::PGRequest PGRt;

	
	

	PGRt.set_code("666");
	PGRt.set_errorinfo("succed");

	PGRt.CheckInitialized();
	PGRt.SerializeToArray(msg, 1024);
}

void closeConnect()
{
	mysql_close(&mysql);
}