/*
    Kavya Mohan CS 457 AST 7
    local path: /Users/kavyamohan/Desktop/cs457/mohan_kavya_a7.sql
    server path: /home/mohank1/mohan_kavya_a7.sql
    source <path> in ProductDB/mohank1 database
*/

--1. create view for each product type joined w/ corresponding table
DROP VIEW IF EXISTS Laptops;
DROP VIEW IF EXISTS Printers;
DROP VIEW IF EXISTS PCs;


create view Laptops as select * from Product natural join Laptop;
create view Printers as select Product.maker, Product.type, Printer.type AS printer_type, Printer.model, Printer.color, Printer.price from Product join Printer ON Product.model = Printer.model;
create view PCs as select * from Product natural join PC;

--2. write a cursor that iterates through a list of models
DELIMITER $$
DROP PROCEDURE IF EXISTS printInfo;
CREATE PROCEDURE printInfo ( INOUT productList varchar(4000) )
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE modelNum INTEGER DEFAULT 0;
    DECLARE manufacturer varchar(50);
    DECLARE prodType varchar(50);
    DECLARE prodPrice INTEGER DEFAULT 0;

    -- declare cursor for product info
    DEClARE cur1 CURSOR FOR (SELECT model, maker, type, price FROM PCs) UNION (SELECT model, maker, type, price FROM Laptops) UNION (SELECT model, maker, type, price FROM Printers);
    -- declare NOT FOUND handler
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
    OPEN cur1;
    getRow: LOOP
        FETCH cur1 INTO modelNum, manufacturer, prodType, prodPrice;
        IF finished = 1 THEN
            LEAVE getRow;
        END IF;
        -- build email list
    SET productList =CONCAT(productList,
        "
        ",manufacturer, "-", UPPER(prodType), " ", modelNum, " for $", prodPrice);   
    END LOOP getRow;
    CLOSE cur1;
END$$
DELIMITER ;


SET @productList = ""; 
CALL printInfo(@productList); 
SELECT @productList;

-- #3 
DELIMITER $$
DROP PROCEDURE IF EXISTS printSales;
CREATE PROCEDURE printSales ( INOUT salesList varchar(4000) )
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE modelNum INTEGER DEFAULT 0;
    DECLARE prodType varchar(50);

    -- declare cursor for product info
    DEClARE cur2 CURSOR FOR (SELECT model, type FROM PCs WHERE hd < 200 OR price > 1000) UNION (SELECT model, type FROM Laptops WHERE price > ram) UNION (SELECT model, type FROM Printers WHERE printer_type = 'laser');
    -- declare NOT FOUND handler
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
    OPEN cur2;
    getRow: LOOP
        FETCH cur2 INTO modelNum, prodType;
        IF finished = 1 THEN
            LEAVE getRow;
        END IF;
        -- build email list
    SET salesList =CONCAT(salesList,
        "
        ",prodType, " ", modelNum, " is on sale !" );  
    END LOOP getRow;
    CLOSE cur2;
END$$
DELIMITER ;

SET @salesList = ""; 
CALL printSales(@salesList); 
SELECT @salesList;