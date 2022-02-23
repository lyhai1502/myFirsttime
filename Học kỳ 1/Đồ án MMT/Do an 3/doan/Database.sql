create Database SocketMmt
go

use SocketMmt
go

create table Account(
	username varchar(50) NOT NULL,
	pass varchar(50) NOT NULL,
)

insert Account values ('admin', '123456')