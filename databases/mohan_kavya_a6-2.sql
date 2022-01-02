/*
    Kavya Mohan CS 457 AST 6
    local path: /Users/kavyamohan/Desktop/cs457/mohan_kavya_a6.sql
    server path: /home/mohank1/mohan_kavya_a6.sql
    source <path> in ProductDB/mohank1 database
*/

--drop tables--
DROP TABLE pc;
DROP TABLE laptop;
DROP TABLE printer;
DROP TABLE product;

--Product(maker, model, type)--
CREATE TABLE Product (
    maker   varchar(7),
    model   int(4),
    type    varchar(7),
    PRIMARY KEY(model),
    CONSTRAINT ck_maker CHECK (maker in ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H')),
    CONSTRAINT ck_model CHECK (model >= 1000),
    CONSTRAINT ck_type CHECK (type in ('pc', 'laptop', 'printer'))
);

--PC(model, speed, ram, hd, price)--
CREATE TABLE PC(
    model   int(4),
    speed   decimal(3,2),
    ram     int(4),
    hd      int(3),
    price   int(4),
    PRIMARY KEY(model),
    CONSTRAINT pc_fk FOREIGN KEY(model) REFERENCES Product(model),
    CONSTRAINT ck_model CHECK (model >= 1000),
    CONSTRAINT ck_speed CHECK (speed >= 0),
    CONSTRAINT ck_ram CHECK (ram >= 0),
    CONSTRAINT ck_hd CHECK (hd >= 0),
    CONSTRAINT ck_price CHECK (price >= 0)
);

--Laptop(model, speed, ram, hd, screen, price)--
CREATE TABLE Laptop(
    model   int(4),
    speed   decimal(3,2),
    ram     int(4),
    hd      int(3),
    screen  decimal(3,1),
    price   int(4),
    PRIMARY KEY(model),
    CONSTRAINT laptop_fk FOREIGN KEY(model) REFERENCES Product(model),
    CONSTRAINT ck_model CHECK (model >= 2000),
    CONSTRAINT ck_speed CHECK (speed >= 0),
    CONSTRAINT ck_ram CHECK (ram >= 0),
    CONSTRAINT ck_hd CHECK (hd >= 0),
    CONSTRAINT ck_screen CHECK (screen >= 0),
    CONSTRAINT ck_price CHECK (price >= 0)
);

--Printer(model, color, type, price)--
CREATE TABLE Printer(
    model   int(4),
    color   boolean             not null,
    type    varchar(10),
    price   int(3),
    PRIMARY KEY(model),
    CONSTRAINT printer_fk FOREIGN KEY(model) REFERENCES Product(model),
    CONSTRAINT ck_model CHECK (model >= 3000),
    CONSTRAINT ck_type CHECK (type in ('ink-jet', 'laser')),
    CONSTRAINT ck_price CHECK (price >= 0)
);

--insert all table entries--
--populating Product--
insert into Product(maker, model, type)
values
    ('A', 1001, 'pc'),
    ('A', 1002, 'pc'),
    ('A', 1003, 'pc'),
    ('A', 2004, 'laptop'),
    ('A', 2005, 'laptop'),
    ('A', 2006, 'laptop'),
    ('B', 1004, 'pc'),
    ('B', 1005, 'pc'),
    ('B', 1006, 'pc'),
    ('B', 2007, 'laptop'),
    ('C', 1007, 'pc'),
    ('D', 1008, 'pc'),
    ('D', 1009, 'pc'),
    ('D', 1010, 'pc'),
    ('D', 3004, 'printer'),
    ('D', 3005, 'printer'),
    ('E', 1011, 'pc'),
    ('E', 1012, 'pc'),
    ('E', 1013, 'pc'),
    ('E', 2001, 'laptop'),
    ('E', 2002, 'laptop'),
    ('E', 2003, 'laptop'),
    ('E', 3001, 'printer'),
    ('E', 3002, 'printer'),
    ('E', 3003, 'printer'),
    ('F', 2008, 'laptop'),
    ('F', 2009, 'laptop'),
    ('G', 2010, 'laptop'),
    ('H', 3006, 'printer'),
    ('H', 3007, 'printer');

--populating PC--
insert into PC(model, speed, ram, hd, price)
values
    (1001, 2.66, 1024, 250, 2114),
    (1002, 2.10, 512, 250, 995),
    (1003, 1.42, 512, 80, 478),
    (1004, 2.80, 1024, 250, 649),
    (1005, 3.20, 512, 250, 630),
    (1006, 3.20, 1024, 320, 1049),
    (1007, 2.20, 1024, 200, 510),
    (1008, 2.20, 2048, 250, 770),
    (1009, 2.00, 1024, 250, 650),
    (1010, 2.80, 2048, 300, 770),
    (1011, 1.86, 2048, 160, 959),
    (1012, 2.80, 1024, 160, 649),
    (1013, 3.06, 512, 80, 529);

--populating Laptop--
insert into Laptop(model, speed, ram, hd, screen, price)
values
    (2001, 2.00, 2048, 240, 20.1, 3673),
    (2002, 1.73, 1024, 80, 17.0, 949),
    (2003, 1.80, 512, 60, 15.4, 549),
    (2004, 2.00, 512, 60, 13.3, 1150),
    (2005, 2.16, 1024, 120, 17.0, 2500),
    (2006, 2.00, 2048, 80, 15.4, 1700),
    (2007, 1.83, 1024, 120, 13.3, 1429),
    (2008, 1.60, 1024, 100, 15.4, 900),
    (2009, 1.60, 512, 80, 14.1, 680),
    (2010, 2.00, 2048, 160, 15.4, 2300);

--populating Printer--
-- SELECT model, IF(color, 'true', 'false') color, type, price FROM Printer; --
insert into Printer(model, color, type, price)
values
    (3001, true, 'ink-jet', 99),
    (3002, false, 'laser', 239),
    (3003, true, 'laser', 899),
    (3004, true, 'ink-jet', 120),
    (3005, false, 'laser', 120),
    (3006, true, 'ink-jet', 100),
    (3007, true, 'laser', 200);

--#1 drop constraints--
ALTER TABLE PC DROP PRIMARY KEY;
ALTER TABLE PC DROP CONSTRAINT pc_fk;
ALTER TABLE PC DROP CONSTRAINT ck_model;
ALTER TABLE PC DROP CONSTRAINT ck_speed;
ALTER TABLE PC DROP CONSTRAINT ck_ram;
ALTER TABLE PC DROP CONSTRAINT ck_hd;
ALTER TABLE PC DROP CONSTRAINT ck_price;

ALTER TABLE LAPTOP DROP PRIMARY KEY;
ALTER TABLE LAPTOP DROP CONSTRAINT laptop_fk,
ALTER TABLE LAPTOP DROP CONSTRAINT ck_model;
ALTER TABLE LAPTOP DROP CONSTRAINT ck_speed;
ALTER TABLE LAPTOP DROP CONSTRAINT ck_ram;
ALTER TABLE LAPTOP DROP CONSTRAINT ck_hd;
ALTER TABLE LAPTOP DROP CONSTRAINT ck_screen;
ALTER TABLE LAPTOP DROP CONSTRAINT ck_price;

ALTER TABLE PRINTER DROP PRIMARY KEY;
ALTER TABLE PRINTER DROP CONSTRAINT printer_fk;
ALTER TABLE PRINTER DROP CONSTRAINT ck_model;
ALTER TABLE PRINTER DROP CONSTRAINT ck_type;
ALTER TABLE PRINTER DROP CONSTRAINT ck_price;

ALTER TABLE PRODUCT DROP PRIMARY KEY;
ALTER TABLE PRODUCT DROP CONSTRAINT ck_maker;
ALTER TABLE PRODUCT DROP CONSTRAINT ck_model;
ALTER TABLE PRODUCT DROP CONSTRAINT ck_type;


--#2 add dummy entries --
insert into Product(maker, model, type)
values
    ('A', 1001, 'pc'),
    ('Z', 1014, 'pc'),
    ('Z', 2015, 'laptop'),
    ('Z', 3016, 'printer'),
    ('ZZ', 9000, 'pc'),
    ('ZZ', 9001, 'laptop'),
    ('ZZ', 9002, 'printer');

insert into PC(model, speed, ram, hd, price)
values
    (1014, 1.0, 256, 1024, 800),
    (9000, -1.0, 256, 1024, 800);

insert into Laptop(model, speed, ram, hd, screen, price)
values
    (2001, 2.00, 2048, 240, 20.1, 3673),
    (2015, 4.0, 512, 512, 13.3, 5000),
    (9001, 1.0, 256, 256, 20.3, 2000);

insert into Printer(model, color, type, price)
values
    (3016, False, 'bubble-jet', 500),
    (9002 True, 'bobble-jet', 1000);

--#4 --