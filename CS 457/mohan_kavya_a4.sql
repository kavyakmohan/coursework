/* 
    Kavya Mohan CS 457 AST 4
    local path: /Users/kavyamohan/Downloads/mohan_kavya_a4.sql
    server path: /home/mohank1/mohan_kavya_a4.sql
    source <path> in ProductDB/mohank1 database
*/

--Product(maker, model, type)--
CREATE TABLE Product (
    maker   char(1)             CHECK (maker in ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H')),
    model   int(4)              CHECK (model >= 1000), 
    type    varchar(7)          CHECK (type in ('pc', 'laptop', 'printer')),
    PRIMARY KEY(model)
);

--PC(model, speed, ram, hd, price)--
CREATE TABLE PC(
    model   int(4)              CHECK (model >= 1000), 
    speed   decimal(3,2)        CHECK (speed >= 0), 
    ram     int(4)              CHECK (ram >= 0),
    hd      int(3)              CHECK (hd >= 0),
    price   int(4)              CHECK (price >= 0),
    PRIMARY KEY(model),
    FOREIGN KEY(model) REFERENCES Product(model)
);

--Laptop(model, speed, ram, hd, screen, price)--
CREATE TABLE Laptop(
    model   int(4)              CHECK (model >= 2000),
    speed   decimal(3,2)        CHECK (speed >= 0), 
    ram     int(4)              CHECK (ram >= 0),
    hd      int(3)              CHECK (hd >= 0),
    screen  decimal(3,1)        CHECK (screen >= 0),
    price   int(4)              CHECK (price >= 0),
    PRIMARY KEY(model),    
    FOREIGN KEY(model) REFERENCES Product(model)
);

--Printer(model, color, type, price)--
CREATE TABLE Printer(
    model   int(4)              CHECK (model >= 3000),
    color   boolean             not null,
    type    varchar(7)          CHECK (type in ('ink-jet', 'laser')),
    price   int(3)              CHECK (price >= 0),
    PRIMARY KEY(model),
    FOREIGN KEY(model) REFERENCES Product(model)
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