start transaction;
create table hit(id smallserial primary key,name text unique not null,value smallint not null constraint positive_hit check( value >= 0));
# Doof
# das mit dem einfach, doppelt dreifahch muss anders sein

insert into hit values (default,'nichts',0),(default,'1',1),(default,'2',2),(default,'3',3),(default,'4',4),(default,'5',5),(default,'6',6),
(default,'7',7),(default,'8',8),(default,'9',9),(default,'10',10),(default,'11',11),(default,'12',12),(default,'13',13),(default,'14',14),
(default,'15',15),(default,'16',16),(default,'17',17),(default,'18',18),(default,'19',19),(default,'20',20),(default,'doppelte 1',2),
(default,'doppelte 2',4),(default,'doppelte 3',6),(default,'doppelte 4',8),(default,'doppelte 5',10),(default,'doppelte 6',12),
(default,'doppelte 7',14),(default,'doppelte 8', 16),(default,'doppelte 9',18),(default,'doppelte 10',20),(default,'doppelte 11',22),
(default,'doppelte 12',24),(default,'doppelte 13',26),(default,'doppelte 14',28),(default,'doppelte 15',30),(default,'doppelte ');
commit;
