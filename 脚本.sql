create database xjgl;
use database xjgl;

create table student(sname char(20),sno char(5),sdept char(10),sage int);
insert into student(sname,sno,sdept) values('zhangsan','01','cs');
insert into student(sname,sdept,sage) values('xwd','math',19);
insert into student(sname,sno,sage) values('ww','04',19);
insert into student values('zhg','05','cs',20);
insert into student values('lisi','02','ee',18);

create table course(cname char(20),cno char(5));
insert into course values('database','01');
insert into course values('compilers','02');
insert into course values('AI','03');

create table sc(sno char(5),cno char(5),grade int);
insert into sc values('01','01',89);
insert into sc values('04','03',98);
insert into sc values('05','01',95);
insert into sc (sno,cno) values('01','02');
insert into sc (sno,cno) values('02','03');
insert into sc (sno,cno) values('05','02');
insert into sc (sno,cno) values('05','03');
insert into sc(cno,grade) values('02',98);