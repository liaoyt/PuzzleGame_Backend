
drop database if exists PuzzleGame;
create database if not exists PuzzleGame;
use PuzzleGame;

drop table if exists User, Pic;
set storage_engine = InnoDB;

create table User (
	username		varchar(30),
	password 		varchar(30),
	nickname		varchar(30),
	score 			int default 0,
	primary key (username)
);

create table Pic (
	id 			int auto_increment,
	username 		varchar(30),
	pictureDate		varchar(30),
	data			timestamp default CURRENT_TIMESTAMP,
	primary key (id),
	foreign key (username) references User (username)
);

insert into User values("zhangsan", "111111", 'zhang san', 0);
insert into User values('lisi', "222222", "li si", 0);
insert into User values('wangwu', "333333", "wang wu", 0);

insert into Pic(username, pictureDate) values('zhangsan', '22222222');
insert into Pic(username, pictureDate) values('zhangsan', '11111111');
insert into Pic(username, pictureDate) values('zhangsan', '33333333');

